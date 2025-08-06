#include "RealizarEmprestimoCommand.h"
#include "../../../repositories/EmprestimoRepository/EmprestimoRepository.h"
#include "../../state/EstadoEmAndamento.h"
#include "../../state/Emprestimo.h"
#include <iostream>
#include <limits>
#include <ctime>  // para std::time

RealizarEmprestimoCommand::RealizarEmprestimoCommand(LivroRepository& lRepo,
                                                     EmprestimoRepository& eRepo,
                                                     const std::string& emailUsuario)
        : livroRepo(lRepo), emprestimoRepo(eRepo), emailUsuario(emailUsuario) {}

void RealizarEmprestimoCommand::execute() {
    int idLivro;
    std::cout << "Digite o ID do livro que deseja emprestar: ";
    std::cin >> idLivro;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa buffer

    auto livroOpt = livroRepo.buscarPorId(idLivro);
    if (!livroOpt.has_value()) {
        std::cout << "Livro não encontrado.\n";
        return;
    }

    Livro livro = livroOpt.value();
    if (!livro.isDisponivel()) {
        std::cout << "Livro indisponível no momento.\n";
        return;
    }

    // Atualiza o status do livro para indisponível
    bool sucesso = livroRepo.atualizarStatus(idLivro, false);
    if (sucesso) {
        // Criar um novo empréstimo com email do usuário
        std::time_t agora = std::time(nullptr);
        std::time_t dataDevolucaoPrevista = agora + 14 * 24 * 3600;  // prazo 14 dias

        Emprestimo novoEmprestimo(
                0,                // id (gerado pelo repo ou deixado 0)
                idLivro,
                emailUsuario,     // <-- agora usa email
                agora,
                dataDevolucaoPrevista,
                0,                // créditos iniciais
                std::make_unique<EstadoEmAndamento>()
        );

        emprestimoRepo.adicionarEmprestimo(novoEmprestimo);

        std::cout << "Empréstimo realizado com sucesso!\n";
        std::cout << "Você emprestou o livro: \n";
        std::cout << "Título: " << livro.getTitulo() << "\n";
        std::cout << "Autor: " << livro.getAutor() << "\n";
        std::cout << "Ano: " << livro.getAno() << "\n";
    } else {
        std::cout << "Não foi possível realizar o empréstimo. Tente novamente.\n";
    }
}

//
// Created by vitor on 30/07/2025.
//

#include "DevolverLivroCommand.h"
#include <iostream>
#include <limits>

DevolverLivroCommand::DevolverLivroCommand(LivroRepository& repo)
        : livroRepo(repo) {}

void DevolverLivroCommand::execute() {
    int idLivro;
    std::cout << "Digite o ID do livro que deseja devolver: ";
    std::cin >> idLivro;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    auto livroOpt = livroRepo.buscarPorId(idLivro);
    if (!livroOpt.has_value()) {
        std::cout << "Livro não encontrado.\n";
        return;
    }

    Livro livro = livroOpt.value();
    if (livro.isDisponivel()) {
        std::cout << "Este livro já está marcado como disponível.\n";
        return;
    }

    bool sucesso = livroRepo.atualizarStatus(idLivro, true);
    if (sucesso) {
        std::cout << "Livro devolvido com sucesso!\n";
        std::cout << "Título: " << livro.getTitulo() << "\n";
        std::cout << "Autor: " << livro.getAutor() << "\n";
    } else {
        std::cout << "Não foi possível registrar a devolução. Tente novamente.\n";
    }
}


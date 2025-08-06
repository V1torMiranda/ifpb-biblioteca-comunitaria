//
// Created by vitor on 06/08/2025.
//

#include "EmprestimoRepository.h"
#include "../state/EstadoEmAndamento.h"   // estado inicial padrão
#include "Emprestimo.h"

#include <sstream>
#include <ctime>

EmprestimoRepository::EmprestimoRepository(const std::string& caminhoArquivo)
        : arquivoEmprestimos(caminhoArquivo) {}

std::string EmprestimoRepository::emprestimoToCSV(const Emprestimo& e) const {
    std::stringstream ss;
    ss << e.getId() << ";"
       << e.getIdLivro() << ";"
       << e.getEmailUsuario() << ";"   // <-- agora email
       << e.getDataEmprestimo() << ";"
       << e.getDataDevolucaoPrevista() << ";"
       << e.getCreditosUsuario() << ";"
       << e.obterNomeEstado();
    return ss.str();
}

Emprestimo EmprestimoRepository::emprestimoFromCSV(const std::string& linhaCSV) {
    std::stringstream ss(linhaCSV);
    std::string idStr, idLivroStr, emailUsuario, dataEmprestimoStr, dataDevPrevStr, creditosStr, estadoNome;

    std::getline(ss, idStr, ';');
    std::getline(ss, idLivroStr, ';');
    std::getline(ss, emailUsuario, ';');   // <-- agora email
    std::getline(ss, dataEmprestimoStr, ';');
    std::getline(ss, dataDevPrevStr, ';');
    std::getline(ss, creditosStr, ';');
    std::getline(ss, estadoNome, ';');

    return Emprestimo(
            std::stoi(idStr),
            std::stoi(idLivroStr),
            emailUsuario,
            static_cast<std::time_t>(std::stoll(dataEmprestimoStr)),
            static_cast<std::time_t>(std::stoll(dataDevPrevStr)),
            std::stoi(creditosStr),
            std::make_unique<EstadoEmAndamento>()
    );
}

bool EmprestimoRepository::adicionarEmprestimo(const Emprestimo& emprestimo) {
    arquivoEmprestimos.abrir("escrita");
    arquivoEmprestimos.escreverLinhaFinal(emprestimoToCSV(emprestimo));
    arquivoEmprestimos.fechar();
    return true;
}

bool EmprestimoRepository::atualizarEmprestimo(const Emprestimo& emprestimo) {
    arquivoEmprestimos.abrir("leitura");
    auto linhas = arquivoEmprestimos.lerTodosDados();
    arquivoEmprestimos.fechar();

    bool atualizado = false;
    std::deque<std::string> novasLinhas;

    for (auto& linha : linhas) {
        Emprestimo e = emprestimoFromCSV(linha);
        if (e.getId() == emprestimo.getId()) {
            novasLinhas.push_back(emprestimoToCSV(emprestimo));
            atualizado = true;
        } else {
            novasLinhas.push_back(linha);
        }
    }

    if (atualizado) {
        arquivoEmprestimos.abrir("sobrescrita");
        for (auto& l : novasLinhas) {
            arquivoEmprestimos.escreverLinhaFinal(l);
        }
        arquivoEmprestimos.fechar();
    }
    return atualizado;
}

bool EmprestimoRepository::removerEmprestimo(int idEmprestimo) {
    arquivoEmprestimos.abrir("leitura");
    auto linhas = arquivoEmprestimos.lerTodosDados();
    arquivoEmprestimos.fechar();

    bool encontrado = false;
    std::deque<std::string> novasLinhas;

    for (auto& linha : linhas) {
        Emprestimo e = emprestimoFromCSV(linha);
        if (e.getId() != idEmprestimo) {
            novasLinhas.push_back(linha);
        } else {
            encontrado = true;
        }
    }

    if (encontrado) {
        arquivoEmprestimos.abrir("sobrescrita");
        for (auto& l : novasLinhas) {
            arquivoEmprestimos.escreverLinhaFinal(l);
        }
        arquivoEmprestimos.fechar();
    }
    return encontrado;
}

std::optional<Emprestimo> EmprestimoRepository::buscarPorId(int idEmprestimo) {
    arquivoEmprestimos.abrir("leitura");
    while (true) {
        std::string linha = arquivoEmprestimos.lerLinha();
        if (linha.empty()) break;
        Emprestimo e = emprestimoFromCSV(linha);
        if (e.getId() == idEmprestimo) {
            arquivoEmprestimos.fechar();
            return e;
        }
    }
    arquivoEmprestimos.fechar();
    return std::nullopt;
}

std::deque<Emprestimo> EmprestimoRepository::listarTodos() {
    arquivoEmprestimos.abrir("leitura");
    auto linhas = arquivoEmprestimos.lerTodosDados();
    arquivoEmprestimos.fechar();

    std::deque<Emprestimo> emprestimos;
    for (auto& linha : linhas) {
        if (!linha.empty()) {
            emprestimos.push_back(emprestimoFromCSV(linha));
        }
    }
    return emprestimos;
}

std::deque<Emprestimo> EmprestimoRepository::listarPorUsuario(const std::string& emailUsuario) {
    auto todos = listarTodos();
    std::deque<Emprestimo> resultado;
    for (auto& e : todos) {
        if (e.getEmailUsuario() == emailUsuario) {
            resultado.push_back(std::move(e));
        }
    }
    return resultado;
}

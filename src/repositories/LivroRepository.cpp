//
// Created by vitor on 30/07/2025.
//

#include "LivroRepository.h"
#include <sstream>
#include <iostream>

LivroRepository::LivroRepository(const std::string& caminhoArquivo) : arquivoLivros(caminhoArquivo) {}

bool LivroRepository::adicionarLivro(const Livro& livro) {
    arquivoLivros.abrir("escrita");
    arquivoLivros.escreverLinhaFinal(livro.toCSV());
    arquivoLivros.fechar();
    return true;
}

std::deque<Livro> LivroRepository::listarLivros() {
    arquivoLivros.abrir("leitura");
    std::deque<std::string> linhas = arquivoLivros.lerTodosDados();
    arquivoLivros.fechar();

    std::deque<Livro> livros;
    for (auto& linha : linhas) {
        if (!linha.empty()) {
            livros.push_back(Livro::fromCSV(linha));
        }
    }
    return livros;
}

bool LivroRepository::removerLivro(int idLivro) {
    arquivoLivros.abrir("leitura");
    auto linhas = arquivoLivros.lerTodosDados();
    arquivoLivros.fechar();

    bool encontrado = false;
    std::deque<std::string> novasLinhas;

    for (auto& linha : linhas) {
        Livro l = Livro::fromCSV(linha);
        if (l.getId() != idLivro) {
            novasLinhas.push_back(linha);
        } else {
            encontrado = true;
        }
    }

    if (encontrado) {
        arquivoLivros.abrir("sobrescrita");
        for (auto& novaLinha : novasLinhas) {
            arquivoLivros.escreverLinhaFinal(novaLinha);
        }
        arquivoLivros.fechar();
    }

    return encontrado;
}

bool LivroRepository::atualizarLivro(const Livro& livro) {
    arquivoLivros.abrir("leitura");
    auto linhas = arquivoLivros.lerTodosDados();
    arquivoLivros.fechar();

    bool atualizado = false;
    std::deque<std::string> novasLinhas;

    for (auto& linha : linhas) {
        Livro l = Livro::fromCSV(linha);
        if (l.getId() == livro.getId()) {
            novasLinhas.push_back(livro.toCSV());
            atualizado = true;
        } else {
            novasLinhas.push_back(linha);
        }
    }

    if (atualizado) {
        arquivoLivros.abrir("sobrescrita");
        for (auto& novaLinha : novasLinhas) {
            arquivoLivros.escreverLinhaFinal(novaLinha);
        }
        arquivoLivros.fechar();
    }

    return atualizado;
}

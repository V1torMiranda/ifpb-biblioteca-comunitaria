// Created by vitor on 30/07/2025.

#include "./LivroRepository.h"
#include <sstream>
#include <iostream>

LivroRepository::LivroRepository(const std::string& caminhoArquivo) : arquivoLivros(caminhoArquivo) {}


std::string LivroRepository::livroToCSV(const Livro& livro) const {
    std::stringstream ss;
    
    ss << livro.getId() << ";" 
       << livro.getTitulo() << ";" 
       << livro.getAutor() << ";" 
       << livro.getEditora() << ";" 
       << livro.getAno() << ";" 
       << (livro.isDisponivel() ? "1" : "0");

    return ss.str();
}

Livro LivroRepository::livroFromCSV(const std::string& linhaCSV) {
    std::stringstream ss(linhaCSV);
    std::string idStr, titulo, autor, editora, anoStr, disponivelStr;
    std::getline(ss, idStr, ';');
    std::getline(ss, titulo, ';');
    std::getline(ss, autor, ';');
    std::getline(ss, editora, ';');
    std::getline(ss, anoStr, ';');
    std::getline(ss, disponivelStr, ';');

    return Livro(std::stoi(idStr), titulo, autor, editora, std::stoi(anoStr), disponivelStr == "1");
}


bool LivroRepository::adicionarLivro(const Livro& livro) {
    arquivoLivros.abrir("escrita");
    arquivoLivros.escreverLinhaFinal(this->livroToCSV(livro));
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
            livros.push_back(this->livroFromCSV(linha));
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
        Livro l = this->livroFromCSV(linha);
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
        Livro l = this->livroFromCSV(linha);
        if (l.getId() == livro.getId()) {
            novasLinhas.push_back(this->livroToCSV(livro));
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

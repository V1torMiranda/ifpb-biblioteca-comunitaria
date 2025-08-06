//
// Created by vitor on 30/07/2025.
//


#include "ConsultarAcervoCommand.h"
#include "../../repositories/LivroRepository/LivroRepository.h"
#include "../utils/ConsoleUtils.h"
#include <iostream>

ConsultarAcervoCommand::ConsultarAcervoCommand(LivroRepository& repo)
        : livroRepo(repo) {}

void ConsultarAcervoCommand::execute() {
    auto livros = livroRepo.listarLivros();

    if (livros.empty()) {
        std::cout << "Nenhum livro encontrado no acervo.\n";
        return;
    }

    ConsoleUtils::printTituloCentralizado("=== Acervo de Livros ===");


    for (const auto& livro : livros) {
        std::cout << livro.getId() << " - " << livro.getTitulo()
                  << " | Autor: " << livro.getAutor()
                  << " | Editora: " << livro.getEditora()
                  << " | Ano: " << livro.getAno()
                  << " | Disponivel: " << (livro.isDisponivel() ? "Sim" : "Nao")
                  << "\n"
                  << std::endl;
    }
}


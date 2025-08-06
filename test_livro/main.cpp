//
// Created by vitor on 30/07/2025.
//

#include "../src/repositories/LivroRepository.h"
#include <iostream>

int main() {
    LivroRepository repo("../database/books.txt");

    Livro novoLivro(1, "Clean Code", "Robert C. Martin", "Prentice Hall", 2008, true);
    repo.adicionarLivro(novoLivro);

    auto livros = repo.listarLivros();
    for (const auto& l : livros) {
        std::cout << l.getId() << " - " << l.getTitulo() << " - " << (l.isDisponivel() ? "Disponível" : "Indisponível") << "\n";
    }

    return 0;
}

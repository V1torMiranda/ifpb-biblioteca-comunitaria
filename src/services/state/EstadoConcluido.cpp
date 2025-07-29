//
// Created by vitor on 29/07/2025.
//

#include <iostream>
#include "EstadoConcluido.h"
#include "Emprestimo.h"

void EstadoConcluido::devolverLivro(Emprestimo& emprestimo) {
    std::cout << "O livro ja foi devolvido anteriormente. Nenhuma acao necessaria.\n";
}

void EstadoConcluido::verificarStatus(Emprestimo& emprestimo) {
    std::cout << "Emprestimo concluido.\n";
}

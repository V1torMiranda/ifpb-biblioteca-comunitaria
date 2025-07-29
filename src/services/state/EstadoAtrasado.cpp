//
// Created by vitor on 29/07/2025.
//

#include <iostream>
#include "EstadoAtrasado.h"
#include "Emprestimo.h"
#include "EstadoConcluido.h"

void EstadoAtrasado::devolverLivro(Emprestimo& emprestimo) {
    std::cout << "Livro devolvido com atraso! Penalidade aplicada.\n";
    emprestimo.ajustarCreditos(-1); // penaliza atraso
    emprestimo.definirEstado(std::make_unique<EstadoConcluido>());
}

void EstadoAtrasado::verificarStatus(Emprestimo& emprestimo) {
    std::cout << "Emprestimo atrasado! Penalidade aplicada.\n";
    emprestimo.ajustarCreditos(-1);
}

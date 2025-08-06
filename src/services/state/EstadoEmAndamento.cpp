//
// Created by vitor on 29/07/2025.
//

#include <iostream>
#include "EstadoEmAndamento.h"
#include "Emprestimo.h"
#include "EstadoConcluido.h"


EstadoEmAndamento::EstadoEmAndamento() = default;
EstadoEmAndamento::~EstadoEmAndamento() = default;

void EstadoEmAndamento::devolverLivro(Emprestimo& emprestimo) {
    std::cout << "Livro devolvido com sucesso!\n";
    emprestimo.definirEstado(std::make_unique<EstadoConcluido>());
}

void EstadoEmAndamento::verificarStatus(Emprestimo& emprestimo) {
    std::cout << "Emprestimo em andamento. Nenhuma acao extra.\n";
}


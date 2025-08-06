//
// Created by vitor on 29/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_ESTADOCONCLUIDO_H
#define BIBLIOTECA_COMUNITARIA_ESTADOCONCLUIDO_H

#endif //BIBLIOTECA_COMUNITARIA_ESTADOCONCLUIDO_H

#pragma once
#include "EstadoEmprestimo.h"

class EstadoConcluido : public EstadoEmprestimo {
public:

    EstadoConcluido();
    ~EstadoConcluido();

    void devolverLivro(Emprestimo& emprestimo) override;
    void verificarStatus(Emprestimo& emprestimo) override;
    std::string nome() const override { return "Concluido"; }
};

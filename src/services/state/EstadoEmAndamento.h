//
// Created by vitor on 29/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_ESTADOEMANDAMENTO_H
#define BIBLIOTECA_COMUNITARIA_ESTADOEMANDAMENTO_H

#endif //BIBLIOTECA_COMUNITARIA_ESTADOEMANDAMENTO_H

#pragma once
#include "EstadoEmprestimo.h"

class EstadoEmAndamento : public EstadoEmprestimo {
public:

    EstadoEmAndamento();  // declarado
    ~EstadoEmAndamento(); // declarado

    void devolverLivro(Emprestimo& emprestimo) override;
    void verificarStatus(Emprestimo& emprestimo) override;
    std::string nome() const override { return "Em andamento"; }
};

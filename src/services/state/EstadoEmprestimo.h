//
// Created by vitor on 29/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_ESTADOEMPRESTIMO_H
#define BIBLIOTECA_COMUNITARIA_ESTADOEMPRESTIMO_H

#endif //BIBLIOTECA_COMUNITARIA_ESTADOEMPRESTIMO_H

#pragma once
#include <string>

class Emprestimo; // Forward declaration

class EstadoEmprestimo {
public:
    virtual ~EstadoEmprestimo() = default;
    virtual void devolverLivro(Emprestimo& emprestimo) = 0;
    virtual void verificarStatus(Emprestimo& emprestimo) = 0;
    virtual std::string nome() const = 0;
};

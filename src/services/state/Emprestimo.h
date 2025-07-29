//
// Created by vitor on 29/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_EMPRESTIMO_H
#define BIBLIOTECA_COMUNITARIA_EMPRESTIMO_H

#endif //BIBLIOTECA_COMUNITARIA_EMPRESTIMO_H

#pragma once
#include <memory>
#include <string>
#include "EstadoEmprestimo.h"

class Emprestimo {
private:
    std::unique_ptr<EstadoEmprestimo> estado;
    int creditosUsuario;

public:
    Emprestimo(std::unique_ptr<EstadoEmprestimo> estadoInicial, int creditos);
    void definirEstado(std::unique_ptr<EstadoEmprestimo> novoEstado);
    void devolverLivro();
    void verificarStatus();
    void ajustarCreditos(int valor);
    int obterCreditos() const;
    std::string obterNomeEstado() const;
};

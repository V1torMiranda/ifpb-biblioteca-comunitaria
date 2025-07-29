//
// Created by vitor on 29/07/2025.
//


#include "Emprestimo.h"

Emprestimo::Emprestimo(std::unique_ptr<EstadoEmprestimo> estadoInicial, int creditos)
        : estado(std::move(estadoInicial)), creditosUsuario(creditos) {}

void Emprestimo::definirEstado(std::unique_ptr<EstadoEmprestimo> novoEstado) {
    estado = std::move(novoEstado);
}

void Emprestimo::devolverLivro() { estado->devolverLivro(*this); }

void Emprestimo::verificarStatus() { estado->verificarStatus(*this); }

void Emprestimo::ajustarCreditos(int valor) { creditosUsuario += valor; }

int Emprestimo::obterCreditos() const { return creditosUsuario; }

std::string Emprestimo::obterNomeEstado() const { return estado->nome(); }

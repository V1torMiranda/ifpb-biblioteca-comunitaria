//
// Created by vitor on 29/07/2025.
//

#include <iostream>
#include "../ifpb-biblioteca-comunitaria/src/services/state/Emprestimo.h"
#include "../ifpb-biblioteca-comunitaria/src/services/state/EstadoEmAndamento.h"
#include "../ifpb-biblioteca-comunitaria/src/services/state/EstadoAtrasado.h"

int main() {
    Emprestimo e1(std::make_unique<EstadoEmAndamento>(), 5);
    std::cout << "Estado atual: " << e1.obterNomeEstado() << "\n";
    e1.verificarStatus();
    e1.devolverLivro();
    std::cout << "Novo estado: " << e1.obterNomeEstado() << "\n";

    Emprestimo e2(std::make_unique<EstadoAtrasado>(), 5);
    std::cout << "\nEstado atual: " << e2.obterNomeEstado() << "\n";
    e2.verificarStatus();
    e2.devolverLivro();
    std::cout << "Novo estado: " << e2.obterNomeEstado() << "\n";
    std::cout << "Creditos do usuario: " << e2.obterCreditos() << "\n";

    return 0;
}

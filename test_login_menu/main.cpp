//
// Created by vitor on 30/07/2025.
//

#include <iostream>
#include "../src/services/LoginFacade/LoginFacade.hpp"


int main() {
    // Caminhos para os arquivos de dados
    std::string caminhoUsuarios = "../database/users.txt";
    std::string caminhoLivros   = "../database/books.txt";
    std::string caminhoEmprestimos = "../database/emprestimos.txt";

    LoginFacade facade(caminhoUsuarios, caminhoLivros, caminhoEmprestimos);


    std::string email, senha;

    std::cout << "==== LOGIN ====\n";
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);

    if (facade.login(email, senha)) {
        facade.exibirMenuPrincipal(email);
    } else {
        std::cout << "Credenciais invalidas.\n";
    }

    return 0;
}


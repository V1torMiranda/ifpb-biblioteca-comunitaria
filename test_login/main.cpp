#include <iostream>
#include "../ifpb-biblioteca-comunitaria/src/repositories/UsuarioRepository.h"
#include "../ifpb-biblioteca-comunitaria/src/services/LoginFacade/LoginFacade.hpp"

int main() {
    LoginFacade loginFacade;

    std::string email, senha;

    std::cout << "Digite seu email: ";
    std::getline(std::cin, email);

    std::cout << "Digite sua senha: ";
    std::getline(std::cin, senha);

    if (loginFacade.login(email, senha)) {
        std::cout << "Login efetuado com sucesso!\n";
    } else {
        std::cout << "Email ou senha incorretos.\n";
    }

    return 0;
}

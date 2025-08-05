#include <iostream>
<<<<<<< HEAD
#include "..\repositories/UsuarioRepository.h"
#include "..\services/LoginFacade/LoginFacade.hpp"
=======
#include "../ifpb-biblioteca-comunitaria/src/repositories/UsuarioRepository.h"
#include "../ifpb-biblioteca-comunitaria/src/services/LoginFacade/LoginFacade.hpp"
>>>>>>> cf5146800141e1a1d1353bc84f6d951df50ec80f

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

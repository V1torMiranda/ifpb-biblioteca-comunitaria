#ifndef LOGIN_FACADE_HPP
#define LOGIN_FACADE_HPP

#include <iostream>
#include <string>
#include "../../repositories/UsuarioRepository.h"

class LoginFacade {
private:
    UsuarioRepository usuarioRepo;

    void limparTela();
    void desenharLinha(int tamanho);
    void desenharTitulo(const std::string& titulo);

public:
    // Construtor agora recebe caminho do arquivo de usuários (default definido)
    explicit LoginFacade(const std::string& caminhoArquivoUsuarios = "../database/users.txt");

    // Retorna true se login válido, false caso contrário
    bool login(const std::string& email, const std::string& senha);

    void exibirMenu();
};

#endif

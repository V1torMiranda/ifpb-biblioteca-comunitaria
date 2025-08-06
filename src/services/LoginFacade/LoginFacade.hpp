#ifndef LOGIN_FACADE_HPP
#define LOGIN_FACADE_HPP

#include "../../repositories/UsuarioRepository/UsuarioRepository.h"
#include <string>
#include <map>
#include <memory>
#include "ICommand.h"

class LoginFacade {
private:
    UsuarioRepository usuarioRepo;
    std::map<int, std::unique_ptr<ICommand>> comandos;
    deque<string> opcoes;  
    
    void registrarComandos(bool admin);
    void limparTela();
    void desenharLinha(int tamanho);
    void desenharTitulo(const std::string& titulo);
    void exibirMenuPadrao();
    void exibirMenuAdmin();

public:
    explicit LoginFacade(const std::string& caminhoUsuarios);
    bool login(const std::string& email, const std::string& senha);
    bool isAdmin(const std::string& email);
    void exibirMenuPrincipal(const std::string& email);
    void validaEntrada(int& escolha);
};

#endif
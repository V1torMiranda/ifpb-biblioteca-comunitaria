#ifndef LOGIN_FACADE_HPP
#define LOGIN_FACADE_HPP

#include <string>

#include <unordered_map>

#include <map>

#include <memory>
#include "../../repositories/UsuarioRepository.h"
#include "../../repositories/LivroRepository.h"
#include "Comandos/ConsultarAcervoCommand.h"

class LoginFacade {
private:
    UsuarioRepository usuarioRepo;

    LivroRepository livroRepo;  // Agora temos o repositório de livros
    std::unordered_map<int, std::unique_ptr<ICommand>> comandos;


    std::map<int, std::unique_ptr<ICommand>> comandos;
    deque<string> opcoes;  
    


    void limparTela();
    void desenharLinha(int tamanho);
    void desenharTitulo(const std::string& titulo);
    void exibirMenuPadrao();
    void exibirMenuAdmin();
    void registrarComandos(bool admin);

public:
    LoginFacade(const std::string& caminhoUsuarios, const std::string& caminhoLivros);

    bool login(const std::string& email, const std::string& senha);
    bool isAdmin(const std::string& email);
    void exibirMenuPrincipal(const std::string& email);
    void validaEntrada(int& escolha);
};


#endif



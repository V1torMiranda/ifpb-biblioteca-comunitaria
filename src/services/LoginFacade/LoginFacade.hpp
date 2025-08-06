#ifndef LOGIN_FACADE_HPP
#define LOGIN_FACADE_HPP

#include "../../repositories/UsuarioRepository/UsuarioRepository.h"
#include "../../repositories/LivroRepository/LivroRepository.h"
#include "../../repositories/EmprestimoRepository/EmprestimoRepository.h"
#include <string>
#include <map>
#include <memory>
#include "ICommand.h"

class LoginFacade {

public:
    LoginFacade(const std::string& caminhoUsuarios,
                const std::string& caminhoLivros,
                const std::string& caminhoEmprestimos);

    bool login(const std::string& email, const std::string& senha);
    bool isAdmin(const std::string& email);
    void exibirMenuPrincipal(const std::string& email);
    void validaEntrada(int& escolha);

private:
    Usuario user;
    UsuarioRepository usuarioRepo;
    LivroRepository livroRepo;
    EmprestimoRepository emprestimoRepo;
    std::map<int, std::unique_ptr<ICommand>> comandos;

    deque<string> opcoes;

    void registrarComandos(bool admin, const std::string& email);
    void limparTela();
    void desenharLinha(int tamanho);
    void desenharTitulo(const std::string& titulo);
    void exibirMenuPadrao();
    void exibirMenuAdmin();


};

#endif
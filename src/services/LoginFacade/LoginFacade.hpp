#ifndef LOGIN_FACADE_HPP
#define LOGIN_FACADE_HPP

#include "../FstreamAdapter/FstreamAdapter.hpp"
#include <iostream>

class LoginFacade {
  private:
    FstreamAdapter bancoDados;
    deque<string> opcoes;
    void limparTela();
    void desenharLinha(int tamanho);
    void desenharTitulo(string titulo);
  
  public:
    LoginFacade();
    ~LoginFacade();
    void login(string email, string senha);
    void exibirMenu();
    void validaEntrada(int& escolha);
};

#endif
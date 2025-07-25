#ifndef LOGIN_FACADE_HPP
#define LOGIN_FACADE_HPP

#include "../FstreamAdapter/FstreamAdapter.hpp"
#include <iostream>

class LoginFacade {
  private:
    // FstreamAdapter bancoDados
    void limparTela();
    void desenharLinha(int tamanho);
    void desenharTitulo(string titulo);
  
  public:
    void login(string email, string senha);
    void exibirMenu();
    void sair();
};

#endif
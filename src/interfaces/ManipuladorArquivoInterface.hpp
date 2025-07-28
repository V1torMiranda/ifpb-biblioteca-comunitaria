#ifndef MANIPULADOR_ARQUIVO_INTERFACE_HPP
#define MANIPULADOR_ARQUIVO_INTERFACE_HPP

#include <string>
#include <deque> // Estrutura de dados que faz inserções e remoções nas extremidades e permite o acesso aleatório por índice.
using namespace std;

class ManipuladorArquivoInterface {
  public:
    virtual void abrir(string modo) = 0;
    virtual void fechar() = 0;

    virtual string lerLinha() = 0;
    virtual deque<string> lerTodosDados() = 0;

    virtual void escreverLinhaFinal(string linha) = 0;
    virtual void modificarLinha(int numLinha, string novaLinha) = 0;

    virtual string getModo() = 0;
    virtual int getQuantLinhas() = 0;
};

#endif
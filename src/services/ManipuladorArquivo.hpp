#ifndef MANIPULADOR_ARQUIVO_HPP 
#define MANIPULADOR_ARQUIVO_HPP

#include <fstream>
#include <string>

using namespace std;

class ManipuladorArquivo {
  private:
    string caminhoArquivo;
    string modo;
    fstream arq;
  
  public:
    ManipuladorArquivo(string caminho);
    void abrir(string modo);
    void fechar();
    string lerLinha();

};

#endif
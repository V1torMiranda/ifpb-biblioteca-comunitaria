#ifndef MANIPULADOR_ARQUIVO_HPP 
#define MANIPULADOR_ARQUIVO_HPP

#include <fstream>
#include <string>

using namespace std;

class ManipuladorArquivo {
  private:
    string caminhoArquivo;
    ifstream arqModoLeitura;
    ofstream arquivoModoEscrita;
  
  public:
    ManipuladorArquivo(string caminho);
    void abrir();
    void fechar();
    string lerLinha();

};

#endif
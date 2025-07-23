#ifndef FSTREAM_ADAPTER_HPP 
#define FSTREAM_ADAPTER_HPP

#include <fstream>
#include "../interfaces/ManipuladorArquivoInterface.hpp"

class FstreamAdapter : public ManipuladorArquivoInterface {
  private:
    string caminhoArquivo;
    string modo;
    fstream arq;
  
  public:
    FstreamAdapter(string caminho);
    ~FstreamAdapter();
    
    void abrir(string modo);
    void fechar();

    string lerLinha();
    deque<string> lerTodosDados();

    void escreverLinhaFinal(string linha);
    void modificarLinha(int numLinha, string novaLinha);

    string getModo();
    int getQuantLinhas();
};

#endif
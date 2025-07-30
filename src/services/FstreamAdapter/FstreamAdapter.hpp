#ifndef FSTREAM_ADAPTER_HPP
#define FSTREAM_ADAPTER_HPP

#include <fstream>
#include <string>
#include <deque>
#include "../../interfaces/ManipuladorArquivoInterface.hpp"

using std::string;
using std::deque;
using std::fstream;

class FstreamAdapter : public ManipuladorArquivoInterface {
private:
    string caminhoArquivo;
    string modo;
    fstream arq;
    bool isOpen;

public:
    FstreamAdapter(string caminho);
    ~FstreamAdapter();

    // Evita cópia, pois fstream não permite
    FstreamAdapter(const FstreamAdapter&) = delete;
    FstreamAdapter& operator=(const FstreamAdapter&) = delete;

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

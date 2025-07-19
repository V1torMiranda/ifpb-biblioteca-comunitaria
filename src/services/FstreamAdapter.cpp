#include "./FstreamAdapter.hpp"
#include <iostream>

FstreamAdapter::FstreamAdapter(string caminho) : caminhoArquivo(caminho) {}

FstreamAdapter::~FstreamAdapter() {
  if (this->arq.is_open()) {
    this->fechar();
  }
}

void FstreamAdapter::abrir(string modo) {
  this->arq = fstream();

  if (modo == "leitura") {
    this->arq.open(this->caminhoArquivo, this->arq.in);
    this->modo = "leitura";
  } else if (modo == "escrita") {
    this->arq.open(this->caminhoArquivo, this->arq.app);
    this->modo = "escrita";
  } else {
    cout << "Não existe esse modo para a manipulação de arquivos." << endl;
  }

  if (!this->arq.is_open()) {
    cout << "Deu algum problema na abertura do arquivo." << endl;
    this->fechar();
  }
}

void FstreamAdapter::fechar() {
  this->arq.close();
  this->modo = "";
}

string FstreamAdapter::lerLinha() {
  
  if (this->modo == "escrita") {
    cout << "O seu arquivo foi aberto em modo escrita. Nenhum dado será lido." << endl;
    return "";
  }

  else if (this->arq.eof()) {
    cout << "O arquivo já foi lido totalmente." << endl;
    return "";
  }
  
  string dados;
  getline(this->arq, dados);
  return dados;
}

deque<string> FstreamAdapter::lerTodosDados() {
  deque<string> linhas = {""};

  // Movendo o ponteiro para o início do arquivo
  this->arq.seekg(this->arq.beg);


  return linhas;
}

void FstreamAdapter::escreverLinhaFinal(string linha) {

}

void FstreamAdapter::modificarLinha(int numLinha, string novaLinha) {

}

string FstreamAdapter::getModo() { return this->modo; }


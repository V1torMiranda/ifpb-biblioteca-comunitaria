#include "./ManipuladorArquivo.hpp"
#include <iostream>

ManipuladorArquivo::ManipuladorArquivo(string caminho) :
  caminhoArquivo(caminho) {}

ManipuladorArquivo::~ManipuladorArquivo() {
  if (this->arq.is_open()) {
    this->fechar();
  }
}

void ManipuladorArquivo::abrir(string modo) {
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

void ManipuladorArquivo::fechar() {
  this->arq.close();
  this->modo = "";
}

string ManipuladorArquivo::lerLinha() {
  
  if (this->modo == "escrita") {
    cout << "O seu arquivo foi aberto em modo escrita. Nenhum dado será lido." << endl;
    return "";
  }
  
  string dados;
  getline(this->arq, dados);
  return dados;
}

string ManipuladorArquivo::getModo() { return this->modo; }
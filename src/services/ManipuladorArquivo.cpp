#include "./ManipuladorArquivo.hpp"

ManipuladorArquivo::ManipuladorArquivo(string caminho) :
  caminhoArquivo(caminho) {}

void ManipuladorArquivo::abrir() {
  this->arqModoLeitura = ifstream();
  this->arqModoLeitura.open(this->caminhoArquivo);
}

void ManipuladorArquivo::fechar() {
  this->arqModoLeitura.close();
}

string ManipuladorArquivo::lerLinha() {
  char dados[100];
  this->arqModoLeitura.getline(dados, 9);
  
  string saida = dados;
  return saida;
}

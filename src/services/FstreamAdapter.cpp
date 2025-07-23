#include "./FstreamAdapter.hpp"
#include <iostream>

FstreamAdapter::FstreamAdapter(string caminho) : caminhoArquivo(caminho), isOpen(false) {}

FstreamAdapter::~FstreamAdapter() {
  if (isOpen)
    this->fechar();
}


void FstreamAdapter::abrir(string modo) {
  this->arq = fstream();

  if (modo == "leitura") {
    this->arq.open(this->caminhoArquivo, this->arq.in);
    this->modo = "leitura";
    this->isOpen = true;
  } else if (modo == "escrita") {
    this->arq.open(this->caminhoArquivo, this->arq.app);
    this->modo = "escrita";
    this->isOpen = true;
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
  this->isOpen = false;
}



string FstreamAdapter::lerLinha() {

  if (!isOpen) {
    return "";
  }
  
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
  deque<string> linhas;

  if (!isOpen) {
    return linhas;
  }

  if (this->modo == "escrita") {
    cout << "O seu arquivo foi aberto em modo escrita. Nenhum dado será lido." << endl;
    return linhas;
  }

  // Movendo o ponteiro para o início do arquivo
  this->arq.seekg(this->arq.beg);

  while (!this->arq.eof()) {
    string linha = this->lerLinha();
    if (linha != "")
      linhas.push_back(linha);
  }

  return linhas;
}

void FstreamAdapter::escreverLinhaFinal(string linha) {

  if (!isOpen) {
    return;
  }

  if (this->modo == "leitura") {
    cout << "O arquivo foi aberto em modo leitura. Nenhum dado será adicionado." << endl;
    return;
  }
  
  this->arq.seekp(this->arq.end); // Movendo o ponteiro para o fim do arquivo
  this->arq << linha + "\n";

  /* Verificar posteriormente qual o último character do arquivo */
}

void FstreamAdapter::modificarLinha(int numLinha, string novaLinha) {
  
  if (!isOpen) {
    return;  
  }

  if (this->modo == "leitura") {
    cout << "O arquivo foi aberto em modo leitura. Nenhum dado será modificado." << endl;
    return;
  }

}

string FstreamAdapter::getModo() { return this->modo; }

int FstreamAdapter::getQuantLinhas() {

  if (!isOpen) {
    return 0;
  }
  
  int quantLinhas = 0;
  
  if (this->modo == "leitura") {
    quantLinhas = (this->lerTodosDados()).size();
    return quantLinhas;
  }
  
  // Abrindo uma cópia do arquivo em modo leitura
  FstreamAdapter arqLeitura = FstreamAdapter(this->caminhoArquivo);
  arqLeitura.abrir("leitura");
  quantLinhas = (arqLeitura.lerTodosDados()).size();
  arqLeitura.fechar();
  
  return quantLinhas; 
}


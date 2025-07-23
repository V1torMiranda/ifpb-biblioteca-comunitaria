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

  if (this->modo == "leitura") {
    cout << "O arquivo foi aberto em modo leitura. Nenhum dado será adicionado." << endl;
    return;
  }

  /* Verificar posteriormente qual o último character do arquivo */
  
  this->arq.seekp(this->arq.end); // Movendo o ponteiro para o fim do arquivo
  this->arq << linha + "\n";
}

void FstreamAdapter::modificarLinha(int numLinha, string novaLinha) {
  
  if (this->modo == "leitura") {
    cout << "O arquivo foi aberto em modo leitura. Nenhum dado será modificado." << endl;
    return;
  }



}

string FstreamAdapter::getModo() { return this->modo; }

int FstreamAdapter::getQuantLinhas() { 
  
  string modoAntigo = this->getModo();

  if (modoAntigo == "escrita") {
    this->modo = "leitura";
  }

  deque<string> linhas = this->lerTodosDados();

  // for (string l : linhas)
  //   cout << l << endl;

  int quantLinhas = linhas.size();

  if (modoAntigo == "escrita") {
    this->modo = "escrita";
  }
  
  return quantLinhas; 
}


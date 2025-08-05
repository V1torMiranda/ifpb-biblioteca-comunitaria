#include "./FstreamAdapter.hpp"
#include <iostream>

/*  
  std::ios_base::openmode:
    - app: joga o ponteiro para o fim do arquivo antes de cada escrita
    - ate: joga o ponteiro para o fim do arquivo (problemático)
    - in: modo leitura
    - binary: trata arquivos binários (problemático)
    - trunc: a princípio, limparia o conteúdo do arquivo (problemático)
    - out: modo escrita
*/

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
    } else if (modo == "sobrescrita") {
        this->arq.open(this->caminhoArquivo, std::ios_base::out);
        this->modo = "sobrescrita";
        this->isOpen = true;
    } else {
        std::cout << "Não existe esse modo para a manipulação de arquivos." << std::endl;
    }

    if (!this->arq.is_open()) {
        std::cout << "Deu algum problema na abertura do arquivo." << std::endl;
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

    if (this->modo == "escrita" || this->modo == "sobrescrita") {
        std::cout << "O seu arquivo foi aberto em modo escrita. Nenhum dado será lido." << std::endl;
        return "";
    }

    else if (this->arq.eof()) {
        std::cout << "O arquivo já foi lido totalmente." << std::endl;
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

    if (this->modo == "escrita" || this->modo == "sobrescrita") {
        std::cout << "O seu arquivo foi aberto em modo escrita. Nenhum dado será lido." << std::endl;
        return linhas;
    }

    // Movendo o ponteiro para o início do arquivo
    this->arq.seekg(this->arq.beg);
    this->lerLinha();

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
        std::cout << "O arquivo foi aberto em modo leitura. Nenhum dado será adicionado." << std::endl;
        return;
    }

    linha += "\n";
    this->arq << linha;
}

void FstreamAdapter::modificarLinha(int numLinha, string novaLinha) {
    if (!isOpen) {
        return;
    }

    if (this->modo == "leitura") {
        std::cout << "O arquivo foi aberto em modo leitura. Nenhum dado será modificado." << std::endl;
        return;
    }

    if (numLinha > this->getQuantLinhas() || numLinha <= 0) {
        std::cout << "O seu arquivo ainda não tem essa linha para ser modificada. Nenhum dado será modificado" << std::endl;
        return;
    }

    // Criando um novo arquivo com os dados atualizados do arquivo atual
    FstreamAdapter arqModificado("../database/arq-modificado.txt");
    arqModificado.abrir("sobrescrita");

    // Cópia do arquivo atual em modo leitura
    FstreamAdapter arqLeitura(this->caminhoArquivo);
    arqLeitura.abrir("leitura");
    deque<string> conteudoArqAtual = arqLeitura.lerTodosDados();
    arqLeitura.fechar();

    // Escrevendo as linhas anteriores à especificada
    for (int i = 0; i < numLinha - 1; i++)
        arqModificado.escreverLinhaFinal(conteudoArqAtual[i]);

    // Sobrescrevendo a linha
    arqModificado.escreverLinhaFinal(novaLinha);

    // Escrevendo o resto das linhas
    for (int i = numLinha; i < (int)conteudoArqAtual.size(); i++)
        arqModificado.escreverLinhaFinal(conteudoArqAtual[i]);

    arqModificado.fechar();
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
    FstreamAdapter arqLeitura(this->caminhoArquivo);
    arqLeitura.abrir("leitura");
    quantLinhas = (arqLeitura.lerTodosDados()).size();
    arqLeitura.fechar();

    return quantLinhas;
}

#include "./LoginFacade.hpp"

/**
 * Código original obtido em: https://pt.stackoverflow.com/questions/448483/implementa%C3%A7%C3%A3o-do-split-em-c. 
 * Data de acesso: 29/07/2025
*/
deque<string> split(const string& text, char sep = ' ') {
  deque<string> elements;
  size_t start = 0, end = 0;

  while ((end = text.find(sep, start)) != string::npos)
  {
    elements.push_back(text.substr(start, end - start));
    start = end + 1;
  }

  elements.push_back(text.substr(start));
  return elements;
}


LoginFacade::LoginFacade() : bancoDados("../database/users.txt") {
  this->opcoes = { "1 - Fazer login", "2 - Fechar o programa" };
  this->bancoDados.abrir("leitura");
}

LoginFacade::~LoginFacade() {
  this->bancoDados.fechar();
}

void LoginFacade::login(string email, string senha) {
  deque<string> linhas = this->bancoDados.lerTodosDados();

  for (string l : linhas) {
    deque<string> dados = split(l);

    string emailI = dados[2], senhaI = dados[3];

    if (email == emailI && senha == senhaI) {
      cout << "Usuário logado uhul! :)" << endl;
      return;
    }    
  }

  cout << "Usuário não está cadastrado no sistema" << endl;
}

void LoginFacade::limparTela() {
  system("clear");
}

void LoginFacade::desenharLinha(int tamanho) {
  for (int i = 0; i < tamanho; i++)
    cout << "=";
  cout << endl;
}

void LoginFacade::desenharTitulo(string titulo) {
  int tamTitulo = titulo.size();
  int espacamento = 5;

  this->desenharLinha(tamTitulo + (espacamento * 2));
  for (int i = 0; i < espacamento; i++)
    cout << " ";

  cout << titulo << endl; 
  this->desenharLinha(tamTitulo + (espacamento * 2));
}

void LoginFacade::exibirMenu() {
  // this->limparTela();
  this->desenharTitulo("BIBLIOTECA COMUNITARIA PARA MEMBROS DO IFPB/CG");

  cout << endl;

  for (string o : this->opcoes)
    cout << o << endl;

  cout << endl;
}

void LoginFacade::validaEntrada(int& escolha) {
  int quantOpcoes = this->opcoes.size();

  while (escolha < 1 || escolha > quantOpcoes) {
    cout << "Valor inválido. Tente novamente: ";
    cin >> escolha;
  }
}

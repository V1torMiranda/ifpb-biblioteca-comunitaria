#include "./LoginFacade.hpp"


void LoginFacade::login(string email, string senha) {

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
  this->limparTela();
  this->desenharTitulo("BIBLIOTECA COMUNITARIA PARA MEMBROS DO IFPB/CG");

  cout << endl;

  deque<string> opcoes = { "1 - Fazer login", "2 - Fechar o programa" };
  for (string o : opcoes)
    cout << o << endl;
  
  cout << endl;
}
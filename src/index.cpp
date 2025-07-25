#include "./services/FstreamAdapter/FstreamAdapter.hpp"
#include "./services/LoginFacade/LoginFacade.hpp"

using namespace std;

int main() {

  LoginFacade login;

  int escolha;
  do {
    login.exibirMenu();

    cout << "Digite a sua opção: ";
    cin >> escolha;

    while (escolha < 1 || escolha > 2) {
      cout << "Valor inválido. Tente novamente: ";
      cin >> escolha;
    }

  } while (escolha != 2);

  return 0;
}

#include "./services/FstreamAdapter/FstreamAdapter.hpp"
#include <iostream> 

int main() {
  
  FstreamAdapter leitor = FstreamAdapter("../database/backup/users.txt");
  cout << "Endereço de leitor: " << &leitor << endl;
  
  leitor.abrir("leitura");
  cout << "Linha 1: " << leitor.lerLinha() << endl;

  deque<string> linhas = leitor.lerTodosDados();
  cout << "Linhas lidas? X" << endl;

  
  return 0;
}
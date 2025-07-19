#include "./services/FstreamAdapter.hpp"
#include <iostream>

using namespace std;

int main() {

  FstreamAdapter manip = FstreamAdapter("../database/users.txt");
  manip.abrir("leitura");

  cout << "Primeira linha: " << manip.lerLinha() << endl;
  cout << "Segunda linha: " << manip.lerLinha() << endl;
  cout << "Terceira linha: " << manip.lerLinha() << endl;

  manip.fechar();
  return 0;
}

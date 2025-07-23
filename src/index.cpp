#include "./services/FstreamAdapter.hpp"
#include <iostream>

using namespace std;

int main() {

  FstreamAdapter manip = FstreamAdapter("../database/users.txt");
  manip.abrir("escrita");
  
  cout << manip.getQuantLinhas() << endl;
  
  manip.fechar();
  return 0;
}

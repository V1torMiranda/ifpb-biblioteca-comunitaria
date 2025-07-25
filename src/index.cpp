#include "./services/FstreamAdapter.hpp"
#include <iostream>

using namespace std;

int main() {

  FstreamAdapter manip = FstreamAdapter("../database/users.txt");
  manip.abrir("escrita");
  
  manip.modificarLinha(4, "Felisberto Costa Silva");

  manip.fechar();



  return 0;
}

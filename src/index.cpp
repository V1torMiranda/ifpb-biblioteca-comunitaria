#include "./services/FstreamAdapter.hpp"
#include <iostream>

using namespace std;

int main() {

  FstreamAdapter manip = FstreamAdapter("../database/users.txt");
  manip.abrir("escrita");
  
  manip.modificarLinha(4, "121 Felipe felipe@ifpb.com.br 212 min 90");

  manip.fechar();
  return 0;
}

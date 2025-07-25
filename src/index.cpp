#include "./services/FstreamAdapter.hpp"
#include <iostream>

using namespace std;

int main() {

  FstreamAdapter manip = FstreamAdapter("../database/users.txt");
  manip.abrir("escrita");
  
  manip.modificarLinha(4, "902 Jonas jonas@gmail.com 141 filosofia 87");

  manip.fechar();



  return 0;
}

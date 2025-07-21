#include "./services/FstreamAdapter.hpp"
#include <iostream>

using namespace std;

int main() {

  FstreamAdapter manip = FstreamAdapter("../database/users.txt");
  manip.abrir("escrita");

  manip.escreverLinhaFinal("10101 William william.costa@gmail.com 1234 engComp 10");

  manip.fechar();
  return 0;
}

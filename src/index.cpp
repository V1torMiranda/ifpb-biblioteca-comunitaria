#include <iostream>
#include <string>
#include "./services/ManipuladorArquivo.hpp"
#include <fstream>

using namespace std;

int main() {

  ManipuladorArquivo manip = ManipuladorArquivo("../database/users.txt");
  manip.abrir("leitura");
  manip.lerLinha();

  // cout << "";


  
  

  return 0;
}

#include <iostream>
#include <string>
#include "./services/ManipuladorArquivo.hpp"

using namespace std;

int main() {

  ManipuladorArquivo manip = ManipuladorArquivo("../database/users.txt");
  manip.abrir();
  cout << manip.lerLinha() << endl;


  

  return 0;
}

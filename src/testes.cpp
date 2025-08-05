#include "./services/FstreamAdapter/FstreamAdapter.hpp"
#include "./repositories/UsuarioRepository/UsuarioRepository.h"
#include <iostream> 

int main() {
  
  Usuario joao = Usuario("Joao", "joao@adm.ifpb.edu.br", "Jo@o2024!", "info", 32);
  cout << "Endereço de Joao: " << &joao << endl;
  cout << "Nome: " << joao.getNome() << endl;
  cout << "Curso: " << joao.getCurso() << endl;

  UsuarioRepository userRepo = UsuarioRepository("../database/backup/users.txt");
  cout << "Joao está no BD? " << userRepo.validarCredenciais(joao.getEmail(), joao.getSenha()) << endl;
  cout << "Joao é adm? " << userRepo.isAdmin(joao.getEmail()) << endl;


  return 0;
}
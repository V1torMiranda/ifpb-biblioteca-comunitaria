#include "LoginFacade.hpp"

LoginFacade::LoginFacade(const std::string& caminhoArquivoUsuarios)
  : usuarioRepo(caminhoArquivoUsuarios) {}

bool LoginFacade::login(const std::string& email, const std::string& senha) {
  return usuarioRepo.validarCredenciais(email, senha);
}

/**
 * Código original obtido em: https://pt.stackoverflow.com/questions/448483/implementa%C3%A7%C3%A3o-do-split-em-c. 
 * Data de acesso: 29/07/2025
*/
deque<string> split(const string& text, char sep = ' ') {
  deque<string> elements;
  size_t start = 0, end = 0;

  while ((end = text.find(sep, start)) != string::npos)
  {
    elements.push_back(text.substr(start, end - start));
    start = end + 1;
  }

  elements.push_back(text.substr(start));
  return elements;
}


void LoginFacade::limparTela() {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
}

void LoginFacade::desenharLinha(int tamanho) {
    for (int i = 0; i < tamanho; i++)
        std::cout << "=";
    std::cout << std::endl;
}

void LoginFacade::desenharTitulo(const std::string& titulo) {
    int tamTitulo = static_cast<int>(titulo.size());
    int espacamento = 5;

    desenharLinha(tamTitulo + (espacamento * 2));
    for (int i = 0; i < espacamento; i++)
        std::cout << " ";

    std::cout << titulo << std::endl;
    desenharLinha(tamTitulo + (espacamento * 2));
}

void LoginFacade::exibirMenu() {
  limparTela();
  desenharTitulo("BIBLIOTECA COMUNITARIA PARA MEMBROS DO IFPB/CG");

  std::cout << std::endl;
  std::cout << "1 - Fazer login" << std::endl;
  std::cout << "2 - Fechar o programa" << std::endl;
  std::cout << std::endl;
}

void LoginFacade::validaEntrada(int& escolha) {
  int quantOpcoes = this->opcoes.size();

  while (escolha < 1 || escolha > quantOpcoes) {
    cout << "Valor inválido. Tente novamente: ";
    cin >> escolha;
  }
}

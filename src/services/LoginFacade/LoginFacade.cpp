#include "./LoginFacade.hpp"
#include <iostream>
#include <limits>
#include "../../classes/Usuario/Usuario.hpp"

// Comandos do membro comum
#include "Comandos/ConsultarAcervoCommand.h"
#include "Comandos/RealizarEmprestimoCommand.h"
#include "Comandos/DevolverLivroCommand.h"
#include "Comandos/VisualizarPerfilCommand.h"

// Comandos do administrador
#include "Comandos/CadastrarLivroCommand.h"
#include "Comandos/ModificarLivroCommand.h"
#include "Comandos/RemoverLivroCommand.h"
#include "Comandos/CadastrarUsuarioCommand.h"
#include "Comandos/ModificarUsuarioCommand.h"
#include "Comandos/RemoverUsuarioCommand.h"

LoginFacade::LoginFacade(const std::string& caminhoUsuarios,
                         const std::string& caminhoLivros,
                         const std::string& caminhoEmprestimos)
        : usuarioRepo(caminhoUsuarios),
          livroRepo(caminhoLivros),
          emprestimoRepo(caminhoEmprestimos) {}


bool LoginFacade::login(const std::string& email, const std::string& senha) {
    return usuarioRepo.validarCredenciais(email, senha);
}

bool LoginFacade::isAdmin(const std::string& email) {
    return usuarioRepo.isAdmin(email);
}

deque<string> split(const string& text, char sep = ' ') {
    deque<string> elements;
    size_t start = 0, end = 0;

    while ((end = text.find(sep, start)) != string::npos) {
        elements.push_back(text.substr(start, end - start));
        start = end + 1;
    }

    elements.push_back(text.substr(start));
    return elements;
}

void LoginFacade::limparTela() {
#ifdef _WIN32
    std::system("cls");
#else
    std::cout << "\x1B[2J\x1B[H";
    std::cout.flush();
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

void LoginFacade::exibirMenuPadrao() {
    desenharTitulo("MENU MEMBRO COMUM");
    std::cout << "1 - Consultar acervo" << std::endl;
    std::cout << "2 - Realizar emprestimo" << std::endl;
    std::cout << "3 - Devolver livro" << std::endl;
    std::cout << "4 - Visualizar perfil" << std::endl;
    std::cout << "0 - Sair" << std::endl;
}

void LoginFacade::exibirMenuAdmin() {
    desenharTitulo("MENU ADMINISTRADOR");
    std::cout << "1 - Cadastrar livro" << std::endl;
    std::cout << "2 - Modificar livro" << std::endl;
    std::cout << "3 - Remover livro" << std::endl;
    std::cout << "4 - Cadastrar usuario" << std::endl;
    std::cout << "5 - Modificar usuario" << std::endl;
    std::cout << "6 - Remover usuario" << std::endl;
    std::cout << "0 - Sair" << std::endl;
}

void LoginFacade::registrarComandos(bool admin, const std::string& email) {
    comandos.clear();

    if (admin) {
        comandos[1] = std::make_unique<CadastrarLivroCommand>();
        comandos[2] = std::make_unique<ModificarLivroCommand>();
        comandos[3] = std::make_unique<RemoverLivroCommand>();
        comandos[4] = std::make_unique<CadastrarUsuarioCommand>();
        comandos[5] = std::make_unique<ModificarUsuarioCommand>();
        comandos[6] = std::make_unique<RemoverUsuarioCommand>();
    } else {
        comandos[1] = std::make_unique<ConsultarAcervoCommand>(livroRepo);
        comandos[2] = std::make_unique<RealizarEmprestimoCommand>(livroRepo, emprestimoRepo, email);
        comandos[3] = std::make_unique<DevolverLivroCommand>(livroRepo);
        comandos[4] = std::make_unique<VisualizarPerfilCommand>(usuarioRepo,emprestimoRepo, email);
    }
}

void LoginFacade::exibirMenuPrincipal(const std::string& email) {
    bool admin = isAdmin(email);
    registrarComandos(admin, email);

    int opcao = -1;
    std::string linha;

    while (opcao != 0) {
        limparTela();

        if (admin)
            exibirMenuAdmin();
        else
            exibirMenuPadrao();

        std::cout << "Escolha uma opcao: ";
        std::getline(std::cin, linha);

        try {
            opcao = std::stoi(linha);
        } catch (...) {
            opcao = -1;
        }

        if (opcao == 0) {
            std::cout << "Encerrando sistema...\n";
            break;
        }

        auto it = comandos.find(opcao);
        if (it != comandos.end()) {
            it->second->execute();
        } else {
            std::cout << "Opcao invalida.\n";
        }

        std::cout << "\nPressione ENTER para continuar...";
        std::getline(std::cin, linha);
    }
}

void LoginFacade::validaEntrada(int& escolha) {
    int quantOpcoes = this->opcoes.size();

    while (escolha < 1 || escolha > quantOpcoes) {
        std::cout << "Valor inválido. Tente novamente: ";
        std::cin >> escolha;
    }
}

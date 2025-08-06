#include "./UsuarioRepository.h"
#include <sstream>
#include <iostream>
#include <optional>

UsuarioRepository::UsuarioRepository(const std::string& caminhoArquivo)
        : arquivoUsuarios(caminhoArquivo) {}

bool UsuarioRepository::validarCredenciais(const std::string& email, const std::string& senha) {
    arquivoUsuarios.abrir("leitura");
    if (arquivoUsuarios.getModo() != "leitura") {
        std::cout << "Erro ao abrir arquivo de usuários." << std::endl;
        return false;
    }

    while (true) {
        std::string linha = arquivoUsuarios.lerLinha();
        if (linha.empty()) break;

        std::stringstream ss(linha);

        std::string idStr;
        std::string nome;
        std::string emailArq;
        std::string senhaArq;
        std::string curso;
        int creditos = 0;

        if (std::getline(ss, idStr, ';') &&
            std::getline(ss, nome, ';') &&
            std::getline(ss, emailArq, ';') &&
            std::getline(ss, senhaArq, ';') &&
            std::getline(ss, curso, ';') &&
            (ss >> creditos))
        {
            // Remover espaços extras (se houver)
            emailArq.erase(0, emailArq.find_first_not_of(" \t"));
            emailArq.erase(emailArq.find_last_not_of(" \t") + 1);
            senhaArq.erase(0, senhaArq.find_first_not_of(" \t"));
            senhaArq.erase(senhaArq.find_last_not_of(" \t") + 1);

            if (email == emailArq && senha == senhaArq) {
                arquivoUsuarios.fechar();
                return true;
            }
        }
    }

    arquivoUsuarios.fechar();
    return false;
}

Usuario UsuarioRepository::usuarioFromCSV(const std::string& linhaCSV) {
    std::stringstream ss(linhaCSV);
    std::string idStr, nome, email, senha, curso, creditosStr;

    // Se o CSV tem id como primeira coluna, lemos mas ignoramos
    std::getline(ss, idStr, ';');
    std::getline(ss, nome, ';');
    std::getline(ss, email, ';');
    std::getline(ss, senha, ';');
    std::getline(ss, curso, ';');
    std::getline(ss, creditosStr, ';');

    int creditos = creditosStr.empty() ? 0 : std::stoi(creditosStr);

    return {nome, email, senha, curso, creditos};
}



bool UsuarioRepository::isAdmin(const std::string& email) {
    arquivoUsuarios.abrir("leitura");
    if (arquivoUsuarios.getModo() != "leitura") {
        std::cout << "Erro ao abrir arquivo de usuários." << std::endl;
        return false;
    }

    while (true) {
        std::string linha = arquivoUsuarios.lerLinha();
        if (linha.empty()) break;

        std::stringstream ss(linha);

        std::string idStr;
        std::string nome;
        std::string emailArq;
        std::string senhaArq;
        std::string curso;
        int creditos = 0;

        if (std::getline(ss, idStr, ';') &&
            std::getline(ss, nome, ';') &&
            std::getline(ss, emailArq, ';') &&
            std::getline(ss, senhaArq, ';') &&
            std::getline(ss, curso, ';') &&
            (ss >> creditos))
        {
            // Remover espaços extras
            emailArq.erase(0, emailArq.find_first_not_of(" \t"));
            emailArq.erase(emailArq.find_last_not_of(" \t") + 1);

            if (email == emailArq) {
                arquivoUsuarios.fechar();
                // Verifica domínio de administrador
                return emailArq.find("@adm.ifpb.edu.br") != std::string::npos;
            }
        }
    }

    arquivoUsuarios.fechar();
    return false;
}

std::optional<Usuario> UsuarioRepository::buscarPorEmail(const std::string& email) {
    arquivoUsuarios.abrir("leitura");
    auto linhas = arquivoUsuarios.lerTodosDados();
    arquivoUsuarios.fechar();

    for (const auto& linha : linhas) {
        if (!linha.empty()) {
            Usuario usuario = this->usuarioFromCSV(linha);
            if (usuario.getEmail() == email) {
                return usuario;
            }
        }
    }
    return std::nullopt;
}

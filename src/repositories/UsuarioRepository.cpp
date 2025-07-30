#include "UsuarioRepository.h"
#include <sstream>
#include <iostream>

UsuarioRepository::UsuarioRepository(const string& caminhoArquivo)
        : arquivoUsuarios(caminhoArquivo) {}

bool UsuarioRepository::validarCredenciais(const string& email, const string& senha) {
    arquivoUsuarios.abrir("leitura");
    if (arquivoUsuarios.getModo() != "leitura") {
        std::cerr << "Erro ao abrir arquivo de usuários." << std::endl;
        return false;
    }

    while (true) {
        string linha = arquivoUsuarios.lerLinha();
        if (linha.empty()) break;

        std::stringstream ss(linha);
        string id, nome, emailArq, senhaArq, curso, creditos;

        // Esperando formato: id nome email senha curso creditos
        if (ss >> id >> nome >> emailArq >> senhaArq >> curso >> creditos) {
            if (email == emailArq && senha == senhaArq) {
                arquivoUsuarios.fechar();
                return true;
            }
        }
    }

    arquivoUsuarios.fechar();
    return false;
}

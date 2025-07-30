#ifndef USUARIO_REPOSITORY_HPP
#define USUARIO_REPOSITORY_HPP

#include <string>
#include <deque>
#include "../services/FstreamAdapter/FstreamAdapter.hpp"

using std::string;
using std::deque;

class UsuarioRepository {
private:
    FstreamAdapter arquivoUsuarios;

public:
    explicit UsuarioRepository(const string& caminhoArquivo);

    // Valida se existe um usuário com email e senha correspondentes
    bool validarCredenciais(const string& email, const string& senha);

    // (Futuro) métodos adicionais:
    // bool cadastrarUsuario(const Usuario& user);
    // bool removerUsuario(int id);
};

#endif

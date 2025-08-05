#ifndef USUARIO_REPOSITORY_HPP
#define USUARIO_REPOSITORY_HPP

#include <deque>
#include <string>
#include "../services/FstreamAdapter/FstreamAdapter.hpp"
#include "../classes/User/User.hpp"

class UsuarioRepository {
private:
    FstreamAdapter arquivoUsuarios;

public:
    explicit UsuarioRepository(const std::string& caminhoArquivo);

    bool validarCredenciais(const std::string& email, const std::string& senha);
    bool isAdmin(const std::string& email);
};

#endif

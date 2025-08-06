#ifndef USUARIO_REPOSITORY_HPP
#define USUARIO_REPOSITORY_HPP

#include <deque>
#include <string>
#include <optional>
#include "../../services/FstreamAdapter/FstreamAdapter.hpp"
#include "../../classes/Usuario/Usuario.hpp"

class UsuarioRepository {
private:
    FstreamAdapter arquivoUsuarios;
    static Usuario usuarioFromCSV(const std::string& linhaCSV);

public:
    explicit UsuarioRepository(const std::string& caminhoArquivo);

    bool validarCredenciais(const std::string& email, const std::string& senha);
    bool isAdmin(const std::string& email);
    std::optional<Usuario> buscarPorEmail(const std::string& email);
};

#endif

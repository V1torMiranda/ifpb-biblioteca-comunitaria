#ifndef VISUALIZARPERFILCOMMAND_H
#define VISUALIZARPERFILCOMMAND_H

#include "../../repositories/UsuarioRepository/UsuarioRepository.h"
#include "../../repositories/EmprestimoRepository/EmprestimoRepository.h"
#include "../ICommand.h"
#include <string>

class VisualizarPerfilCommand : public ICommand {
private:
    UsuarioRepository& usuarioRepo;
    EmprestimoRepository& emprestimoRepo;
    std::string emailUsuario;

public:
    VisualizarPerfilCommand(UsuarioRepository& uRepo, EmprestimoRepository& eRepo, const std::string& email);

    void execute() override;
};

#endif

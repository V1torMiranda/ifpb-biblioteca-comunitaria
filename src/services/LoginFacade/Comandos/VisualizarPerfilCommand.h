//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_VISUALIZARPERFILCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_VISUALIZARPERFILCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_VISUALIZARPERFILCOMMAND_H

// Comandos/VisualizarPerfilCommand.hpp
#ifndef VISUALIZAR_PERFIL_COMMAND_HPP
#define VISUALIZAR_PERFIL_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>

class VisualizarPerfilCommand : public ICommand {
public:
    void execute() override;
};

#endif

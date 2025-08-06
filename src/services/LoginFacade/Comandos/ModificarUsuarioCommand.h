//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_MODIFICARUSUARIOCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_MODIFICARUSUARIOCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_MODIFICARUSUARIOCOMMAND_H

// Comandos/ModificarUsuarioCommand.hpp
#ifndef MODIFICAR_USUARIO_COMMAND_HPP
#define MODIFICAR_USUARIO_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>

class ModificarUsuarioCommand : public ICommand {
public:
    void execute() override;
};

#endif

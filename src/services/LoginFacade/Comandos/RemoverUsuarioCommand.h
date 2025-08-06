//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_REMOVERUSUARIOCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_REMOVERUSUARIOCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_REMOVERUSUARIOCOMMAND_H

// Comandos/RemoverUsuarioCommand.hpp
#ifndef REMOVER_USUARIO_COMMAND_HPP
#define REMOVER_USUARIO_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>

class RemoverUsuarioCommand : public ICommand {
public:
    void execute() override;
};

#endif

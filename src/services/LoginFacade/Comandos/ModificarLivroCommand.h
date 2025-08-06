//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_MODIFICARLIVROCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_MODIFICARLIVROCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_MODIFICARLIVROCOMMAND_H

// Comandos/ModificarLivroCommand.hpp
#ifndef MODIFICAR_LIVRO_COMMAND_HPP
#define MODIFICAR_LIVRO_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>

class ModificarLivroCommand : public ICommand {
public:
    void execute() override;
};

#endif

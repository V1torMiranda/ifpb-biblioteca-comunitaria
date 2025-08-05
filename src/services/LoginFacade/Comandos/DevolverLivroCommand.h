//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_DEVOLVERLIVROCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_DEVOLVERLIVROCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_DEVOLVERLIVROCOMMAND_H

// Comandos/DevolverLivroCommand.hpp
#ifndef DEVOLVER_LIVRO_COMMAND_HPP
#define DEVOLVER_LIVRO_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>

class DevolverLivroCommand : public ICommand {
public:
    void execute() override;
};

#endif

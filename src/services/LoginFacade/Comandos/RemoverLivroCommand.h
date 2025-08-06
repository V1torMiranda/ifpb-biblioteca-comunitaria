//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_REMOVERLIVROCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_REMOVERLIVROCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_REMOVERLIVROCOMMAND_H

// Comandos/RemoverLivroCommand.hpp
#ifndef REMOVER_LIVRO_COMMAND_HPP
#define REMOVER_LIVRO_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>

class RemoverLivroCommand : public ICommand {
public:
    void execute() override;
};

#endif

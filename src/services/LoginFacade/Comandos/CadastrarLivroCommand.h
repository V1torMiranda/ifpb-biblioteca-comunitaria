//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_CADASTRARLIVROCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_CADASTRARLIVROCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_CADASTRARLIVROCOMMAND_H

// Comandos/CadastrarLivroCommand.hpp
#ifndef CADASTRAR_LIVRO_COMMAND_HPP
#define CADASTRAR_LIVRO_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>

class CadastrarLivroCommand : public ICommand {
public:
    void execute() override;
};

#endif

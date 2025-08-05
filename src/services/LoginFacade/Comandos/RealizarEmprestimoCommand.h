//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_REALIZAREMPRESTIMOCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_REALIZAREMPRESTIMOCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_REALIZAREMPRESTIMOCOMMAND_H

// Comandos/RealizarEmprestimoCommand.hpp
#ifndef REALIZAR_EMPRESTIMO_COMMAND_HPP
#define REALIZAR_EMPRESTIMO_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>

class RealizarEmprestimoCommand : public ICommand {
public:
    void execute() override;
};

#endif

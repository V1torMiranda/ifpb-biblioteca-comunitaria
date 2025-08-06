//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_DEVOLVERLIVROCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_DEVOLVERLIVROCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_DEVOLVERLIVROCOMMAND_H

// Comandos/DevolverLivroCommand.hpp
#ifndef DEVOLVER_LIVRO_COMMAND_H
#define DEVOLVER_LIVRO_COMMAND_H

#include "ICommand.h"
#include "../../../repositories/LivroRepository/LivroRepository.h"
#include <memory>

class DevolverLivroCommand : public ICommand {
private:
    LivroRepository& livroRepo;

public:
    explicit DevolverLivroCommand(LivroRepository& repo);
    void execute() override;
};

#endif


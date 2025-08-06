//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_CONSULTARACERVOCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_CONSULTARACERVOCOMMAND_H

#endif //BIBLIOTECA_COMUNITARIA_CONSULTARACERVOCOMMAND_H

// Comandos/ConsultarAcervoCommand.hpp
#ifndef CONSULTAR_ACERVO_COMMAND_HPP
#define CONSULTAR_ACERVO_COMMAND_HPP

#include "../ICommand.h"
#include <iostream>
#include "../../repositories/LivroRepository/LivroRepository.h"

class ConsultarAcervoCommand : public ICommand {
private:
    LivroRepository& livroRepo;

public:
    explicit ConsultarAcervoCommand(LivroRepository& repo);
    void execute() override;
};

#endif

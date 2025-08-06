//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_REALIZAREMPRESTIMOCOMMAND_H
#define BIBLIOTECA_COMUNITARIA_REALIZAREMPRESTIMOCOMMAND_H

#include "ICommand.h"
#include "../../../repositories/LivroRepository/LivroRepository.h"
#include "../../../repositories/EmprestimoRepository/EmprestimoRepository.h"
#include <memory>


class RealizarEmprestimoCommand : public ICommand {
private:
    LivroRepository& livroRepo;
    EmprestimoRepository& emprestimoRepo;
    std::string emailUsuario;  // <-- email do usuário logado

public:
    RealizarEmprestimoCommand(LivroRepository& lRepo,
                              EmprestimoRepository& eRepo,
                              const std::string& emailUsuario);

    void execute() override;
};

#endif

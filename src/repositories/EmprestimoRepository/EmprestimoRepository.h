//
// Created by vitor on 06/08/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_EMPRESTIMOREPOSITORY_H
#define BIBLIOTECA_COMUNITARIA_EMPRESTIMOREPOSITORY_H

#endif //BIBLIOTECA_COMUNITARIA_EMPRESTIMOREPOSITORY_H

#ifndef EMPRESTIMOREPOSITORY_H
#define EMPRESTIMOREPOSITORY_H

#include <deque>
#include <string>
#include <optional>
#include "../../services/FstreamAdapter/FstreamAdapter.hpp"
#include "Emprestimo.h"

class EmprestimoRepository {
private:
    FstreamAdapter arquivoEmprestimos;

    std::string emprestimoToCSV(const Emprestimo& e) const;
    Emprestimo emprestimoFromCSV(const std::string& linhaCSV);

public:
    explicit EmprestimoRepository(const std::string& caminhoArquivo);

    bool adicionarEmprestimo(const Emprestimo& emprestimo);
    bool atualizarEmprestimo(const Emprestimo& emprestimo);
    bool removerEmprestimo(int idEmprestimo);
    std::optional<Emprestimo> buscarPorId(int idEmprestimo);
    std::deque<Emprestimo> listarTodos();
    std::deque<Emprestimo> listarPorUsuario(const std::string& emailUsuario); // <-- agora recebe email
};

#endif

#ifndef BIBLIOTECA_COMUNITARIA_EMPRESTIMO_H
#define BIBLIOTECA_COMUNITARIA_EMPRESTIMO_H

#include <string>
#include <memory>
#include <ctime>
#include "EstadoEmprestimo.h"

class Emprestimo {
private:
    int id;
    int idLivro;
    std::string emailUsuario;   // <-- agora usamos email
    std::time_t dataEmprestimo;
    std::time_t dataDevolucaoPrevista;
    int creditosUsuario;
    std::unique_ptr<EstadoEmprestimo> estado;

public:
    Emprestimo(int id,
               int idLivro,
               const std::string& emailUsuario,
               std::time_t dataEmprestimo,
               std::time_t dataDevolucaoPrevista,
               int creditosUsuario,
               std::unique_ptr<EstadoEmprestimo> estado);

    int getId() const { return id; }
    int getIdLivro() const { return idLivro; }
    const std::string& getEmailUsuario() const { return emailUsuario; }
    std::time_t getDataEmprestimo() const { return dataEmprestimo; }
    std::time_t getDataDevolucaoPrevista() const { return dataDevolucaoPrevista; }
    int getCreditosUsuario() const { return creditosUsuario; }
    std::string obterNomeEstado() const { return estado->nome(); }
    void definirEstado(std::unique_ptr<EstadoEmprestimo> novoEstado);
};

#endif

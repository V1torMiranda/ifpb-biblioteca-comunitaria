#include <ctime>
#include "Emprestimo.h"

Emprestimo::Emprestimo(int id,
                       int idLivro,
                       const std::string& emailUsuario,
                       std::time_t dataEmprestimo,
                       std::time_t dataDevolucaoPrevista,
                       int creditosUsuario,
                       std::unique_ptr<EstadoEmprestimo> estado)
        : id(id),
          idLivro(idLivro),
          emailUsuario(emailUsuario),
          dataEmprestimo(dataEmprestimo),
          dataDevolucaoPrevista(dataDevolucaoPrevista),
          creditosUsuario(creditosUsuario),
          estado(std::move(estado)) {}

void Emprestimo::definirEstado(std::unique_ptr<EstadoEmprestimo> novoEstado) {
    estado = std::move(novoEstado);
}
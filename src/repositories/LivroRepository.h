//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_LIVROREPOSITORY_H
#define BIBLIOTECA_COMUNITARIA_LIVROREPOSITORY_H

#endif //BIBLIOTECA_COMUNITARIA_LIVROREPOSITORY_H


#ifndef LIVRO_REPOSITORY_HPP
#define LIVRO_REPOSITORY_HPP

#include "../services/FstreamAdapter/FstreamAdapter.hpp"
#include "../classes/Livro/Livro.h"
#include <deque>

class LivroRepository {
private:
    FstreamAdapter arquivoLivros;

public:
    LivroRepository(const std::string& caminhoArquivo);

    bool adicionarLivro(const Livro& livro);
    std::deque<Livro> listarLivros();
    bool removerLivro(int idLivro);
    bool atualizarLivro(const Livro& livro);
};

#endif

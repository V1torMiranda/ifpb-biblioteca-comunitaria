//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_LIVROREPOSITORY_H
#define BIBLIOTECA_COMUNITARIA_LIVROREPOSITORY_H

#endif //BIBLIOTECA_COMUNITARIA_LIVROREPOSITORY_H


#ifndef LIVRO_REPOSITORY_HPP
#define LIVRO_REPOSITORY_HPP

#include "../../services/FstreamAdapter/FstreamAdapter.hpp"
#include "../../classes/Livro/Livro.h"
#include <deque>

class LivroRepository {
private:
    FstreamAdapter arquivoLivros;

    std::string livroToCSV(const Livro& livro) const;
    Livro livroFromCSV(const std::string& linhaCSV);

public:
    LivroRepository(const std::string& caminhoArquivo);

    std::deque<Livro> listarLivros();
    bool adicionarLivro(const Livro& livro);
    bool removerLivro(int idLivro);
    bool atualizarLivro(const Livro& livro);
};

#endif

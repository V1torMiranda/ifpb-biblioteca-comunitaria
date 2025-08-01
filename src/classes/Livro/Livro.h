//
// Created by vitor on 31/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_LIVRO_H
#define BIBLIOTECA_COMUNITARIA_LIVRO_H

#endif //BIBLIOTECA_COMUNITARIA_LIVRO_H

//
// Created by vitor on 30/07/2025.
//

#ifndef BIBLIOTECA_COMUNITARIA_LIVRO_H
#define BIBLIOTECA_COMUNITARIA_LIVRO_H

#endif //BIBLIOTECA_COMUNITARIA_LIVRO_H

#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>

class Livro {
private:
    int id;
    std::string titulo;
    std::string autor;
    std::string editora;
    int ano;
    bool disponivel;

public:
    Livro();
    Livro(int id, const std::string& titulo, const std::string& autor,
          const std::string& editora, int ano, bool disponivel = true);

    int getId() const;
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getEditora() const;
    int getAno() const;
    bool isDisponivel() const;

    void setTitulo(const std::string& titulo);
    void setAutor(const std::string& autor);
    void setEditora(const std::string& editora);
    void setAno(int ano);
    void setDisponivel(bool disponivel);

    std::string toCSV() const;
    static Livro fromCSV(const std::string& linhaCSV);
};

#endif
//
// Created by vitor on 30/07/2025.
//

#include "Livro.h"
#include <sstream>

Livro::Livro() : id(0), ano(0), disponivel(true) {}

Livro::Livro(int id, const std::string& titulo, const std::string& autor,
             const std::string& editora, int ano, bool disponivel)
        : id(id), titulo(titulo), autor(autor), editora(editora), ano(ano), disponivel(disponivel) {}

int Livro::getId() const { return id; }
std::string Livro::getTitulo() const { return titulo; }
std::string Livro::getAutor() const { return autor; }
std::string Livro::getEditora() const { return editora; }
int Livro::getAno() const { return ano; }
bool Livro::isDisponivel() const { return disponivel; }

void Livro::setTitulo(const std::string& t) { titulo = t; }
void Livro::setAutor(const std::string& a) { autor = a; }
void Livro::setEditora(const std::string& e) { editora = e; }
void Livro::setAno(int a) { ano = a; }
void Livro::setDisponivel(bool d) { disponivel = d; }

std::string Livro::toCSV() const {
    std::stringstream ss;
    ss << id << ";" << titulo << ";" << autor << ";" << editora << ";" << ano << ";" << (disponivel ? "1" : "0");
    return ss.str();
}

Livro Livro::fromCSV(const std::string& linhaCSV) {
    std::stringstream ss(linhaCSV);
    std::string idStr, titulo, autor, editora, anoStr, disponivelStr;
    std::getline(ss, idStr, ';');
    std::getline(ss, titulo, ';');
    std::getline(ss, autor, ';');
    std::getline(ss, editora, ';');
    std::getline(ss, anoStr, ';');
    std::getline(ss, disponivelStr, ';');

    return Livro(std::stoi(idStr), titulo, autor, editora, std::stoi(anoStr), disponivelStr == "1");
}

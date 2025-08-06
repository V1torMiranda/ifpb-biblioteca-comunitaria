// Created by vitor on 31/07/2025.

#include "./Livro.h"
#include <sstream>

Livro::Livro() : id(0), ano(0), disponivel(true) {}

Livro::Livro(int id, const std::string& titulo, const std::string& autor, const std::string& editora, int ano, bool disponivel)
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

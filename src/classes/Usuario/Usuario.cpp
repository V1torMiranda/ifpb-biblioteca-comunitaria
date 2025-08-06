#include "./Usuario.hpp"
#include <sstream>

Usuario::Usuario(std::string nome, std::string email, std::string senha, std::string curso, int creditos)
        : nome(std::move(nome)), email(std::move(email)), senha(std::move(senha)), curso(std::move(curso)), creditos(creditos) {}

int Usuario::getId() const { return id;}
std::string Usuario::getNome() const { return nome; }
std::string Usuario::getEmail() const { return email; }
std::string Usuario::getSenha() const { return senha; }
std::string Usuario::getCurso() const { return curso; }
int Usuario::getCreditos() const { return creditos; }

void Usuario::setNome(const std::string& novoNome) { nome = novoNome; }
void Usuario::setEmail(const std::string& novoEmail) { email = novoEmail; }
void Usuario::setSenha(const std::string& novaSenha) { senha = novaSenha; }
void Usuario::setCurso(const std::string& novoCurso) { curso = novoCurso; }
void Usuario::setCreditos(int novosCreditos) { creditos = novosCreditos; }

std::string Usuario::toCSV() const {
    std::ostringstream ss;
    ss << nome << ";" << email << ";" << senha << ";" << curso << ";" << creditos;
    return ss.str();
}

Usuario Usuario::fromCSV(const std::string& linhaCSV) {
    std::stringstream ss(linhaCSV);
    std::string nome, email, senha, curso;
    int creditos;
    std::getline(ss, nome, ';');
    std::getline(ss, email, ';');
    std::getline(ss, senha, ';');
    std::getline(ss, curso, ';');
    ss >> creditos;
    return Usuario(nome, email, senha, curso, creditos);
}

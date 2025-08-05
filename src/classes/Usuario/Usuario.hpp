#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
private:
    std::string nome;
    std::string email;
    std::string senha;
    std::string curso;
    int creditos;

public:
    Usuario() = default;
    Usuario(std::string nome, std::string email, std::string senha, std::string curso, int creditos);

    std::string getNome() const;
    std::string getEmail() const;
    std::string getSenha() const;
    std::string getCurso() const;
    int getCreditos() const;

    void setNome(const std::string& novoNome);
    void setEmail(const std::string& novoEmail);
    void setSenha(const std::string& novaSenha);
    void setCurso(const std::string& novoCurso);
    void setCreditos(int novosCreditos);

    // Converte para CSV
    std::string toCSV() const;
    static Usuario fromCSV(const std::string& linhaCSV);
};

#endif

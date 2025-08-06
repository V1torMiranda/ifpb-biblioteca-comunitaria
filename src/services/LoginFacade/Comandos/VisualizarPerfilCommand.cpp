// VisualizarPerfilCommand.cpp
#include "VisualizarPerfilCommand.h"
#include <iostream>
#include <optional>

VisualizarPerfilCommand::VisualizarPerfilCommand(UsuarioRepository& usuarioRepo,
                                                 EmprestimoRepository& emprestimoRepo,
                                                 const std::string& email)
        : usuarioRepo(usuarioRepo), emprestimoRepo(emprestimoRepo), emailUsuario(email) {}

void VisualizarPerfilCommand::execute() {
    auto usuarioOpt = usuarioRepo.buscarPorEmail(emailUsuario);

    if (!usuarioOpt) {
        std::cout << "Usuário não encontrado.\n";
        return;
    }

    const Usuario& usuario = usuarioOpt.value();
    std::cout << "\n=== Perfil do Usuário ===\n";
    std::cout << "Nome: " << usuario.getNome() << "\n";
    std::cout << "Email: " << usuario.getEmail() << "\n";
    std::cout << "Curso: " << usuario.getCurso() << "\n";
    std::cout << "Créditos: " << usuario.getCreditos() << "\n";

    // --- Listando livros emprestados ---
    auto emprestimos = emprestimoRepo.listarPorUsuario(usuario.getEmail());

    if (emprestimos.empty()) {
        std::cout << "\nNenhum livro emprestado no momento.\n";
    } else {
        std::cout << "\nLivros emprestados:\n";
        for (const auto& emp : emprestimos) {
            std::cout << "- Livro ID: " << emp.getIdLivro()
                      << " | Estado: " << emp.obterNomeEstado()
                      << "\n";
        }
    }
}


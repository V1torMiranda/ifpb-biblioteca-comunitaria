cmake_minimum_required(VERSION 3.27)
project(biblioteca_comunitaria)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Diretórios de includes para o projeto principal
include_directories(
        src/classes/User
        src/interfaces
        src/services/FstreamAdapter
        src/services/LoginFacade
        src/services/state
)

# Executável principal
add_executable(biblioteca_comunitaria
        src/classes/Usuario/Usuario.cpp
        src/classes/Usuario/Usuario.hpp
        src/interfaces/ManipuladorArquivoInterface.hpp
        src/services/FstreamAdapter/FstreamAdapter.cpp
        src/services/FstreamAdapter/FstreamAdapter.hpp
        src/services/LoginFacade/LoginFacade.cpp
        src/services/LoginFacade/LoginFacade.hpp
        src/index.cpp
        src/repositories/UsuarioRepository/UsuarioRepository.cpp
        test_login/main.cpp

        src/classes/Livro/Livro.h
        src/classes/Livro/Livro.cpp
        src/repositories/LivroRepository/LivroRepository.cpp
        test_login_menu/main.cpp
        src/services/LoginFacade/Comandos/ConsultarAcervoCommand.cpp
        src/services/LoginFacade/Comandos/ConsultarAcervoCommand.cpp
        src/services/LoginFacade/Comandos/ConsultarAcervoCommand.cpp
        src/services/LoginFacade/Comandos/ConsultarAcervoCommand.h
        src/services/LoginFacade/Comandos/DevolverLivroCommand.cpp
        src/services/LoginFacade/Comandos/DevolverLivroCommand.h
        src/services/LoginFacade/Comandos/VisualizarPerfilCommand.cpp
        src/services/LoginFacade/Comandos/VisualizarPerfilCommand.h
        src/services/LoginFacade/Comandos/CadastrarLivroCommand.cpp
        src/services/LoginFacade/Comandos/CadastrarLivroCommand.h
        src/services/LoginFacade/Comandos/ModificarLivroCommand.h
        src/services/LoginFacade/Comandos/ModificarLivroCommand.cpp
        src/services/LoginFacade/Comandos/RemoverLivroCommand.h
        src/services/LoginFacade/Comandos/RemoverLivroCommand.cpp
        src/services/LoginFacade/Comandos/CadastrarUsuarioCommand.cpp
        src/services/LoginFacade/Comandos/CadastrarUsuarioCommand.h
        src/services/LoginFacade/Comandos/ModificarUsuarioCommand.cpp
        src/services/LoginFacade/Comandos/ModificarUsuarioCommand.h
        src/services/LoginFacade/Comandos/RemoverUsuarioCommand.cpp
        src/services/LoginFacade/ICommand.h
        src/repositories/LivroRepository/LivroRepository.cpp
        src/repositories/EmprestimoRepository/EmprestimoRepository.cpp
        src/repositories/EmprestimoRepository/EmprestimoRepository.h

)

# Executável de teste (State Pattern)
add_executable(test_state
        test_state/main.cpp
        src/services/state/Emprestimo.cpp
        src/services/state/EstadoEmAndamento.cpp
        src/services/state/EstadoAtrasado.cpp
        src/services/state/EstadoConcluido.cpp
)

target_include_directories(test_state PRIVATE
        src/services/state
)

add_executable(test_login
        test_login/main.cpp
        src/repositories/UsuarioRepository/UsuarioRepository.cpp
        src/services/LoginFacade/LoginFacade.cpp
        src/services/FstreamAdapter/FstreamAdapter.cpp
)

target_include_directories(test_login PRIVATE
        repositories
        services/LoginFacade
        services/FstreamAdapter
)


add_executable(test_livro
        test_livro/main.cpp
        src/classes/Livro/Livro.cpp
        src/repositories/LivroRepository/LivroRepository.cpp
        src/services/FstreamAdapter/FstreamAdapter.cpp
)

add_executable(test_login_menu
        test_login_menu/main.cpp
        src/services/LoginFacade/LoginFacade.cpp
        src/repositories/EmprestimoRepository/EmprestimoRepository.cpp
        src/services/state/Emprestimo.cpp
        src/services/state/EstadoEmAndamento.cpp
        src/services/state/EstadoConcluido.cpp
        src/repositories/UsuarioRepository/UsuarioRepository.cpp
        src/repositories/LivroRepository/LivroRepository.cpp       # <-- Faltava este
        src/classes/Livro/Livro.cpp                      # <-- E este (ou onde estiver a classe Livro)
        src/services/FstreamAdapter/FstreamAdapter.cpp
        src/classes/Usuario/Usuario.cpp
        src/utils/ConsoleUtils.cpp


        # Comandos do membro comum
        src/services/LoginFacade/Comandos/ConsultarAcervoCommand.cpp
        src/services/LoginFacade/Comandos/RealizarEmprestimoCommand.cpp
        src/services/LoginFacade/Comandos/DevolverLivroCommand.cpp
        src/services/LoginFacade/Comandos/VisualizarPerfilCommand.cpp

        # Comandos do administrador
        src/services/LoginFacade/Comandos/CadastrarLivroCommand.cpp
        src/services/LoginFacade/Comandos/ModificarLivroCommand.cpp
        src/services/LoginFacade/Comandos/RemoverLivroCommand.cpp
        src/services/LoginFacade/Comandos/CadastrarUsuarioCommand.cpp
        src/services/LoginFacade/Comandos/ModificarUsuarioCommand.cpp
        src/services/LoginFacade/Comandos/RemoverUsuarioCommand.cpp
)





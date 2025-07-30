cmake_minimum_required(VERSION 3.27)
project(biblioteca_comunitaria)

set(CMAKE_CXX_STANDARD 14)

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
        src/classes/User/User.cpp
        src/classes/User/User.hpp
        src/interfaces/ManipuladorArquivoInterface.hpp
        src/services/FstreamAdapter/FstreamAdapter.cpp
        src/services/FstreamAdapter/FstreamAdapter.hpp
        src/services/LoginFacade/LoginFacade.cpp
        src/services/LoginFacade/LoginFacade.hpp
        src/index.cpp
        src/repositories/UsuarioRepository.cpp
        test_login/main.cpp
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
        src/repositories/UsuarioRepository.cpp
        src/services/LoginFacade/LoginFacade.cpp
        src/services/FstreamAdapter/FstreamAdapter.cpp
)

target_include_directories(test_login PRIVATE
        repositories
        services/LoginFacade
        services/FstreamAdapter
)




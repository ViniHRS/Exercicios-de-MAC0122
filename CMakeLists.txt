cmake_minimum_required(VERSION 3.10)
project(Exercicios-de-MAC0122 C)

# Define onde os arquivos executáveis serão salvos.
# ${CMAKE_BINARY_DIR} representará a pasta "build" que você criar.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# =========================================================================
# 1. Adiciona as pastas presentes no repositório
# =========================================================================
set(FOLDERS
    "Binary Tree"
    "Hashing"
    "Linked List"
    "Queue"
    "Recursion"
    "Search"
    "Sorting"
    "Stack"
)

# =========================================================================
# 2. Lógica automática de geração dos alvos de compilação e execução
# =========================================================================
foreach(folder IN LISTS FOLDERS)
    # Procura por todos os arquivos .c dentro da pasta atual
    file(GLOB files_c "${folder}/*.c")

    foreach(file IN LISTS files_c)
        # Extrai apenas o nome do arquivo sem a extensão (ex: main.c -> main)
        get_filename_component(programa ${file} NAME_WE)

        # Define o nome do alvo (Target) no formato folder_program
        set(compiling_target "${folder}_${file}")

        # Cria o comando de compilação (make folder_file)
        add_executable(${compiling_target} ${file})

        # Cria o comando de execução (make run_file)
        # O comando DEPENDS garante que o código seja compilado antes de rodar
        add_custom_target(run_${file}
            COMMAND ${compiling_target}
            DEPENDS ${compiling_target}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
            COMMENT "================ Rodando ${programa} da pasta ${pasta} ================"
        )
    endforeach()
endforeach()
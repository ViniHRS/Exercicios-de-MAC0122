cmake_minimum_required(VERSION 3.10)
project(Exercicios-de-MAC0122 C)

# Define onde os arquivos executáveis serão salvos.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# =========================================================================
# 1. Mapeamento de Apelido -> Nome Real da Pasta
# Formato: "apelido:Nome da Pasta"
# =========================================================================
set(FOLDER_MAPPINGS
    "tree:Binary Tree"
    "graph:Graph Search"
    "hash:Hashing"
    "linked:Linked List"
    "mst:Minimum Spanning Tree"
    "queue:Queue"
    "recursion:Recursion"
    "search:Search"
    "short:Shortest Path"
    "sort:Sorting"
    "stack:Stack"
)

# =========================================================================
# 2. Lógica automática de geração dos alvos de compilação e execução
# =========================================================================
foreach(mapping IN LISTS FOLDER_MAPPINGS)
    # Substitui os ":" por ";" para transformar a string em uma lista nativa do CMake
    string(REPLACE ":" ";" mapping_list "${mapping}")
    
    # Extrai o primeiro elemento (apelido) e o segundo elemento (nome real da pasta)
    list(GET mapping_list 0 alias)
    list(GET mapping_list 1 folder)

    # Procura por todos os arquivos .c dentro da pasta real
    file(GLOB files_c "${folder}/*.c")

    foreach(file_path IN LISTS files_c)
        # Extrai apenas o nome do arquivo sem a extensão (ex: Binary Tree/main.c -> main)
        get_filename_component(programa "${file_path}" NAME_WE)

        # Define o nome do alvo (Target) no formato alias_programa (ex: sort_heap)
        set(compiling_target "${alias}_${programa}")

        # Cria o comando de compilação (make alias_programa)
        add_executable(${compiling_target} "${file_path}")

        # Cria o comando de execução (make run_programa)
        add_custom_target(run_${programa}
            COMMAND ${compiling_target}
            DEPENDS ${compiling_target}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        )
    endforeach()
endforeach()
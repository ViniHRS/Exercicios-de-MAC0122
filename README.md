# Exercícios de MAC0122
**Repositório com meus exercícios de MAC0122**  
Esses exercícios têm como objetivo praticar o conteúdo dado nas aulas de MAC0122

## 📄 Informações do Curso

**De:** Vinícius Hiroshi Rodrigues Sakuma  
**Ano:** 2026  
**Disciplina:** MAC0122 - Princípios de Desenvolvimento de Algoritmos    
**Professor:** Leônidas de Oliveira Brandão  
**Curso:** Engenharia de Computação  
**Instituição:** Escola Politécnica da Universidade de São Paulo

## ⚙️ Como Compilar e Executar
1) Crie uma pasta `build` e entre nessa pasta;
2) Dentro da pasta `build`, execute o comando `cmake ..` para gerar os arquivos do cmake necessários para a compilar e executar os programas;
3) Para compilar um programa, digite o comando `make folder_file`, onde `folder` se refere à pasta em que o algoritmo a ser compilado se encontra e `file` é o nome do arquivo `.c` do algoritmo.  
O target `folder`, apesar de fazer referência a pasta em que o programa se encontra, não recebe diretamente o nome da pasta. Na verdade, ela deve receber um "apelido" que faça referência ao nome da pasta. O arquivo `CMakeLists.txt` contém uma lista com todas as pastas e seus respectivos apelidos, identificando, assim, a que pasta o apelido informado em `folder` se refere. Abaixo, segue uma tabela com todos esses apelidos e a que pasta eles se referem:  

    | Pasta       | Apelido   |  
    | ---         | ---       |  
    | Binary Tree | tree      |  
    | Hashing     | hash      |  
    | Linked List | linked    |  
    | Queue       | queue     |  
    | Recursion   | recursion |  
    | Search      | search    |  
    | Sorting     | sort      |  
    | Stack       | stack     |  

    Exemplo de compilação:  
    `make sort_merge` --> Procura o arquivo merge.c na pasta Sorting e o compila.

4) Para executar um programa, digite `make run_file`, em que `file` é o programa que acabou de ser compilado.
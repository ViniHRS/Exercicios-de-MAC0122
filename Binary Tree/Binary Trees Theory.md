# Teoria sobre Árvores Binárias

## Conceito
Uma Árvore Binária é uma estrutura de dados hierárquica e não-linear. Diferente de Listas, Filas e Pilhas (onde os dados estão em uma sequência unidimensional de vizinhos lado a lado), a árvore organiza os dados de forma ramificada, imitando a estrutura de uma árvore genealógica ou de uma árvore na natureza (porém invertida, com a raiz no topo).  
A característica que a torna "binária" é a seguinte regra: cada elemento pode ter, no máximo, dois descendentes diretos (um à esquerda e um à direita).

## Anatomia da Árvore
- **Nó (Node):** A unidade básica que armazena o dado útil e os ponteiros para os seus descendentes.

- **Raiz (Root):** O nó inicial e absoluto. É o único nó da árvore que não possui um "pai". Todos os caminhos na árvore começam por ela. Se a raiz for nula, a árvore inteira está vazia.

- **Folha (Leaf):** Um nó que fica nas extremidades, ou seja, não possui nenhum filho (seus dois ponteiros apontam para NULL).

- **Pai e Filhos:** Se um nó $A$ aponta para um nó $B$, $A$ é o nó pai e $B$ é o nó filho.

- **Nível / Profundidade:** A distância de saltos de um nó específico até a raiz. A raiz está no nível 0, seus filhos diretos no nível 1, os netos no nível 2, e assim sucessivamente.

- **Altura (Height):** Representa o comprimento do caminho mais longo da raiz até a folha mais profunda. O controle de altura é crítico para garantir que a árvore não cresça apenas para um lado.

Abaixo, segue um exemplo que ilustra a estrutura de uma Árvore Binária  
![Árvore Binária](<Images/Árvore Binária Imagem.png>)

## Utilidade da Árvore Binária
Se Listas Ligadas e Vetores já armazenam dados dinamicamente, o motivo de usarmos árvores se resume a desempenho logarítmico e modelagem natural de dados.

- **Busca Rápida (Árvore Binária de Busca - BST):** Se organizarmos os dados seguindo a regra de que tudo à esquerda é menor que o pai, e tudo à direita é maior, podemos descartar metade da árvore a cada comparação durante uma busca. Isso reduz o tempo de busca de $O(n)$ (em uma lista) para $O(\log n)$, o que significa que encontrar um dado entre 1 milhão de registros leva, no máximo, cerca de 20 passos.

- **Representação Semântica:** Expressões matemáticas (ex: $A * (B + C)$) formam árvores naturalmente, onde os operadores são os nós pais e os números são as folhas.


## Travessias na Árvore
Como a árvore não é uma linha reta, você não pode percorrê-la com um laço simples de repetição (while ou for). É necessário usar recursão. A ordem em que você manda o algoritmo processar a "Raiz" em relação aos filhos esquerdo e direito muda drasticamente o resultado:

- **Pré-ordem (Pre-order): Raiz → Esquerda → Direita**  
    A raiz é lida primeiro, antes de descer para os filhos. É muito útil quando você precisa serializar a árvore ou criar uma cópia/clone exata dela na memória.

- **Em-ordem (In-order): Esquerda → Raiz → Direita**  
    O algoritmo desce tudo que pode para a esquerda, lê o pai, depois desce para a direita. Em uma Árvore de Busca (BST), este passeio é fundamental porque ele imprime os elementos perfeitamente ordenados em ordem crescente.

- **Pós-ordem (Post-order): Esquerda → Direita → Raiz**  
    A raiz só é processada após todos os seus descendentes serem resolvidos. É ideal para deletar a árvore inteira da memória sem deixar nós órfãos (você apaga os filhos antes de apagar o pai) e para avaliar o resultado final de árvores matemáticas.
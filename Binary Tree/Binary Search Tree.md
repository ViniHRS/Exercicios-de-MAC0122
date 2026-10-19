# Teoria sobre Árvore Binária de Busca

##  Conceito
Uma Árvore Binária de Busca (BST — Binary Search Tree) é uma estrutura de dados hierárquica projetada para realizar buscas, inserções e remoções rápidas, combinando a eficiência da busca binária com a alocação dinâmica de memória.

## Regra Fundamental
A característica que define uma BST é uma propriedade estrita aplicada a todos os nós da estrutura:

- **Subárvore Esquerda:** Todos os nós possuem valores estritamente menores que o nó pai.

- **Subárvore Direita:** Todos os nós possuem valores estritamente maiores que o nó pai.

![Árvore Binária](<Images/Árvore Binária Imagem.png>)
No exemplo acima, a qualquer momento que você olhar para um nó (ex: 7), tudo à esquerda dele (4) é menor e tudo à direita (9) é maior.

## Operações Principais
1. **Busca — $O(\log n)$**  
A busca compara a chave procurada com o nó atual:
    - Se for igual, o elemento foi encontrado.
    - Se for menor, descarta-se toda a subárvore direita e navega-se para a esquerda.
    - Se for maior, descarta-se toda a subárvore esquerda e navega-se para a direita.  

    A cada passo, o algoritmo elimina metade da árvore restante, alcançando desempenho logarítmico.
2. **Inserção — $O(\log n)$**  
Segue a mesma lógica da busca até encontrar um ponteiro nulo (NULL). O novo nó é então alocado e anexado a esse ponteiro.  
3. **Remoção — $O(\log n)$**  
A remoção é a operação mais complexa porque precisa reestruturar os ponteiros sem quebrar a regra da BST. Ela se divide em três cenários:
    1. **O nó é uma folha (sem filhos):** Basta liberar a memória (free) e ajustar o ponteiro do pai para NULL.  
    2. **O nó tem 1 filho:** Desaloca-se o nó e reconecta-se o seu pai diretamente ao seu único filho.  
    3. **O nó tem 2 filhos:** Não é possível simplesmente apagar o nó. Substitui-se o valor desse nó pelo seu sucessor (o menor valor da subárvore direita) ou pelo seu antecessor (o maior valor da subárvore esquerda). Em seguida, remove-se recursivamente esse sucessor/antecessor (que cairá no caso 1 ou 2).

### Propriedade Especial (Ordenação Automática)
Se você realizar um passeio Em-Ordem (In-Order) em uma BST (isto é, visitar recursivamente a Esquerda, processar a Raiz e visitar a Direita), os elementos serão visitados em ordem perfeitamente crescente.

## Análise de Complexidade e o Pior Caso
|  Operação | Caso Médio (Balanceada) | Pior Caso (Degenerada) |  
| --- | --- | --- |  
| Busca | $O(\log n)$ | $O(n)$ |  
| Inserção | $O(\log n)$ | $O(n)$ |  
| Remoção | $O(\log n)$ | $O(n)$ |  

## O Problema da Degeneração (Desbalanceamento)
Se você inserir uma sequência de dados já ordenados (por exemplo: 1, 2, 3, 4, 5) em uma BST simples, cada nó será inserido sempre à direita do anterior. Abaixo, segue um exemplo visual de árvore binária degenerada:  
![Árvore Binária Degenerada](<Images/Árvore Binária Degenerada.png>)

A árvore perde suas ramificações e se degenera em uma Lista Ligada. A altura passa a ser n e todas as operações degradam para tempo linear $O(n)$.

Para resolver esse problema, utilizam-se Árvores Binárias Autobalanceadas (como AVL e Red-Black), que executam rotações na memória durante inserções e remoções para reestruturar a árvore e garantir que a altura permaneça sempre em $O(\log n)$.
# Teoria sobre Algoritmos de Busca em Grafos

## Busca em Profundidade (DFS - Depth-First Search)
A busca em profundidade, ou DFS, é um algoritmo que explora o grafo avançando por um caminho até não conseguir continuar. Quando isso acontece, retorna aos vértices anteriores para explorar outras possibilidades.

Seu funcionamento utiliza uma pilha.

A ideia é relativamente simples:
1. Escolhemos um vértice inicial.
2. Visitamos esse vértice e inserimos seus vizinhos ainda não visitados na pilha.
3. Retiramos o elemento do topo da pilha.
4. Exploramos seus vizinhos ainda não visitados.
5. Repetimos o processo até que a pilha esteja vazia.

### Exemplo de execução
Considere o grafo:
```
    A
   / \
  B   C
 / \   \
D   E   F
```
- **Passo 1:**  
Começamos inserindo A na pilha  
    ```
    Pilha:
    | A |
    -----
    ```
    Retiramos A, visitamos esse vértice e adicionamos seus vizinhos B e C.

    Para este exemplo, vamos inserir primeiro C e depois B, de modo que B fique no topo.
    ```
    Pilha:
    | B | <- Topo
    | C |
    -----
    ```
- **Passo 2:**  
    Retiramos B e visitamos esse vértice.

    Seus vizinhos são A, D e E.

    Como A já foi visitado, não precisamos adicioná-lo novamente.

    Inserimos D e E, colocando E antes de D para que D fique no topo:
    ```
    Pilha:
    | D | <- Topo
    | E |
    | C |
    -----
    ```
- **Passo 3:**  
    Retiramos D e o visitamos.

    Seu único vizinho é B, que já foi visitado.

    Portanto, não adicionamos nenhum elemento.
    ```
    Pilha:
    | E | <- Topo
    | C |
    -----
    ```
- **Passo 4:**  
    Retiramos E e o visitamos.

    Seu único vizinho também já foi visitado.
    ```
    Pilha:
    | C | <- Topo
    -----
    ```
- **Passo 5:**  
    Retiramos C e o visitamos.

    Seu vizinho A já foi visitado, mas F ainda não.

    Adicionamos F:
    ```
    Pilha:
    | F | <- Topo
    -----
    ```
- **Passo 6:**  
    Retiramos F e o visitamos.

    Como seu único vizinho, C, já foi visitado, não adicionamos nada.

    A pilha fica vazia e o algoritmo termina.

- **Resultado do algoritmo:**  
    A ordem que cada vérticie foi visitado é:
    ```​
    A --> B --> D --> E --> C --> F
    ```

### Por que precisamos de uma pilha para o algoritmo DFS?

Porque queremos que o último vértice descoberto seja o próximo a ser explorado.

Esse comportamento LIFO permite avançar continuamente pelo caminho mais recentemente iniciado, retornando aos vértices anteriores quando necessário.

## Busca em Largura (BFS - Breadth-First Search)
Diferentemente da DFS, esse algoritmo explora primeiro todos os vértices que estão diretamente conectados ao vértice inicial.

Em seguida, explora os vizinhos desses vértices, avançando progressivamente pelo grafo.

Por isso, a BFS utiliza uma fila.

Seu funcionamento é:
1. Escolhemos um vértice inicial.
2. Visitamos esse vértice e inserimos seus vizinhos ainda não visitados na fila.
3. Retiramos o primeiro elemento da fila.
4. Inserimos na fila os vizinhos ainda não visitados desse elemento.
5. Repetimos o processo até que a fila esteja vazia.

### Exemplo de execução
Considere o mesmo grafo apresentado no exemplo da DFS.

- **Passo 1:**  
    Inserimos A na fila:
    ```
    Início        Final
     | A |
    ```
    Retiramos A, visitamos esse vértice e adicionamos seus vizinhos B e C.
    ```
    Início                Final
     | B | -------------- | C |
    ```
- **Passo 2:**  
    Retiramos B e o visitamos.

    Seus vizinhos são A, D e E.

    Como A já foi visitado, adicionamos D e E ao final da fila.
    ```
    Início                         Final
     | C | -------- | D | -------- | E |
    ```
- **Passo 3:**  
    Retiramos C e o visitamos.

    Seus vizinhos são A e F.

    Como A já foi visitado, adicionamos F:
    ```
    Início                         Final
     | D | -------- | E | -------- | F |
    ```
- **Passo 4:**  
    Retiramos D e o visitamos.

    Seu único vizinho, B, já foi visitado.

    Portanto, não adicionamos nada.
    ```
    Início             Final
     | E | ----------- | F |
    ```
- **Passo 5:**  
    Retiramos E e o visitamos.

    Seu único vizinho, B, já foi visitado.
    ```
    Início
     | F |
    ```
- **Passo 6:**  
    Retiramos F e o visitamos.

    Seu único vizinho, C, já foi visitado.

    A fila fica vazia e o algoritmo termina.
- **Resultado do algoritmo:**  
    A ordem de visitação foi:
    ```
    A --> B --> C --> D --> E --> F
    ```

Observe a diferença em relação à DFS.

Na BFS, primeiro visitamos todos os vértices que estão a uma aresta de distância de A.

Depois, visitamos os vértices que estão a duas arestas de distância.

Essa é justamente a característica da busca em largura: explorar o grafo por camadas, começando pelos vértices mais próximos da origem.

### Por que a BFS encontra o caminho mínimo?
Considere que cada aresta representa o mesmo custo de deslocamento.

Quando a BFS começa em A, primeiro visita todos os vértices que estão a uma aresta de distância.

Depois, visita aqueles que estão a duas arestas de distância, e assim sucessivamente.

Portanto, quando encontramos um determinado vértice pela primeira vez, sabemos que não existe um caminho com menos arestas entre ele e a origem.

Isso acontece porque todos os caminhos com menos arestas já foram explorados anteriormente.

A DFS não apresenta essa garantia, pois pode explorar primeiro um caminho muito longo, mesmo que exista outro caminho mais curto.

**Atenção:** para grafos ponderados com pesos diferentes, a BFS não necessariamente encontra o caminho de menor custo. Nesse caso, podemos utilizar algoritmos como Dijkstra, que trabalha com uma fila de prioridade.

## Aplicações Práticas de DFS e BFS

### Aplicações de DFS
A busca em profundidade é particularmente interessante quando queremos explorar completamente as possibilidades de um caminho.

Algumas aplicações:
- Detecção de ciclos: verificar se existem ciclos em um grafo.
- Componentes conexas: identificar grupos de vértices conectados.
- Labirintos: encontrar caminhos explorando possibilidades até encontrar uma saída.
- Ordenação topológica: organizar tarefas respeitando suas dependências, em grafos direcionados acíclicos (DAGs).
- Análise de conectividade: identificar pontes e pontos de articulação.

### Aplicações de BFS
A busca em largura é especialmente útil quando queremos encontrar os elementos mais próximos de um determinado vértice.

Algumas aplicações:
- Menor caminho: encontrar o caminho com menos arestas em grafos não ponderados.
- Redes sociais: identificar pessoas que estão a determinada quantidade de conexões de distância.
- Redes de computadores: explorar conexões por níveis.
- Labirintos: encontrar o caminho com o menor número de movimentos.
- Análise de redes: calcular distâncias entre vértices.

## Complexidade dos Algoritmos
Por fim, existe uma questão importante quando estudamos a implementação desses algoritmos: a complexidade computacional.

Considerando:
- \(V\): quantidade de vértices.
- \(E\): quantidade de arestas.

Tanto a DFS quanto a BFS possuem complexidade **O(V + E)**.

Essa complexidade considera a utilização de uma lista de adjacência.

Isso significa que o algoritmo precisa processar cada vértice e cada aresta, no máximo, uma quantidade constante de vezes.

Quando utilizamos uma matriz de adjacência, a complexidade passa a ser **O(V²)**.

Isso ocorre porque, para cada vértice, precisamos verificar todas as possíveis conexões com os demais vértices.

Ambos os algoritmos também podem utilizar **O(V)** de espaço auxiliar, considerando o vetor de visitados e a pilha ou fila utilizada na exploração.
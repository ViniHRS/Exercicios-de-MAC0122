# Teoria sobre Fila

## Conceito
A Fila (ou Queue) é uma estrutura de dados que se comporta como uma fila do mundo real: os primeiros objetos são os primeiros a serem removidos da fila e os últimos são removidos por último (**First In, First Out - FIFO**). Ainda seguindo a lógica de uma fila, qualquer objeto deve ser inserido no final da fila.

## Operações de uma Fila
Uma fila bem projetada executa todas as suas operações principais em tempo constante **O(1)**:
- **Enqueue (Enfileirar):** adiciona um elemento ao final (rear ou tail) da fila

- **Dequeue (Desenfileirar):** remove e retorna o elemento do início (front ou head) da fila

- **Peek / Front (Espiar):** retorna o valor do elemento do início sem removê-lo

- **IsEmpty:** verifica se a fila contém elementos

## Implementações
A fila pode ser construída tanto utilizando vetores como uma Lista Ligada. Neste repositório, a fila será implementada das duas formas. Entretanto, é importante destacar que a implementação com vetor não segue o jeito clássico, em que o vetor é criado estaticamente.  
Na implementação deste repositório, a fila com vetor é criada dinamicamente e, para cada inserção ou remoção, o tamanho do vetor é alterado. Por conta disso, a função de remoção torna-se de complexidade **O(n)**, pois os elementos devem ser deslocados e, em seguida, o tamanho do vetor é ajustado. Além disso, as funções Peek e IsEmpty não foram implementadas.

## Aplicações Reais de Fila
- **Escalonamento de Processos na CPU:** gerenciamento de tarefas que aguardam tempo de processamento (Round Robin).

- **Filas de Impressão:** documentos enviados para a impressora são processados na ordem de chegada.

- **Algoritmos em Grafos:** o algoritmo de Busca em Largura (BFS) usa uma fila para explorar vértices nível por nível.
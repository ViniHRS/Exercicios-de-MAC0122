# Teoria sobre os algoritmos de ordenação

## Insertion Sort
### Descrição do Algoritmo
O algoritmo Insertion Sort (ordenação por inserção) consiste em dividir o vetor em duas partes: uma parte ordenada e outra não ordenada. Deve-se, então, percorrer a parte não ordenada e inserir cada elemento desta parte na posição correta da porção ordenada do vetor.

A figura abaixo ilustra um exemplo visual de como o Insertion Sort funciona:  
![Insertion Sort Image](<Images/Insertion Sort.jpeg>)

### Análise de Complexidade
- **Melhor caso**  
No melhor caso, o vetor já está ordenado. Se isso ocorrer, para cada elemento é feita apenas uma comparação e nenhum deslocamento. Assim: **O(n)**
- **Pior caso**  
No pior caso, nenhum elemento do vetor está na posição correta. Se isso ocorrer, todos os elementos devem ser deslocados.  
Nesse caso, o primeiro elemento deve ser deslocado 1 vez, o segundo elemento deve ser deslocado 2 vezes, o terceiro 3 vezes e assim por diante. Dessa forma, o número de deslocamentos feitos é dado por:  

    1 + 2 + 3 + ... + (n-1) = n(n-1)/2 = (n²-n)/2

    Portanto, no pior caso o algoritmo tem complexidade **O(n²)**
- **Caso médio**  
No caso médio, o algoritmo também possui complexidade **O(n²)**, pois o número de comparações que o algoritmo faz também é de ordem n².

Percebe-se, então, que o Insertion Sort é um algoritmo lento, pois consome um tempo de processamento de ordem O(n²). Porém, apesar dessa desvantagem, o Insertion Sort é um algoritmo simples e de fácil implementação, utiliza pouca memória adicional e é estável, ou seja, não troca elementos iguais de posição. É um algoritmo útil para vetores pequenos e, no melhor caso, é eficiente (consome um tempo de ordem O(n)).

## Selection Sort
### Descrição do Algoritmo
O algoritmo de Selection Sort (ordenação por seleção) consistem em dividir o vetor em duas sublistas: a sublista esquerda ordenada e a sublista direita não ordenada.  
Primeiramente, o algoritmo considera a sublista ordenada vazia e a não ordenada como todo o vetor. Depois, ele percorre todo o vetor não ordenado em busca do menor elemento e, ao encontrá-lo, troca-se o menor elemento com o primeiro elemento da região não ordenada. Por fim, o algoritmo desloca a fronteira entre as sublistas uma posição para a direita e repete todo o processo, até ordenar o vetor completamente.

A figura abaixo ilustra visualmente como o Selection Sort funciona:  
![Selection Sort Image](<Images/Selection Sort.png>)

### Análise de Complexidade
- **Pior, médio e melhor casos**
Nos três casos, o algoritmo possui complexidade **O(n²)**, pois ele sempre varre toda a sublista não ordenada, independentemente se o vetor está parcialmente ou totalmente ordenado.

Assim como o Insertion Sort, o Selection Sort é um algoritmo in-place, ou seja, opera diretamente na estrutura original (não cria vetores auxiliares para ordenação). Entretanto, ao contrário do Insertion Sort, ele não é estável (pode trocar elementos iguais de posição) e, em seu melhor caso, possui complexidade O(n²). Portanto, o algoritmo Insertion Sort é preferível ao Selection Sort, pois, no melhor caso, aquele é mais rápido do que este.

## Bubble Sort
### Descrição do Algoritmo
O algoritmo Bubble Sort consiste em comparar elementos vizinhos e, se estiverem na ordem errada, devem ser trocados de posição. A ideia é que os elementos maiores vão "subindo" no vetor até chegarem na posição correta, semelhante a uma bolha.

Abaixo, segue uma ilustração de como o Bubble Sort funciona:  
![Bubble Sort Image](<Images/Bubble Sort.jpg>)

### Análise de Complexidade
- **Melhor caso**  
No melhor caso, o algoritmo realiza n comparações e nenhuma troca. Assim, a complexidade nesse caso é de **O(n)**.
- **Pior caso**  
No pior caso, o número de comparações feitas é aproximadamente  
    (n-1) + (n-2) + (n-3) + ... + 2 + 1 = (n²-n)/2  
    Assim, a complexidade é **O(n²)**.  
- **Caso médio**  
No caso médio, o número de comparações realizadas também é da ordem n². Portanto, a complexidade nesse caso também é **O(n²)**.

O Bubble Sort, assim como o Insertion Sort, também é estável e in-place. Além disso, ele também possui melhor caso O(n) e casos médio e ruim O(n²).

## Merge Sort
### Descrição do Algoritmo
O Merge Sort é um algoritmo de ordenação baseado no paradigma de Divisão e Conquista, reduzindo o problema principal de ordenar um grande vetor em subproblemas menores e mais fáceis de resolver.

<u>Fundamento Teórico:</u>

1. **Divisão:** O vetor é dividido sucessivamente ao meio até gerar subvetores contendo apenas um elemento. Um vetor com um único elemento é considerado ordenado por definição.

2. **Conquista:** As subdivisões são ordenadas recursivamente.

3. **Combinação (Intercalação ou Merge):** Dois subvetores adjacentes e já ordenados são fundidos em um único vetor ordenado. Para isso, compara-se o primeiro elemento não processado de cada subvetor e copia-se o menor elemento para o vetor final até consumir ambas as partes.

Segue uma imagem para ilustrar o funcionamento do Merge Sort:  
![Merge Sort Image](<Images/Merge Sort.png>)

### Análise de Complexidade
- **Pior, médio e melhor casos**  
Independente do caso, o algoritmo divide o vetor em uma árvore de profundidade $\log_2 n$, e cada nível da árvore requer O(n) operações para realizar a intercalação dos elementos. Assim, a complexidade do algoritmo é da ordem **O($n \log n$)**.  

O Merge Sort tem complexidade de espaço O(n) e, ao contrário dos algoritmos anteriores, não é in-place, pois ele requer memória adicional proporcional ao tamanho da estrutura para criar os subvetores temporários durante a fusão (merge).  
Entretanto, ele é um algoritmo estável e rápido, sendo mais vantajoso em questão de tempo. Porém, é importante ressaltar que, para garantir uma menor execução de tempo, o Merge Sort utiliza mais memória, devendo-se, então, avaliar se compensa gastar mais memória para executar a ordenação em menos tempo.

## Quick Sort
### Descrição do Algoritmo
O Quick Sort é um dos algoritmos de ordenação mais eficientes na prática, baseado no paradigma de Divisão e Conquista, assim como o Merge Sort. Ele rearranja a estrutura reposicionando os elementos com base em um valor de referência chamado pivô.

<u>Funcionamento Passo a Passo:</u>

1. **Escolha do Pivô:** Seleciona-se um elemento do vetor para ser a referência (comumente o último elemento, o primeiro, o elemento central ou a mediana de três).

2. **Particionamento:** Os elementos do vetor são reorganizados de forma que todos os itens menores que o pivô fiquem à sua esquerda, e todos os maiores ou iguais fiquem à sua direita. Ao final dessa fase, o pivô é inserido em sua posição exata e definitiva.

3. **Recursão:** Aplica-se o processo de forma independente para a sublista à esquerda do pivô e para a sublista à direita. A recursão atinge o caso-base quando o subvetor possui 0 ou 1 elemento (já ordenado).

A figura abaixo ilustra como o Quick Sort funciona:  
![Quick Sort Image](<Images/Quick Sort.jpg>)

### Análise de Complexidade
- **Melhor e médio caso**  
O melhor e o médio caso ocorrem quando o pivô divide o vetor em partes balanceadas, gerando uma árvore de chamadas recursivas com altura $\log_2 n$. Como cada nível requer operações de intercalação de ordem O(n), o algoritmo é de complexidade **O($n \log n$)**.
- **Pior caso**  
No pior caso, a escolha do pivô é desfavorável em todas as etapas, tornando o algoritmo de complexidade **O(n²)**.

Ao contrário do Merge Sort, o Quick Sort não é um algoritmo estável. Além disso, apesar de ser rápido como o Merge Sort no pior caso e caso médio, ele não requer memória adicional para fazer a ordenação (é in-place). Entretanto, caso a escolha do pivô seja desfavorável, o pior caso do Quick Sort acaba sendo pior do que o caso mais desfavorável do Merge Sort. Nesse sentido, o Merge Sort acaba sendo um algoritmo mais previsível do que o Quick Sort.

## Heap Sort
### Descrição do Algoritmo
O Heap Sort é um algoritmo que utiliza uma estrutura de dados chamada Heap (especificamente um Max-Heap) para ordenar os elementos. Ele é considerado um algoritmo híbrido do ponto de vista de vantagens, pois combina a previsibilidade de tempo do Merge Sort com a eficiência de memória do Selection Sort.

**A Estrutura Max-Heap**

O segredo do algoritmo é não usar ponteiros ou estruturas complexas, mas sim enxergar o vetor comum como uma árvore binária completa. Em um Max-Heap, a regra fundamental é que o valor de qualquer nó pai é sempre maior ou igual ao de seus filhos.

Em um vetor comum, se um nó pai está no índice i, o algoritmo encontra seus filhos matematicamente:  
- O filho da esquerda está em 2i + 1.  
- O filho da direita está em 2i + 2.

**Funcionamento Passo a Passo:**

1. **Construção do Heap (Build-Heap):** O algoritmo primeiro varre a metade inicial do vetor de trás para frente, aplicando uma função corretiva para garantir que todos os pais sejam maiores que seus filhos. O maior elemento de todo o vetor acaba subindo para a raiz (índice 0).

2. **Troca e Isolamento:** O elemento da raiz (o maior de todos) é trocado com o último elemento do vetor. Com isso, o maior número já está na sua posição definitiva no final da lista.

3. **Redução:** O tamanho "visível" do Heap é reduzido em 1. O elemento recém-posicionado no fim passa a ser ignorado.

4. **Reconstrução (Heapify):** A nova raiz colocada no passo 2 provavelmente é um número pequeno (já que veio do final da árvore), violando a regra do Max-Heap. O algoritmo a "afunda" na árvore, trocando-a com o maior de seus filhos, até que a propriedade seja restaurada e o segundo maior elemento assuma a raiz.

5. **Repetição:** Os passos 2 a 4 se repetem até restar apenas um elemento.

Abaixo, segue uma ilustração de como funciona o Heap Sort:  
![Heap Sort Image](<Images/Heap Sort.png>)

### Análise de Complexidade
- **Tempo (para todos os casos):** **$O(n \log n)$**. A construção inicial do heap custa $O(n)$. Depois, a cada extração, o reposicionamento (Heapify) custa $O(\log n)$. Como isso é feito $n-1$ vezes, o desempenho é extremamente consistente, sem a queda de performance que o Quick Sort sofre no pior caso.

O Heap Sort é um algoritmo in-place, pois a manipulação ocorre diretamente no vetor original. Entretanto, ele não é um algoritmo estável, pois a ação de pegar o último elemento da árvore e jogá-lo na raiz desestabiliza a ordem original de elementos repetidos.

## Counting Sort
### Descrição do Algoritmo

### Análise de Complexidade
- **Melhor caso**
- **Caso médio**
- **Pior caso**

## Radix Sort
### Descrição do Algoritmo

### Análise de Complexidade
- **Melhor caso**
- **Caso médio**
- **Pior caso**
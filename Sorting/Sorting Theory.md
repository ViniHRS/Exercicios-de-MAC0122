# Teoria sobre os algoritmos de ordenação

## Insertion Sort
### Descrição do Algoritmo
O algoritmo Insertion Sort (ordenação por inserção) consiste em dividir o vetor em duas partes: uma parte ordenada e outra não ordenada. Deve-se, então, percorrer a parte não ordenada e inserir cada elemento desta parte na posição correta da porção ordenada do vetor.

A figura abaixo ilustra um exemplo visual de como o Insertion Sort funciona:  
![alt text](<Images/Insertion Sort.jpeg>)

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

### Análise de Complexidade
- **Melhor caso**
- **Caso médio**
- **Pior caso**

## Bubble Sort
### Descrição do Algoritmo

### Análise de Complexidade
- **Melhor caso**
- **Caso médio**
- **Pior caso**

## Merge Sort
### Descrição do Algoritmo

### Análise de Complexidade
- **Melhor caso**
- **Caso médio**
- **Pior caso**

## Quick Sort
### Descrição do Algoritmo

### Análise de Complexidade
- **Melhor caso**
- **Caso médio**
- **Pior caso**

## Heap Sort
### Descrição do Algoritmo

### Análise de Complexidade
- **Melhor caso**
- **Caso médio**
- **Pior caso**

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
# Teoria sobre os algoritmos de ordenação

**Insertion Sort**  
O algoritmo de Insertion Sort (Ordenação por Inserção) consiste em separar o vetor em duas  
partes, uma ordenada na esquerda e outra desordenada na direita. O algoritmo deve percorrer  
a parte não ordenada do vetor, encontrar o menor elemento e inserí-lo na posição correta da  
região ordenada. Abaixo, segue um exemplo para ilustrar a ideia do Insertion Sort:

[3 | 5 8 9 0] (A princípio, considera-se o início do vetor como ordenado)  
Percorre-se a parte não ordenada para achar o menor elemento, que nesse caso é 0  

Compara-se o elemento encontrado com o elemento da parte ordenada.  
Como 3 > 0, o 0 é inserido na frente do 2, resultando em:  
[0 3 | 5 8 9]  

[0 3 | 5 8 9] (5 é o menor elemento da parte não ordenada e é maior do que 3, logo ele deve ser inserido à direita do 3)  

[0 3 5 | 8 9] -> [0 3 5 8 | 9] -> [0 3 5 8 9]  

Por fim, ao repetir o processo, deve-se obter o vetor ordenado.  
É importante ressaltar que esse algoritmo faz aproximadamente  
n²/2 comparações, pois, no pior caso, faz-se 1 + 2 + ... + n = n(n-1)/2  
comparações. Portanto, o Insertion Sort é de complexidade O(n²).  

**Selection Sort**  
A ideia do algoritmo Selection Sort é percorrer o vetor não ordenado,  
encontrar o menor elemento e movê-lo para a posição inicial. Assim como  
o Insertion Sort, o Selection Sort também divide o vetor em uma parte  
ordenada e outra não ordenada, porém os elementos são selecionados e  
inseridos sempre em ordem crescente. Abaixo, segue um exemplo para  
ilustrar o Selection Sort:  

[4 5 1 0 7] (Procura-se no vetor o menor elemento, que no caso é 0)  
Ao encontrar o menor elemento, deve-se deslocá-lo para a posição inicial  

[0 | 5 1 4 7] (Agora, procura-se o menor elemento da parte não ordenada, deslocando-o logo depois do 0)  

[0 | 5 1 4 7] -> [0 1 | 5 4 7] -> [0 1 4 | 5 7] -> [0 1 4 5 7]  

Assim como o Insertion Sort, o Selection Sort também possui complexidade  
O(n²), pois o algoritmo sempre varre a sublista não ordenada doo vetor,  
independentemente se o vetor já está parcialmente ou totalmente ordenado.  
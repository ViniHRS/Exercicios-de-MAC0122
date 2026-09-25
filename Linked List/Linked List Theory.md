# Teoria sobre Lista Ligada

## Conceito
Uma Lista Ligada (ou Lista Encadeada ou Linked List) é uma estrutura de dados linear e dinâmica. Diferente de um vetor, onde os elementos são armazenados em blocos contínuos na memória, os elementos de uma Lista Ligada ficam espalhados, ou seja, o próximo elemento da lista não está necessariamente armazenado do lado do seu antecessor na memória. Eles mantêm a ordem estrita porque cada elemento armazena o endereço do próximo.

### **Conceito de Nó**
O nó é a estrutura fundamental que constrói a Lista Ligada. Ele armzane o dado da lista (um inteiro, caractere, etc) e o endereço de memória do próximo elemento da sequência.

### **Anatomia da Lista**
- **Cabeça (Head):** a lista não existe sem um ponto de partida. O Head é um ponteiro especial que guarda o endereço do primeiro nó. Se a lista estiver vazia, o Head aponta para NULL.

- **A Cauda (Tail/Fim da lista):** o último nó da sequência não tem ninguém para apontar depois dele. Portanto, seu ponteiro aponta para NULL, sinalizando o fim da estrutura.

Segue um exemplo que ilustra a Lista Ligada:  
![Linked List Image](<Images/Lista Encadeada Image.jpg>)

### **Comparativo: Lista Ligada vs Vetor**
Característica      | Lista Ligada | Vetor  
------------------- | ------------ | -----  
Alocação de memória | Dinâmica (cresce e diminui nó a nó conforme a necessidade) | Maior (cada elemento exige memória extra para armazenar o ponteiro)  
Inserção/Remoção    | O(1) no início  (basta redirecionar ponteiros, sem deslocar outros itens) | O(n) (exige deslocar todos os elementos seguintes)  
Acesso a elementos  | O(n) (busca sequencial obrigatória começando pela Cabeça) | O(1) (acesso direto via índice)  
Custo de memória    | Maior (cada elemento exige memória extra para armazenar o ponteiro) | Menor (armazena apenas os dados brutos)  
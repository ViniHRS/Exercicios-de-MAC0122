# Teoria sobre Lista Ligada

## Conceito
Uma Lista Ligada (ou Lista Encadeada ou Linked List) é uma estrutura de dados linear e dinâmica. Diferente de um vetor, onde os elementos são armazenados em blocos contínuos na memória, os elementos de uma lista ligada ficam espalhados, ou seja, o próximo elemento da lista não está necessariamente armazenado do lado do seu antecessor na memória. Eles mantêm a ordem estrita porque cada elemento armazena o endereço do próximo.

### **Conceito de Nó**
O nó é a estrutura fundamental que constrói a Lista Ligada. Ele armzane o dado da lista (um inteiro, caractere, etc) e o endereço de memória do próximo elemento da sequência.

### **Anatomia da Lista**
- **Cabeça (Head):** a lista não existe sem um ponto de partida. O Head é um ponteiro especial que guarda o endereço do primeiro nó. Se a lista estiver vazia, o Head aponta para NULL.

- **A Cauda (Tail/Fim da lista):** o último nó da sequência não tem ninguém para apontar depois dele. Portanto, seu ponteiro aponta para NULL, sinalizando o fim da estrutura.
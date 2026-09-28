# Teoria sobre Pilha

## Conceito
A Pilha (Stack) é uma estrutura de dados que se comporta semelhante a uma pilha na vida real (como uma pilha de pratos, por exemplo): o último elemento inserido é o primeiro elemento a ser removido (Last In, First Out - LIFO).  

Na Fila, tínhamos duas extremidades ativas (uma para entrada, Head, e outra para saída, Tail). Na Pilha, todas as operações acontecem em um único ponto: o Topo (Top).  

Isso torna a Pilha muito mais simples de implementar via vetor, pois não precisamos de buffer circular nem de deslocamento de memória. As operações ocorrem naturalmente em tempo estrito de **O(1)**.

## Operações de uma Pilha
- **Push (Empilhar):** adiciona um elemento no topo da pilha (**O(1)**)

- **Pop (Desempilhar):** remove e retorna o elemento do topo (**O(1)**)  

- **Peek / Top (Espiar):** retorna o elemento do topo sem removê-lo (**O(1)**)

- **IsEmpty:** verifica se a pilha está vazia (**O(1)**).

## Aplicações Reais da Pilha
- **Call Stack (Pilha de Chamadas de Funções):** quando uma função chama outra em C (ou na recursão), o estado da função atual é empilhado na memória da CPU.

- **Mecanismo de Desfazer/Refazer (Ctrl + Z):** cada ação do usuário é empilhada. Desfazer significa dar um pop da última ação efetuada.

- **Verificação de Sintaxe (Parentização):** compiladores usam pilhas para verificar se parênteses, colchetes e chaves foram abertos e fechados na ordem correta, ex: { [ ( ) ] }.

- **Navegação de Páginas Web:** o botão "Voltar" do navegador empilha os links visitados.
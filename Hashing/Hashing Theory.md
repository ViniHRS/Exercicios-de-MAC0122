# Teoria sobre Hashing

## Conceito
O Hashing (Espalhamento) é um algoritmo de busca diferente dos algoritmos clássicos (como a Busca Binária). Enquanto as buscas clássicas precisam "procurar" o elemento comparando valores até achá-lo (**O(n)** para Busca Sequencial e **$O(\log n)$** para Busca Binária), o Hashing tem uma ambição maior: saber exatamente onde o dado está armazenado de forma instantânea, em tempo **O(1)**.

Imagine que você está em uma biblioteca. Em vez de procurar um livro prateleira por prateleira, você coloca o título do livro em uma fórmula matemática e ela te devolve exatamente o corredor, a prateleira e a posição do livro.

## Os três pilares do Hashing
1. **Tabela Hash (Hash Table):** é um vetor comum onde os dados serão armazenados. Cada posição desse vetor é chamada de bucket ou slot.

2. **Função Hash:** é o coração do algoritmo. É uma função matemática que recebe a chave do dado e a transforma em um índice válido do vetor.

    *Exemplo simples*: se o vetor tem tamanho 10 e a chave é o número 452, a função hash pode ser o resto da divisão: 452 % 10 = 2. O dado será guardado no índice 2.

3. **Tratamento de Colisões:** se você tem infinitas chaves possíveis, mas um vetor de tamanho limitado, em algum momento a função matemática vai gerar o mesmo índice para duas chaves diferentes. Isso é uma colisão.

Abaixo, segue um exemplo visual de uma tabela Hash, juntamente com um caso de colisão:  
![Hash Table Image](<Images/Hashing Image.png>)

## Como resolver colisões
A técnica mais clássica é o Encadeamento Separado (Separate Chaining).
Em vez de guardar o dado diretamente na posição do vetor, cada posição do vetor guarda o início de uma Lista Encadeada. Se dois dados caírem no mesmo índice, o algoritmo simplesmente adiciona o novo dado ao final da Lista Encadeada daquele índice, como pode ser observado na imagem acima.

## Análise de complexidade
- **Tempo Médio:** **O(1)** para buscar, inserir e deletar. A função hash calcula o índice na hora.

- **Tempo no Pior Caso:** **O(n)**. Ocorre se a função Hash for muito ruim e jogar todos os elementos no mesmo índice, transformando a tabela em uma única e longa Lista Ligada.  

- **Espaço:** **O(n + m)**, onde n é o número de elementos e m é o tamanho do vetor da tabela.

## Observações
Neste repositório:  
- A tabela Hash foi implementada com um tamanho fixo de 10 índices;  
- A função Hash implementada divide a chave recebida por 10 e utiliza o resto da divisão como índice para a tabela;  
- A função de inserção foi implementada de um jeito diferente: em vez de inserir um novo elemento no final de uma Lista Ligada para evitar colisões, o novo elemento é sempre inserido no começo da Lista, evitando inserções de complexidade **O(n)**;
- Outras formas de implementar a tabela Hash e a função Hash também são possíveis.
# Documentação do Programa de Ordenação de Pessoas
Este programa em C ordena um vetor de 100 structs Pessoa pelo campo nome em ordem alfabética, utilizando os algoritmos Bubble Sort, Selection Sort e Merge Sort. Ele mede o desempenho dos algoritmos, calculando:

Comparações: Quantidade de comparações de nomes usando strcmp.
Trocas: Quantidade de trocas ou movimentações de elementos.
Tempo médio: Tempo em milissegundos, média de 1000 execuções por algoritmo.

O código é projetado para ser claro e simples, com variáveis em português (ex.: comparacoes, trocas) e nomes dos algoritmos em inglês, adequado para estudantes de graduação. Esta documentação detalha dois algoritmos escolhidos (Bubble Sort e Selection Sort), suas complexidades e os resultados da última execução, incluindo dados do Merge Sort.
Estrutura do Código
Arquivo

ordenacao_pessoas.c: Contém o código completo, incluindo a struct Pessoa, funções auxiliares, algoritmos de ordenação e a função principal.

Estrutura de Dados
typedef struct {
    char nome[100];
    int idade;
} Pessoa;


Campos:
nome: String de até 100 caracteres, com nomes únicos gerados aleatoriamente (ex.: "Ana12", "Fernanda3").
idade: Inteiro gerado aleatoriamente entre 18 e 67.



Algoritmos de Ordenação
Bubble Sort
Explicação:O Bubble Sort é um algoritmo simples que compara pares de elementos adjacentes no vetor e os troca se o nome em vetor[j] vier alfabeticamente após vetor[j+1]. O processo é repetido em várias passadas, movendo o maior elemento para o final em cada iteração, como bolhas subindo na água. No programa:

Usa strcmp para comparar nomes.
Chama a função trocar para realizar trocas.
Conta cada comparação (strcmp) e troca.

Funcionamento:

Dois loops aninhados:
Loop externo (i de 0 a n-2): Controla o número de passadas.
Loop interno (j de 0 a n-i-1): Compara pares adjacentes.


Se strcmp(vetor[j].nome, vetor[j+1].nome) > 0, troca os elementos com trocar e incrementa trocas.
Cada passada posiciona o maior elemento restante no final do vetor.

Complexidade:

Comparações: ( O(n^2) ), aproximadamente ( \frac{n(n-1)}{2} ) (ex.: 4950 para ( n=100 )).
Trocas: ( O(n^2) ), até ( \frac{n(n-1)}{2} ) no pior caso, cerca de ( \frac{n(n-1)}{4} ) em média para vetores aleatórios (ex.: ~2475 para ( n=100 )).
Tempo: ( O(n^2) ), ineficiente para vetores grandes devido aos loops aninhados.

Selection Sort
Explicação:O Selection Sort seleciona o menor elemento restante no vetor em cada iteração e o coloca na posição correta. Ele percorre o vetor a partir da posição atual para encontrar o menor nome (usando strcmp) e troca com o elemento atual, se necessário. No programa:

Usa strcmp para comparar nomes.
Chama a função trocar para realizar trocas.
Conta cada comparação (strcmp) e troca.

Funcionamento:

Dois loops:
Loop externo (i de 0 a n-2): Seleciona a posição atual.
Loop interno (j de i+1 a n-1): Busca o menor nome.


Mantém indice_menor como o índice do menor nome encontrado.
Incrementa comparacoes a cada strcmp.
Se indice_menor != i, troca vetor[i] com vetor[indice_menor] e incrementa trocas.

Complexidade:

Comparações: ( O(n^2) ), aproximadamente ( \frac{n(n-1)}{2} ) (ex.: 4950 para ( n=100 )).
Trocas: ( O(n) ), até ( n-1 ) no pior caso (ex.: ~99 para ( n=100 )).
Tempo: ( O(n^2) ), mas com menos trocas que o Bubble Sort, geralmente resultando em tempos menores.

Resultados
Os resultados foram obtidos executando o programa com um vetor de 100 elementos, com 1000 execuções por algoritmo para calcular o tempo médio. A tabela abaixo apresenta as estatísticas da última execução, incluindo Bubble Sort, Selection Sort e Merge Sort:



Algoritmo
Comparações
Trocas
Tempo Médio (ms)



Bubble Sort
4950
2291
0.12


Selection Sort
4950
97
0.04


Merge Sort
537
387
0.01


Observações:

Bubble Sort: Realiza muitas comparações (4950) and trocas (2291) devido à complexidade ( O(n^2) ). O tempo médio (0.12 ms) reflete sua ineficiência.
Selection Sort: Faz o mesmo número de comparações que o Bubble Sort (4950), mas significativamente menos trocas (97), resultando em um tempo menor (0.04 ms).
Merge Sort: Faz muito menos comparações (537) e trocas (387), com um tempo médio muito menor (0.01 ms), mostrando a eficiência de ( O(n \log n) ).
Trocas no Merge Sort: Contadas como atribuições durante a mesclagem, o que pode inflar o número em comparação com trocas diretas.



Fernanda0, 24
Eduardo1, 36
Carlos2, 64
Fernanda3, 21
Ana4, 66
(...e mais 95 elementos)

Bubble Sort:
Vetor ordenado (primeiros 5 elementos):
Ana12, 43
Ana20, 27
Ana23, 50
Ana30, 53
Ana35, 34
(...e mais 95 elementos)
Comparacoes: 4950
Trocas: 2291
Tempo medio: 0.12 ms

Selection Sort:
Vetor ordenado (primeiros 5 elementos):
Ana12, 43
Ana20, 27
Ana23, 50
Ana30, 53
Ana35, 34
(...e mais 95 elementos)
Comparacoes: 4950
Trocas: 97
Tempo medio: 0.04 ms

Merge Sort:
Vetor ordenado (primeiros 5 elementos):
Ana12, 43
Ana20, 27
Ana23, 50
Ana30, 53
Ana35, 34
(...e mais 95 elementos)
Comparacoes: 537
Trocas: 387
Tempo medio: 0.01 ms

Notas

Tamanho do Vetor: 100 elementos garantem tempos mensuráveis, com apenas os primeiros 5 exibidos para legibilidade.
Trocas no Merge Sort: Contadas como atribuições na mesclagem, inflando o número em comparação com trocas diretas.
Tempo Médio: Calculado sobre 1000 execuções para maior precisão, considerando a baixa resolução do clock() em alguns sistemas.
Aleatoriedade: Nomes são únicos (ex.: "Ana12") para evitar ambiguidades na ordenação.


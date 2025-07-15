#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

// Troca duas pessoas
void trocar(Pessoa *a, Pessoa *b) {
    Pessoa temp = *a;
    *a = *b;
    *b = temp;
}

// Imprime o vetor (apenas os primeiros 5 elementos)
void imprimirVetor(Pessoa vetor[], int n) {
    for (int i = 0; i < n && i < 5; i++) {
        printf("%s, %d\n", vetor[i].nome, vetor[i].idade);
    }
    if (n > 5) printf("(...e mais %d elementos)\n", n - 5);
    printf("\n");
}

// Gera um vetor com nomes e idades aleatórios
void gerarVetor(Pessoa vetor[], int n) {
    char nomes[][20] = {"Ana", "Beatriz", "Carlos", "Daniel", "Eduardo", "Fernanda", "Gabriel", "Helena", "Igor", "Julia"};
    for (int i = 0; i < n; i++) {
        sprintf(vetor[i].nome, "%s%d", nomes[rand() % 10], i);
        vetor[i].idade = 18 + (rand() % 50);
    }
}

// Bubble Sort
void bubbleSort(Pessoa vetor[], int n, long *comparacoes, long *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            (*comparacoes)++;
            if (strcmp(vetor[j].nome, vetor[j+1].nome) > 0) {
                trocar(&vetor[j], &vetor[j+1]);
                (*trocas)++;
            }
        }
    }
}

// Selection Sort
void selectionSort(Pessoa vetor[], int n, long *comparacoes, long *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 0; i < n-1; i++) {
        int indice_menor = i;
        for (int j = i+1; j < n; j++) {
            (*comparacoes)++;
            if (strcmp(vetor[j].nome, vetor[indice_menor].nome) < 0) {
                indice_menor = j;
            }
        }
        if (indice_menor != i) {
            trocar(&vetor[i], &vetor[indice_menor]);
            (*trocas)++;
        }
    }
}

// Merge Sort
void merge(Pessoa vetor[], int esq, int meio, int dir, long *comparacoes, long *trocas) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    Pessoa esquerda[n1], direita[n2];

    for (int i = 0; i < n1; i++)
        esquerda[i] = vetor[esq + i];
    for (int j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        (*comparacoes)++;
        if (strcmp(esquerda[i].nome, direita[j].nome) <= 0) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
            (*trocas)++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
        (*trocas)++;
    }

    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
        (*trocas)++;
    }
}

void mergeSort(Pessoa vetor[], int esq, int dir, long *comparacoes, long *trocas) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(vetor, esq, meio, comparacoes, trocas);
        mergeSort(vetor, meio + 1, dir, comparacoes, trocas);
        merge(vetor, esq, meio, dir, comparacoes, trocas);
    }
}

// Função auxiliar para Merge Sort
void mergeSortAuxiliar(Pessoa vetor[], int n, long *comparacoes, long *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    mergeSort(vetor, 0, n-1, comparacoes, trocas);
}

int main() {
    srand(time(NULL));
    int n = 100;
    Pessoa pessoas_original[n], pessoas[n], pessoas2[n], pessoas3[n];
    long comparacoes = 0, trocas = 0;
    clock_t inicio, fim;
    double tempo;
    int execucoes = 1000;

    // Gera vetor com dados aleatórios
    gerarVetor(pessoas_original, n);
    for (int i = 0; i < n; i++) {
        pessoas[i] = pessoas_original[i];
        pessoas2[i] = pessoas_original[i];
        pessoas3[i] = pessoas_original[i];
    }

    printf("Vetor original (primeiros 5 elementos):\n");
    imprimirVetor(pessoas_original, n);

    // Bubble Sort
    tempo = 0.0;
    for (int i = 0; i < execucoes; i++) {
        for (int j = 0; j < n; j++) pessoas[j] = pessoas_original[j];
        inicio = clock();
        bubbleSort(pessoas, n, &comparacoes, &trocas);
        fim = clock();
        tempo += ((double)(fim - inicio)) * 1000.0 / CLOCKS_PER_SEC;
    }
    tempo /= execucoes;
    printf("Bubble Sort:\n");
    printf("Vetor ordenado (primeiros 5 elementos):\n");
    imprimirVetor(pessoas, n);
    printf("Comparacoes: %ld\n", comparacoes);
    printf("Trocas: %ld\n", trocas);
    printf("Tempo medio: %.2f ms\n\n", tempo);

    // Selection Sort
    comparacoes = 0;
    trocas = 0;
    tempo = 0.0;
    for (int i = 0; i < execucoes; i++) {
        for (int j = 0; j < n; j++) pessoas2[j] = pessoas_original[j];
        inicio = clock();
        selectionSort(pessoas2, n, &comparacoes, &trocas);
        fim = clock();
        tempo += ((double)(fim - inicio)) * 1000.0 / CLOCKS_PER_SEC;
    }
    tempo /= execucoes;
    printf("Selection Sort:\n");
    printf("Vetor ordenado (primeiros 5 elementos):\n");
    imprimirVetor(pessoas2, n);
    printf("Comparacoes: %ld\n", comparacoes);
    printf("Trocas: %ld\n", trocas);
    printf("Tempo medio: %.2f ms\n\n", tempo);

    // Merge Sort
    comparacoes = 0;
    trocas = 0;
    tempo = 0.0;
    for (int i = 0; i < execucoes; i++) {
        for (int j = 0; j < n; j++) pessoas3[j] = pessoas_original[j];
        inicio = clock();
        mergeSortAuxiliar(pessoas3, n, &comparacoes, &trocas);
        fim = clock();
        tempo += ((double)(fim - inicio)) * 1000.0 / CLOCKS_PER_SEC;
    }
    tempo /= execucoes;
    printf("Merge Sort:\n");
    printf("Vetor ordenado (primeiros 5 elementos):\n");
    imprimirVetor(pessoas3, n);
    printf("Comparacoes: %ld\n", comparacoes);
    printf("Trocas: %ld\n", trocas);
    printf("Tempo medio: %.2f ms\n", tempo);

    return 0;
}
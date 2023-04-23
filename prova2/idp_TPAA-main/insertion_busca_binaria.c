#include <stdio.h>

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para realizar a busca binária
int buscaBinaria(int vetor[], int valor, int esquerda, int direita) {
    int meio;

    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (valor < vetor[meio]) {
            direita = meio - 1;
        }
        else {
            esquerda = meio + 1;
        }
    }

    return esquerda;
}

// Função para realizar o Insertion Sort com busca binária
void insertionSortBinario(int vetor[], int tamanho) {
    int i, j, atual;
    int posicao;

    for (i = 1; i < tamanho; i++) {
        atual = vetor[i];
        posicao = buscaBinaria(vetor, atual, 0, i-1);
        for (j = i-1; j >= posicao; j--) {
            vetor[j+1] = vetor[j];
        }
        vetor[posicao] = atual;
    }
}

// Função principal
int main() {
    int vetor[] = {9, 3, 1, 4, 6, 8, 7, 5, 2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    imprimirVetor(vetor, tamanho);

    insertionSortBinario(vetor, tamanho);

    printf("Vetor ordenado: ");
    imprimirVetor(vetor, tamanho);

    return 0;
}

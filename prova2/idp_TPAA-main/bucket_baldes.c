#include <stdio.h>
#include <stdlib.h>

// Estrutura para cada elemento da lista encadeada
struct Node {
    int data;
    struct Node* next;
};

void printBuckets(struct Node* buckets[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Bucket %d: ", i);
        struct Node* currentNode = buckets[i];
        while (currentNode != NULL) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

void BucketSort(int arr[], int n, int k) {
    // Cria os buckets
    struct Node* buckets[k];

    // Inicializa os buckets como lista encadeada vazia
    for (int i = 0; i < k; i++) {
        buckets[i] = NULL;
    }

    // Insere cada elemento no seu bucket apropriado
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        int bucketIndex = (k * arr[i]) / (n + 1);
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = newNode;
        } else {
            struct Node* currentNode = buckets[bucketIndex];
            while (currentNode->next != NULL) {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    // Ordena cada bucket usando Insertion Sort
    for (int i = 0; i < k; i++) {
        struct Node* currentNode = buckets[i];
        while (currentNode != NULL) {
            int key = currentNode->data;
            int j = i - 1;
            while (j >= 0 && buckets[j]->data > key) {
                buckets[j + 1] = buckets[j];
                j--;
            }
            buckets[j + 1]->data = key;
            currentNode = currentNode->next;
        }
      printBuckets(buckets, k);
    }

    // Concatena todos os buckets ordenados na lista original
    int index = 0;
    for (int i = 0; i < k; i++) {
        struct Node* currentNode = buckets[i];
        while (currentNode != NULL) {
            arr[index++] = currentNode->data;
            currentNode = currentNode->next;
        }
    }
  
}

// Função auxiliar para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 4, 2, 5, 3, 7, 9, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;  // número de buckets

    printf("Array antes da ordenação: ");
    printArray(arr, n);

    BucketSort(arr, n, k);

    printf("Array após a ordenação: ");
    printArray(arr, n);

    return 0;
}

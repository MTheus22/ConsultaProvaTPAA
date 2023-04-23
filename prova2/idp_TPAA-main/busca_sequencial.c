#include <stdio.h>

int SequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; // Elemento não encontrado
}

int main() {
    int arr[] = {5, 2, 4, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    int index = SequentialSearch(arr, n, x);

    if (index != -1) {
        printf("O elemento %d está na posição %d\n", x, index);
    } else {
        printf("O elemento %d não está presente no array\n", x);
    }

    return 0;
}

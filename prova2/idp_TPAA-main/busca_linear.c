#include <stdio.h>

int LinearSearch(int arr[], int l, int r, int x) {
    if (r < l) {
        return -1; // Elemento não encontrado
    }
    if (arr[l] == x) {
        return l;
    }
    if (arr[r] == x) {
        return r;
    }
    return LinearSearch(arr, l + 1, r - 1, x);
}

int main() {
    int arr[] = {5, 2, 4, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    int index = LinearSearch(arr, 0, n - 1, x);

    if (index != -1) {
        printf("O elemento %d está na posição %d\n", x, index);
    } else {
        printf("O elemento %d não está presente no array\n", x);
    }

    return 0;
}

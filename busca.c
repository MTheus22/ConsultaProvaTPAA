#include<stdio.h>
#include<stdlib.h>


int main()
{
    int j;
    int V[j];
    int elem;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &j);

    printf("Digite os elementos");
    for(int i =0; i<j; i++)
    {
        scanf("%d");
    }
    printf("Digite o elemento que deseja pesquisar: ");
    scanf("%d", &j);

    for(i=0; i<j; i++){
        if(elem==V[i])
            return i;
    }
    return 0;
}
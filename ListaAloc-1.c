#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ler_valor(int *vetorfunc, int tam);
int main(){
    int n, *vetor, i = 0;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    vetor = (int*)malloc(n*sizeof(int));
    free(vetor);
    ler_valor(vetor, n);
    for (i = 0; i < n; i++){
        printf("Vetor Posicao %d: %d\n", i+1, *vetor);
        vetor++;
    }
}
void ler_valor(int *vetorfunc, int tam){
    int i = 0;
    for (i = 0; i < tam; i++){
        scanf("%d", vetorfunc);
        vetorfunc++;
    }
}
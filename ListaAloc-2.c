#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *Primeira_Func(int n);
void Imprime_Vetor(int *iniciovet, int tamfunc);
int main(){
    int tam = 0, *PtrPrimerFunc, i = 0, *Inicio;
    printf("Informe o Tamanho do vetor a ser criado: ");
    scanf("%d", &tam);
    PtrPrimerFunc = Primeira_Func(tam);
    Inicio = PtrPrimerFunc;
    for (i = 0; i < tam; i++){
        scanf("%d", PtrPrimerFunc);
        PtrPrimerFunc++;
    }
    Imprime_Vetor(Inicio, tam);
    return 0;
}
int *Primeira_Func(int n){
    int *vetor;
    vetor = (int*)malloc(n*sizeof(int));
    free(vetor);
    return vetor;
}
void Imprime_Vetor(int *iniciovet, int tamfunc){
    int i = 0;
    for (i = 0; i < tamfunc; i++){
        printf("Valor %d do vetor: %d\n", i+1, *iniciovet);
        iniciovet++;
    }
}
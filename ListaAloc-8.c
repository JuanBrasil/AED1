#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *vetores_uniao(int *vet1, int *vet2, int tam1, int tam2);
int main(){
    int tam1main, tam2main, *vet1, *vet2, i = 0, *vet_uniao, *ini1, *ini2;
    printf("Qual o tamanho do Vetor 1: ");
    scanf("%d", &tam1main);
    printf("Qual o tamanho do Vetor 2: ");
    scanf("%d", &tam2main);
    vet1 = (int*)malloc(tam1main*(sizeof(int)));
    ini1 = vet1;
    vet2 = (int*)malloc(tam2main*(sizeof(int)));
    ini2 = vet2;
    for ( i = 0; i < tam1main; i++){
        printf("Vetor 1[%d]: ", i);
        scanf("%d", vet1);
        vet1++;
    }
    for ( i = 0; i < tam2main; i++){
        printf("Vetor 2[%d]: ", i);
        scanf("%d", vet2);
        vet2++;
    }
    vet1 = ini1;
    vet2 = ini2;
    vet_uniao = vetores_uniao(vet1, vet2, tam1main, tam2main);
    printf("Vetor Uniao: ");
    for ( i = 0; i < (tam1main + tam2main); i++){
        printf("%d ", *vet_uniao);
        vet_uniao++;
    }
    printf("\n");
    free(vet1);
    free(vet2);
}
int *vetores_uniao(int *vet1, int *vet2, int tam1, int tam2){
    int *vet3, i = 0, *ini;
    vet3 = (int*)malloc((tam1+tam2)*(sizeof(int)));
    ini = vet3;
    for (i = 0; i < tam1; i++){
        *vet3 = *vet1;
        vet3++;
        vet1++;
    }
    for ( i = 0; i < tam2; i++){
       *vet3 = *vet2;
        vet3++;
        vet2++;
    }
    vet3 = ini;
    return vet3;
    free(vet3);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int **Cria_Matriz(int m, int n);
int **preenche_matriz(int **matrizini, int m, int n);
void Imprime_Matriz(int **matriz, int m, int n);
void Limpa_Memoria(int **q, int m);
int main(){
    int coluna, linha, **matrizcriada;
    int **matrizmain, **matrizpreenchida;
    printf("Informe o numero de linhas depois de colunas: ");
    scanf("%d %d", &linha, &coluna);
    matrizcriada = Cria_Matriz(linha, coluna);
    matrizmain = matrizcriada; // copia o inicio da matriz
    matrizpreenchida = preenche_matriz(matrizmain, linha, coluna);
    Imprime_Matriz(matrizmain,linha,coluna);
    Limpa_Memoria(matrizmain, linha);
}
void Limpa_Memoria(int **q, int m){
    int i;
    for ( i = 0; i < m; i++){
        free(q[i]); // free na segunda parte da matriz
    }
    free(q); // free na primeira parte da matriz
}
int **Cria_Matriz(int m, int n){
    int i;
    int **matriz;

    matriz = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++){
        matriz[i] = (int*)malloc(n * sizeof(int));
    }
    return matriz;
}
int **preenche_matriz(int **matrizini, int m, int n){
    int i = 0, j = 0;
    for (i = 0; i < m; i++) {
       for (j = 0; j < n; j++){
           printf("Valor[%d][%d]: \n", i,j);
           scanf("%d", &matrizini[i][j]);
       }
    }
    return matrizini;
}
void Imprime_Matriz(int **matriz, int m, int n){
    int i,j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf("Matriz Valor[%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    }
}
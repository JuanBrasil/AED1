#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void ler_aposta(int Apostas, int *VetordeApostas);
void sorteia_valores(int *sorteio, int n);
int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);
int main(){
    int numApostas, i = 0, *Vetor, *ini, numerosparasortear, *vetorsorteios, *apostasCertas, *vetAcertosMain;
    printf("Quantos Numeros Deseja Apostar?(1 a 20): ");
    scanf("%d", &numApostas);
    Vetor = (int*)malloc(numApostas*(sizeof(int)));
    ini = Vetor;
    ler_aposta(numApostas, Vetor);
    for ( i = 0; i < numApostas; i++){
        printf("Aposta %d : %d\n", i+1, *Vetor);
        Vetor++;
    }
    printf("Quantos numeros serao sorteados? ");
    scanf("%d", &numerosparasortear);
    vetorsorteios = (int*)malloc(numerosparasortear * sizeof(int));
    sorteia_valores(vetorsorteios, numerosparasortear);
    apostasCertas = (int*)malloc(sizeof(int));
    vetAcertosMain = compara_aposta(ini, vetorsorteios, apostasCertas, numApostas, numerosparasortear);    
    printf("Acertou %d valores\n", *apostasCertas);
    printf("Os valores acertados foram: ");
    for (i = 0; i < *apostasCertas; i++){
        printf("%d ", *vetAcertosMain);
        vetAcertosMain++;
    }
    printf("\n");
    free(vetorsorteios);
    Vetor = ini;
    free(Vetor);
    free(apostasCertas);
}
void ler_aposta(int Apostas, int *VetordeApostas){
    int i, NumeroApostado;
    for ( i = 0; i < Apostas; i++){
        printf("Informe sua Aposta: ");
        scanf("%d", &NumeroApostado);
        while((NumeroApostado < 0)||(NumeroApostado > 100)){
            printf("Sua Aposta deve estar entre 0 a 100, digite novamente: ");
            scanf("%d", &NumeroApostado);
        }
        *VetordeApostas = NumeroApostado;
        VetordeApostas++;            
        }
    }
void sorteia_valores(int *sorteio, int n){
    int sorteado, i;
        srand(time(NULL));
    for ( i = 0; i < n; i++){
        sorteado = rand()%100;
        printf("Sorteado: %d\n", sorteado);
        *sorteio = sorteado;
        sorteio++;
    }
}
int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
    int i, j, n = 1, *vetAcertos, *inicioAcertos;
    vetAcertos = (int*)malloc(sizeof(int));
    inicioAcertos = vetAcertos;
    for (i = 0; i < ns; i++){
        for (j = 0; j < na; j++){
            if (aposta[j] == sorteio[i]){
                n+=1;
                vetAcertos = realloc(inicioAcertos,(n*sizeof(int)));
                *vetAcertos = aposta[j];
                vetAcertos++;
                *qtdacertos = *qtdacertos + 1;
            }
        }
    }
    return inicioAcertos;
    free(vetAcertos);
}

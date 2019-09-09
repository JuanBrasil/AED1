#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Data{
    int dia;
    int mes;
    int ano;
};
struct Pessoa{
    char nome[100];
    unsigned long int CPF;
    struct Data Data;
};
typedef struct Pessoa Pessoa;
typedef struct Data Data;
void Preenche_Estrutura(Pessoa *PtrFuncPessoa);
void Imprime_Estrutura(Pessoa *PtrFuncPessoa);
int main(){
    Pessoa *PtrPessoa;
    PtrPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    Preenche_Estrutura(PtrPessoa);
    Imprime_Estrutura(PtrPessoa);
    free(PtrPessoa);
}
void Preenche_Estrutura(Pessoa *PtrFuncPessoa){
    printf("Nome: ");
    fgets(PtrFuncPessoa->nome, 100, stdin);
    printf("CPF: ");
    scanf("%lu", &PtrFuncPessoa->CPF);
    printf("Data de Nascimento: ");
    scanf("%d %d %d", &PtrFuncPessoa->Data.dia, &PtrFuncPessoa->Data.mes, &PtrFuncPessoa->Data.ano);
}
void Imprime_Estrutura(Pessoa *PtrFuncPessoa){
    printf("------------------\n");
    printf("Nome: %s", PtrFuncPessoa->nome);
    printf("CPF: %lu\n", PtrFuncPessoa->CPF);
    printf("Data De Nascimento: %d/%d/%d\n", PtrFuncPessoa->Data.dia, PtrFuncPessoa->Data.mes, PtrFuncPessoa->Data.ano);
}
/******************************************************************************
    Nome: ContagemRegressiva.cpp
    Autor: Sandy Pereira cavalcanti
    data: 22/04/2025
    Descrição: programa para realizar recursividade DIRETA, com o uso de ponteiros e alocação dinâmica de memória.
*******************************************************************************/
#include <stdio.h>
#include <string.h>
// Início da função ContagemRegressiva que realliza recursividade direta
void ContagemRegressiva(int *n){
    if(*n == 0){
        puts("FIM!");
    } else{
        printf("%d |", *n);
        (*n)--;
        ContagemRegressiva(n);
    };
};  // Fim da função ContagemRegressiva
// Início do programa
int main(){
    printf("Contagem Regressiva\n\n");
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d",&n);
    ContagemRegressiva(&n);
};  // Fim do main


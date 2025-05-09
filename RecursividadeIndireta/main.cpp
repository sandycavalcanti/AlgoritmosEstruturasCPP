/******************************************************************************
    Nome: LoginSenha.cpp
    Autor: Sandy Pereira cavalcanti
    data: 12/03/2025    09:50
    Descrição: programa para realizar recursividade INDIRETA para simular Login em um sistema
*******************************************************************************/
// Sessão de Importação
#include <stdio.h>
#include <string.h>
// Sessão de prototipação
void verLogin();
void verSenha();
// Sessão de variaveis globais
char nome[10] = "Sandy";
int senha = 1234;
int tentativa = 1;
int limiteTentativa = 3;
// Inicio do programa
int main(){
    puts("Realizar Login no sistema\n");
    puts("__________________________\n");
    verLogin();
}   //Fim do programa
// inicio da função verLogin, que verifica o login do usuario
void verLogin(){
    fflush(stdin);
    char user[10] = " ";
    printf("Login: ");
    gets(user);
    if(strcmp(user,nome)==0){
        verSenha();
    }else{
        puts("\nLogin incorreto, tente novamente");
        verLogin();
    };
};  // Fim da função verLogin
// Inicio da função verSenha, que verifica a senha do usuario
void verSenha(){    
    int pwd = 0;
    printf("\nSenha: ");
    scanf("%d", &pwd);
    if(pwd == senha){
        puts("Login efetuado com sucesso");  
    }else{
        if(tentativa < limiteTentativa){        
            puts("Senha incorreto, tente novamente");
            tentativa++;
            verSenha();
        }else{
            puts("\nLimite de tentativas atingido!\n");
            tentativa = 0;
            verLogin();
        };
    };
};  // Fim da função verSenha
/******************************************************************************
    Nome: ClienteCaixa.cpp
    Autor: Sandy Pereira cavalcanti
    data: 12/03/2025    09:50
    Descrição: programa para realizar recursividade INDIRETA para simular Login em um sistema
*******************************************************************************/
#include <stdio.h>
#include <string.h>
//Sessão de protótipação
int verNumeroConta(int);
int verSenha();
void depositar();
void verSaldo();
void realizarSaque();
void linha();
// Variáveis globais
char nome[10] = "Sandy";
int numeroConta = 12345;
int senha = 1234;
int status = 0;
int tentativa = 1;
float saldo = 3000;
int limiteTentativa = 3;
// Início do programa
int main(){
    puts("Caixa Eletr�nico\n");
    linha();
    do{
		puts("O que deseja fazer hoje?\n");
		puts("1 - Ver saldo disponivel");
		puts("2 - Realizar saque");
		puts("3 - Depositar");
		puts("0 - Sair do programa");
		scanf("%d", &status);
		switch(status){
			case 1:
				verSaldo();
				linha();
				break;
			case 2:
				realizarSaque();
				linha();
				break;
			case 3:
				depositar();
				linha();
				break;
			defalt:
				break;
		};
	} while(status != 0);
	linha();
	puts("Saindo do programa!");
	linha();   
}   //Fim do programa
// Função para verificar o saldo
void verSaldo(){
	if(verNumeroConta(1)){
		printf("\nSaldo atual: %2.f\n", saldo);
	}else{
		puts("N�o foi possivel verificar o saldo da conta selecionada");
	};
};   //Fim da função verSaldo
// Função para realizar o saque
void realizarSaque(){
	float valorSaque = 0;
	if(verNumeroConta(2)){
		puts("Quanto deseja retirar?");
		scanf("%f", &valorSaque);
		if(valorSaque > saldo){
			printf("Nao � possivel realizar o saque!Valor insuficiente!");
		}else{
			saldo = saldo-valorSaque;
			printf("Saque realizado com sucesso!");
		}
	}else{
		puts("Nao � possivel realizar o saque da conta selecionada");
	};
	
}   //Fim da função realizarSaque
// Função para depositar dinheiro
void depositar(){
	float valorDeposito = 0;
	if(verNumeroConta(3)){
		puts("Quanto deseja depositar?");
		scanf("%f", &valorDeposito);
		if(valorDeposito < 0){
			puts("Nao � possivel realizar saques negativos!");
		}
		saldo = saldo +valorDeposito;
		printf("Saque realizado com sucesso!");
	}else{
		puts("Nao � possivel realizar o saque da conta selecionada");
	};
}	// Fim da função depositar
// Função para verificar o número da conta
int verNumeroConta(int indice){
    fflush(stdin);
    int numero = 0;
    printf("Numero da conta: ");
    scanf("%d", &numero);
    if(numero == numeroConta){
		if(indice == 3){
			return 1;
		}else{
			return verSenha();
		}
    }else{
        puts("\nLogin incorreto, tente novamente");
        verNumeroConta(indice);
    };
};
// Função para verificar a senha
// A senha é verificada através de recursividade direta
int verSenha(){ 
	if(senha == 0){
		linha();
		puts("Conta bloqueada, nao e possivel acessar");
		linha();
		return 0;
	}   
    int pwd = 0;
    printf("\nSenha: ");
    scanf("%d", &pwd);
    if(pwd == senha){
        puts("Login efetuado com sucesso");  
        return 1;
    }else{
		if(tentativa < limiteTentativa){        
			puts("Senha incorreto, tente novamente");
			tentativa++;
			verSenha();
		}else{
			puts("\nLimite de tentativas atingido!\n");
			puts("\Essa conta esta bloqueada\n");
			senha = 0;
			return 0;
		};
    };
};   //Fim da função verSenha
// Função para imprimir uma linha
void linha(){
    puts("\n__________________________\n");
}	// Fim da função linha


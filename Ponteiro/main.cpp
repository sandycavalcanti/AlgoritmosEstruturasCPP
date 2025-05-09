/*
	Nome: Ponteiros.cpp
	Autor: Sandy Pereira Cavalcanti
	Date: 19/03/2025
	Descrição: Programa para explorar os recursos dos Ponteiros
*/
// Sessão de Importação
#include <stdio.h>
// Inicio da função principal
int main(){
	int a, b, c;
	char c1, c2, c3;
	a = 5;
	b = 8;
	c = 10;
	c1 = 'a';
	c2 = 'b';	
	c3 = 'c';
	// Exibe o conteudo das variaveis
	printf("valor variavel A: %d", a);
	printf("\nvalor variavel B: %d", b);
	printf("\nvalor variavel C: %d", c);
	// Exibe o endereço das variaveis
	printf("\n\nEndereço variavel A: %p", &a);
	printf("\nEndereço variavel B: %p", &b);
	printf("\nEndereço variavel C: %p", &c);
	// Exibe o valor dos ponteiro das variaveis
	printf("\n\nValor ponteiro variavel A: %d", &a);
	printf("\nValor ponteiro variavel B: %d", &b);
	printf("\nValor ponteiro variavel C: %d", &c);
	// Exibe o conteudo das variaveis do tipo char
	printf("\n\nValor das variaveis do tipo Char, C1: %c", c1);
	printf("\n\nValor das variaveis do tipo Char, C2: %c", c2);
	printf("\n\nValor das variaveis do tipo Char, C3: %c", c3);	
	// Exibe o endereço das variaveis do tipo char
	printf("\n\nEndereço das variaveis do tipo Char, C1: %p", &c1);
	printf("\nEndereço das variaveis do tipo Char, C2: %p", &c2);
	printf("\nEndereço das variaveis do tipo Char, C3: %p", &c3);
	// Exibe o valor ponteiro das variaveis do tipo char
	printf("\n\nValor ponteiro das variaveis do tipo Char, C1: %d", &c1);
	printf("\nValor ponteiro das variaveis do tipo Char, C2: %d", &c2);
	printf("\nValor ponteiro das variaveis do tipo Char, C3: %d", &c3);
}// fim do programa

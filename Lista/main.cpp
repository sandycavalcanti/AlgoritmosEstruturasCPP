/*
	Nome: ListaLigada.cpp
	Autor: Sandy Pereira Cavalcanti
	Date: 19/03/2025
	Descrição: Implementação de lista ligada (Encadeada)
*/
// Sessão de Importação
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Structs globais
typedef struct Pessoa{
	char *nome;
	int idade;
	float altura;
	struct Pessoa *proximo;
};
typedef struct{
	Pessoa *inicio, *fim;
	int tamanho;
}ListaPessoas;
// Inicio da função InseririnicioLista, que insere um elemento no inicio da lista
void InseririnicioLista(ListaPessoas *lista, char *n, int idade, float altura){
	Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa)); // reserva espaçoo na memóriaem bytes para armazenar um nó(Pessoa)
	novo->nome = n;
	novo->idade = idade;
	novo->altura = altura;
	if(lista->inicio == NULL){ // A lista esta vazia
		novo->proximo = NULL;
		lista->inicio = novo;
		lista->fim = novo;
	}else{ // A lista Não esta vazia
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}
	lista->tamanho++;
	puts("Elemento iserido com sucesso!!");
};// fim da função InseririnicioLista
// Inicio do programa
int main(){
	ListaPessoas pessoas;
	char *nome = "Maria";
	int idade = 34;
	float altura = 1.70;
	InseririnicioLista(&pessoas, nome, idade, altura);
}// fim do programa

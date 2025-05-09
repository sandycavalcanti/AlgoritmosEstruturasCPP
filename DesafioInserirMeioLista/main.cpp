/*
	Nome: DesafioLista.cpp
	Autor: Sandy Pereira Cavalcanti
	Date: 19/03/2025
	Descrição: Implementação de lista ligada (Encadeada)
*/
// Seção de protótipação
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
// Definição de estrutura para armazenar os dados
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
// Funçao para inserir um novo membro no inicio da lista
void inserirInicioLista(ListaPessoas *lista, char *n, int idade, float altura){
	Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa)); // reserva espaço na memória em bytes para armazenar um nó (Pessoa)
	novo->nome = n;
	novo->idade = idade;
	novo->altura = altura;
	if(lista->inicio == NULL){ // a lista esta vazia
		novo->proximo = NULL;
		lista->inicio = novo;
		lista->fim = novo;
	}else{ // a lista NÃo esta vazia
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}
	lista->tamanho++;
	puts("Elemento iserido no inicio com sucesso!!");
};// fim da função InseririnicioLista
// Função para inserir um elemento em ordem alfabética na lista
void inserirMeioLista(ListaPessoas *lista, char *n, int idade, float altura) {
	Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));
	if (!novo) {
		puts("Erro ao alocar memória!");
		return;
	}
	novo->nome = strdup(n);
	novo->idade = idade;
	novo->altura = altura;
	novo->proximo = NULL;
    // Verifica se a lista está vazia ou se o novo elemento deve ser inserido no início( Se ele for menor que o primeiro elemento de acrdo com o strcmp)
	if (lista->inicio == NULL || strcmp(lista->inicio->nome, n) > 0) {
		novo->proximo = lista->inicio;
		lista->inicio = novo;
		if (lista->fim == NULL) lista->fim = novo;
	} else {
		Pessoa *atual = lista->inicio;  // Ponteiro para o nó atual, para ser utilizado no loop
        // Loop para encontrar a posição correta para inserir o novo elemento(Ele utiliza o strcmp para comparar os nomes, se o nome do novo nó for menor que o nome do nó atual, ele insere o novo nó antes do nó atual)
		while (atual->proximo && strcmp(atual->proximo->nome, n) < 0) {
			atual = atual->proximo;
		}
		novo->proximo = atual->proximo;
		atual->proximo = novo;
		if (novo->proximo == NULL) lista->fim = novo;
	}
	lista->tamanho++;
	puts("Elemento inserido em ordem alfabética com sucesso!");
} // fim da função inserirMeioLista
// Função para inserir um elemento no final da lista
void inserirFimLista(ListaPessoas *lista, char *n, int idade, float altura){
	Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));
	novo->nome = n;
	novo->idade = idade;
	novo->altura = altura;
	novo->proximo= NULL;
	if(lista->inicio == NULL){// Se a ista estiver vazia
		lista->inicio = novo;
		lista->fim = novo;
	}else{	//Se a lista NÂO estiver vazia
		lista->fim->proximo = novo;
		lista->fim = novo;
	}
	lista->tamanho++;
	puts("Elemento iserido no fim com sucesso!!");
}// fim da função inserirFimLista
//Função para exibir todo o conteudo da lista
void exibirLista(ListaPessoas *lista){
	// Definindo as cores do console
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	// Salvar os atributos de cores
	GetConsoleScreenBufferInfo(hconsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	Pessoa *inicio = lista->inicio;
	printf("\nTamanho da lista: %d elementos\n", lista->tamanho);
	// Exibir os elementos da lista
	while(inicio != NULL){
		printf("Nome: %s | Idade: %d", &inicio->nome , inicio->idade);
		SetConsoleTextAttribute(hconsole,FOREGROUND_GREEN);
		printf(" -> ");
		SetConsoleTextAttribute(hconsole,saved_attributes);
		inicio = inicio->proximo;
	}
	printf("NULL");
}	// fim da função exibirLista
// Função para retirar um elemento da lista
void retirarElementoLista(ListaPessoas *lista, char *nomeRemover){
	Pessoa *inicio = lista->inicio;	//Ponteiro para o primeiro nó da lista (primeira pessoa)
	Pessoa *pessoaRemover = NULL;
	if(inicio != NULL && lista->inicio->nome == nomeRemover){  //Remove o primeiro elemento a lista
		pessoaRemover = lista->inicio;
		lista->inicio = pessoaRemover->proximo;
		if(lista->inicio == NULL){
			lista->fim = NULL; 
		}
	}
	else{	//Remover nós que estão no fim ou no meio da lista
		while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->nome != nomeRemover){
			inicio = inicio->proximo;
		}
		if(inicio != NULL && inicio->proximo != NULL){
			pessoaRemover = inicio->proximo;
			inicio->proximo = pessoaRemover->proximo;
			if(inicio->proximo == NULL){ 	//Se o ultimo elemento for removido
				lista->fim = inicio;
			}
		}
	}
	if(pessoaRemover){	// Testa se ele é NULL
		free(pessoaRemover); //Libera o espaço de memória rezervado para o nó
		lista->tamanho--;
	}
} // fim da função retirarElementoLista
// Início do programa
int main(){
	ListaPessoas pessoas;
	pessoas.fim = NULL;
	pessoas.inicio = NULL;
	pessoas.tamanho=0;
	char *nome;
	int idade;
	float altura;
	int opc;	// Variavel que ira armazenar a opção do menu
	while(1){	//Looping infinito
		system("cls");	//Clear screen
		puts("1-Inserir no inicio\n2-Inserir no final\n3-Inserir em ordem alfabética\n4-Exibir lista\n4-Remover elemento\n5-sair...\n");
		puts("Selecione a opcao desejada: ");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				puts("INICIO da lista");
				puts("===============");
				printf("Nome: "); scanf("%s", &nome);
				printf("Idade: "); scanf("%d", &idade);
				printf("Altura: "); scanf("%f", &altura);
				inserirInicioLista(&pessoas, nome,idade,altura);
				break;
			case 2:
				puts("FIM da lista");
				puts("===============");
				printf("Nome: "); scanf("%s", &nome);
				printf("Idade: "); scanf("%d", &idade);
				printf("Altura: "); scanf("%f", &altura);
				inserirFimLista(&pessoas,nome,idade,altura);
				break;
            case 3:
                puts("FIM da lista");
                puts("===============");
                printf("Nome: "); scanf("%s", &nome);
                printf("Idade: "); scanf("%d", &idade);
                printf("Altura: "); scanf("%f", &altura);
                inserirMeioLista(&pessoas,nome,idade,altura);
                break;
			case 4:
				exibirLista(&pessoas);
				break;
			case 5:
				printf("Digite o nome da pessoa que você deseja remover da lista: ");
				scanf("%s", &nome);
				retirarElementoLista(&pessoas, nome);
				break;
			case 6: exit(0);
		}	//Fim do switch case
		printf("\nPrecione qualquer tecla para continuar");
		getch();
	} //fim do looping infinito
}// fim do programa

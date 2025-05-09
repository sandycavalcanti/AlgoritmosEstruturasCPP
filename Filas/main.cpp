/*
	Nome: Filas.cpp
	Autor: Sandy Pereira Cavalcanti
	Data: 02/04/2025
	Descrição: Programa para implementar o conceito de Filas  FIFO
*/
// Sessão de Importação
#include <stdio.h>
//Sessão de prototipação
void enqueue(int); //Inserir elemento na fila
int dequeue(); //Retirar elemento da fila
int isFull(); //Testa se a fila esta cheia
int isEmpty(); //Testa se a fila eesta vazia
void showFIFO(); //Exibir conteudo da fila
//Variáveis globais
int inicio, fim, total, tamanho, opcao, senha; //Variaveis para controle da fila
int senhas[7];
// Inicio do programa
int main(){
	inicio = 0;
	fim = 0;
	total=0;
	opcao = 0;
	senha = 0;
	tamanho = sizeof(senhas)/sizeof(int);	// Verifica o tamanho do vetor em bytes senha e divide pelo tamanho em bytes da variavel int, para poder calcular o tamanho do vetor
	printf("Tamanho do vetor %d", tamanho);
//	printf("Tamanho do veor senha em bytes %d", sizeof(senhas));
	do {
		printf("\n================== MENU ==================\n");
		printf("1. Inserir elementos na Fila (enfileirar)\n");
		printf("2. Retirar um elemento da Fila (desenfileirar)\n");
		printf("3. Exibir o conteudo da fila\n");
		printf("4. Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		switch(opcao) {
			case 1:
				printf("\nOpcao Enfileirar selecionada.\n");
				printf("Digite uma senha para adicionar a fila: ");
				scanf("%d", &senha);
				enqueue(senha);
				break;
			case 2:
				printf("\nOpcao Desenfileirar selecionada. Um elemento saiu da fila\n");
				int valor = dequeue();
				printf("O elemento retirado da fila foi: %d\n", valor);
				break;
			case 3:
				printf("\nOpcao Exibir Conteudo selecionada.");
				showFIFO();
				printf("\n");
				break;
			case 4:
				printf("\nSaindo do programa...\n");
				break;
			default:
				printf("Opcao invalida. Tente novamente.\n");
				break;
		}	// Fim do switch menu
	} while(opcao != 4);	// Fim do loop do menu
}	// Fim do programa
//Inserir elemento na fila
void enqueue(int elem){
	if(isFull()==1){
		puts("\nA fila esta cheia :(");
	}else{
		senhas[fim] = elem;
		fim++;
		total++;
	}
};	 // Fim da função enqueue
//Retirar elemento da fila
int dequeue(){
	if(isEmpty()==1){
		puts("\nA lista esta vazia!!");
	}else{
		int elemento = senhas[inicio];
		inicio++;
		total--;
		return elemento;
	};
}; // Fim da função dequeue
//Testa se a fila esta cheia
int isFull(){
	if(total == tamanho){
		return 1;
	}else{
		return 0;
	};
};	// Fim da função isFull
//Testa se a fila esta vazia
int isEmpty(){
	if(total==0){
		return 1;
	}else{
		return 0;
	};
};	// Fim da função isEmpty
//Exibir conteudo da fila
void showFIFO(){
	int contador, i;
	puts("\n\nConteudo da fila:\n");
	for(contador = 0, i = inicio;contador < total; contador++){
		printf("%d |", senhas[i++]);	
	};
};	// Fim da função showFIFO

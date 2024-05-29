#include <stdio.h>
#include <stdlib.h>
#include "../jogar/jogar.h"
#include "../adicionar_palavra/adicionar_palavra.h"


void menu_pos_jogo(){
	char opcao;
	
	printf("Voce deseja: \n\n");
	
	puts("1 - Jogar novamente");
	puts("2 - Adicionar nova palavra");
	puts("0 - Sair");
	
	printf("\nInforme a opcao desejada: ");
	opcao = getchar();
	fflush(stdin);
	
	system("cls");
	
	switch(opcao){
		case '1':
			jogar();
			break;
		case '2':
			adicionar_palavra();
		case '0':
			printf("Jogo Encerrado.");
			exit(1);
			break;
	}	
}

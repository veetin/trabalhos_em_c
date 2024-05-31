#include <stdio.h>
#include <stdlib.h>
#include "../jogar/jogar.h"
#include <string.h>

void menu(){
	int opcao;
	
	printf("JOGO DA FORCA\n\n");
	
	puts("1 - Jogar");
	puts("0 - Sair");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	fflush(stdin);
	system("cls");
	
	switch(opcao){
		case 1:
			jogar();
			break;
		case 0:
			printf("Jogo Encerrado.");
			exit(1);
			break;
	}
}


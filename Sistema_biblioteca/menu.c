#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/area_biblioteca.h"
#include "aluno/area_aluno.h"

void entrar(){
	int opcao;
	printf("Acessar area de:\n");
	printf("1 - Biblioteca\n");
	printf("2 - Aluno\n");
	printf("\n");
	
	printf("0 - Sair\n");
	printf("\n");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	system("cls");
	
	switch(opcao){
		case 1:
			menu_biblioteca();
			break;
		case 2:
			menu_aluno();
			break;
		case 0:
			system("cls");
			printf("Sistema Encerrado.");
			exit(1);
			break;
		default:
			printf("opcao invalida!\n", opcao);
			fflush(stdin);
			system("pause");
			system("cls");
			entrar();	
	}
}

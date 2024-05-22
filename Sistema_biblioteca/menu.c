#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/area_biblioteca.h"
#include "aluno/area_aluno.h"

void entrar(){
	int opcao;
	puts("Acessar area de: ");
	puts("Biblioteca ( 1 )");
	puts("Aluno ( 2 )");
	puts("Sair ( 0 )");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	system("cls");
	
	switch(opcao){
		case 1:
			menu_biblioteca();
			//login_biblioteca();
			break;
		case 2:
			menu_aluno();
			//login_aluno();
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

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "opcoes_agenda.h"


void menu(){
	int opcao;
	
	printf("\nMenu:\n");
	printf("Listar todos os contatos - ( 1 )\n");
	printf("Buscar contato - ( 2 )\n");
	printf("Adicionar contato - ( 3 )\n");
	printf("Excluir contato - ( 4 )\n");
	printf("Sair - ( 0 )\n");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	escolha_usuario(opcao);	
}

int escolha_usuario(int opcao){
	switch(opcao){
		case 1:
			listar_contatos();
			break;
		
		case 2:
			buscar_contato();
			break;
		case 3:
			adicionar_contato();
			break;
		case 4:
			excluir_contato();
			break;
		case 0:
			system("cls");
			printf("Agenda fechada.");
			exit(1);
			break;	
	}
	return 0;	
}


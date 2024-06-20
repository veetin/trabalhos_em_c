#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gerenciar_tarefas.h"
#include "listar_tarefas.h"

void menu(){
	char opcao;
	printf("Menu da lista de tarefas:\n");
	printf("1 - Cadastrar uma nova tarefa\n");
	printf("2 - Listar tarefas pendentes\n");
	printf("3 - Listas tarefas concluidas\n");
	printf("4 - Deletar uma tarefa\n");
	printf("5 - Concluir uma tarefa\n");
	printf("\n");
	
	printf("0 - Sair\n");
	printf("\n");
	
	printf("Informe a opcao desejada: ");
	opcao = getchar();
	fflush(stdin);
	system("cls");

	switch(opcao){
		case '1':
			cadastrar_tarefa();
			break;
		case '2':
			listar_tarefas(false);
			break;
		case '3':
			listar_tarefas(true);
			break;
		case '4':
			deletar_tarefa();
			break;
		case '5':
			concluir_tarefa();
			break;
		case '0':
			system("cls");
			printf("Sistema Encerrado.");
			exit(1);
			break;
		default:
			printf("opcao '%c' invalida!\n", opcao);
			fflush(stdin);
			system("pause");
			system("cls");
			menu();
	} 
}


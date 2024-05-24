#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../menu.h"

void listar_alunos(){
	// abrindo o arquivo txt
	FILE *alunos;
	alunos = fopen("alunos.txt", "r");
	
	// verificando se o arquivo existe
	if(alunos == NULL){
		system("cls"); 
		printf("\nVoce nao possui alunos cadastrados!\n\n");
		system("pause");
		menu_aluno();		
	}
	
	// listando alunos
	system("cls");
	
	printf("-------------------\n");
	printf("| Lista de Alunos |\n");
	printf("-------------------\n");
	
	char lista_alunos[100];
	int i;
	i = 1;
	while(fgets(lista_alunos, sizeof(lista_alunos), alunos) != NULL){
		if(i == 5){
			printf("-------------------");
			i = 0;
		}
		printf("%s", lista_alunos);
		i++;
	}
	
	// fecha o alunos.txt e volta para o menu
	fclose(alunos);
	
	system("pause");
	system("cls");
	menu_aluno();	
}


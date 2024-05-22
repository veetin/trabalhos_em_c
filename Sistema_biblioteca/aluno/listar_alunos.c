#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../menu.h"

void listar_alunos(){
	// abrindo o arquivo txt
	FILE *alunos;
	alunos = fopen("alunos.txt", "r");
	
	// Verificando se o arquivo existe.
	
	if(alunos == NULL){
		system("cls"); 
		printf("\nVoce nao possui alunos cadastrados!\n\n");
		system("pause");
		menu_aluno();		
	}
	
	// listando contatos
	system("cls");
	printf("\nListando alunos...\n\n");
	
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
	
	// fecha a agenda e volta para o menu
	fclose(alunos);
	printf("\n");
	system("pause");
	system("cls");
	menu_aluno();	
}


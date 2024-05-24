#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "area_aluno.h"

void livros_disponiveis(){
	FILE *catalogo_livros;
	catalogo_livros = fopen("catalogo_livros.txt", "r");
	
	int i;
	char nome_livro[100], categoria[100], lancamento[100], situacao[12], vazia[2];
	
	if(catalogo_livros == NULL){
		printf("Sem livros disponiveis no catalogo\n");
		fclose(catalogo_livros);
		system("pause");
		system("cls");
		menu_aluno();
	}
	
	printf("----------------------\n");
	printf("| Livros Disponiveis |\n");
	printf("----------------------\n");
	
	while(fgets(nome_livro, sizeof(nome_livro), catalogo_livros) != NULL){
		char situacao_temp[100];
		
		fgets(categoria, sizeof(categoria), catalogo_livros);
		fgets(lancamento, sizeof(lancamento), catalogo_livros);
		fgets(situacao, sizeof(situacao), catalogo_livros);
		
		strcpy(situacao_temp, situacao);
		strtok(situacao_temp, "\n");
		
		//a função strcmp retorna 0 se as strings forem iguais
		if(strcmp(situacao_temp, "disponivel") == 0){
			printf(nome_livro);
			printf(categoria);
			printf(lancamento);
			printf(situacao);
			printf("------------------\n");
		}
		
		fgets(vazia, sizeof(vazia), catalogo_livros);
	}
	
	fclose(catalogo_livros);
	
	system("pause");
    system("cls");
    menu_aluno();
}


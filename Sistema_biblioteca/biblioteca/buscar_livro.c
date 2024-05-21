#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "area_biblioteca.h"

void buscar_livro(){
	
	// abrindo arquivo txt
	FILE *catalogo_livros;
	catalogo_livros = fopen("catalogo_livros.txt", "r");
	
	// verificando se o arquivo existe 
	if(catalogo_livros == NULL){
		printf("\nCatalogo de livros vazio\n");
		fclose(catalogo_livros);
		system("pause");
		system("cls");
		menu_biblioteca();
	}
	
	// salvando escolha do usuario entre nome ou cpf
	char nome_livro[100], livro[100];
	
	bool livro_nao_encontrado;
	int i;
	
	// pedindo o nome do contato
	printf("Informe o nome do livro: ");
	fgets(nome_livro, sizeof(nome_livro), stdin);
	fflush(stdin);
	
	system("cls");
	
	livro_nao_encontrado = true;
	
	while(fgets(livro, sizeof(livro), catalogo_livros) != NULL){

		// verificando se o nome digitado pelo usuario e o contato são iguais
		if(strcmp(nome_livro, livro) == 0 ){
			livro_nao_encontrado = false;
			printf("Livro encontrado:");
			printf("\n-------------------");
			
			// listando as informações do respectivo contato.
			printf("\n%s", livro);
			for(i = 0; i<=2; i++){
				fgets(livro, sizeof(livro), catalogo_livros);
				printf("%s", livro);
			}
			printf("-------------------\n");
		}

	}
	
	// verificnado se a condição contato não encontrado é verdadeira.
	if(livro_nao_encontrado){
		fclose(catalogo_livros);
		printf("Livro nao encontrado!\n\n");
	}					
	
	fclose(catalogo_livros);
	system("pause");
	system("cls");
	menu_biblioteca();

}

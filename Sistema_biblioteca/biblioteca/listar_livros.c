#include <stdio.h>
#include <stdlib.h>
#include "area_biblioteca.h"

void listar_livros(){
	FILE *catalogo_livros;
	catalogo_livros = fopen("catalogo_livros.txt", "r");
	
	int i;
	char livro[100];
	
	if(catalogo_livros == NULL){
		printf("Sem livros no catalogo\n");
		fclose(catalogo_livros);
		system("pause");
		system("cls");
		menu_biblioteca();
	}
	
	printf("-------------------\n");
	printf("| Lista de Livros |\n");
	printf("-------------------\n");
	
	while(fgets(livro, sizeof(livro), catalogo_livros) != NULL){
		printf("%s", livro);
		printf("------------------\n");
		
		for(i = 0; i <= 3; i++){
			fgets(livro, sizeof(livro), catalogo_livros);
		}
	}
	
	fclose(catalogo_livros);
	
	system("pause");
    system("cls");
    menu_biblioteca();
}


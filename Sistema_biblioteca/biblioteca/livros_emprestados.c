#include <stdio.h>
#include <stdlib.h>
#include "area_biblioteca.h"

void livros_emprestados(){
	
	FILE *catalogo_livros;
	catalogo_livros = fopen("livros_emprestados.txt", "r");
	
 	int i;
	char livro[100];
	
	if(catalogo_livros == NULL){
		printf("Sem livros emprestados\n");
		fclose(catalogo_livros);
		system("pause");
		system("cls");
		menu_biblioteca();
	}
	
	
	printf("--------------------------------\n");
	printf("| Lista de livros emprestados: |\n");
	printf("--------------------------------\n");
	
	while(fgets(livro, sizeof(livro), catalogo_livros) != NULL){
		
		for(i = 0; i <= 1; i++){
			printf("%s", livro);
			fgets(livro, sizeof(livro), catalogo_livros);
			
		}
		puts("------------------");
		
	}
	
	fclose(catalogo_livros);	
		
}


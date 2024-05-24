#include <stdio.h>
#include <stdlib.h>
#include "area_biblioteca.h"

void adicionar_livro(){
    FILE *catalogo_livros;
    catalogo_livros = fopen("catalogo_livros.txt", "a");

    char nome[100], categoria[100], data_lancamento[100], situacao[12] = "disponivel";	
    
	// se o catalogo_livros não existir ele cria o catalogo_livros em 'w'
    if(catalogo_livros == NULL){
        fclose(catalogo_livros);
        catalogo_livros = fopen("catalogo_livros.txt", "w");
    }

	// nome do livro
    printf("Nome do livro: ");
    fgets(nome, 100, stdin);
    fflush(stdin);
    system("cls");

	// categoria
    printf("Categoria: ");
    fgets(categoria, 100, stdin);
    fflush(stdin);
    system("cls");
	
	// data de lancamento
    printf("Data de lancamento -> (dd-mm-aaaa): ");
    scanf("%s", &data_lancamento);
    system("cls");
    
    // adicionando as informações no arquivo txt
	fprintf(catalogo_livros,"%s",nome);
	fprintf(catalogo_livros,"%s",categoria);
	fprintf(catalogo_livros,"%s\n",data_lancamento);
	fprintf(catalogo_livros,"%s\n\n",situacao);
	
    system("cls");
    printf("Livro inserido com sucesso!\n\n");
	
	fclose(catalogo_livros);

    system("pause");
    system("cls");
    menu_biblioteca();
}


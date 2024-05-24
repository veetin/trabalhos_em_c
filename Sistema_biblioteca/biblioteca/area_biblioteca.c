#include <stdio.h>
#include <stdlib.h>
#include "listar_livros.h"
#include "adicionar_livro.h"
#include "buscar_livro.h"
#include "livros_emprestados.h"


void menu_biblioteca(){
	int opcao;
	
	printf("Menu:\n");
	printf("1 - Cadastrar livro\n");
	printf("2 - Listar todos os livros\n");
	printf("3 - Buscar por livros\n");
	printf("4 - Listar livros emprestados\n");
	printf("\n");
	
	printf("0 - Voltar\n");
	printf("\n");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	switch(opcao){
		case 1:
			adicionar_livro();
			break;
		case 2:
			listar_livros();
			break;
		case 3:
			buscar_livro();
			break;
		case 4:
			livros_emprestados();
			break;
		case 0:
			system("cls");
			entrar();
			break;
			
	}
}

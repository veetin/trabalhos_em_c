#include <stdio.h>
#include <stdlib.h>
#include "listar_livros.h"
#include "adicionar_livro.h"
#include "buscar_livro.h"
#include "livros_emprestados.h"


void menu_biblioteca(){
	int opcao;
	
	printf("\nMenu:\n");
	printf("Cadastrar livro - ( 1 )\n");
	printf("Listar todos os livros - ( 2 )\n");
	printf("Buscar por livros - ( 3 )\n");
	printf("Listar livros emprestados - ( 4 )\n");
	printf("Voltar - ( 0 )\n");
	
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

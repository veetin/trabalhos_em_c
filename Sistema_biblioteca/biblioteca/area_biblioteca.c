#include <stdio.h>
#include <stdlib.h>

void menu_biblioteca(){
	int opcao;
	
	printf("\nMenu:\n");
	printf("Cadastrar livro - ( 1 )\n");
	printf("Listar livros - ( 2 )\n");
	printf("Buscar por livros - ( 3 )\n");
	printf("Listar livros emprestados - ( 4 )\n");
	printf("Sair - ( 0 )\n");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	switch(opcao){
		case 1:
			//cadastrar_livros();
			break;
		
		case 2:
			//listar_livros();
			break;
		case 3:
			//adicionar_contato();
			break;
		case 4:
			//buscar_livros()
			break;
		case 0:
			system("cls");
			printf("Sistema Encerrado.");
			exit(1);
			break;	
	}
}

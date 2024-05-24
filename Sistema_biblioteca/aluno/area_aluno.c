#include <stdio.h>
#include <stdlib.h>
#include "cadastrar_aluno.h"
#include "listar_alunos.h"
#include "../menu.h"

void menu_aluno(){
	int opcao;
	
	printf("Menu:\n");
	printf("1 - Cadastrar aluno\n");	
	printf("2 - Emprestimo de livro \n");
	printf("3 - Devolver livro\n");
	printf("4 - Listar alunos\n");
	printf("5 - Livros disponiveis\n");
	printf("\n");
	
	printf("0 - Voltar\n");
	printf("\n");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	switch(opcao){
		case 1:
			cadastrar_aluno();
			break;
		
		case 2:
			emprestimo_livro();
			break;
		case 3:
			devolver_livro();
			break;
		case 4:
			listar_alunos();
			break;
		case 5:
			livros_disponiveis();
			break;
		case 0:
			system("cls");
			entrar();
			break;	
	}
}

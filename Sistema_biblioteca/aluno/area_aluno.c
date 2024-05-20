#include <stdio.h>
#include <stdlib.h>

void menu_aluno(){
	int opcao;
	
	printf("\nMenu:\n");
	printf("Cadastrar aluno - ( 1 )\n");
	printf("Emprestimo de livro - ( 2 )\n");
	printf("Devolver livro - ( 3 )\n");
	printf("Listar alunos - ( 4 )\n");
	printf("Livros disponiveis - ( 5 )\n");
	printf("Sair - ( 0 )\n");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	switch(opcao){
		case 1:
			//cadastrar_aluno();
			break;
		
		case 2:
			//emprestimo_livro();
			break;
		case 3:
			//devolver_livro();
			break;
		case 4:
			//listar_alunos()
			break;
		case 5:
			//livros_disponiveis()
			break;
		case 0:
			system("cls");
			printf("Sistema Encerrado.");
			exit(1);
			break;	
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//verifica se o aluno existe
int validar_aluno(char aluno[100]){
	FILE *lista_alunos;
	lista_alunos = fopen("alunos.txt", "r");
	
	char aluno_controle[100];
	
	while(fgets(aluno_controle, sizeof(aluno_controle), lista_alunos) != NULL){
		if(!(strcmp(aluno_controle, aluno))){
			fclose(lista_alunos);
			return situacao_aluno(aluno);
		}
	}
	
	printf("O aluno '%s' nao existe!\n", strtok(aluno, "\n"));
	fclose(lista_alunos);
	return 1;
}

//verifica se o aluno ja possui um livro emprestado
int situacao_aluno(char aluno[100]){
	FILE *livros_emprestados;
	livros_emprestados = fopen("livros_emprestados.txt", "r");
	
	char aluno_controle[100];
	
	while(fgets(aluno_controle, sizeof(aluno_controle), livros_emprestados) != NULL){
		if(!(strcmp(aluno_controle, aluno))){
			fclose(livros_emprestados);
			printf("O aluno '%s' ja possui um livro emprestado!\n", strtok(aluno, "\n"));
			return 1;
		}
	}
	
	fclose(livros_emprestados);
	return 0;
}

//verificando se o livro existe
int validar_livro(char livro[100]){
	FILE *catalogo_livros;
	catalogo_livros = fopen("catalogo_livros.txt", "r");
	
	char livro_controle[100];
	
	while(fgets(livro_controle, sizeof(livro_controle), catalogo_livros) != NULL){
		if(!(strcmp(livro_controle, livro))){
			fclose(catalogo_livros);
			return situacao_livro(livro);
		}
	}
	
	printf("O livro '%s' nao existe!\n", strtok(livro, "\n"));
	fclose(catalogo_livros);
	return 1;
}

//verifica se o livro ja foi emprestado
int situacao_livro(char livro[100]){
	FILE *livros_emprestados;
	livros_emprestados = fopen("livros_emprestados.txt", "r");
	
	char livro_controle[100];
	
	while(fgets(livro_controle, sizeof(livro_controle), livros_emprestados) != NULL){
		if(!(strcmp(livro_controle, livro))){
			fclose(livros_emprestados);
			printf("O livro '%s' ja esta emprestado para outro aluno!\n", strtok(livro, "\n"));
			return 1;
		}
	}
	
	fclose(livros_emprestados);
	return 0;
}


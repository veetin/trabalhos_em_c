#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verificacoes/verificacoes.h"

//funcao principal do emprestimo
void emprestimo_livro(){
	char aluno[100], livro[100];
	
	printf("Informe o nome do aluno: ");
	fgets(aluno, sizeof(aluno), stdin);
	fflush(stdin);
	system("cls");
	
	if(validar_aluno(aluno)){
		system("pause");
		system("cls");
		menu_aluno();
	}
	
	printf("Informe o nome do livro: ");
	fgets(livro, sizeof(livro), stdin);
	fflush(stdin);
	system("cls");
	
	if(validar_livro(livro)){
		system("pause");
		system("cls");
		menu_aluno();
	}
	
	FILE *livros_emprestados;
	livros_emprestados = fopen("livros_emprestados.txt", "a");
	
	fprintf(livros_emprestados,"%s",aluno);
	fprintf(livros_emprestados,"%s\n",livro);
	
	fclose(livros_emprestados);
	
	// trocando a situação do livro no catalogo
	char nome_livro[100], categoria[100], lancamento[100], situacao[12] = "emprestado", linha[100];
	
	FILE *catalogo_livros, *catalogo_temp;
	
	catalogo_livros = fopen("catalogo_livros.txt", "r");
	catalogo_temp = fopen("catalogo_temp.txt", "w");
	
	int i;
	strtok(livro, "\n");
	
	while(fgets(linha, sizeof(linha), livros_emprestados) != NULL){
		char livro_temp[100];
		strcpy(livro_temp, linha);
		strtok(livro_temp, "\n");
		
		if(strcmp(livro_temp, livro) == 0){
    		// pula as linhas com os dados do contato
			for(i = 0; i<=3; i++){
				fgets(livro_temp, sizeof(livro_temp), catalogo_livros);
				switch(i){
					case 0:
						strcpy(categoria, livro_temp);
						break;
					case 1:
						strcpy(lancamento, livro_temp);
						break;
				}
			}
    	} else {
			// copia cada aluno não encontrado para o arquivo catalogo_temp
			fputs(linha, catalogo_temp);
			
			// coloca as linhas com os dados no arquivo catalogo_temp
			for(i = 0; i<=2; i++){
				fgets(linha, sizeof(linha), catalogo_livros);
				fputs(linha, catalogo_temp);
				
			}
			fputs("\n", catalogo_temp);
			fgets(linha, sizeof(linha), catalogo_livros);
		}
	}
	
	fprintf(catalogo_temp, "%s\n", livro);
	fprintf(catalogo_temp, "%s", categoria);
	fprintf(catalogo_temp, "%s", lancamento);
	fprintf(catalogo_temp, "%s\n\n", situacao);
	
	fclose(catalogo_livros);	
	fclose(catalogo_temp);
	
	// exclui arquivo original
	remove("catalogo_livros.txt");
	
	// renomeia o arquivo temp para se tornar o principal
	rename("catalogo_temp.txt", "catalogo_livros.txt");
	
	printf("Livro '%s' foi emprestado para '%s'", livro, strtok(aluno, "\n"));

	printf("\n\n");
		
	system("pause");
    system("cls");
    menu_aluno();
}


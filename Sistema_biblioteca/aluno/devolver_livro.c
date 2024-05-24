#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void devolver_livro(){
	int i;
	char aluno[100], livro[100];
	bool devolvido = false;
	
	printf("Informe o nome do aluno: ");
	fgets(aluno, sizeof(aluno), stdin);
	fflush(stdin);
	system("cls");
	
	printf("Informe o nome do livro: ");
	fgets(livro, sizeof(livro), stdin);
	fflush(stdin);
	system("cls");
	
	FILE *livros_emprestados, *livros_emprestados_temp;
	livros_emprestados = fopen("livros_emprestados.txt", "r");
	livros_emprestados_temp = fopen("livros_emprestados_temp.txt", "w");
	
	// trocando a situação do livro no livros_emprestados
	char aluno_linha[100], livro_linha[100], vazia[2];
	
	while(fgets(aluno_linha, sizeof(aluno_linha), livros_emprestados) != NULL){
		char aluno_temp[100], livro_temp[100];
		
		fgets(livro_linha, sizeof(livro_linha), livros_emprestados);
		fgets(vazia, sizeof(vazia), livros_emprestados);
		
		// verifica se os nomes são DIFERENTES
		if(strcmp(aluno_linha, aluno) != 0 && strcmp(livro_linha, livro) != 0){
			// copia cada aluno e livro DIFERENTE DO DIGITADO para o arquivo livros_emprestados_temp
			fputs(aluno_linha, livros_emprestados_temp);
			fputs(livro_linha, livros_emprestados_temp);
			
			fputs("\n", livros_emprestados_temp);
		} else {
			devolvido = true;
			break;
		}
	}
	
	fclose(livros_emprestados);	
	fclose(livros_emprestados_temp);
	
	// trocando a situação do livro no catalogo
	char linha[100];
	
	if(devolvido == true){
		FILE *catalogo_livros, *catalogo_temp;
		catalogo_livros = fopen("catalogo_livros.txt", "r");
		catalogo_temp = fopen("catalogo_temp.txt", "w");
		
		while(fgets(livro_linha, sizeof(livro_linha), catalogo_livros) != NULL){
			char livro_temp[100];
			
			fprintf(catalogo_temp, "%s", livro_linha);
			
			if(!(strcmp(livro_linha, livro))){
				for(i = 0; i <= 1; i++){
					fgets(linha, sizeof(linha), catalogo_livros);
					fprintf(catalogo_temp, "%s", linha);
				}
				fprintf(catalogo_temp, "%s\n", "disponivel");
				fgets(linha, sizeof(linha), catalogo_livros);
				fgets(vazia, sizeof(vazia), catalogo_livros);
				fprintf(catalogo_temp, "%s", vazia);
			} else {
				for(i = 0; i <= 3; i++){
					fgets(linha, sizeof(linha), catalogo_livros);
					fprintf(catalogo_temp, "%s", linha);
				}
			}
		}
		
		printf("Livro '%s' foi devolvido por '%s'", strtok(livro, "\n"), strtok(aluno, "\n"));
		
		fclose(catalogo_livros);
		fclose(catalogo_temp);
		
		// exclui(remove) os arquivos originais e renomeia(rename) os arquivos temp para se tornarem os principais
		remove("catalogo_livros.txt");
		rename("catalogo_temp.txt", "catalogo_livros.txt");
	
		remove("livros_emprestados.txt");
		rename("livros_emprestados_temp.txt", "livros_emprestados.txt");
	} else {
		printf("Livro %s nao foi pego emprestado por %s", strtok(livro, "\n"), strtok(aluno, "\n"));
		
		// exclui(remove) o arquivo livros_emprestados_temp
		remove("livros_emprestados_temp.txt");
	}

	printf("\n\n");
		
	system("pause");
    system("cls");
    menu_aluno();
}


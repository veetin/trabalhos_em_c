#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void buscar_palavra(char texto[1001]){
	FILE *arquivo;
	
	arquivo = fopen("texto.txt", "r");
	
	char palavra[100], linha[100];
	int count,i, encontrado = 0;
	
	printf("Informe o nome da palvara: ");
	scanf("%s", palavra);
	
	system("cls");
	count = 0;
	//lendo as linhas do arquivo txt
	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		// buscando a ocorrencia da palavra informada pelo usuario
		if(strstr(linha ,palavra) != NULL){
			count++;
			encontrado = 1;
		}
	}
	
	
	if(encontrado){
		printf("Quantidade de ocorrencias da palavra '%s' foi de %d vezes\n\n", palavra, count-1);
		
	}else{
		puts("palavra não encontrada\n\n");
	}
	
	
	
	system("pause");
	system("cls");
}

void menu(){
	FILE *arquivo;
	char c, opcao, palavra_texto[100], texto[1001];
	int i;
	
	arquivo = fopen("texto.txt", "r");
	
	
	if(arquivo == NULL){
		system("cls");
		puts("Arquivo nao encontrado");
		exit(1);
	}
	
	i=0;
	
	// listando palavras
	// EOF -> End Of File
	while((fscanf(arquivo, "%s", palavra_texto)) != EOF){ 
		printf("%s ", palavra_texto);
	}
	

	
	fclose(arquivo);	
	
	puts("\n\nDeseja ver a quantidade de ocorrencias de uma palavra?\n");
	puts("[ 1 ] - Sim");
	puts("[ 0 ] - Nao");
	printf("\nInforme a opcao escolhida: ");
	
	opcao = getchar();
	
	system("cls");
	
	switch(opcao){
		case '1':
			system("cls");
			buscar_palavra(texto);
			break;
		case '0':
			system("cls");
			puts("Programa encerrado!");
			exit(1);
			break;
	}
	
}



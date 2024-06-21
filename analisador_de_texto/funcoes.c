#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void palavras_diferentes() {
   FILE *arquivo;
    arquivo = fopen("texto.txt", "r");
    
    // verificando se o arquivo existe
    if (arquivo == NULL) {
        puts("Erro ao abrir o arquivo");
        exit(1);
    }
    
    char dicionario[1000][100], palavra[100];
    
    int i, j;
    
    i = 0;
    
    bool encontrada;
    
    while(fscanf(arquivo, "%s", palavra) == 1){
        encontrada = false;
        
        // verifica se a palavra ja esta no dicionário
        for (j = 0; j < i; j++){
            if (!(strcmp(dicionario[j], palavra))){
                encontrada = true;
                break;
            }
        }
        
        // se a palavra não foi encontrada, adiciona no dicionário
        if (!encontrada) {
            strcpy(dicionario[i], palavra);
            i++;
        }
    }
    
    fclose(arquivo); 
    
    // printa as palavras armazenadas no dicionário
    puts("Palavras Distintas: ");
	for (j = 0; j < i; j++) {
        printf("%s\n", dicionario[j]);
    }
    
    
	system("pause");
	system("cls");
}

void buscar_palavra() {
    char palavra[100], palavra_busca[100];
    bool encontrado = false;
    int ocorrencias = 0;
    int i;
    
	printf("Informe a palvara: ");
	scanf("%s", palavra);
    
    FILE *arquivo;
    arquivo = fopen("texto.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de texto.\n");
        exit(1);
    }
    
    // percorre o arquivo lendo palavra por palavra
    while (fscanf(arquivo, "%s", palavra_busca) != EOF) {
        // verifica se a palavra encontrada eh igual a palavra de busca
        if (!(strcmp(palavra, palavra_busca))) {
            ocorrencias++;
            encontrado = true;
        }
    }
    
    fclose(arquivo);
    
    if (encontrado) {
    	printf("A palavra '%s' aparece %d vezes no texto.\n", palavra, ocorrencias);
	} else {
		printf("A palavra '%s' nao aparece no texto.\n");	
	}
	
	system("pause");
	system("cls");
}

void menu(){
	FILE *arquivo;
	char c, opcao, palavra_texto[100], texto[1001];
	int qtd_char = 0;
	
	arquivo = fopen("texto.txt", "r");
	
	if(arquivo == NULL){
		system("cls");
		puts("Arquivo nao encontrado");
		exit(1);
	}
	
	// Verificando se o texto possui mais de 1000 caracteres
	while(c = fgetc(arquivo) != EOF){
		qtd_char++;
	}
	
	// volto pro inicio do txt
	rewind(arquivo);
	
	// verifica se o texto está no limite de caracteres
	if(qtd_char > 1000){
		puts("Texto muito grande");
		puts("Informe um texto menor de ate 1000 caracteres");
		exit(1);
	}
	
	// printando o texto na tela
	// EOF -> End Of File
	puts("Texto: \n");
	while((fscanf(arquivo, "%s", palavra_texto)) != EOF){ 
		printf("%s ", palavra_texto);
	}
	puts("\n");
	fclose(arquivo);	
	
	puts("\n");
	puts("[ 1 ] - Listar palavras diferentes");
	puts("[ 2 ] - Buscar quantidade de ocorrencias de uma palavra");
	puts("[ 0 ] - Sair");
	printf("\nInforme a opcao escolhida: ");
	
	opcao = getchar();
	
	system("cls");
	
	switch(opcao){
		case '1':
			system("cls");
			palavras_diferentes();
			break;
		case '2':
			system("cls");
			buscar_palavra();
			break;
		case '0':
			system("cls");
			puts("Programa encerrado!");
			exit(1);
			break;
	}
}


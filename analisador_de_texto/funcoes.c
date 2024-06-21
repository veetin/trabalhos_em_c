#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int palavra_impressa(char palavra_texto[], FILE *palavras_unicas) {
    // retorna para o início do arquivo
	rewind(palavras_unicas);
    
    char palavra[100];
    
	// EOF -> End Of File
    while (fscanf(palavras_unicas, "%s", palavra) != EOF) {
        if (strcmp(palavra, palavra_texto) == 0) {
            return 1;
        }
    }
    
    return 0;
}

void listar_palavras_diferentes() {
    char palavra_texto[100];
    int i;
    
    FILE *texto, *palavras_unicas;
    
    texto = fopen("texto.txt", "r");
    if (texto == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    
    palavras_unicas = fopen("palavras_unicas.txt", "w");
    
    if (palavras_unicas == NULL) {
        printf("Erro ao criar o arquivo de palavras unicas.\n");
        exit(1);
    }
    
	// EOF -> End Of File
    // percorre o arquivo lendo palavra por palavra
    while (fscanf(texto, "%s", palavra_texto) != EOF) {
        // verifica se a palavra já foi impressa
        if (!palavra_impressa(palavra_texto, palavras_unicas)) {
            // imprime a palavra no arquivo de palavras unicas
			fprintf(palavras_unicas, "%s\n", palavra_texto);
        }
    }
    
    fclose(texto);
    fclose(palavras_unicas);
    
    // Exibe as palavras únicas
    palavras_unicas = fopen("palavras_unicas.txt", "r");
    printf("Palavras diferentes no texto:\n");
    
    while (fscanf(palavras_unicas, "%s", palavra_texto) != EOF) {
        printf("%s\n", palavra_texto);
    }
    
    fclose(palavras_unicas);
    
	system("pause");
	system("cls");
    main();
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
        if (strcmp(palavra, palavra_busca) == 0) {
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
	main();
}

void menu(){
	FILE *arquivo;
	char c, opcao, palavra_texto[100], texto[1001];
	
	arquivo = fopen("texto.txt", "r");
	
	if(arquivo == NULL){
		system("cls");
		puts("Arquivo nao encontrado");
		exit(1);
	}
	
	// listando palavras
	// EOF -> End Of File
	while((fscanf(arquivo, "%s", palavra_texto)) != EOF){ 
		printf("%s ", palavra_texto);
	}
	
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
			listar_palavras_diferentes();
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


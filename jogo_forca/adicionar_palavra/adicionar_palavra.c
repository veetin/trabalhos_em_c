#include <stdio.h>
#include <stdlib.h>
#include "../menu/menu.h"
#include "../helpers/helpers.h"

void adicionar_palavra() {
	FILE *lista_palavras;
	char palavra[100];
	lista_palavras = fopen("lista_palavras.txt", "a");
	
	puts("Adicionar nova palavra\n");
	
	printf("Informe a palavra desejada: ");
	scanf("%s", &palavra);
	
	// colocando palavra inteira em lowercase
	palavra_to_lowercase(palavra);
	
	fprintf(lista_palavras, "%s\n", palavra);
	fclose(lista_palavras);
	
	system("cls");
	puts("Palavra adicionada com sucesso\n");
	system("pause");
	system("cls");
	
	menu();
}


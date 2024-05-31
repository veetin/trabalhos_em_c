#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void sortear_palavra(char palavra[100]){
	FILE *lista_palavras;
	char linha[100];
	int qtd_palavras, posicao_aleatoria, i;
	
	// abrindo a lista de palavras
	lista_palavras = fopen("lista_palavras.txt", "r");

	qtd_palavras = 1;
	
	// conta a quantidade de palavras
	while(fgets(linha, sizeof(linha), lista_palavras) != NULL){
		qtd_palavras++;
	}
	fclose(lista_palavras);
	
	// excluindo a ultima linha
	qtd_palavras--;
	
	// gera um numero aleatorio entre 1 e qtd_palavras
	srand(time(NULL));
	posicao_aleatoria = rand() % qtd_palavras+1;
	
	lista_palavras = fopen("lista_palavras.txt", "r");
	
	// percorrendo a lista até o indice da palavra sorteada
	for(i = 1; i <= posicao_aleatoria; i++){
		fgets(linha, sizeof(linha), lista_palavras);
	}
	
	// removendo a quebra de linha e copiando para o vetor externo
	strtok(linha,"\n");
	strcpy(palavra, linha);
	
	fclose(lista_palavras);
}


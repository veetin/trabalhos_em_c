#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int verificar_letra(char palavra[100], char tentativa, char letras_certas[100]) {
	int i;
	
	// variavel de controle para verificar se a letra foi ou não encontrada
	bool letra_nao_encontrada = true;
	
	// letra nao encontrada
	for (i = 0; i < strlen(letras_certas); i++) {
		// compara cada letra da palavra secreta com a letra informada pelo usuario
		if (palavra[i] == tentativa) {
			// troca o '_' na posicao onde a letra foi encontrada
			letras_certas[i] = tentativa;
			// informa que uma letra foi encontrada
			letra_nao_encontrada = false;
		}
	}
	
	// caso a letra não for encontrada ele retorna 1
	if (letra_nao_encontrada == true) {
		return 1;
	}
	
	// se a letra for encontrada retorna 0;
	return 0;
}


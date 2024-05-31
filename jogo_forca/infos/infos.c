#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void infos(int chances, char letras_erradas[5], bool fim_jogo) {
	int i;
	
	//informa as chances do usuario
	printf("Chances restantes: %d\n", chances);
	
	if (fim_jogo == true && chances == 5) {
		printf("Nenhuma letra errada!");
	} else {
		//informa as letras erradas do usuario
		printf("Letras erradas: ");
		
		for (i = 0; i <= strlen(letras_erradas); i++) {
			printf("%c ", letras_erradas[i]);
		}		
	}
}


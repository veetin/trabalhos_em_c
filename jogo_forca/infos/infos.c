#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void infos(int chances, char letras_erradas[5]){
	int i;
	//informa as chances do usuario
	printf("chances: %d\n", chances);
	
	//informa as letras erradas do usuario
	printf("letras erradas: ");
	for(i = 0; i <= strlen(letras_erradas); i++){
		printf("%c ", letras_erradas[i]);
	}
}


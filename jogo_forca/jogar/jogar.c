#include <stdio.h>
#include <stdlib.h>

void jogar(){
	int i;
	char palavra[100];
	FILE *palavras;
	
	palavras = fopen("arquivos/palavras_forca.txt", "r");
	
	if (palavras == NULL) {
		printf("Arquivo vazio!");
    	fclose(palavras);
    	return;
	}
	
	for(i = 0; i < sizeof(palavras); i++){
		if(fgets(palavra, sizeof(palavra), palavras) != NULL) {
			printf("%s", palavra);
		};
	}
	
    fclose(palavras);
}


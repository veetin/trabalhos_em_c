#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// coloca palavra em lowercase
void palavra_to_lowercase(char *palavra) {
	int i;
	
	// pega cada letra da palavra e coloca em lowercase
	for (i = 0; palavra[i]; i++) {
		palavra[i] = tolower(palavra[i]);
	}
}


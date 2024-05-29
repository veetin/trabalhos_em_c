#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../sortear_palavra/sortear_palavra.h"
#include "../tabuleiro/tabuleiro.h"
#include "../verificar_letra/verificar_letra.h"

void jogar(){
	char palavra[100], letras_erradas[5], letras_certas[100], tentativa;
	int chances, tabuleiro_controle,i;
	
	chances = 5;
	tabuleiro_controle = 1;
	sortear_palavra(palavra);
	strcpy(letras_certas, palavra);
	
	// escondendo a palavra secreta com '_'
	for(i=0; i < strlen(letras_certas); i++){
		letras_certas[i] = '_'; 
	}
	
	while(chances > 0){
		//informa a quantidade de chances e as letras erradas do usuario
		infos(chances, letras_erradas);
		
		puts("");
		//mostra o desenho da forca
		tabuleiro(tabuleiro_controle);
		
		//informa a palavra secreta com '_'
		printf("\nAdivinhe: %s", letras_certas);
		
		//pede para o usuario digitar uma letra
		printf("\nTentativa: ");
		tentativa = getchar();
		fflush(stdin);
		
		//verifica se a letra do usuario é umas das letras da palavra secreta
		//se não for ele entra no if	
		if(verificar_letra(palavra, tentativa, letras_certas)){
			//adiciona a letra digitada pelo usuario no vetor de letra errada
			letras_erradas[5 - chances] = tentativa; 
			//diminui as tentativas do usuario
			chances--;
			//atualiza o desenho da forca
			tabuleiro_controle++;
			
		}
		// verifica se o usuario acertou todas as letras
		//o strchr verifica se o caracter '_' está em letras_certas
		//se não estiver, ele entende que o usuario ganhou
		if(!(strchr(letras_certas, '_'))){
			system("cls");
			puts("Voce acertou!");
			printf("A palavra era: %s", palavra);
			puts("\n");
			infos(chances, letras_erradas);
			
			puts("\n");
			system("pause");
			system("cls");
			break;
		}
		
		system("cls");
	}
	//verifica se o ususario perdeu
	if(chances == 0){
		infos(chances, letras_erradas);
		puts("");
		tabuleiro(tabuleiro_controle);
		printf("\nAdivinhe: %s\n", letras_certas);
		puts("\nVoce perdeu.");
		printf("A palavra era: %s\n\n", palavra);
		
		system("pause");
		system("cls");
	}
	
	menu_pos_jogo();
}


#include <stdio.h>
#include <stdlib.h>

void tabuleiro(int opcao){
	switch(opcao){
		case 1:
			printf(	
				" +---+\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"     |\n"	
				"     |\n" 
				"=========\n");
			break;
		case 2:
			printf(	
				" +---+\n"
				" |   |\n"
				" 0   |\n"
				" |   |\n"
				"     |\n"	
				"     |\n" 
				"=========\n");
			break;
		case 3:
			printf(	
				" +---+\n"
				" |   |\n"
				" 0   |\n"
				"/|   |\n"
				"     |\n"	
				"     |\n" 
				"=========\n");
			break;
		case 4:
			printf(	
				" +---+\n"
				" |   |\n"
				" 0   |\n"
				"/|\\  |\n"
				"     |\n"	
				"     |\n" 
				"=========\n");
			break;
		case 5:
			printf(	
				" +---+\n"
				" |   |\n"
				" 0   |\n"
				"/|\\  |\n"
				"/    |\n"	
				"     |\n" 
				"=========\n");
			break;
		case 6:
			printf(	
				" +---+\n"
				" |   |\n"
				" 0   |\n"
				"/|\\  |\n"
				"/ \\  |\n"	
				"     |\n" 
				 "=========\n");
			break;		
	}
}


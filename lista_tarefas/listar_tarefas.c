#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tarefas_pendentes(){
	
	FILE *lista_tarefas;
	lista_tarefas = fopen("lista_tarefas.txt", "r");
	
	char nome[100], descricao[255], data_hora_atual[18], prazo[12], status[27], data_conclusao[12], linha[255], vericacao_status[] = "Pendente";
	int i;
	
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    puts("voce nao possui tarefas pendentes!");
	    system("pause");
	    system("cls");
	    menu();
    }
    
	while(fgets(linha, sizeof(linha), lista_tarefas) != NULL){
		
		strcpy(nome, linha);
		for(i = 0; i<4; i++){
			fgets(linha, sizeof(linha), lista_tarefas);
			switch(i){
				case 0:
					strcpy(descricao, linha);
					break;
				case 1:
					strcpy(data_hora_atual, linha);
					break;
				case 2:
					strcpy(prazo, linha);
					break;
				case 3:
					strcpy(status, linha);
					break;
			}
		}
		
		if(!(strcmp(strtok(status, "\n"), vericacao_status))){
			printf("nome: %sdescricao: %sdata/hora de cadastro: %sprazo: %sstatus: %s",nome, descricao, data_hora_atual, prazo, status);
			puts("\n");
			
		}
		fgets(linha, sizeof(linha), lista_tarefas);
		for(i = 0; i < 1; i++){
			fgets(linha, sizeof(linha), lista_tarefas);
		}
	}
	
}

void tarefas_concluidas(){
	puts("listando concluidas");
}

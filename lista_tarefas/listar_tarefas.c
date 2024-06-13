#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void listar_tarefas(bool bool_concluidas){
	FILE *lista_tarefas;
	lista_tarefas = fopen("lista_tarefas.txt", "r");
	
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    printf("Voce nao possui nenhuma tarefa!");
	    system("pause");
	    system("cls");
	    menu();
    }
	
	char nome[100], descricao[255], data_hora_atual[18], prazo[12], status[27], data_conclusao[12], linha[255];
	int i;
	bool vazio = true;
    
	while(fgets(linha, sizeof(linha), lista_tarefas) != NULL){
		strcpy(nome, linha);
		for(i = 0; i<=4; i++){
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
				case 4:
					strcpy(data_conclusao, linha);
					break;
			}
		}
		
		if(!(strcmp(strtok(status, "\n"), (bool_concluidas ? "Concluida" : "Pendente")))){
			vazio = false;
			printf("Nome: %sDescricao: %sData/hora de cadastro: %sPrazo: %sStatus: %s", nome, descricao, data_hora_atual, prazo, status);
			if (bool_concluidas) {
				printf("\nData de conclusao: %s\n", data_conclusao);
			} else {
				puts("\n");
			}
		}
		
		fgets(linha, sizeof(linha), lista_tarefas);
	}
	
	if (vazio) {
		printf("Voce nao possui tarefas %s!", bool_concluidas ? "concluidas" : "pendentes");
		puts("\n");
	}
	
    system("pause");
    system("cls");
	menu();
}


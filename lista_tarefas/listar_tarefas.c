#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void listar_tarefas(bool bool_concluidas){
	FILE *lista_tarefas;
	lista_tarefas = fopen("lista_tarefas.txt", "r");
	
	//verifica se o arquivo existe
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    puts("Voce nao possui nenhuma tarefa!");
	    system("pause");
	    system("cls");
	    menu();
    }
	
	char nome[100], descricao[255], data_hora_atual[18], prazo[12], status[50], status_temp[50], data_conclusao[100], linha[255];
	int i;
	bool vazio = true;
    
    // pega cada linha do txt
	while(fgets(linha, sizeof(linha), lista_tarefas) != NULL){
		strcpy(nome, linha);
		for(i = 0; i<=4; i++){
			fgets(linha, sizeof(linha), lista_tarefas);
			
			// armazena os dados de cada linha
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
					strcpy(status_temp, linha);
					break;
				case 4:
					strcpy(data_conclusao, linha);
					break;
			}
		}
		
		// se a situação da tarefa é Finalizada ou Pendente
		if(!(strcmp(strtok(status_temp, " "), (bool_concluidas ? "Finalizada" : "Pendente\n")))){
			vazio = false;
			printf("Nome: %sDescricao: %sData/hora de cadastro: %sPrazo: %sStatus: %s", nome, descricao, data_hora_atual, prazo, status);
			// mostra a data de conclusao caso a tarefa estja concluida
			if (bool_concluidas) {
				printf("Data de conclusao: %s\n", data_conclusao);
			} else {
				puts("");
			}
		}
		
		fgets(linha, sizeof(linha), lista_tarefas);
	}
	
	// verifica se possui tarafa
	if (vazio) {
		printf("Voce nao possui tarefas %s!", bool_concluidas ? "concluidas" : "pendentes");
		puts("\n");
	}
	
	fclose(lista_tarefas);
	puts("\n");
    system("pause");
    system("cls");
	menu();
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void cadastrar_tarefa(){
	
	FILE *lista_tarefas;
	lista_tarefas = fopen("lista_tarefas.txt", "a");
	
	char nome[100], descricao[255], prazo[12], status[27] = "Pendente", data_conclusao[12] = "sem data";
	int dia, mes, ano, hora, minuto;
	
	// pegar hora 
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	
	data_hora_atual = localtime(&segundos);
	
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    lista_tarefas = fopen("lista_tarefas.txt", "w");
    }

	printf("Nome da tarefa: ");
	fgets(nome, sizeof(nome), stdin);
	fflush(stdin);
	
	system("cls");
	
	printf("Descrição da tarefa: ");
	fgets(descricao, sizeof(descricao), stdin);
	fflush(stdin);
	
	system("cls");
	
	printf("Prazo de conclusao(dd-mm-aaaa): ");
	fgets(prazo, sizeof(prazo), stdin);
	fflush(stdin);
	
	system("cls");
	
	dia =  data_hora_atual->tm_mday;
	mes = data_hora_atual->tm_mon+1;
	ano = data_hora_atual->tm_year + 1900;
	hora = data_hora_atual->tm_hour;
	minuto = data_hora_atual->tm_min;

	fprintf(lista_tarefas, "%s",nome);
	fprintf(lista_tarefas, "%s",descricao);
	fprintf(lista_tarefas, "%d-%d-%d %d:%d\n",dia, mes, ano, hora, minuto);
	fprintf(lista_tarefas, "%s",prazo);
	fprintf(lista_tarefas, "%s\n",status);
	fprintf(lista_tarefas, "%s\n\n", data_conclusao);
	
	
	fclose(lista_tarefas);
	system("cls");
	
	puts("tarefa cadastrada com sucesso!");
	system("pause");
	system("cls");
	menu();
	
}

void deletar_tarefa(){
	FILE *lista_tarefas;
	FILE *lista_temp;
	
	char nome_deletar[100], nome_temp[100], linha[255];
	int i;
	bool tarefa_encontrada = false;
	
	lista_tarefas = fopen("lista_tarefas.txt", "r");
	lista_temp	= fopen("deletar_temp.txt", "w");
	
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    puts("Sua lista de tarefas está vazia!");
	    system("pause");
	    system("cls");
	    menu();
    }
    
    printf("informe o nome da tarefa: ");
    fgets(nome_deletar, sizeof(nome_deletar), stdin);
    fflush(stdin);
    system("cls");
    
    while(fgets(linha, sizeof(linha), lista_tarefas) != NULL){
    	
    	strcpy(nome_temp, linha);
    	
		if(!(strcmp(nome_temp, nome_deletar))){
			tarefa_encontrada = true;
			
			for(i = 0; i < 6; i++){
				fgets(linha, sizeof(linha), lista_tarefas);
			}
		}
		else{
			fprintf(lista_temp,"%s", linha);
		}
		
	}
    
	
	
	fclose(lista_tarefas);
	fclose(lista_temp);
	
	if(tarefa_encontrada){
		remove("lista_tarefas.txt");
		
		rename("deletar_temp.txt", "lista_tarefas.txt");
		
		printf("tarefa excluida com sucesso!\n\n");
		system("pause");
	    system("cls");
	    menu();
	}
	else{
		printf("Tarefa nao encontrada!\n");
		system("pause");
	    system("cls");
	    menu();
	}
}


void concluir_tarefa(){
	FILE *lista_tarefas;
	FILE *lista_temp;
	
	char nome[100], nome_temp[100], linha[255],prazo_temp[11];
	int i, dia, mes, ano, hora, minuto;
	bool tarefa_encontrada = false;
	
	struct tm *data_conclusao;
	
	struct tm *prazo;
	
	char *format = "%d-%m-%Y";
	
	time_t segundos;
	time(&segundos);
	
	data_conclusao = localtime(&segundos);
	
	dia =  data_conclusao->tm_mday;
	mes = data_conclusao->tm_mon+1;
	ano = data_conclusao->tm_year + 1900;
	hora = data_conclusao->tm_hour;
	minuto = data_conclusao->tm_min;
	
	lista_tarefas = fopen("lista_tarefas.txt", "r");
	lista_temp	= fopen("concluir_temp.txt", "w");
	
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    puts("Sua lista de tarefas está vazia!");
	    system("pause");
	    system("cls");
	    menu();
    }
    
    printf("informe o nome da tarefa: ");
    fgets(nome, sizeof(nome), stdin);
    fflush(stdin);
    system("cls");
    
    while(fgets(linha, sizeof(linha), lista_tarefas) != NULL){
    	
    	strcpy(nome_temp, linha);
    	
		if(!(strcmp(nome_temp, nome))){
			tarefa_encontrada = true;
			
			printf("%s", nome_temp);
			for(i = 0; i <= 2; i++){
				fgets(linha, sizeof(linha), lista_tarefas);
				printf("%s", linha);
			}
			strcpy(prazo_temp, linha);
			
			for(i = 0; i <= 11; i++){
				strptime(prazo_temp, "%d-%m-%Y", &prazo);
			}
			
			
			printf("concluida\n %s");
			printf("%d-%d-%d %d:%d", dia, mes, ano, hora, minuto);
			
			
		}
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

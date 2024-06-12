#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void cadastrar_tarefas(){
	
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
	fprintf(lista_tarefas, "%d-0%d-%d %d:%d\n",dia, mes, ano, hora, minuto);
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
	puts("deletando...");
}

void concluir_tarefa(){
	puts("concluindo...");
}

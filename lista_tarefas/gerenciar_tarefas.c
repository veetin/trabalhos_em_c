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
	
	// pegar hora  atual
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	
	data_hora_atual = localtime(&segundos);
	
	// verifica se o arquivo de txt esta vazio
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    lista_tarefas = fopen("lista_tarefas.txt", "w");
    }
	
	// nome da tarefa
	printf("Nome da tarefa: ");
	fgets(nome, sizeof(nome), stdin);
	fflush(stdin);
	
	system("cls");
	
	// descrição da tarefa 
	printf("Descrição da tarefa: ");
	fgets(descricao, sizeof(descricao), stdin);
	fflush(stdin);
	
	system("cls");
	
	// prazo de conclusao
	printf("Prazo de conclusao(dd-mm-aaaa): ");
	fgets(prazo, sizeof(prazo), stdin);
	fflush(stdin);
	
	system("cls");
	
	// armazena as informações de data e hora em variaveis
	dia =  data_hora_atual->tm_mday;
	mes = data_hora_atual->tm_mon+1;
	ano = data_hora_atual->tm_year + 1900;
	hora = data_hora_atual->tm_hour;
	minuto = data_hora_atual->tm_min;
	
	// armazena as informações no txt
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
	
	//verifica se o arquivo existe
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    puts("Sua lista de tarefas está vazia!");
	    system("pause");
	    system("cls");
	    menu();
    }
    
	// pede o nome da tarefa para ser excluida
    printf("informe o nome da tarefa: ");
    fgets(nome_deletar, sizeof(nome_deletar), stdin);
    fflush(stdin);
    system("cls");
    
    // pega cada linha do txt
    while(fgets(linha, sizeof(linha), lista_tarefas) != NULL){
    	//copia nome da tarefa
    	strcpy(nome_temp, linha);
    	
    	//verifica se a tarefa existe
		if(!(strcmp(nome_temp, nome_deletar))){
			//se ela existir, ela é ignorada
			tarefa_encontrada = true;
			
			// pula os dados que eu quero deletar
			for(i = 0; i < 6; i++){
				fgets(linha, sizeof(linha), lista_tarefas);
			}
		}
		else{
			//casos contrario, armazena a tarefa em um  txt temporario
			fprintf(lista_temp,"%s", linha);
		}
		
	}
    
	
	
	fclose(lista_tarefas);
	fclose(lista_temp);
	
	// exclui a lista principal e renomeia a temp como principal
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
	
	char nome[100], nome_temp[100], linha[255],prazo_temp[12];
	int i, *hora, *minuto;
	bool tarefa_encontrada = false;
	
	struct tm prazo= {0};
	struct tm entrega = {0};
	
	// paga data do computador na hora de concluir a tarefa
	time_t segundos;
	segundos = time(NULL);
	entrega = *localtime(&segundos);
	
	// é preciso serar o horario da entrega para comparar com a data do prazo
	entrega.tm_hour = 0;
	entrega.tm_min = 0;
	entrega.tm_sec = 0;
	
	
	lista_tarefas = fopen("lista_tarefas.txt", "r");
	lista_temp	= fopen("concluir_temp.txt", "w");
	
	// verifica se a lista de tarefa está vazia
	if(lista_tarefas == NULL){
	    fclose(lista_tarefas);
	    puts("Sua lista de tarefas está vazia!");
	    system("pause");
	    system("cls");
	    menu();
    }
    
    // pega o nome da tarefa
    printf("informe o nome da tarefa: ");
    fgets(nome, sizeof(nome), stdin);
    fflush(stdin);
    system("cls");
    
    // pega cada linha do txt
    while(fgets(linha, sizeof(linha), lista_tarefas) != NULL){
    	
    	strcpy(nome_temp, linha);
    	// verifica se o nome existe
		if(!(strcmp(nome_temp, nome))){
			tarefa_encontrada = true;
			
			//print o nome em um txt temporario
			fprintf(lista_temp, "%s", nome_temp);
			for(i = 0; i < 2; i++){
				// printa as outras informações fixas 
				fgets(linha, sizeof(linha), lista_tarefas);
				fprintf(lista_temp, "%s", linha);
			}
			fgets(linha, sizeof(linha), lista_tarefas);
			
			// extrai o prazo do txt e formata para data 
			sscanf(linha, "%d-%d-%d", &prazo.tm_mday, &prazo.tm_mon, &prazo.tm_year);
			prazo.tm_year -= 1900;
			prazo.tm_mon -= 1;
			
			// adiciona a informação de prazo no txt
			fprintf(lista_temp,"%02d-%02d-%d\n", prazo.tm_mday, prazo.tm_mon+1, prazo.tm_year + 1900);
			
			// comparando a data de entrega com a de prazo
			time_t entrega_comparar = mktime(&entrega);
		   	time_t prazo_comparar = mktime(&prazo);
		   	
		   	// verifica a diferança das datas em segundo(não considera as horas, apenas a data)
		    double dif_segundos = difftime(prazo_comparar, entrega_comparar);
		   	
		   	// se a diferença for negativa, significa que foi entregue atrasado
		   	if(dif_segundos < 0){
				fprintf(lista_temp, "Finalizada com atraso\n");
			}else{
				fprintf(lista_temp, "Finalizada dentro do prazo\n");
			}		
			
			//odciona a data de entrega com o horario no txt temporario
			entrega = *localtime(&segundos);
			fprintf(lista_temp, "%02d-%02d-%d as %02d:%02dh\n", entrega.tm_mday, entrega.tm_mon+1, entrega.tm_year+1900, entrega.tm_hour, entrega.tm_min);
			
			// pula as informações que estão no txt que foram atualizadas manualmente
			for(i = 0; i < 2; i++){
				fgets(linha, sizeof(linha), lista_tarefas);
			}
			
		}else{
			fprintf(lista_temp, "%s", linha);
		}
	
	}
	
	fclose(lista_tarefas);
	fclose(lista_temp);
	
	// exclui a lista principal e renomeia a temp como principal
	if(tarefa_encontrada){
		remove("lista_tarefas.txt");
		
		rename("concluir_temp.txt", "lista_tarefas.txt");
		
		printf("tarefa concluida com sucesso!\n\n");
		system("pause");
	    system("cls");
	    menu();
	}else{
		printf("Tarefa nao encontrada!\n");
		system("pause");
	    system("cls");
	    menu();
	}
	
}


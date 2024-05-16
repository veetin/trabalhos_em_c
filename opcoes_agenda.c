#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Funções auxiliares (frufru)
int listar_nomes(int opcao){
	
	FILE *agenda;
	agenda = fopen("agenda.txt", "r");
	
	switch(opcao){
		int i, qtd_contatos;
		char lista_nomes[100];
		case 0:
			printf("----------------------\n");
			printf("| Lista de contatos: |\n");
			printf("----------------------\n");
			
			while(fgets(lista_nomes, sizeof(lista_nomes), agenda) != NULL){
				printf("%s", lista_nomes);
				printf("-------------\n");
				for(i = 1; i <= 4; i++){
					fgets(lista_nomes, sizeof(lista_nomes), agenda);
				}
			}
			fclose(agenda);
			break;
		
		case 1:
			qtd_contatos = 1;
			while(fgets(lista_nomes, sizeof(lista_nomes), agenda) != NULL){
				qtd_contatos++;
			}
			qtd_contatos = (qtd_contatos - 1)/5;
			printf("\nQuantidade de contatos: %d/5", qtd_contatos);
			
			if(qtd_contatos == 5){
				printf(" - Agenda cheia.\n");
				fclose(agenda);
				return 1;
			}
			
			fclose(agenda);
			return 0;
			
			break;
	}
}

int validar_cpf(char cpf[11]){
	int i;
	for(i=0; cpf[i] != '\0'; i++){
		// verifica se cada caractere do cpf eh digito, ignorando a quebra de linha
		if(!isdigit(cpf[i])){ //&& cpf[i] != '\n'
			return 0;
		}
	}
	
	// verifica se o cpf tem 12 caracteres (contando com a quebra de linha)
	if(strlen(cpf) != 11){
		return 0;
	}
	
	return 1;
}

int validar_telefone(char telefone[9]){
	int i;
	for(i=0; telefone[i] != '\0'; i++){
		// verifica se cada caractere do cpf eh digito, ignorando a quebra de linha
		if(!isdigit(telefone[i])){ //&& cpf[i] != '\n'
			return 0;
		}
	}
	
	// verifica se o cpf tem 12 caracteres (contando com a quebra de linha)
	if(strlen(telefone) != 9){
		return 0;
	}
	
	return 1;
}


// Funções principais

void listar_contatos(){
	// abrindo o arquivo txt
	FILE *agenda;
	agenda = fopen("agenda.txt", "r");
	
	// Verificando se o arquivo existe.
	
	if(agenda == NULL){
		system("cls"); 
		printf("\nVoce nao possui contatos!\n\n");
		system("pause");
		menu();		
	}
	
	// listando contatos
	system("cls");
	printf("\nListando contatos...\n\n");
	
	char lista_contatos[100];
	int i;
	i = 1;
	while(fgets(lista_contatos, sizeof(lista_contatos), agenda) != NULL){
		if(i == 5){
			printf("-------------------");
			i = 0;
		}
		printf("%s", lista_contatos);
		i++;
	}
	
	//informa a quantidade de contatos
	listar_nomes(1);
	
	// fecha a agenda e volta para o menu
	fclose(agenda);
	printf("\n");
	system("pause");
	system("cls");
	menu();	
}

void buscar_contato(){
	
	// abrindo arquivo txt
	FILE *agenda;
	agenda = fopen("agenda.txt", "r");
	
	// verificando se o arquivo existe 
	if(agenda == NULL){
		printf("\nVoce nao possui contatos!\n");
		fclose(agenda);
		system("pause");
		system("cls");
		menu();
	}
	
	// salvando escolha do usuario entre nome ou cpf
	int opcao;
	
	printf("Buscar por:\n");
	printf("Nome - ( 1 )\n");
	printf("CPF - ( 2 )\n");
	
	printf("Informe a opcao desejada: ");
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	

	// Verificando a opcao escolhida pelo usuario
	switch(opcao){
		
		char nome[100], contato[100], cpf[12];
		bool contato_nao_encontrado;
		int i;
		case 1:
			// buscando contato pelo nome.
			//listando os nomes dos contatos para facilitar na busca
			listar_nomes(0);
			
			// pedindo o nome do contato
			printf("\n\nInforme o nome: ");
			fgets(nome, sizeof(nome), stdin);
			fflush(stdin);
			
			system("cls");
			
			contato_nao_encontrado = true;
			
			while(fgets(contato, sizeof(contato), agenda) != NULL){
		
				// verificando se o nome digitado pelo usuario e o contato são iguais
				if(strcmp(nome, contato) == 0 ){
					contato_nao_encontrado = false;
					printf("Contato encontrado:");
					printf("\n-------------------");
					
					// listando as informações do respectivo contato.
					printf("\n%s", contato);
					for(i = 0; i<=2; i++){
						fgets(contato, sizeof(contato), agenda);
						printf("%s", contato);
					}
					printf("-------------------\n");
				}
	
			}
			
			// verificnado se a condição contato não encontrado é verdadeira.
			if(contato_nao_encontrado){
				fclose(agenda);
				printf("Contato nao encontrado!\n\n");
				system("pause");
				system("cls");
				menu();
			}			
			break;
				
		case 2:
			// pedindo o cpf do contato
			printf("Informe o CPF: ");
			fgets(cpf, 14, stdin);
			fflush(stdin);
			
			system("cls");
			
			i = 1;
			contato_nao_encontrado = true;
			
			while(fgets(contato, sizeof(contato), agenda) != NULL){
		
				switch(i){
					case 1:
						strcpy(nome, contato);
						i++;
						continue;
					case 2:
						if(strcmp(cpf, contato) == 0){
							contato_nao_encontrado = false;
							printf("CPF encontrado: \n");
							printf("-------------------\n");
							printf("%s%s", nome, cpf);
							
							for(i = 0; i <= 1; i++){
								fgets(contato, sizeof(contato), agenda);
									printf("%s", contato);
							}
							printf("-------------------\n");
							break;
						}
						else{
							for(i = 0; i <= 2; i++){
								fgets(contato, sizeof(contato), agenda);
							}
							i = 1;	
						}
				}
			}
			if(contato_nao_encontrado){
				system("cls");
				printf("CPF nao encontrado!\n");
				break;
			}
	}
	fclose(agenda);
	system("pause");
	system("cls");
	menu();	

}

void adicionar_contato(){

    FILE *agenda;
    agenda = fopen("agenda.txt", "a");

    char nome[100], email[100], telefone[9], cpf[11];

    if(agenda == NULL){
        fclose(agenda);
        agenda = fopen("agenda.txt", "w");
    }
    
    if(listar_nomes(1)){
    	printf("\nNao e possivel adicionar novos contatos com a genda cheia.\n\n");
    	fclose(agenda);
		system("pause");
    	system("cls");
    	menu();
	}
    
	//nome
    printf("\n\nDigite um nome: ");
    fgets(nome, 100, stdin);
    fflush(stdin);
    system("cls");

	// cpf
    printf("Digite o CPF: ");
    scanf("%s", &cpf);
    
    while(!validar_cpf(cpf)){
        system("cls");
        printf("CPF INVALIDO!\n");
        printf("Informe um CPF valido (11 digitos e apenas numeros): ");
       	scanf("%s", &cpf);
	}
    
    system("cls");
	
	//email
    printf("Digite um email: ");
    scanf("%s", &email);
    system("cls");
    
    while(!(strchr(email, '@') && strchr(email, '.'))){
        system("cls");
        printf("EMAIL INVALIDO!\n");
        printf("Informe um EMAIL valido (deve conter '@'): ");
    	scanf("%s", &email);
    }

	// telefone
    printf("Digite um numero de telefone: ");
    scanf("%s", &telefone);
    
   while(!validar_telefone(telefone)){
        system("cls");
        printf("NUMERO INVALIDO!\n");
        printf("Informe um NUMERO valido (9 digitos e apenas numeros): ");
        scanf("%s", &telefone);
    }
    
	fprintf(agenda,"%s",nome);
	fprintf(agenda,"%s\n",cpf);
	fprintf(agenda,"%s\n",email);
	fprintf(agenda,"%s\n\n",telefone);
	
    system("cls");
    printf("Contato criado com sucesso!\n\n");
	
	fclose(agenda);
	
	listar_nomes(0);

    system("pause");
    system("cls");
    menu();


}

void excluir_contato(){
	// abrindo arquivo txt
	FILE *agenda;
	agenda = fopen("agenda.txt", "r");	

	// criando um arquivo temp
	FILE *agenda_temp;
	agenda_temp	= fopen("temp.txt", "w");
	
	// verificando se o arquivo existe 
	if(agenda == NULL){
		printf("\nVoce nao possui contatos!\n");
		fclose(agenda);
		fclose(agenda_temp);
		system("pause");
		system("cls");
		menu();
	}
	
	listar_nomes(0);
	
    char nome[100], email[100], contato[11], cpf[14], linha[255];
    char nome_excluir[100];
    bool contato_encontrado = false;
    
    // recebe o nome do contato para excluir
    printf("\nQual contato deseja excluir: ");
    fgets(nome_excluir, sizeof(nome_excluir), stdin);
	strtok(nome_excluir, "\n");
    system("cls");
    
    // procura o nome do contato percorrendo o arquivo
    while(fgets(linha, sizeof(linha), agenda) != NULL){		
    	int i; // para usar no for do if else dentro do loop while
		
		// copia a linha para variavel nome
		strcpy(nome, linha);
		
		// cria uma variavel temp e remove a quebra de linha para ser comparada com o nome_excluir
		char nome_temp[100];
		strcpy(nome_temp, nome);
		strtok(nome_temp, "\n");
    	
		// verifica se os nomes batem
    	if(strcmp(nome_temp, nome_excluir) == 0){
    		contato_encontrado = true;
    		
    		// pula as linhas com os dados do contato
			for(i = 0; i<=3; i++){
				fgets(linha, sizeof(linha), agenda);
			}
    	}
		else{
			// copia cada contato não encontrado para o arquivo agenda_temp
			fputs(nome, agenda_temp);
			
			// coloca as linhas com os dados do contato no arquivo agenda_temp
			for(i = 0; i<=2; i++){
				fgets(linha, sizeof(linha), agenda);
				fputs(linha, agenda_temp);
				
			}
			fputs("\n", agenda_temp);
			fgets(linha, sizeof(linha), agenda);
		}
	}
	
	fclose(agenda);	
	fclose(agenda_temp);
	
	if(contato_encontrado){
		// exclui a agenda original
		remove("agenda.txt");
		
		// renomeia o arquivo temp para se tornar o principal
		rename("temp.txt", "agenda.txt");
		
		printf("Contato excluido com sucesso!\n\n");
		
		listar_nomes(0);
		listar_nomes(1);
		printf("\n\n");
		
	}
	else{
		printf("Contato nao encontrado!\n");
	}
	
    system("pause");
    system("cls");
    menu();
}

















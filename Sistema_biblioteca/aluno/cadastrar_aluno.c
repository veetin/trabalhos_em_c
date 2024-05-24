#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "area_aluno.h"

int validar_cpf(char cpf[11]){
	int i;
	for(i=0; cpf[i] != '\0'; i++){
		// verifica se cada caractere do cpf eh digito
		if(!isdigit(cpf[i])){
			return 0;
		}
	}
	
	// verifica se o cpf tem 11 caracteres
	if(strlen(cpf) != 11){
		return 0;
	}
	
	return 1;
}

int validar_telefone(char telefone[9]){
	int i;
	for(i=0; telefone[i] != '\0'; i++){
		// verifica se cada caractere do telefone eh digito
		if(!isdigit(telefone[i])){ 
			return 0;
		}
	}
	
	// verifica se o telefone tem 9 caracteres
	if(strlen(telefone) != 9){
		return 0;
	}
	
	return 1;
}

void cadastrar_aluno(){
    FILE *alunos;
    alunos = fopen("alunos.txt", "a");

    char nome[100], email[100], telefone[9], cpf[11];
    
	// se o alunos.txt não existir ele cria a agenda em 'w'
    if(alunos == NULL){
        fclose(alunos);
        alunos = fopen("alunos.txt", "w");
    }
    
	// NOME
    printf("Digite um nome: ");
    fgets(nome, 100, stdin);
    fflush(stdin);
    system("cls");

	// CPF
    printf("Digite o CPF: ");
    scanf("%s", &cpf);
    
    // verificando se o cpf foi digitado corretamente 11 digitos e apenas numeros
    while(!validar_cpf(cpf)){
        system("cls");
        printf("CPF INVALIDO!\n");
        printf("Informe um CPF valido (11 digitos e apenas numeros): ");
       	scanf("%s", &cpf);
	}
    
    system("cls");
	
	// EMAIL
    printf("Digite um email: ");
    scanf("%s", &email);
    system("cls");
    
	// verificando se o email foi digitado corretamente com '@' e '.'
    while(!(strchr(email, '@') && strchr(email, '.'))){
        system("cls");
        printf("EMAIL INVALIDO!\n");
        printf("Informe um EMAIL valido: ");
    	scanf("%s", &email);
    }

	// TELEFONE
    printf("Digite um numero de telefone: ");
    scanf("%s", &telefone);
    
    while(!validar_telefone(telefone)){
        system("cls");
        printf("NUMERO INVALIDO!\n");
        printf("Informe um NUMERO valido (9 digitos e apenas numeros): ");
        scanf("%s", &telefone);
    }
    
    // adicionando as informações no arquivo txt
	fprintf(alunos,"%s",nome);
	fprintf(alunos,"%s\n",cpf);
	fprintf(alunos,"%s\n",email);
	fprintf(alunos,"%s\n\n",telefone);
	
    system("cls");
    printf("Aluno cadastrado com sucesso!\n\n");
	
	fclose(alunos);

    system("pause");
    system("cls");
    menu_aluno();
}


#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>	//biblioteca de alocação de espaço em memória
#include <locale.h>	//biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variaveis/strings
	char arquivo[40];																					
	char nome[40];
	char sobrenome[40];
	char cpf[40];
	char cargo[40];
	//final da criação de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cpf); //salva as informações do usuário
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das strings
	
	FILE *file;
	file=fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,"CPF: ");
	fprintf(file,cpf);
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //escreve novas informações no arquivo
	fprintf(file,"\n NOME: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //cadastra o nome do usuário
	scanf("%s",nome); //salva as informações do usuráio
	
	file=fopen(arquivo,"a"); //escreve novas informações no arquivo
	fprintf(file,nome); 
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //escreve novas informacoes no arquivo
	fprintf(file,"\n SOBRENOME: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //cadastra o sobrenome do usuáiro
	scanf("%s",sobrenome); //salva as informações do usuário
	
	file=fopen(arquivo,"a"); //escreve novas infomações no arquivo
	fprintf(file,sobrenome);
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //escreve novas informações no arquivo
	fprintf(file,"\n CARGO: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu cargo a ser cadastrado: "); //cadastra o cargo do usuário
	scanf("%s",cargo); //salva as informações do usuário
	
	file=fopen(arquivo,"a"); //escreve novas informações no arquivo
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file); //fecha o arquivo
	system("pause");
}

int consulta() //função responsável por consultar os dados dos usuários
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da criação de variaveis/strings
	char cpf[40];
	char conteudo[100];
	//fim da crição de variaveis/strings
	
	printf("Digite o CPF a ser consultado: "); //consulta os dados do usuráio
	scanf("%s",cpf); //salva as informações do usuário
	printf("\nEssas são as informações do usuário:\n\n "); //exibe as informações do usuário
	
	FILE *file;
	file=fopen(cpf,"r"); //lê o arauivo
	
	if(file==NULL) //exibe uma mensagem  caso não encontre o usuário no sistema
	{
		system("cls");
		printf("Usuário não localizado!.");
		printf("\n\n");
	}	
	
	while(fgets(conteudo,100,file)!=NULL)
	{
		printf("%s",conteudo);
	}
	system("pause");
}

int deletar() //função responsável por deletar os dados de usuários
{
	char cpf[40]; //incío/fim da criação de variaveis/strings
	
	printf("Digite o CPF a ser deletado: "); //pede as informações a serem deletadas
	scanf("%s",cpf); //salva as informações do usuário
	
	remove(cpf); //responsável por deletar os dados de usuário
	
	FILE *file;
	file=fopen(cpf,"r"); //lê o arquivo
	
	if(file==NULL)//exibe uma mensagem caso o usuário seja deletado com sucesso
	{
		printf("\nUsuário deltado com sucesso!\n\n");
		system("pause");
	}
			
}

int main() //função principal
{
	int opcao=0; //definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
	system("cls"); //resposável por limpar a tela
		
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("\t   Cartório da EBAC\n\n"); //início do menu
	printf("\tEscolha a opção desejada do menu:\n\n");
	printf("\t1-Registar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n");
	printf("\t4-Sair do sistema\n\n");
	printf("Opção: "); //fim do menu
	
	scanf("%d",&opcao); //armazenando a escolha do usuário
	
	system("cls"); //responsável por limpar a tela
	
	switch(opcao) //início das escolhas do menu
	{
		case 1: //opção número Um
		registro();
		break;
		
		case 2: //opção número Dois
		consulta();
		break;
		
		case 3: //opção número Tres
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;	
		
		default:
		printf("Esta opção não está disponível!\n\n");
		system("pause");
		break; //fim das escolhas do menu
	}
	
	}
	
}

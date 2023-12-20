#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>	//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>	//biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];																					
	char nome[40];
	char sobrenome[40];
	char cpf[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //salva as informa��es do usu�rio
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores das strings
	
	FILE *file;
	file=fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,"CPF: ");
	fprintf(file,cpf);
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //escreve novas informa��es no arquivo
	fprintf(file,"\n NOME: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //cadastra o nome do usu�rio
	scanf("%s",nome); //salva as informa��es do usur�io
	
	file=fopen(arquivo,"a"); //escreve novas informa��es no arquivo
	fprintf(file,nome); 
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //escreve novas informacoes no arquivo
	fprintf(file,"\n SOBRENOME: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //cadastra o sobrenome do usu�iro
	scanf("%s",sobrenome); //salva as informa��es do usu�rio
	
	file=fopen(arquivo,"a"); //escreve novas infoma��es no arquivo
	fprintf(file,sobrenome);
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo,"a"); //escreve novas informa��es no arquivo
	fprintf(file,"\n CARGO: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu cargo a ser cadastrado: "); //cadastra o cargo do usu�rio
	scanf("%s",cargo); //salva as informa��es do usu�rio
	
	file=fopen(arquivo,"a"); //escreve novas informa��es no arquivo
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file); //fecha o arquivo
	system("pause");
}

int consulta() //fun��o respons�vel por consultar os dados dos usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da cria��o de variaveis/strings
	char cpf[40];
	char conteudo[100];
	//fim da cri��o de variaveis/strings
	
	printf("Digite o CPF a ser consultado: "); //consulta os dados do usur�io
	scanf("%s",cpf); //salva as informa��es do usu�rio
	printf("\nEssas s�o as informa��es do usu�rio:\n\n "); //exibe as informa��es do usu�rio
	
	FILE *file;
	file=fopen(cpf,"r"); //l� o arauivo
	
	if(file==NULL) //exibe uma mensagem  caso n�o encontre o usu�rio no sistema
	{
		system("cls");
		printf("Usu�rio n�o localizado!.");
		printf("\n\n");
	}	
	
	while(fgets(conteudo,100,file)!=NULL)
	{
		printf("%s",conteudo);
	}
	system("pause");
}

int deletar() //fun��o respons�vel por deletar os dados de usu�rios
{
	char cpf[40]; //inc�o/fim da cria��o de variaveis/strings
	
	printf("Digite o CPF a ser deletado: "); //pede as informa��es a serem deletadas
	scanf("%s",cpf); //salva as informa��es do usu�rio
	
	remove(cpf); //respons�vel por deletar os dados de usu�rio
	
	FILE *file;
	file=fopen(cpf,"r"); //l� o arquivo
	
	if(file==NULL)//exibe uma mensagem caso o usu�rio seja deletado com sucesso
	{
		printf("\nUsu�rio deltado com sucesso!\n\n");
		system("pause");
	}
			
}

int main() //fun��o principal
{
	int opcao=0; //definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		
	system("cls"); //respos�vel por limpar a tela
		
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	printf("\t   Cart�rio da EBAC\n\n"); //in�cio do menu
	printf("\tEscolha a op��o desejada do menu:\n\n");
	printf("\t1-Registar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n");
	printf("\t4-Sair do sistema\n\n");
	printf("Op��o: "); //fim do menu
	
	scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
	system("cls"); //respons�vel por limpar a tela
	
	switch(opcao) //in�cio das escolhas do menu
	{
		case 1: //op��o n�mero Um
		registro();
		break;
		
		case 2: //op��o n�mero Dois
		consulta();
		break;
		
		case 3: //op��o n�mero Tres
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;	
		
		default:
		printf("Esta op��o n�o est� dispon�vel!\n\n");
		system("pause");
		break; //fim das escolhas do menu
	}
	
	}
	
}

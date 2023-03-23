#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenomes[40];
	char cargo[40];
	//final da cria��o de vari�veirs
	
	printf("Por favor, digite o CPF: \n"); //coletando as informa��es do usu�rio
	scanf ("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file=fopen(arquivo, "w"); //cria o arquivo "w" significa escrever
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite um nome: ");
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenomes);
	
	file=fopen(arquivo, "a");
	fprintf(file, sobrenomes);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Por favor, digite o CPF: \n");
	scanf ("%s", cpf);
	
	FILE *file; 
	file=fopen(cpf, "r"); 
	
	if (file == NULL)
	{
		printf("Cpf n�o encontrado! \n");
	}
	
	while (fgets(conteudo,200, file) != NULL)
	{
		printf("\n essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF que deseja deletar \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; 
	file=fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Cpf n�o encontrado! \n");
	}
	system("pause");
	
}

int main()
{
	int opcao=0;  //Definindo as vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
		setlocale(LC_ALL, "Portuguese");                                              //Definido linguagem 
	
		printf("\t\t\t\t\t\tCart�rio EBAC  \n\n");                                    //In�cio do menu
		printf("Bem vindo ao cart�rio EBAC!! Por favor, escolha uma op��o: \n\n");    
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n\n");
		printf("Digite a op��o desejada: "); //Fim do Menu

		scanf("%d", &opcao);  //Armazenando as informal��es do usu�rio
	 
		system("cls"); 
		
		switch(opcao)
		{
			case 1:
				registro();
				break;
				
			case 2: 
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Voc� escolheu uma op��o indispon�vel!! Por favor, digite as op��es 1, 2 ou 3 \n");
				system("pause");
				break;
				
				
				
		}
	
	
	}
}

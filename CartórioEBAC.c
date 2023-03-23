#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenomes[40];
	char cargo[40];
	//final da criação de variáveirs
	
	printf("Por favor, digite o CPF: \n"); //coletando as informações do usuário
	scanf ("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file=fopen(arquivo, "w"); //cria o arquivo "w" significa escrever
	fprintf(file, cpf); //salvo o valor da variável
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
		printf("Cpf não encontrado! \n");
	}
	
	while (fgets(conteudo,200, file) != NULL)
	{
		printf("\n essas são as informações do usuário: ");
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
		printf("Cpf não encontrado! \n");
	}
	system("pause");
	
}

int main()
{
	int opcao=0;  //Definindo as variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
		setlocale(LC_ALL, "Portuguese");                                              //Definido linguagem 
	
		printf("\t\t\t\t\t\tCartório EBAC  \n\n");                                    //Início do menu
		printf("Bem vindo ao cartório EBAC!! Por favor, escolha uma opção: \n\n");    
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n\n");
		printf("Digite a opção desejada: "); //Fim do Menu

		scanf("%d", &opcao);  //Armazenando as informalções do usuário
	 
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
				printf("Você escolheu uma opção indisponível!! Por favor, digite as opções 1, 2 ou 3 \n");
				system("pause");
				break;
				
				
				
		}
	
	
	}
}

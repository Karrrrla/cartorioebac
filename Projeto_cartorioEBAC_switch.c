#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar/dar vida ao string

int incluir() //fun��o responsavel por cadastar os usu�rios
{
	//in�cio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //percent string para armazenar dentro de um string, refer�ncia para uma string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abre/cria o arquivo, w � igual a write
	fprintf(file,cpf); // salva o valor da variavel no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo salvo na vari�vel a=atualizar a informa��o
	fprintf(file,","); //adicionado a informa��o que nesse caso foi a virgula
	fclose(file);// fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
    	
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r"); //r � igual a read, ler
  	
 	if(file == NULL)
{
	printf("N�o foi poss�vel abrir o arquivo! CPF n�o encontrado.\n");
}
	
	while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
	system ("pause");	
}

int deletar()
{
	char cpf[40];
	
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{printf("CPF n�o encontrado no sistema!.\n");
	system("pause");
	} 
}

int main()
    {
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//apaga todo o menu ap�s o usu�rio selecionar a op��o desejada
		
		setlocale(LC_ALL, "Portuguese");//Linguagem definida
	
		printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
		printf("Selecione a op��o desejada do menu:\n\n");
		printf("\t1 - Incluir nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando  a escolha do usu�rio
		
		system("cls");//apaga todo o menu ap�s o usu�rio selecionar a op��o desejada
		
		
		switch(opcao)//incio da sele��o
		{
			case 1:
			incluir();//chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:	
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema! At� a pr�xima.\n");
			return 0;
			break;
			
			default:
			printf("Op��o indispon�vel!\n");
			system("pause");
			break;
			
		}//fim da sele��o
	}
}

#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar/dar vida ao string

int incluir() //função responsavel por cadastar os usuários
{
	//início da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //percent string para armazenar dentro de um string, referência para uma string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abre/cria o arquivo, w é igual a write
	fprintf(file,cpf); // salva o valor da variavel no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo salvo na variável a=atualizar a informação
	fprintf(file,","); //adicionado a informação que nesse caso foi a virgula
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
	file = fopen(cpf,"r"); //r é igual a read, ler
  	
 	if(file == NULL)
{
	printf("Não foi possível abrir o arquivo! CPF não encontrado.\n");
}
	
	while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
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
	{printf("CPF não encontrado no sistema!.\n");
	system("pause");
	} 
}

int main()
    {
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");//apaga todo o menu após o usuário selecionar a opção desejada
		
		setlocale(LC_ALL, "Portuguese");//Linguagem definida
	
		printf("### Cartório da EBAC ###\n\n");//inicio do menu
		printf("Selecione a opção desejada do menu:\n\n");
		printf("\t1 - Incluir nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando  a escolha do usuário
		
		system("cls");//apaga todo o menu após o usuário selecionar a opção desejada
		
		
		switch(opcao)//incio da seleção
		{
			case 1:
			incluir();//chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:	
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema! Até a próxima.\n");
			return 0;
			break;
			
			default:
			printf("Opção indisponível!\n");
			system("pause");
			break;
			
		}//fim da seleção
	}
}

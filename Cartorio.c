#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocações de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings.

int registro() //Função responsável por cadastrar os usuários.
{
	//Início de criação das variáveis/string.
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim de criação das variáveis/string.
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário.
	scanf("%s", cpf); //%s refere-se a string para armazenar dentro da variável.
	
	strcpy(arquivo, cpf); //responsável por copiar os valores da string.
	
	FILE *file; //acessar o FILE e criar um file. File é uma busca na biblioteca.
	file = fopen(arquivo, "w"); // abrir um arquivo novo, W - write(escrever).
	fprintf(file, cpf); //salvar no arquivo a variável CPF.
	fclose(file); //fechar arquivo.
	
	file = fopen(arquivo, "a"); //fopen - Abrir o arquivo que fechamos. Não queremos criar um novo arquivo, mas sim 'A'tualizá-lo.
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200]; //lugar onde estão os registros.
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //abrir o arquivo e consultar.
	file = fopen(cpf, "r"); //"R "ler o arquivo(cpf).
	
	if(file == NULL) //Se for nulo, não existir.
	{
		printf("Não foi possível abrir o arquivo, pois não foi localizado nada com esse registro!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto estiver escrevendo na variavel conteudo os 200(max) arquivos ele irá buscar e trazer eles no arquivo cpf.
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //deletar
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível deletar o arquivo, pois não foi localizado nada com esse registro em nosso sistema!\n");
		system("pause");
	}
	
	else
	{
		remove(cpf);
		printf("CPF deletado com sucesso!\n");
		system("pause");
	}
}


int main()

{
	int opcao=0; //Definindo variáveis. int irá receber a opção desejada pelo o usuário. Lembra de começar =0.
	int laco=1; //início do laço
	
	for(laco=1;laco=1;)
	{ //início do laço
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //(scanf) escaneia a opção do Usuário.(%d) para armazenar uma variavel do tipo inteiro.(&) definir o nome da variavel q irá receber o armazenamento.
	
		system("cls"); //limpar a tela, deletar as mensagens anteriores  e melhorar o visual.
	
	
		switch(opcao)
		{ //início Switch, seleção.
			case 1:
			registro(); //chamada de funções.
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
			
		} //fim do Switch, seleção.

	} //fim/reinicio do laço
} //fim

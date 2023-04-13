#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //biblioteca de aloca��es de texto por regi�o.
#include <string.h> //biblioteca respons�vel por cuidar das strings.

int registro() //Fun��o respons�vel por cadastrar os usu�rios.
{
	//In�cio de cria��o das vari�veis/string.
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim de cria��o das vari�veis/string.
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio.
	scanf("%s", cpf); //%s refere-se a string para armazenar dentro da vari�vel.
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string.
	
	FILE *file; //acessar o FILE e criar um file. File � uma busca na biblioteca.
	file = fopen(arquivo, "w"); // abrir um arquivo novo, W - write(escrever).
	fprintf(file, cpf); //salvar no arquivo a vari�vel CPF.
	fclose(file); //fechar arquivo.
	
	file = fopen(arquivo, "a"); //fopen - Abrir o arquivo que fechamos. N�o queremos criar um novo arquivo, mas sim 'A'tualiz�-lo.
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
	char conteudo[200]; //lugar onde est�o os registros.
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //abrir o arquivo e consultar.
	file = fopen(cpf, "r"); //"R "ler o arquivo(cpf).
	
	if(file == NULL) //Se for nulo, n�o existir.
	{
		printf("N�o foi poss�vel abrir o arquivo, pois n�o foi localizado nada com esse registro!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto estiver escrevendo na variavel conteudo os 200(max) arquivos ele ir� buscar e trazer eles no arquivo cpf.
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //deletar
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel deletar o arquivo, pois n�o foi localizado nada com esse registro em nosso sistema!\n");
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
	int opcao=0; //Definindo vari�veis. int ir� receber a op��o desejada pelo o usu�rio. Lembra de come�ar =0.
	int laco=1; //in�cio do la�o
	
	for(laco=1;laco=1;)
	{ //in�cio do la�o
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //(scanf) escaneia a op��o do Usu�rio.(%d) para armazenar uma variavel do tipo inteiro.(&) definir o nome da variavel q ir� receber o armazenamento.
	
		system("cls"); //limpar a tela, deletar as mensagens anteriores  e melhorar o visual.
	
	
		switch(opcao)
		{ //in�cio Switch, sele��o.
			case 1:
			registro(); //chamada de fun��es.
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
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		} //fim do Switch, sele��o.

	} //fim/reinicio do la�o
} //fim

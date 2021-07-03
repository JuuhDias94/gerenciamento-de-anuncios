/* Author: Juliete Dias de Oliveira */

/*

OBSERVA��O: 
Ao rodar o c�digo para teste, colocar valor com v�rgula, n�o ponto.

*/


//bibliotecas que ser�o utilizadas:
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu(); //fun��o que mostra um menu

int main(){ //in�cio fun��o main
	
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentua��o
	
	char nomeAnuncio[100]; //vari�vel do tipo caractere para nome do an�ncio
	char cliente[100]; //vari�vel do tipo caractere para cliente
	int c; //vari�vel do tipo inteiro
	int opcao; //vari�vel do tipo inteiro para op��o escolhida do menu
	int diaInicio; //vari�vel do tipo inteiro para dia de in�cio
	int mesInicio; //vari�vel do tipo inteiro para m�s de in�cio
	int anoInicio; //vari�vel do tipo inteiro para ano de in�cio
	int diaTermino; //vari�vel do tipo inteiro para dia de t�rmino
	int mesTermino; //vari�vel do tipo inteiro para m�s de t�rmino
	int anoTermino; //vari�vel do tipo inteiro para ano de t�rmino
	int calculoAno; //vari�vel do tipo inteiro para c�lculo da quantidade de ano(s)
	int calculoMes; //vari�vel do tipo inteiro para c�lculo da quantidade de mes(es)
	int calculoDias; //vari�vel do tipo inteiro para c�lculo da quantidade de dia(s)
	int calculoAnoMes; //vari�vel do tipo inteiro para transforma��o de ano em m�s
	int calculoMesDia; //vari�vel do tipo inteiro para transforma��o de m�s em dia
	float investimentoDia; // vari�vel do tipo float para valor de investimento por dia
	float totalInvestido; //vari�vel do tipo float para valor total investido
	float maximoVisualizacoes; //vari�vel do tipo float para quantidade m�xima de visualiza��es
	float maximoCliques; //vari�vel do tipo float para quantidade m�xima de cliques
	float maximoCompartilhamentos; //vari�vel do tipo float para quantidade m�xima de compartilhamentos
	float valorVisualizacao = 0.0333; //vari�vel valor aproximado de cada visualiza��o (R$1 dividido por 30 pessoas)
	float pessoas; //vari�vel para armazenar n�mero de pessoas que visualizar�o o an�ncio original
	float pessoasClicam = 0.12; //vari�vel clique por pessoa que visualiza ( 12 cliques divididos por 100 visualiza��es)
	float pessoasCompartilham = 0.15; //vari�vel compartilhamento por pessoa que clica (3 compartilhamentos divididos por 20 cliques)
	float visualizacaoCompartilhamento = 40; //vari�vel n�mero de visualiza��es por compartilhamento
	float compartilhamento1, compartilhamento2, compartilhamento3; //vari�veis compartilhamentos
	
	//la�o de repeti��o que mostra menu:
	while(1){
		opcao = menu(); //chama fun��o menu
		
		switch(opcao){ //executa de acordo com a op��o escolhida do menu
		case 1: //pede dados do an�ncio
			printf("Digite o nome do an�ncio: "); //pede nome do an�ncio
			fgets(nomeAnuncio, 99, stdin); //armazena nome do an�ncio
		
			printf("\nDigite o nome do cliente: "); //pede nome do cliente
			fgets(cliente, 99, stdin); //armazena nome do cliente
		
			printf("\nDigite o dia de in�cio: "); //pede dia de in�cio
			scanf_s("%d", &diaInicio); //armazena dia de in�cio
			printf("\nDigite o m�s de in�cio: "); //pede m�s de in�cio
			scanf_s("%d", &mesInicio); //armazena m�s de in�cio
			printf("\nDigite o ano de in�cio: "); //pede ano de in�cio
			scanf_s("%d", &anoInicio); //armazena ano de in�cio
		
			printf("\nDigite o dia de t�rmino: "); //pede dia de t�rmino	
			scanf_s("%d", &diaTermino); //armazena dia de t�rmino
			printf("\nDigite o m�s de t�rmino: "); //pede m�s de t�rmino
			scanf_s("%d", &mesTermino); //armazena m�s de t�rmino
			printf("\nDigite o ano de t�rmino: "); //pede ano de t�rmino
			scanf_s("%d", &anoTermino); //armazena ano de t�rmino
		
			printf("\nDigite o valor de investimento por dia: "); //pede o valor de investimento por dia
			scanf_s("%f", &investimentoDia); //armazena o valor de investimento por dia
			
			while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
			
			printf("\n\nAN�NCIO CADASTRADO COM SUCESSO!\n\n"); //imprime na tela que o an�ncio foi cadastrado com sucesso
			system("pause");
			break;
		case 2: //mostra relat�rio do an�ncio
		
			/* ----- IN�CIO VALOR TOTAL INVESTIDO ----- */
			calculoAno = (anoTermino - anoInicio); //calcula quantidade de ano(s)
			calculoMes = (mesTermino - mesInicio); //calcula quantidade de mes(es)
			calculoDias = (diaTermino - diaInicio); //calcula quantidade de dia(s)
	
			calculoAnoMes = (calculoAno * 12) + calculoMes; //transforma ano em m�s e soma com a quantidade de m�s calculado anteriormente
			if(calculoAnoMes < 0){ //verifica se m�s deu negativo, se sim, deixa ele positivo
				calculoAnoMes = calculoAnoMes * (-1); //torna positivo m�s negativo
			}
	
			//para o c�lculo, considera como se todos os meses tivessem 30 dias:
			calculoMesDia = (calculoAnoMes * 30) + calculoDias; //transforma m�s em dia e soma com a quantidade de dia calculado anteriormente
			if(calculoMesDia < 0){ //verifica se dia deu negativo, se sim, deixa ele positivo
				calculoMesDia = calculoMesDia * (-1); //torna positivo dia negativo
			}
	
			totalInvestido = (investimentoDia * calculoMesDia); //calcula o valor total investido
			printf("\nValor total investido: %.2f\n", totalInvestido); //imprime valor total investido
			/* ----- FIM VALOR TOTAL INVESTIDO ----- */
			
			
			/* ----- IN�CIO QUANTIDADE M�XIMA DE VISUALIZA��ES ----- */	
			//condicional para testar total investido:
			if(totalInvestido > 0){ //se o valor investido for maior que zero, realiza o c�lculo abaixo
				pessoas = (totalInvestido / valorVisualizacao); //primeira quantidade de visualiza��es
			}
			else { //se o valor for zero ou negativo, mostra mensagem de erro
				printf("\n\nERRO! N�o houve valor investido.\n\n");
			}
			
			//condicional para testar n�mero de pessoas que visualizar�o o an�ncio:
			if(pessoas >= 1){ //se pelo menos uma pessoa for visualizar o an�ncio, realiza os c�lculos abaixo
				compartilhamento1 = (pessoas * pessoasClicam * pessoasCompartilham) * visualizacaoCompartilhamento; //segunda quantidade de visualiza��es
				compartilhamento2 = (compartilhamento1 * pessoasClicam * pessoasCompartilham) * visualizacaoCompartilhamento; //terceira quantidade de visualiza��es
				compartilhamento3 = (compartilhamento2 * pessoasClicam * pessoasCompartilham) * visualizacaoCompartilhamento; //quarta quantidade de visualiza��es
			}
			else{ //se nenhuma pessoa for visualizar o an�ncio
				printf("\nNenhuma pessoa visualizar� o an�ncio.\n");
			}
			
			//soma da quantidade m�xima de visualiza��es:
			maximoVisualizacoes = pessoas + compartilhamento1 + compartilhamento2 + compartilhamento3;
			
			printf("Quantidade m�xima de visualiza��es: %.f\n", maximoVisualizacoes); //imprime na tela a quantidade m�xima de visualiza��es
			/* ----- FIM QUANTIDADE M�XIMA DE VISUALIZA��ES ----- */
			
			
			/* ----- IN�CIO QUANTIDADE M�XIMA DE CLIQUES ----- */
			if(pessoas >= 1){ //se pelo menos uma pessoa for visualizar o an�ncio, realiza o c�lculo abaixo
				maximoCliques = maximoVisualizacoes * pessoasClicam;
			}
			else{ //se nenhuma pessoa for visualizar o an�ncio
				printf("\nO an�ncio n�o ter� cliques.\n");
			}
			
			printf("Quantidade m�xima de cliques: %.f\n", maximoCliques); //imprime na tela a quantidade m�xima de cliques
			/* ----- FIM QUANTIDADE M�XIMA DE CLIQUES ----- */
			
			
			/* ----- IN�CIO QUANTIDADE M�XIMA DE COMPARTILHAMENTOS ----- */
			if(pessoas >= 1){ //se pelo menos uma pessoa for visualizar o an�ncio, realiza o c�lculo abaixo
				maximoCompartilhamentos = maximoCliques * pessoasCompartilham;
			}
			else{ //se nenhuma pessoa for visualizar o an�ncio
				printf("\nO an�ncio n�o ter� compatilhamentos.\n");
			}
			
			printf("Quantidade m�xima de compartilhamentos: %.f\n\n", maximoCompartilhamentos); //imprime na tela a quantidade m�xima de compartilhamentos
			/* ----- FIM QUANTIDADE M�XIMA DE COMPARTILHAMENTOS ----- */
			
			system("pause");
			break;
		case 3: //encerra o sistema
			printf("O sistema foi encerrado com sucesso!\n");
			return 0;
		default: //caso uma op��o inv�lida seja digitada
			printf("\nOP��O INV�LIDA!\n\n");
			system("pause");
			break;				
		}
	}	
	
	system("pause");
	return 0;
	
} //fim fun��o main

int menu(){ //in�cio fun��o menu
	
	int opcao, c; //vari�veis do tipo inteiro
	
	system("cls"); //limpa a tela

	//menu do sistema de cadastro de an�ncio:
	printf("SISTEMA DE CADASTRO DE AN�NCIO\n\n");
	printf("1 - Cadastrar an�ncio\n");
	printf("2 - Relat�rio do an�ncio\n");
	printf("3 - Sair\n\n");
	
	printf("Digite a op��o desejada: "); //pede op��o desejada
	scanf_s("%d", &opcao); //armazena a op��o escolhida
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
	
	printf("\n"); //pula linha
	
	return opcao;
	
} //fim fun��o menu


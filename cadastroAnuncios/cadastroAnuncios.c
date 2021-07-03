/* Author: Juliete Dias de Oliveira */

/*

OBSERVAÇÃO: 
Ao rodar o código para teste, colocar valor com vírgula, não ponto.

*/


//bibliotecas que serão utilizadas:
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu(); //função que mostra um menu

int main(){ //início função main
	
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentuação
	
	char nomeAnuncio[100]; //variável do tipo caractere para nome do anúncio
	char cliente[100]; //variável do tipo caractere para cliente
	int c; //variável do tipo inteiro
	int opcao; //variável do tipo inteiro para opção escolhida do menu
	int diaInicio; //variável do tipo inteiro para dia de início
	int mesInicio; //variável do tipo inteiro para mês de início
	int anoInicio; //variável do tipo inteiro para ano de início
	int diaTermino; //variável do tipo inteiro para dia de término
	int mesTermino; //variável do tipo inteiro para mês de término
	int anoTermino; //variável do tipo inteiro para ano de término
	int calculoAno; //variável do tipo inteiro para cálculo da quantidade de ano(s)
	int calculoMes; //variável do tipo inteiro para cálculo da quantidade de mes(es)
	int calculoDias; //variável do tipo inteiro para cálculo da quantidade de dia(s)
	int calculoAnoMes; //variável do tipo inteiro para transformação de ano em mês
	int calculoMesDia; //variável do tipo inteiro para transformação de mês em dia
	float investimentoDia; // variável do tipo float para valor de investimento por dia
	float totalInvestido; //variável do tipo float para valor total investido
	float maximoVisualizacoes; //variável do tipo float para quantidade máxima de visualizações
	float maximoCliques; //variável do tipo float para quantidade máxima de cliques
	float maximoCompartilhamentos; //variável do tipo float para quantidade máxima de compartilhamentos
	float valorVisualizacao = 0.0333; //variável valor aproximado de cada visualização (R$1 dividido por 30 pessoas)
	float pessoas; //variável para armazenar número de pessoas que visualizarão o anúncio original
	float pessoasClicam = 0.12; //variável clique por pessoa que visualiza ( 12 cliques divididos por 100 visualizações)
	float pessoasCompartilham = 0.15; //variável compartilhamento por pessoa que clica (3 compartilhamentos divididos por 20 cliques)
	float visualizacaoCompartilhamento = 40; //variável número de visualizações por compartilhamento
	float compartilhamento1, compartilhamento2, compartilhamento3; //variáveis compartilhamentos
	
	//laço de repetição que mostra menu:
	while(1){
		opcao = menu(); //chama função menu
		
		switch(opcao){ //executa de acordo com a opção escolhida do menu
		case 1: //pede dados do anúncio
			printf("Digite o nome do anúncio: "); //pede nome do anúncio
			fgets(nomeAnuncio, 99, stdin); //armazena nome do anúncio
		
			printf("\nDigite o nome do cliente: "); //pede nome do cliente
			fgets(cliente, 99, stdin); //armazena nome do cliente
		
			printf("\nDigite o dia de início: "); //pede dia de início
			scanf_s("%d", &diaInicio); //armazena dia de início
			printf("\nDigite o mês de início: "); //pede mês de início
			scanf_s("%d", &mesInicio); //armazena mês de início
			printf("\nDigite o ano de início: "); //pede ano de início
			scanf_s("%d", &anoInicio); //armazena ano de início
		
			printf("\nDigite o dia de término: "); //pede dia de término	
			scanf_s("%d", &diaTermino); //armazena dia de término
			printf("\nDigite o mês de término: "); //pede mês de término
			scanf_s("%d", &mesTermino); //armazena mês de término
			printf("\nDigite o ano de término: "); //pede ano de término
			scanf_s("%d", &anoTermino); //armazena ano de término
		
			printf("\nDigite o valor de investimento por dia: "); //pede o valor de investimento por dia
			scanf_s("%f", &investimentoDia); //armazena o valor de investimento por dia
			
			while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
			
			printf("\n\nANÚNCIO CADASTRADO COM SUCESSO!\n\n"); //imprime na tela que o anúncio foi cadastrado com sucesso
			system("pause");
			break;
		case 2: //mostra relatório do anúncio
		
			/* ----- INÍCIO VALOR TOTAL INVESTIDO ----- */
			calculoAno = (anoTermino - anoInicio); //calcula quantidade de ano(s)
			calculoMes = (mesTermino - mesInicio); //calcula quantidade de mes(es)
			calculoDias = (diaTermino - diaInicio); //calcula quantidade de dia(s)
	
			calculoAnoMes = (calculoAno * 12) + calculoMes; //transforma ano em mês e soma com a quantidade de mês calculado anteriormente
			if(calculoAnoMes < 0){ //verifica se mês deu negativo, se sim, deixa ele positivo
				calculoAnoMes = calculoAnoMes * (-1); //torna positivo mês negativo
			}
	
			//para o cálculo, considera como se todos os meses tivessem 30 dias:
			calculoMesDia = (calculoAnoMes * 30) + calculoDias; //transforma mês em dia e soma com a quantidade de dia calculado anteriormente
			if(calculoMesDia < 0){ //verifica se dia deu negativo, se sim, deixa ele positivo
				calculoMesDia = calculoMesDia * (-1); //torna positivo dia negativo
			}
	
			totalInvestido = (investimentoDia * calculoMesDia); //calcula o valor total investido
			printf("\nValor total investido: %.2f\n", totalInvestido); //imprime valor total investido
			/* ----- FIM VALOR TOTAL INVESTIDO ----- */
			
			
			/* ----- INÍCIO QUANTIDADE MÁXIMA DE VISUALIZAÇÕES ----- */	
			//condicional para testar total investido:
			if(totalInvestido > 0){ //se o valor investido for maior que zero, realiza o cálculo abaixo
				pessoas = (totalInvestido / valorVisualizacao); //primeira quantidade de visualizações
			}
			else { //se o valor for zero ou negativo, mostra mensagem de erro
				printf("\n\nERRO! Não houve valor investido.\n\n");
			}
			
			//condicional para testar número de pessoas que visualizarão o anúncio:
			if(pessoas >= 1){ //se pelo menos uma pessoa for visualizar o anúncio, realiza os cálculos abaixo
				compartilhamento1 = (pessoas * pessoasClicam * pessoasCompartilham) * visualizacaoCompartilhamento; //segunda quantidade de visualizações
				compartilhamento2 = (compartilhamento1 * pessoasClicam * pessoasCompartilham) * visualizacaoCompartilhamento; //terceira quantidade de visualizações
				compartilhamento3 = (compartilhamento2 * pessoasClicam * pessoasCompartilham) * visualizacaoCompartilhamento; //quarta quantidade de visualizações
			}
			else{ //se nenhuma pessoa for visualizar o anúncio
				printf("\nNenhuma pessoa visualizará o anúncio.\n");
			}
			
			//soma da quantidade máxima de visualizações:
			maximoVisualizacoes = pessoas + compartilhamento1 + compartilhamento2 + compartilhamento3;
			
			printf("Quantidade máxima de visualizações: %.f\n", maximoVisualizacoes); //imprime na tela a quantidade máxima de visualizações
			/* ----- FIM QUANTIDADE MÁXIMA DE VISUALIZAÇÕES ----- */
			
			
			/* ----- INÍCIO QUANTIDADE MÁXIMA DE CLIQUES ----- */
			if(pessoas >= 1){ //se pelo menos uma pessoa for visualizar o anúncio, realiza o cálculo abaixo
				maximoCliques = maximoVisualizacoes * pessoasClicam;
			}
			else{ //se nenhuma pessoa for visualizar o anúncio
				printf("\nO anúncio não terá cliques.\n");
			}
			
			printf("Quantidade máxima de cliques: %.f\n", maximoCliques); //imprime na tela a quantidade máxima de cliques
			/* ----- FIM QUANTIDADE MÁXIMA DE CLIQUES ----- */
			
			
			/* ----- INÍCIO QUANTIDADE MÁXIMA DE COMPARTILHAMENTOS ----- */
			if(pessoas >= 1){ //se pelo menos uma pessoa for visualizar o anúncio, realiza o cálculo abaixo
				maximoCompartilhamentos = maximoCliques * pessoasCompartilham;
			}
			else{ //se nenhuma pessoa for visualizar o anúncio
				printf("\nO anúncio não terá compatilhamentos.\n");
			}
			
			printf("Quantidade máxima de compartilhamentos: %.f\n\n", maximoCompartilhamentos); //imprime na tela a quantidade máxima de compartilhamentos
			/* ----- FIM QUANTIDADE MÁXIMA DE COMPARTILHAMENTOS ----- */
			
			system("pause");
			break;
		case 3: //encerra o sistema
			printf("O sistema foi encerrado com sucesso!\n");
			return 0;
		default: //caso uma opção inválida seja digitada
			printf("\nOPÇÃO INVÁLIDA!\n\n");
			system("pause");
			break;				
		}
	}	
	
	system("pause");
	return 0;
	
} //fim função main

int menu(){ //início função menu
	
	int opcao, c; //variáveis do tipo inteiro
	
	system("cls"); //limpa a tela

	//menu do sistema de cadastro de anúncio:
	printf("SISTEMA DE CADASTRO DE ANÚNCIO\n\n");
	printf("1 - Cadastrar anúncio\n");
	printf("2 - Relatório do anúncio\n");
	printf("3 - Sair\n\n");
	
	printf("Digite a opção desejada: "); //pede opção desejada
	scanf_s("%d", &opcao); //armazena a opção escolhida
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
	
	printf("\n"); //pula linha
	
	return opcao;
	
} //fim função menu


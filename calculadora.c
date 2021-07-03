/* Author: Juliete Dias de Oliveira */

/*

OBSERVA��O: 
Ao rodar o c�digo para teste, colocar valor com v�rgula, n�o ponto.

*/


//bibliotecas que ser�o utilizadas:
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){ //in�cio fun��o main
	
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentua��o
	
	float valorInvestido = 0; //vari�vel do tipo float (para n�meros com v�rgula)
	float valorVisualizacao = 0.0333; //vari�vel valor aproximado de cada visualiza��o (R$1 dividido por 30 pessoas)
	float pessoas = 0; //vari�vel para armazenar n�mero de pessoas que visualizar�o o an�ncio original
	float pessoasVisualizacao; //vari�vel para armazenar n�mero total de pessoas que visualizar�o o an�ncio
	float pessoasClicam = 0.12; //vari�vel clique por pessoa que visualiza ( 12 cliques divididos por 100 visualiza��es)
	float pessoasCompartilham = 0.15; //vari�vel compartilhamento por pessoa que clica (3 compartilhamentos divididos por 20 cliques)
	float visualizacaoCompartilhamento = 40; //vari�vel n�mero de visualiza��es por compartilhamento
	float compartilhamento1, compartilhamento2, compartilhamento3; //vari�veis compartilhamentos
	int c = 0; //vari�vel do tipo inteiro
	
	printf("Digite o valor (em reais) que ser� investido: "); //pede o valor que ser� investido
	scanf_s("%f", &valorInvestido); //armazena o valor
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
	
	//condicional para testar valor inserido:
	if(valorInvestido > 0){ //se o valor inserido for maior que zero, realiza o c�lculo abaixo
		pessoas = (valorInvestido / valorVisualizacao); //primeira quantidade de visualiza��es
	}
	else { //se o valor for zero ou negativo, mostra mensagem de erro
		printf("\n\nERRO! O valor investido deve ser maior que zero.\n\n");
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
	
	//soma da quantidade total aproximada de pessoas que visualizar�o o an�ncio:
	pessoasVisualizacao = pessoas + compartilhamento1 + compartilhamento2 + compartilhamento3;
	
	printf("\nValor investido: %.2f\n", valorInvestido); //imprime na tela o valor investido
	printf("Proje��o aproximada da quantidade m�xima de pessoas que visualizar�o o an�ncio: %.f\n\n", pessoasVisualizacao); //imprime na tela a quantidade de pessoas que visualizar�o o an�ncio
	
	system("pause");
	return 0;
	
} //fim fun��o main

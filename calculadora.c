/* Author: Juliete Dias de Oliveira */

/*

OBSERVAÇÃO: 
Ao rodar o código para teste, colocar valor com vírgula, não ponto.

*/


//bibliotecas que serão utilizadas:
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){ //início função main
	
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentuação
	
	float valorInvestido = 0; //variável do tipo float (para números com vírgula)
	float valorVisualizacao = 0.0333; //variável valor aproximado de cada visualização (R$1 dividido por 30 pessoas)
	float pessoas = 0; //variável para armazenar número de pessoas que visualizarão o anúncio original
	float pessoasVisualizacao; //variável para armazenar número total de pessoas que visualizarão o anúncio
	float pessoasClicam = 0.12; //variável clique por pessoa que visualiza ( 12 cliques divididos por 100 visualizações)
	float pessoasCompartilham = 0.15; //variável compartilhamento por pessoa que clica (3 compartilhamentos divididos por 20 cliques)
	float visualizacaoCompartilhamento = 40; //variável número de visualizações por compartilhamento
	float compartilhamento1, compartilhamento2, compartilhamento3; //variáveis compartilhamentos
	int c = 0; //variável do tipo inteiro
	
	printf("Digite o valor (em reais) que será investido: "); //pede o valor que será investido
	scanf_s("%f", &valorInvestido); //armazena o valor
	while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
	
	//condicional para testar valor inserido:
	if(valorInvestido > 0){ //se o valor inserido for maior que zero, realiza o cálculo abaixo
		pessoas = (valorInvestido / valorVisualizacao); //primeira quantidade de visualizações
	}
	else { //se o valor for zero ou negativo, mostra mensagem de erro
		printf("\n\nERRO! O valor investido deve ser maior que zero.\n\n");
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
	
	//soma da quantidade total aproximada de pessoas que visualizarão o anúncio:
	pessoasVisualizacao = pessoas + compartilhamento1 + compartilhamento2 + compartilhamento3;
	
	printf("\nValor investido: %.2f\n", valorInvestido); //imprime na tela o valor investido
	printf("Projeção aproximada da quantidade máxima de pessoas que visualizarão o anúncio: %.f\n\n", pessoasVisualizacao); //imprime na tela a quantidade de pessoas que visualizarão o anúncio
	
	system("pause");
	return 0;
	
} //fim função main

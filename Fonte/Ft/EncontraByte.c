#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include "funcoesEspecificasGM.h"
//Booleano Falso hahaha!!!
#define bool   int
#define TRUE   1
#define FALSE  0
//cores em ANSI utilizadas 
#define ANSI_COLOR_RED      "\x1b[31m" 
#define ANSI_COLOR_GRAY     "\e[0;37m"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {

	
	char Id[4];
	char Nome[100];
	bool escolha, i;
	int j = 0;
	
	//Abre arquivo de leituras
	FILE *capturado;
	char Linha[33],lixo[100];
	char *result;
	char byte[3];
	
	printf("Qual byte deseja encontrar?");
	scanf("%s",byte);
	
	byte[0] = toupper(byte[0]);
	byte[1] = toupper(byte[1]);
		
	capturado = fopen("Capturado.txt", "rt");
	

	
	if (capturado == NULL){
		printf("ATENCAO:Não foi possivel ler o arquivo\n");
		printf("Por favor verifique se o arquivo capturados existe na mesma pasta onde esra o programa!\n");
		
	}
	
	i = 1;
	result = fgets(lixo, 100, capturado);  // o 'fgets' lê até 31 caracteres ou até o '\n' (grava dentro do linha)
	
	while (!feof(capturado)){
    	result = fgets(Linha, 33, capturado);  // o 'fgets' lê até 31 caracteres ou até o '\n' (grava dentro do linha)
    	if (result) {
    		printf("linha %d - ", j);
    		for (i=0;i<33;i++){
				if(Linha[i] == byte[0] && Linha[i+1] == byte[1]){	
					//Linha[31] = 'null';
					printf("[Aqui tem %s] ",byte);
					//printf("%s",Linha);
					//result = fgets(Linha, 33, capturado);
			
				}
					printf("%c",Linha[i]);
			}
		
		}
		j++;
	}

	fclose(capturado);
 
	return 0;
		
}

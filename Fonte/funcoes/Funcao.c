#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Booleano Falso hahaha!!!
#define bool   int
#define TRUE   1
#define FALSE  0


void assinatura(char Nome[100]){
	system("cls");
	printf("Program developed by Belisca Lua! \nVersion: 0.1.2 \n\n");
	
	printf("--------------------------------------------------------\n\n");
	printf("Filtro de protocolo GM");
	printf("\n\n");
}

int converteAscii(int Tamanho1, int Tamanho2){
	int TamanhoConvertido;
	if (Tamanho1>57){
		Tamanho1 = (Tamanho1 - 55) * 16;
	} else {
		Tamanho1 = (Tamanho1 - 48) * 16;
	}
	if (Tamanho2 > 57){
		Tamanho2 = (Tamanho2 - 55);
	} else {
		Tamanho2 = (Tamanho2 - 48);
	}
	
	TamanhoConvertido = Tamanho1+Tamanho2;
	return TamanhoConvertido;
}
char ConstroiFrameCase(int Tamanho,char Linha[33], char *result, FILE *capturado, FILE *Saida){

	bool fim;
	int i;
	printf(" TAMANHO (%d) - ", Tamanho -1);
	fprintf(Saida," TAMANHO (%d) - ",Tamanho -1);
	Tamanho *= 3;
	Tamanho -=18;
	printf(" Pacote ");
	fprintf(Saida," Pacote - ");
	
	while(Tamanho > 0){
		//Esta linha deve pegar apenas as informacoes relevantes do frame com o 2C
		for (i=16;i<=30;i++){
			printf("%c",Linha[i]);
			fprintf(Saida,"%c",Linha[i]);
		}
		//Pula a linha Sd 7EA.30.00.0A.
		result = fgets(Linha, 33, capturado);
		//reagrupa demais linhas
		do{
			result = fgets(Linha, 100, capturado);
			for(i=10;i<=30;i++){
				printf("%c",Linha[i]);
				fprintf(Saida,"%c",Linha[i]);  
				Tamanho = Tamanho - 1;
				if(Tamanho <= 0){
					break;
				}
			}
		}while (Tamanho > 0);				
	}
	printf("\n");
	fprintf(Saida,"\n");
	return TRUE;
	//return VetResposta;
}

void GravaTXT() {
	int result;
	FILE *Saida;
	int i;
	//clrscr();
	Saida = fopen("Saida.txt", "wt");  // Cria um arquivo texto para gravação
	
	if (Saida == NULL){ // Se nào conseguiu criar
		printf("Problemas na CRIACAO do arquivo\n");
		return;
	}
	
	for (i = 0; i<10;i++){
		
		// A funcao 'fprintf' devolve o número de bytes gravados 
		// ou EOF se houve erro na gravação
		result = fprintf(Saida,"//",i);  					  
		
		if (result == EOF){
		printf("Erro na Gravacao\n");
		}		    
	}
	
	fclose(Saida);
}

int EscolheID(){
	//Esta função tem como objetivo interpretar os IDs do capturado;
	//e mostrar Escolher por si só o ID de teste!
	int escolha;
	
	char Id[4];
	FILE* ID;
	int capturado;
	
	capturado = fopen("Capturado.txt", "rt");
	
	printf("Deseja usar ID automatico?\n   - SIM(1)\n   - NAO(0)");
	scanf("%d", escolha);
	
	if(escolha == 1){
		
	}else{
		return 0;
	}
	
}

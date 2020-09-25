
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "funcoes\funcao.h"

int main(int argc, char *argv[]) {


	char Id[4];
	char Nome[100];
	bool escolha;
	
	assinatura('v');
	//printf("Nome do modulo:");
	//scanf("%s", &Nome);
	printf("ID de Teste : ");
	scanf("%s", &Id);
	
	printf("Pacotes selecionados altomaticamente? \nSim(1)\nNao(0)\nResposta:  ");
	scanf("%d", &escolha);
	
	Id[0] = toupper(Id[0]);
	Id[1] = toupper(Id[1]);
	Id[2] = toupper(Id[2]);
	
	//system("cls");
	//system("color 0B");
	
	//Abre arquivo de leituras
	FILE *capturado;
	char Linha[33],lixo[100];
	char *result;
	
	// Abre arquivo de gravação 
	int Ret_Output_File;
	FILE *Saida;
	Saida = fopen("Saida.txt", "wt");  // Cria um arquivo texto para gravação
	
	
	int i,Tamanho,k,ContaPacote;
	bool cabecalho = TRUE;
	k = 0;
	ContaPacote = 0;
	
	capturado = fopen("Capturado.txt", "rt");
	
	assinatura(Nome);
	
	if (capturado == NULL){
		printf("ATENCAO:Não foi possivel ler o arquivo\n");
		printf("Por favor verifique se o arquivo capturados existe na mesma pasta onde esra o programa!\n");
		return;
	}
	
	i = 1;
	result = fgets(lixo, 100, capturado);  // o 'fgets' lê até 31 caracteres ou até o '\n' (grava dentro do linha)
	
	while (!feof(capturado)){
    	result = fgets(Linha, 33, capturado);  // o 'fgets' lê até 31 caracteres ou até o '\n' (grava dentro do linha)
    	if (result) {
    		
    		
			if(Linha[13] == '2' && Linha[14] == 'C'){	
				//Linha[31] = 'null';
				Tamanho = converteAscii(Linha[10], Linha[11]);
				ConstroiFrameCase(Tamanho,Linha,result,capturado,Saida);
				ContaPacote++;
			}
		}	
	}
	int SizeVet = ContaPacote * 8;
	char RespPronta[SizeVet];
	
	//printf("COntador %d", ContaPacote); -> 6
	capturado = fopen("Capturado.txt", "rt");
	
	switch (escolha){
		case TRUE:
      		// código 1
      		while(ContaPacote>0){
    			result = fgets(Linha, 33, capturado);  // o 'fgets' lê até 31 caracteres ou até o '\n' (grava dentro do linha)
    			if (result) {
    				//printa cabeçalho
					if(cabecalho){
						printf("\nRESPOSTAS:\n");
						fprintf(Saida,"\nRESPOSTA\n");
						cabecalho = FALSE;
					}
					//while(ContaPacote >= 0){
			
					//printf("\nID  %c%c%c\n",Linha[3],Linha[4],Linha[5] );
			
					//Respostas dos pacotes individuais
					if(Linha[3] == Id[0] && Linha[4] == Id[1] && Linha[5] == Id[2]){
					ContaPacote--;
					//printa respostas
						if(Linha[7] == 0x30){
							//não imprime nada
						}else{
							for(i=7;i<=30;i++){
								printf("%c",Linha[i]);
								fprintf(Saida,"%c",Linha[i]);
								
							}
						}
						printf("\n");
						fprintf(Saida,"\n");				
					}
				}
			}
			break;
		case FALSE:
      		// código 2
      		while (!feof(capturado)){
    			result = fgets(Linha, 33, capturado);  // o 'fgets' lê até 31 caracteres ou até o '\n' (grava dentro do linha)
    			if (result) {
    				//printa cabeçalho
					if(cabecalho){
						printf("\nRESPOSTAS:\n");
						fprintf(Saida,"\nRESPOSTA\n");
						cabecalho = FALSE;
					}
					//while(ContaPacote >= 0){
			
					//printf("\nID  %c%c%c\n",Linha[3],Linha[4],Linha[5] );
			
					//Respostas dos pacotes individuais
					if(Linha[3] == Id[0] && Linha[4] == Id[1] && Linha[5] == Id[2]){
					ContaPacote--;
					//printa respostas
						if(Linha[7] == 0x30){
							//não imprime nada
						}else{
							for(i=7;i<=30;i++){
								printf("%c",Linha[i]);
								fprintf(Saida,"%c",Linha[i]);
								
							}
						}
						printf("\n");
						fprintf(Saida,"\n");				
					}
				}
			}
			break;
	}
	
	printf("\n\n\n""resposta pronta: ");
	//fprintf("\n\n\n""resposta pronta: ");
	
	//GravaTXT(result,capturado); 
	fclose(Saida);
	fclose(capturado);
 
	return 0;
		
}

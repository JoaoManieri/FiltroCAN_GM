#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Booleano Falso hahaha!!!
#define bool   int
#define TRUE   1
#define FALSE  0

void assinatura(char Nome[100]);
int converteAscii(int Tamanho1, int Tamanho2);
char ConstroiFrameCase(int Tamanho,char Linha[33], char *result, FILE *capturado, FILE *Saida);
void GravaTXT();
int EscolheID();
int EncontraByte();


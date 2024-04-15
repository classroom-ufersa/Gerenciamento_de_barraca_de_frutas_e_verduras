#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Função para mostra o menu*/
void menu();

/*Função para verificar se existem caracter especiais no nome*/
int verificaCaracteresEspeciais(char *nome);

/*Função para verificar se existem números no nome*/
int verificaNumeros(char *nome);

/*Função que verifica o nome*/
int verificaNome(char *nome);

/*Função para verificar a escolha do menu*/
char verificaEscolha(char escolha);

/*Função para passar os dados em maiusculo*/
void passaMaiusculo(char *nome);

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Struct que irar guardar os dados das barracas*/
typedef struct barracas Barraca;

/*Struct que irar guardar os dados das barracas*/
typedef struct listabarracas ListaBarracas;

/*Função criada para criar a lista de barracas*/
void CriaListaBarracas(ListaBarracas **lista);

/*Função para pegar os dados do arquivos txt e passar para as listas*/
ListaBarracas *NovaBarracatxt(char nome[], char localizacao[]);

/*Função para passar os dados da barraca para lista*/
void AdicionaBarracaLista(ListaBarracas **lista);

/*Função para remover uma barraca escolhida pelo usuario*/
void RemoveBarraca(ListaBarracas **lista);
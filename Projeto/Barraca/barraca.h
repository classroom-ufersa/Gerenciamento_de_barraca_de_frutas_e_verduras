#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

/*Struct que irar guardar os dados das barracas*/
typedef struct barracas Barracas;

/*Struct criada para listar as barracas*/
typedef struct ListBarracas ListaBarracas;

/*Função que cria a lista de barracas*/
void criarlista(ListaBarracas **lista);

/*Função que adiciona uma barraca na lista*/
void AdicionarBarraca(ListaBarracas **lista, Barracas barraca);


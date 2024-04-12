#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

/*Struct que irar guardar os dados das barracas*/
typedef struct barracas Barraca;

/*Struct que irar guardar os dados das barracas*/
typedef struct listabarracas ListaBarracas;

/*Função que irar criar a lista de barracas*/
void CriaListaBarracas(ListaBarracas **lista);

/*Função que irar adicionar uma barraca na lista*/
void AdicionarBarraca(ListaBarracas **lista);

/*Função que irar remover uma barraca da lista*/
void RemoverBarraca(ListaBarracas **lista);

/*Função de editar um produto escolhido pelo usario*/
void EditaProduto(ListaBarracas **lista);
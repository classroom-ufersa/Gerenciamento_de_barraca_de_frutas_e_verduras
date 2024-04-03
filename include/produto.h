#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "barraca.h"
#define Max_Caracter 300

/*Struct que irar guardar os dados dos produtos*/
typedef struct produto Produto;

/*Struct criada para listar os produtos*/
typedef struct listaprodutos ListaProdutos;

/*Função criada para criar a lista de produtos*/
void CriaLista(ListaProdutos **lista);

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

/*Função criada para adicionar um produto na barraca*/
void AdicionarProduto(ListaBarracas **listabarraca, ListaProdutos **listaprodutos);

/*Função criada para remover um produto dentro da lista*/
void Remover_produto(ListaBarracas **listabarraca, ListaProdutos **listaproduto);

/*Função criada para buscar um produto dentro da lista*/
void BuscarProduto(ListaBarracas **listabarraca, ListaProdutos **listaproduto);

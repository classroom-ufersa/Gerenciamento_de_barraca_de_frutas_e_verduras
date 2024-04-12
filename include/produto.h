#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "barraca.h"

#define Max_Caracter 300

/*Struct que irar guardar os dados dos produtos*/
typedef struct produto Produto;

/*Struct criada para listar os produtos*/
typedef struct listaprodutos ListaProdutos;

/*Função criada para criar a lista de produtos*/
void CriaLista(ListaProdutos **lista);

/*Função para pegar os dados do arquivos e passar para a lista*/
void NovoProdutotxt(ListaBarracas **lista,char *nomebarraca, char *nomeproduto, float preco, char *tipo, int quantidade);

/*Função para adicionar um novo produto dentro de uma barraca escolhida pelo usuario*/
void AdicionaProduto(ListaBarracas **lista);

/*Função para remover um produto digitado pelo usuario*/
void RemoveProduto(ListaBarracas **lista);

/*Função para realizar venda de um produto escolhido pelo usuario*/
void RealizaVenda(ListaBarracas **lista);

/*Função para buscar um produto digitado pelo usuario*/
void BuscaProduto(ListaBarracas **lista);

/*Função para editar um produto digitado pelo usuario*/
void EditaProduto(ListaBarracas **lista);

/*Função criada para mostrar as barracas e seus dados*/
void MostraBarracas(ListaBarracas **lista);

/*Função criada para remover um produto quando sua quantidade de estoque é igual a 0*/
void RemoveVenda(ListaBarracas **lista, char NomeProduto[], char NomeBarraca[]);

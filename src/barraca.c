#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/include/barraca.h"
#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/include/produto.h"

struct barracas{
    char nome[Max_Caracter];
    char localizacao[Max_Caracter];
    ListaProdutos *produtos;
};

struct listabarracas{
    Barraca barraca;
    ListaBarracas *prox;
};

void CriaListaBarracas(ListaBarracas **lista)
{
    *lista = NULL;
}
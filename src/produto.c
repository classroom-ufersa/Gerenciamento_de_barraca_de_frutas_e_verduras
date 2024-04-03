#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/include/barraca.h"
#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/include/produto.h"

struct produto{
    char nome[Max_Caracter];
    char tipo[Max_Caracter]; //Fruta ou verdura
    float preco;
    int quantidade;//Para um determinado produto
};

struct listaprodutos{
    Produto produto;
    ListaProdutos *prox;
};

void CriaLista(ListaProdutos **lista)
{
    *lista = NULL;
}

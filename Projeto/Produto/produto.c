#include "produto.h"
#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/Projeto/Barraca/barraca.h"

struct produtos{
    char nome[30];
    float preco;
    char tipo[30];//fruta ou verdura
    int quantidadeestq;
};

struct listaprodutos{
    Produto produtos;
    ListaProdutos *proximo;
};

void criarlistaprodutos(ListaProdutos **lista)
{
    *lista = NULL;
}
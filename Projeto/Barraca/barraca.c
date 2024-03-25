#include "barraca.h"
#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/Projeto/Produto/produto.h"
struct barracas
{
    char nome[30];
    char localizacao[30];
    ListaProdutos *produtos;
};

struct ListBarracas
{
    Barracas Barraca;
    ListaBarracas *proximo;
};

void criarlista(ListaBarracas **lista)
{
    *lista = NULL;
}

void AdicionarBarraca(ListaBarracas **lista, Barracas barraca)
{
    ListaBarracas *novo = (ListaBarracas *)malloc(sizeof(ListaBarracas));
    novo->Barraca = barraca;
    novo->proximo = *lista;
    *lista = novo;

    FILE *arquivo = fopen("barracas.txt", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    fprintf(arquivo, "%s\n%s\n", barraca.nome, barraca.localizacao);

    fclose(arquivo);
    printf("Barraca adicionada com sucesso!\n");
}
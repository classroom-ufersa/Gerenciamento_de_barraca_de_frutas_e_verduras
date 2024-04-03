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

void AdicionarBarraca(ListaBarracas **lista)
{
    printf("Digite o nome da barraca: ");
    char nome[Max_Caracter];
    scanf(" %s", nome);

    //verificando se o nome digitado ja existe
    ListaBarracas *aux = *lista;

    while (aux != NULL && strcmp(aux->barraca.nome, nome) == 0)
    {
        printf("Nome ja existente, digite outro nome: ");
        scanf(" %s", nome);
    }

    printf("Digite a localizacao da barraca: ");
    char localizacao[Max_Caracter];
    scanf(" %s", localizacao);

    ListaBarracas *novo = (ListaBarracas *)malloc(sizeof(ListaBarracas));

    strcpy(novo->barraca.nome, nome);
    strcpy(novo->barraca.localizacao, localizacao);

    novo->prox = *lista;
    *lista = novo;

    printf("Barraca cadastrada com sucesso\n");
}

void RemoverBarraca(ListaBarracas **lista)
{
    printf("Digite o nome da barraca que deseja remover: ");
    char nome[Max_Caracter];
    scanf(" %s", nome);

    ListaBarracas *aux = *lista;

    //verificando se a barraca existe
    while (aux != NULL && strcmp(aux->barraca.nome, nome) != 0)
    {
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        printf("Barraca nao encontrada\n");
        return;
    }

    //removenndo a barraca
    if (aux == *lista)
    {
        *lista = aux->prox;
    }
    else
    {
        ListaBarracas *aux2 = *lista;
        while (aux2->prox != aux)
        {
            aux2 = aux2->prox;
        }

        aux2->prox = aux->prox;
    }

    free(aux);

    printf("Barraca removida com sucesso\n");
}

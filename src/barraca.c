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

void AdicionaBarracaLista(ListaBarracas **lista)
{
    //variaveis usadas
    char NomeBarraca[Max_Caracter];
    char LocalizacaoBarraca[Max_Caracter];

    //recebe o nome da barraca
    printf("Digite o nome da barraca: ");
    scanf(" %[^\n]", NomeBarraca);
    
    //verifica se a barraca já existe
    ListaBarracas *auxnomerepetido = *lista;

    while(auxnomerepetido != NULL)
    {
        if(strcmp(auxnomerepetido->barraca.nome, NomeBarraca) == 0)
        {
            printf("Barraca ja existe\n");
            return;
        }
        auxnomerepetido = auxnomerepetido->prox;
    }

    //recebe a localização da barraca
    printf("Digite a localizacao da barraca: ");
    scanf(" %[^\n]", LocalizacaoBarraca);

    //cria a nova barraca
    ListaBarracas *nova = (ListaBarracas *)malloc(sizeof(ListaBarracas));
    strcpy(nova->barraca.nome, NomeBarraca);
    strcpy(nova->barraca.localizacao, LocalizacaoBarraca);
    CriaLista(&nova->barraca.produtos);

    //se a lista estiver vazia
    if(*lista == NULL)
    {
        nova->prox = NULL;
        *lista = nova;
        return;
    }

    //se a lista não estiver vazia
    ListaBarracas *auxnomerepetido2 = *lista;
    ListaBarracas *auxnomerepetido3 = NULL;

    while(auxnomerepetido2 != NULL && strcmp(auxnomerepetido2->barraca.nome, NomeBarraca) < 0)
    {
        auxnomerepetido3 = auxnomerepetido2;
        auxnomerepetido2 = auxnomerepetido2->prox;
    }

    //se a barraca for a primeira da lista
    if(auxnomerepetido3 == NULL)
    {
        nova->prox = *lista;
        *lista = nova;
    }
    else
    {
        auxnomerepetido3->prox = nova;
        nova->prox = auxnomerepetido2;
    }

    printf("Barraca adicionada com sucesso!\n");
}

void RemoveBarraca(ListaBarracas **lista)
{
    //variaveis usadas
    char NomeBarraca[Max_Caracter];

    //recebe o nome da barraca
    printf("Digite o nome da barraca que deseja remover: ");
    scanf(" %[^\n]", NomeBarraca);

    //verificando se a barraca existe
    ListaBarracas *auxremove = *lista;
    ListaBarracas *auxremove2 = NULL;

    while(auxremove != NULL)
    {
        if(strcmp(auxremove->barraca.nome, NomeBarraca) == 0)
        {
            break;
        }
        auxremove2 = auxremove;
        auxremove = auxremove->prox;
    }

    //se a barraca não existir
    if(auxremove == NULL)
    {
        printf("Barraca nao encontrada\n");
        return;
    }

    //se a barraca for a primeira da lista
    if(auxremove2 == NULL)
    {
        *lista = auxremove->prox;
    }
    else
    {
        auxremove2->prox = auxremove->prox;
    }

    //liberando a memoria
    free(auxremove);

    printf("Barraca removida com sucesso!\n");
}
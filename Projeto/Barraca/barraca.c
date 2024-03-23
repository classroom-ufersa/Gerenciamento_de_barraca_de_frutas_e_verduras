#include "barraca.h"

struct barracas
{
    char nome[30];
    char localizacao[30];
    int Produtos_disponiveis;
};

struct ListBarracas
{
    Barracas Barraca;
    ListaBarracas *proximo;
};

ListaBarracas *Primeiro;
ListaBarracas *ultimo;

void Add_Barraca(char nome[], char localizacao[])
{
    ListaBarracas *NewBarraca = (ListaBarracas *)(sizeof(ListaBarracas));
    
    if(NewBarraca == NULL)
    {
        printf("não foi possivel alocar memoria\n");
        exit(1);
    }
    
    strcpy(NewBarraca->Barraca.nome,nome);
    strcpy(NewBarraca->Barraca.localizacao,localizacao);
    NewBarraca->proximo = NULL;
    
    if(Primeiro = NULL)
    {
        Primeiro = ultimo = NewBarraca;
    }
    
    else
    {
        ultimo->proximo = NewBarraca;
        ultimo = NewBarraca;
    }

    printf("BARRACA ADICIONADA!");

}
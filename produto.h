#include <stdio.h>
#include <stdlib.h>

/*Adicionando a struct do tipo Produto que irar guardar os dados referentes ao Produto*/
typedef struct produto
{
    char nome[30];
    char tipo[30];/*Fruta ou verdura*/
    float preco;
    int Qnt_Estoque;
}Produto;
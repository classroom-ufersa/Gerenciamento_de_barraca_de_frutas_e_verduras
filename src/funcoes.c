#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/include/funcoes.h"

int verificaCaracteresEspeciais(char *nome)
{
    int i;
    for (i = 0; i < strlen(nome); i++)
    {
        if ((nome[i] >= 33 && nome[i] <= 47) || (nome[i] >= 58 && nome[i] <= 64) || (nome[i] >= 91 && nome[i] <= 96) || (nome[i] >= 123 && nome[i] <= 126))
        {
            return 1;
        }
    }
    return 0;
}

int verificaNumero(char *nome)
{
    int i;
    for (i = 0; i < strlen(nome); i++)
    {
        if (nome[i] >= 48 && nome[i] <= 57)
        {
            return 1;
        }
    }
    return 0;
}

int verificaNome(char *nome)
{
    if (verificaCaracteresEspeciais(nome) == 1)
    {
        return 1;
    }
    if (verificaNumero(nome) == 1)
    {
        return 1;
    }

    return 0;
}

void menu()
{

    printf("=======MENU=======\n\n");
    printf("|1 - Adicionar produto \n");
    printf("|2 - Remover produto\n");
    printf("|3 - Adicionar barraca\n");
    printf("|4 - Remover barraca\n");
    printf("|5 - Realizar venda\n");
    printf("|6 - Buscar produto\n");
    printf("|7 - Editar Produto\n");
    printf("|8 - Listar barracas e seus produtos\n");
    printf("|9 - SAIR\n");
    printf("==================\n");
}

char verificaEscolha(char escolha)
{

    // verificando se o usuadio digitou apenas um caracter e se esse caracter é um numero
    printf("Escolha invalida, digite novamente: ");
    while (getchar() != '\n')
    {
        scanf(" %c", &escolha);
    }
    return escolha;
}

void passaMaiusculo(char *nome)
{
    int i;
    for (i = 0; i < strlen(nome); i++)
    {
        nome[i] = toupper(nome[i]);
    }
}
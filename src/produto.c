#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/include/barraca.h"
#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/include/produto.h"
#include "/home/lailson/Desktop/Github/repositories/Gerenciamento_de_barraca_de_frutas_e_verduras/include/funcoes.h"

struct produto
{
    char nome[Max_Caracter];
    char tipo[Max_Caracter]; // Fruta ou verdura
    float preco;
    int quantidade; // Para um determinado produto
};

struct listaprodutos
{
    Produto produto;
    ListaProdutos *prox;
};

void CriaLista(ListaProdutos **lista)
{
    *lista = NULL;
}

void NovoProdutotxt(ListaBarracas **lista, char *nomebarraca, char *nomeproduto, float preco, char *tipo, int quantidade)
{
    // Verificando se a barraca existe
    ListaBarracas *Novoprod = *lista;

    while (Novoprod != NULL)
    {
        if (strcmp(Novoprod->barraca.nome, nomebarraca) == 0)
        {
            break;
        }
        Novoprod = Novoprod->prox;
    }

    // Se a barraca não existir
    if (Novoprod == NULL)
    {
        printf("Barraca nao encontrada\n");
        return;
    }

    // Adicionando o produto
    ListaProdutos *novo = (ListaProdutos *)malloc(sizeof(ListaProdutos));
    strcpy(novo->produto.nome, nomeproduto);
    strcpy(novo->produto.tipo, tipo);
    novo->produto.preco = preco;
    novo->produto.quantidade = quantidade;
    novo->prox = Novoprod->barraca.produtos;
    Novoprod->barraca.produtos = novo;

    return;
}

void AdicionaProduto(ListaBarracas **lista)
{
    // Variaveis usadas
    char NomeBarraca[Max_Caracter];
    char NomeProduto[Max_Caracter];
    float PrecoProduto;
    char TipoProduto[Max_Caracter];
    int QuantidadeProduto;
    int verificacao;

    // Recebendo o nome da barraca
    printf("Digite o nome da barraca que voce deseja adicionar o produto: ");
    scanf(" %[^\n]", NomeBarraca);
    passaMaiusculo(NomeBarraca);

    // Verificando se a barraca existe
    ListaBarracas *Novoprod = *lista;

    while (Novoprod != NULL)
    {
        if (strcmp(Novoprod->barraca.nome, NomeBarraca) == 0)
        {
            break;
        }
        Novoprod = Novoprod->prox;
    }

    // Se a barraca não existir
    if (Novoprod == NULL)
    {
        printf("Barraca nao encontrada\n");
        return;
    }

    // Recebendo o nome do produto
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", NomeProduto);

    // Verificando o formato do nome
    if (verificaNome(NomeProduto) == 1)
    {
        while (verificaNome(NomeProduto) == 1)
        {
            printf("Nome invalido, deseja tentar novamente? (s/n): ");
            char opcao;
            scanf(" %c", &opcao);
            if (opcao == 'n')
            {
                return;
            }
            printf("Digite o nome do produto: ");
            scanf(" %[^\n]", NomeProduto);
        }
    }

    // Recebendo o tipo do produto
    printf("Digite o tipo do produto: ");
    scanf(" %[^\n]", TipoProduto);

    // Verificando o formato do tipo
    if (verificaNome(TipoProduto) == 1)
    {
        while (verificaNome(TipoProduto) == 1)
        {
            printf("Tipo invalido, deseja tentar novamente? (s/n): ");
            char opcao;
            scanf(" %c", &opcao);
            if (opcao == 'n')
            {
                return;
            }
            printf("Digite o tipo do produto: ");
            scanf(" %[^\n]", TipoProduto);
        }
    }

    // Recebendo o preco do produto
    printf("Digite o preco do produto: ");
    scanf(" %f", &PrecoProduto);

    // verificando se o usuario digitou apenas numeros inteiros evitando char
    if (getchar() != '\n')
    {
        printf("Preco invalido, digite novamente!\n");
        while (getchar() != '\n')
        {
            scanf(" %f", &PrecoProduto);
        }
    }

    // Recebendo a quantidade do produto
    printf("Digite a quantidade do produto: ");
    scanf(" %d", &QuantidadeProduto);

    // verificando se o usuario digitou apenas numeros inteiros evitando char
    if (getchar() != '\n')
    {
        printf("Quantidade invalida, digite novamente!\n");
        while (getchar() != '\n')
        {
            scanf(" %d", &QuantidadeProduto);
        }
    }

    // Adicionando o produto
    ListaProdutos *novo = (ListaProdutos *)malloc(sizeof(ListaProdutos));

    strcpy(novo->produto.nome, NomeProduto);
    strcpy(novo->produto.tipo, TipoProduto);
    novo->produto.preco = PrecoProduto;
    novo->produto.quantidade = QuantidadeProduto;

    novo->prox = Novoprod->barraca.produtos;
    Novoprod->barraca.produtos = novo;

    printf("Produto adicionado com sucesso\n");
    return;
}

void RemoveProduto(ListaBarracas **lista)
{
    // Variaveis usadas
    char NomeBarraca[Max_Caracter];
    char NomeProduto[Max_Caracter];
    int verificacao;

    // Recebendo o nome da barraca
    printf("Digite o nome da barraca que voce deseja remover o produto: ");
    scanf(" %[^\n]", NomeBarraca);
    passaMaiusculo(NomeBarraca);

    // Verificando se a barraca existe
    ListaBarracas *Novoprod = *lista;

    while (Novoprod != NULL)
    {
        if (strcmp(Novoprod->barraca.nome, NomeBarraca) == 0)
        {
            break;
        }
        Novoprod = Novoprod->prox;
    }

    // Se a barraca não existir
    if (Novoprod == NULL)
    {
        printf("Barraca nao encontrada\n");
        return;
    }

    // Recebendo o nome do produto
    printf("Digite o nome do produto que deseja remover: ");
    scanf(" %[^\n]", NomeProduto);

    // Verificando se o produto existe
    ListaProdutos *aux = Novoprod->barraca.produtos;
    ListaProdutos *aux2 = NULL;

    while (aux != NULL)
    {
        if (strcmp(aux->produto.nome, NomeProduto) == 0)
        {
            break;
        }
        aux2 = aux;
        aux = aux->prox;
    }

    // Se o produto não existir
    if (aux == NULL)
    {
        printf("Produto nao encontrado\n");
        return;
    }

    // Removendo o produto
    if (aux2 == NULL)
    {
        Novoprod->barraca.produtos = aux->prox;
    }
    else
    {
        aux2->prox = aux->prox;
    }

    free(aux);
    printf("Produto removido com sucesso\n");
    return;
}

void RealizaVenda(ListaBarracas **lista)
{
    // Variaveis usadas
    char NomeBarraca[Max_Caracter];
    char NomeProduto[Max_Caracter];
    int QuantidadeVenda;
    int verificacao;

    // Recebendo o nome da barraca
    printf("Digite o nome da barraca que voce deseja realizar a venda: ");
    scanf(" %[^\n]", NomeBarraca);
    passaMaiusculo(NomeBarraca);

    // Verificando se a barraca existe
    ListaBarracas *Novoprod = *lista;

    while (Novoprod != NULL)
    {
        if (strcmp(Novoprod->barraca.nome, NomeBarraca) == 0)
        {
            break;
        }
        Novoprod = Novoprod->prox;
    }

    // Se a barraca não existir
    if (Novoprod == NULL)
    {
        printf("Barraca nao encontrada\n");
        return;
    }

    // Recebendo o nome do produto
    printf("Digite o nome do produto que deseja vender: ");
    scanf(" %[^\n]", NomeProduto);

    // Verificando se o produto existe
    ListaProdutos *aux = Novoprod->barraca.produtos;

    while (aux != NULL)
    {
        if (strcmp(aux->produto.nome, NomeProduto) == 0)
        {
            break;
        }
        aux = aux->prox;
    }

    // Se o produto não existir
    if (aux == NULL)
    {
        printf("Produto nao encontrado\n");
        return;
    }

    // Recebendo a quantidade que deseja vender
    printf("Digite a quantidade que deseja vender: ");
    scanf(" %d", &QuantidadeVenda);

    // verificando se o usuario digitou apenas numeros inteiros evitando char
    if (getchar() != '\n')
    {
        printf("Quantidade invalida, digite novamente!\n");
        while (getchar() != '\n')
        {
            scanf(" %d", &QuantidadeVenda);
        }
    }

    // Verificando se a quantidade é valida
    if (QuantidadeVenda > aux->produto.quantidade)
    {
        printf("Quantidade invalida\n");
        return;
    }

    // Realizando a venda
    aux->produto.quantidade -= QuantidadeVenda;

    if (aux->produto.quantidade == 0)
    {
        RemoveVenda(lista, NomeProduto, NomeBarraca);
    }

    printf("Venda realizada com sucesso\n");
    return;
}

void BuscaProduto(ListaBarracas **lista)
{
    // Variaveis usadas
    char NomeBarraca[Max_Caracter];
    char NomeProduto[Max_Caracter];
    int verificacao;

    // Recebendo o nome da barraca
    printf("Digite o nome da barraca que voce deseja buscar o produto: ");
    scanf(" %[^\n]", NomeBarraca);
    passaMaiusculo(NomeBarraca);

    // Verificando se a barraca existe
    ListaBarracas *Novoprod = *lista;

    while (Novoprod != NULL)
    {
        if (strcmp(Novoprod->barraca.nome, NomeBarraca) == 0)
        {
            break;
        }
        Novoprod = Novoprod->prox;
    }

    // Se a barraca não existir
    if (Novoprod == NULL)
    {
        printf("Barraca nao encontrada\n");
        return;
    }

    // Recebendo o nome do produto
    printf("Digite o nome do produto que deseja buscar: ");
    scanf(" %[^\n]", NomeProduto);

    // Verificando se o produto existe
    ListaProdutos *aux = Novoprod->barraca.produtos;

    while (aux != NULL)
    {
        if (strcmp(aux->produto.nome, NomeProduto) == 0)
        {
            break;
        }
        aux = aux->prox;
    }

    // Se o produto não existir
    if (aux == NULL)
    {
        printf("Produto nao encontrado\n");
        return;
    }

    // Mostrando o produto
    system("clear");
    printf("PRODUTO ENCONTRADO\n");
    printf("Nome do produto: %s\n", aux->produto.nome);
    printf("Tipo do produto: %s\n", aux->produto.tipo);
    printf("Preco do produto: %.2f\n", aux->produto.preco);
    printf("Quantidade do produto: %d\n", aux->produto.quantidade);

    printf("Digite qualquer tecla para continuar\n");
    getchar();

    return;
}

void EditaProduto(ListaBarracas **lista)
{
    // Variaveis usadas
    char NomeBarraca[Max_Caracter];
    char NomeProduto[Max_Caracter];
    int verificacao;

    // Recebendo o nome da barraca
    printf("Digite o nome da barraca que voce deseja editar o produto: ");
    scanf(" %[^\n]", NomeBarraca);
    passaMaiusculo(NomeBarraca);

    // Verificando se a barraca existe
    ListaBarracas *Novoprod = *lista;

    while (Novoprod != NULL)
    {
        if (strcmp(Novoprod->barraca.nome, NomeBarraca) == 0)
        {
            break;
        }
        Novoprod = Novoprod->prox;
    }

    // Se a barraca não existir
    if (Novoprod == NULL)
    {
        printf("Barraca nao encontrada\n");
        return;
    }

    // Recebendo o nome do produto
    printf("Digite o nome do produto que deseja editar: ");
    scanf(" %[^\n]", NomeProduto);

    // Verificando se o produto existe
    ListaProdutos *aux = Novoprod->barraca.produtos;

    while (aux != NULL)
    {
        if (strcmp(aux->produto.nome, NomeProduto) == 0)
        {
            break;
        }
        aux = aux->prox;
    }

    // Se o produto não existir
    if (aux == NULL)
    {
        printf("Produto nao encontrado\n");
        return;
    }

    printf("O que deseja editar?\n");
    printf("1 - Nome\n");
    printf("2 - Tipo\n");
    printf("3 - Preco\n");
    printf("4 - Quantidade\n");

    scanf(" %d", &verificacao);

    switch (verificacao)
    {
    case 1:
        printf("Digite o novo nome do produto: ");
        scanf(" %[^\n]", aux->produto.nome);

        // Verificando o formato do nome
        if (verificaNome(aux->produto.nome) == 1)
        {
            while (verificaNome(aux->produto.nome) == 1)
            {
                printf("Nome invalido, deseja tentar novamente? (s/n): ");
                char opcao;
                scanf(" %c", &opcao);
                if (opcao == 'n')
                {
                    return;
                }
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", aux->produto.nome);
            }
        }

        break;

    case 2:
        printf("Digite o novo tipo do produto: ");
        scanf(" %[^\n]", aux->produto.tipo);

        // Verificando o formato do tipo
        if (verificaNome(aux->produto.tipo) == 1)
        {
            while (verificaNome(aux->produto.tipo) == 1)
            {
                printf("Tipo invalido, deseja tentar novamente? (s/n): ");
                char opcao;
                scanf(" %c", &opcao);
                if (opcao == 'n')
                {
                    return;
                }
                printf("Digite o tipo do produto: ");
                scanf(" %[^\n]", aux->produto.tipo);
            }
        }

        break;

    case 3:
        printf("Digite o novo preco do produto: ");
        scanf(" %f", &aux->produto.preco);

        // verificando se o usuario digitou apenas numeros inteiros evitando char
        if (getchar() != '\n')
        {
            printf("Preco invalido, digite novamente!\n");
            while (getchar() != '\n')
            {
                scanf(" %f", &aux->produto.preco);
            }
        }
        break;

    case 4:
        printf("Digite a nova quantidade do produto: ");
        scanf(" %d", &aux->produto.quantidade);

        // verificando se o usuario digitou apenas numeros inteiros evitando char
        if (getchar() != '\n')
        {
            printf("Quantidade invalida, digite novamente!\n");
            while (getchar() != '\n')
            {
                scanf(" %d", &aux->produto.quantidade);
            }
        }
        break;

    default:
        printf("Opcao invalida\n");
        break;
    }

    printf("Produto editado com sucesso\n");
    return;
}

void MostraBarracas(ListaBarracas **lista)
{
    ListaBarracas *aux = *lista;
    ListaProdutos *aux2;

    while (aux != NULL)
    {
        printf("=================DADOS=================\n");
        printf("Nome da barraca: %s\n", aux->barraca.nome);
        printf("Localizacao: %s\n", aux->barraca.localizacao);
        printf("Produtos:\n");

        aux2 = aux->barraca.produtos;
        while (aux2 != NULL)
        {
            printf("Nome do produto: %s\n", aux2->produto.nome);
            printf("Tipo do produto: %s\n", aux2->produto.tipo);
            printf("Preco do produto: %.2f\n", aux2->produto.preco);
            printf("Quantidade do produto: %d\n", aux2->produto.quantidade);
            printf("\n");
            aux2 = aux2->prox;
        }
        printf("==================FIM==================\n");
        printf("\n");
        aux = aux->prox;
    }
    printf("Digite qualquer tecla para continuar\n");
    getchar();

    return;
}

void RemoveVenda(ListaBarracas **lista, char NomeProduto[], char NomeBarraca[])
{
    ListaBarracas *aux = *lista;
    ListaProdutos *aux2 = NULL;

    //verificando se a barraca existe
    while (aux != NULL)
    {
        if (strcmp(aux->barraca.nome, NomeBarraca) == 0)
        {
            break;
        }
        aux = aux->prox;
    }

    //se a barraca não existir
    if (aux == NULL)
    {
        return;
    }

    aux2 = aux->barraca.produtos;

    //verificando se o produto existe
    while (aux2 != NULL)
    {
        if (strcmp(aux2->produto.nome, NomeProduto) == 0)
        {
            break;
        }
        aux2 = aux2->prox;
    }

    //se o produto não existir
    if (aux2 == NULL)
    {
        return;
    }

    //removendo o produto
    if (aux2 == aux->barraca.produtos)
    {
        aux->barraca.produtos = aux2->prox;
    }

    //se o produto for o ultimo da lista
    else
    {
        ListaProdutos *aux3 = aux->barraca.produtos;
        while (aux3->prox != aux2)
        {
            aux3 = aux3->prox;
        }
        aux3->prox = aux2->prox;
        free(aux3);
    }

    free(aux);
    free(aux2);
    return;
}
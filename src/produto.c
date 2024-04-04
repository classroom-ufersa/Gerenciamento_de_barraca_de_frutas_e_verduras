#include "C:\Users\Tobyg\OneDrive\Área de Trabalho\EnviarAqui\Gerenciamento_de_barraca_de_frutas_e_verduras\include\barraca.h"
#include "C:\Users\Tobyg\OneDrive\Área de Trabalho\EnviarAqui\Gerenciamento_de_barraca_de_frutas_e_verduras\include\produto.h"

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

void AdicionarProduto(ListaBarracas **listabarraca, ListaProdutos **listaprodutos)
{
    //Ponteiro auxiliar
    ListaBarracas *listaAux = *listabarraca;

    //Verificando se existem barracas cadastradas
    if(listaAux == NULL){
        printf("Nenhuma barraca cadastrada\n");
        return;
    }

    //Variavel para armazenar o nome da barraca
    char nomebarraca[Max_Caracter];

    //Escolhendo a barraca
    printf("Em qual barraca deseja adicionar o produto?\n");
    scanf(" %s", nomebarraca);

    printf("Opção: 1-novo produto 2-produto existente\n");
    int opcao;
    scanf("%d", &opcao);
    system("clear");

    //Procurando a barraca
    while(listaAux != NULL && strcmp(listaAux->barraca.nome, nomebarraca) != 0){
        listaAux = listaAux->prox;
    }

    //Verificando se a barraca foi encontrada
    if(listaAux == NULL){
        printf("Barraca nao encontrada\n");
        return;
    }

    //Variavel para armazenar os dados do produto
    Produto Dados;

    //Adicionando um novo produto
    if(opcao == 1){
        printf("Nome do produto: ");
        scanf(" %[^\n]", Dados.nome);

        //verificando se o produto ja existe
        ListaProdutos *listaAux2 = listaAux->barraca.produtos;
        while(listaAux2 != NULL && strcmp(listaAux2->produto.nome, Dados.nome) != 0){
            listaAux2 = listaAux2->prox;
        }

        if(listaAux2 != NULL){
            //enquanto o nome do produto for igual ao nome do produto ja cadastrado
            while(strcmp(listaAux2->produto.nome, Dados.nome) == 0){
                printf("Produto ja cadastrado, tente novamente!\n");
                printf("Nome do produto: ");
                scanf(" %[^\n]", Dados.nome);
                //verificando se o produto ja existe
                ListaProdutos *listaAux2 = listaAux->barraca.produtos;
                while(listaAux2 != NULL && strcmp(listaAux2->produto.nome, Dados.nome) != 0){
                    listaAux2 = listaAux2->prox;
                }
                if(listaAux2 == NULL){
                    break;
                }
            }
        }
        printf("Tipo do produto: ");
        scanf(" %[^\n]", Dados.tipo);
        printf("Preco do produto: ");
        scanf("%f", &Dados.preco);
        printf("Quantidade do produto: ");
        scanf("%d", &Dados.quantidade);
        system("clear");

        //Adicionando o produto na barraca
        ListaProdutos *novo = (ListaProdutos *)malloc(sizeof(ListaProdutos));
        novo->produto = Dados;
        novo->prox = listaAux->barraca.produtos;
        listaAux->barraca.produtos = novo;

        printf("Produto adicionado com sucesso\n");
    }
    else{
        //Variavel para armazenar o nome do produto
        char nomeproduto[Max_Caracter];

        //Escolhendo o produto
        printf("Nome do produto: ");
        scanf(" %[^\n]", nomeproduto);

        //Procurando o produto
        ListaProdutos *listaAux2 = listaAux->barraca.produtos;
        while(listaAux2 != NULL && strcmp(listaAux2->produto.nome, nomeproduto) != 0){
            listaAux2 = listaAux2->prox;
        }

        //Verificando se o produto foi encontrado
        if(listaAux2 == NULL){
            printf("Produto nao encontrado\n");
            return;
        }

        //Adicionando a quantidade do produto
        int quantidade;
        printf("Quantidade: ");
        scanf("%d", &quantidade);
        system("clear");

        listaAux2->produto.quantidade += quantidade;

        printf("Produto abastecido com sucesso\n");
    }
}

void Remover_produto(ListaBarracas **listabarraca, ListaProdutos **listaproduto){

    //Escolhendo a barraca
    printf("Em qual barraca deseja remover o produto?\n");
    char nomebarraca[Max_Caracter];
    scanf(" %[^\n]", nomebarraca);
    system("clear");

    //Ponteiro auxiliar
    ListaBarracas *listaAux = *listabarraca;

    //Procurando a barraca
    while(listaAux != NULL && strcmp(listaAux->barraca.nome, nomebarraca) != 0){
        listaAux = listaAux->prox;
    }

    //Verificando se a barraca foi encontrada
    if(listaAux == NULL){
        printf("Barraca nao encontrada\n");
        return;
    }

    //Escolhendo o produto
    printf("Nome do produto: ");
    char nomeproduto[Max_Caracter];
    scanf(" %[^\n]", nomeproduto);
    system("clear");

    //Ponteiro auxiliar
    ListaProdutos *listaAux2 = listaAux->barraca.produtos;
    ListaProdutos *ant = NULL;

    //Procurando o produto
    while(listaAux2 != NULL && strcmp(listaAux2->produto.nome, nomeproduto) != 0){
        ant = listaAux2;
        listaAux2 = listaAux2->prox;
    }

    //Verificando se o produto foi encontrado
    if(listaAux2 == NULL){
        printf("Produto nao encontrado\n");
        return;
    }

    //Removendo o produto
    if(ant == NULL){
        listaAux->barraca.produtos = listaAux2->prox;
    }
    else{
        ant->prox = listaAux2->prox;
    }

    free(listaAux2);
    printf("Produto removido com sucesso\n");
}

void BuscarProduto(ListaBarracas **listabarraca, ListaProdutos **listaproduto){
    //Escolhendo a barraca
    printf("Em qual barraca deseja buscar o produto?\n");
    char nomebarraca[Max_Caracter]; 
    scanf(" %[^\n]", nomebarraca);
    system("clear");

    //Ponteiro auxiliar
    ListaBarracas *listaAux = *listabarraca;

    //Procurando a barraca
    while(listaAux != NULL && strcmp(listaAux->barraca.nome, nomebarraca) != 0){
        listaAux = listaAux->prox;
    }

    //Verificando se a barraca foi encontrada
    if(listaAux == NULL){
        printf("Barraca nao encontrada\n");
        return;
    }

    //Escolhendo o produto
    printf("Nome do produto: ");
    char nomeproduto[Max_Caracter];
    scanf(" %[^\n]", nomeproduto);
    system("clear");

    //Ponteiro auxiliar
    ListaProdutos *listaAux2 = listaAux->barraca.produtos;

    //Procurando o produto
    while(listaAux2 != NULL && strcmp(listaAux2->produto.nome, nomeproduto) != 0){
        listaAux2 = listaAux2->prox;
    }

    //Verificando se o produto foi encontrado
    if(listaAux2 == NULL){
        printf("Produto nao encontrado\n");
        return;
    }

    //Mostrando os dados do produto
    printf("Produto encontrado\nSeus dados:\n\n");
    printf("Nome: %s\n", listaAux2->produto.nome);
    printf("Tipo: %s\n", listaAux2->produto.tipo);
    printf("Preco: %.2f\n", listaAux2->produto.preco);
    printf("Quantidade: %d\n", listaAux2->produto.quantidade);

    printf("Digite qualquer tecla para continuar\n");
    char tecla;
    scanf(" %c", &tecla);
    system("clear");
}


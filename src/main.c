#include "barraca.c"
#include "produto.c"

int main(void)
{   

    //Variavel de opcao
    char opcao;

    //Variavel para trabalhar no menu;
    int verificacao;

    //Criando a lista de barracas
    ListaBarracas *listabarr;
    CriaListaBarracas(&listabarr);
    
    //Variavel que ira guardar o arquivo
    FILE *arquivo;
    
    do
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

        printf("Opcao: ");
        scanf(" %c", &opcao);
        system("clear");

        switch (opcao)
        {
            case '1':
                //verificando se existe barracas cadastradas
                if (listabarr == NULL)
                {
                    printf("Nenhuma barraca cadastrada\n");
                    break;
                }
                system("clear");
                AdicionaProduto(&listabarr);
                break;

            case '2':
                //verificando se existe barracas cadastradas
                if (listabarr == NULL)
                {
                    printf("Nenhuma barraca cadastrada\n");
                    break;
                }
                system("clear");
                RemoveProduto(&listabarr);
                break;

            case '3':
                system("clear");
                AdicionaBarracaLista(&listabarr);             
                break;

            case '4':
                //verificando se existe barracas cadastradas
                if (listabarr == NULL)
                {
                    printf("Nenhuma barraca cadastrada\n");
                    break;
                } 
                system("clear");      
                RemoveBarraca(&listabarr);
                break;               

            case '5':
                //verificando se existe barracas cadastradas
                if (listabarr == NULL)
                {
                    printf("Nenhuma barraca cadastrada\n");
                    break;
                }
                system("clear");
                RealizaVenda(&listabarr);
                break;

            case '6':
                //verificando se existe barracas cadastradas
                if (listabarr == NULL)
                {
                    printf("Nenhuma barraca cadastrada\n");
                    break;
                }
                system("clear");
                BuscaProduto(&listabarr);
                break;

            case '7':
                //verificando se existe barracas cadastradas
                if (listabarr == NULL)
                {
                    printf("Nenhuma barraca cadastrada\n");
                    break;
                }
                system("clear");
                EditaProduto(&listabarr);
                break;

            case '8':
                //verificando se existe barracas cadastradas
                if (listabarr == NULL)
                {
                    printf("Nenhuma barraca cadastrada\n");
                    break;
                }
                system("clear");
                MostraBarracas(&listabarr);
                break;

            case '9':
                break;

            default:
                printf("Opcao invalida\n");
                break;
            }

    } while (opcao != '9');

    ListaBarracas *aux = listabarr;

    arquivo = fopen("dados.txt", "w");
    //passando as barracas e os seus produtos para o arquivo
    while (aux != NULL)
    {
        fprintf(arquivo, "Nome da barraca: %s   ", aux->barraca.nome);
        fprintf(arquivo, "Localizacao: %s\n", aux->barraca.localizacao);
        fprintf(arquivo, "Produtos: \n");
        
        ListaProdutos *aux2 = aux->barraca.produtos;

        while (aux2 != NULL)
        {
            fprintf(arquivo, "Nome: %s  ", aux2->produto.nome);
            fprintf(arquivo, "Preco: %.2f   ", aux2->produto.preco);
            fprintf(arquivo, "Tipo: %s  ", aux2->produto.tipo);
            fprintf(arquivo, "Quantidade: %d\n", aux2->produto.quantidade);
            aux2 = aux2->prox;
        }
        fprintf(arquivo, "\n");
        aux = aux->prox;
    }

    //fechando o arquivo
    fclose(arquivo);
    //liberando a memoria
    free(listabarr);
    printf("Programa encerrado com sucesso!\n");
    return 0;
}


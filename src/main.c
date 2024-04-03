#include "barraca.c"
#include "produto.c"

int main(void)
{
    //Variavel de opcao
    char opcao;

    //Lista de barracas
    ListaBarracas *listabarr;
    CriaListaBarracas(&listabarr);
    Barraca DadosBarraca;

    //Lista de produtos
    ListaProdutos *listaprod;
    CriaLista(&listaprod);

    do
    {

        printf("=======MENU=======\n\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Remover produto\n");
        printf("3 - Adicionar barraca\n");
        printf("4 - Remover barraca\n");
        printf("5 - Realizar venda\n");
        printf("6 - Buscar produto\n");
        printf("7 - Listar todas barracas\n");
        printf("8 - sair\n");
        printf("==================\n");

        printf("Opcao: ");
        scanf(" %c", &opcao);
        system("clear");

        switch (opcao)
        {
            case '1':
                
                break;
            case '2':

                break;

            case '3':
                AdicionarBarraca(&listabarr);
                break;

            case '4':
                //verificicação de barraca
                if(listabarr == NULL)
                {
                    printf("Nenhuma barraca cadastrada\n");
                    break;
                }
               
                else
                {
                    RemoverBarraca(&listabarr);
                    break;                    
                }                  

            case '5':
            
                break;

            case '6':

                break;

            case '7':
                break;

            case '8':
                printf("\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
            }

    } while (opcao != '8');

    //liberando a memoria
    free(listaprod);
    printf("Programa encerrado com sucesso!\n");
    return 0;
}
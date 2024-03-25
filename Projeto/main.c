#include "Barraca/barraca.c"
#include "Produto/produto.c"

int main(void)
{

    char opcao;
    char nome[30];
    char localizacao[30];
    ListaBarracas *lista;
    criarlista(&lista);

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

        switch(opcao)
        {
            case '1':
                
            break;

            case '2':
   
            break;

            case '3': 
                printf("Digite o nome da barraca: ");
                scanf(" %s", nome);
                printf("Digite a localizacao da barraca: ");
                scanf(" %s", localizacao);
                Barracas barraca;
                strcpy(barraca.nome, nome);
                strcpy(barraca.localizacao, localizacao);
                AdicionarBarraca(&lista, barraca);
            break;

            case '4': 

            break;
            
            case '5':
              
            break;

            case '6':

            break;

            case '7':

            break;

            default:
                printf("Opcao invalida\n");
            break;
        
        }
    
    }while (opcao != '8');
    
    free(lista);
    printf("Programa encerrado com sucesso!\n");
    
    return 0;
}
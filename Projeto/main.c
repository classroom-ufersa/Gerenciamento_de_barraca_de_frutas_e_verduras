#include "barraca.h"
#include "produto.h"

int main(void)
{
    //Variavel para guardar produtos;
    int QUANT_PROD = 0;
    //Variavel para guardar Barracas;
    int QUANT_BARRACAS = 0;
    
    char opcao;
    
    do
    {  

        printf("====MENU====\n\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Remover produto\n");
        printf("3 - Adicionar barraca\n");
        printf("4 - Remover barraca\n");
        printf("5 - Realizar venda\n");
        printf("6 - Buscar produto\n");
        printf("7 - Listar todas barracas\n");
        printf("8 - sair\n");
        printf("============\n");
       
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch(opcao)
        {
            case '1':
                
            break;

            case '2':
   
            break;

            case '3': 

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
    
    printf("Progama encerrado com sucesso!\n");
    
    return 0;
}
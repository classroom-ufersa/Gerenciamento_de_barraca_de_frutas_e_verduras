#include "Barraca/barraca.c"


int main(void)
{

    char opcao;
    char nome[30];
    char localizacao[30];

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
                printf("Digite o nome da nova barraca:\n");
                scanf("%s",nome);
                printf("Digite a localizacao da nova barraca:\n");
                scanf("%s",localizacao);
                Add_Barraca(nome,localizacao);
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
    
    printf("Programa encerrado com sucesso!\n");
    
    return 0;
}
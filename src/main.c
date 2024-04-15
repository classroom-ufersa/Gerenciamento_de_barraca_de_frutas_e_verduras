#include "barraca.c"
#include "produto.c"
#include "funcoes.c"

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

    //Carregando os dados do arquivo
    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL)
    {
        printf("Arquivo nao encontrado\n");
        return 0;
    }

    //Carregando os dados do arquivo
    char linha[Max_Caracter];

    char nomebarracaARQ[Max_Caracter];
    char localizacaoARQ[Max_Caracter];
    char nomeprodutoARQ[Max_Caracter];
    float precoprodutoARQ;
    char tipoprodutoARQ[Max_Caracter];
    int quantidadeprodutoARQ;

    //pegando os dados do arquivo
    while (fgets(linha, Max_Caracter, arquivo) != NULL)
    {
        if (strstr(linha, "Nome da barraca:"))
        {
            sscanf(linha, "Nome da barraca: %s   Localizacao: %s", nomebarracaARQ, localizacaoARQ);
            ListaBarracas *nova = NovaBarracatxt(nomebarracaARQ, localizacaoARQ);

            if (listabarr == NULL)
            {
                listabarr = nova;
            }
            else
            {
                ListaBarracas *aux = listabarr;
                while (aux->prox != NULL)
                {
                    aux = aux->prox;
                }
                aux->prox = nova;
            }
        }
        else if (strstr(linha, "Produtos:"))
        {
            while (fgets(linha, Max_Caracter, arquivo) != NULL)
            {
                if (strstr(linha, "Nome:"))
                {
                    sscanf(linha, "Nome: %s  Preco: %f   Tipo: %s  Quantidade: %d", nomeprodutoARQ, &precoprodutoARQ, tipoprodutoARQ, &quantidadeprodutoARQ);
                    NovoProdutotxt(&listabarr, nomebarracaARQ, nomeprodutoARQ, precoprodutoARQ, tipoprodutoARQ, quantidadeprodutoARQ);
                }
                else
                {
                    break;
                }
            }
        }
    }

    fclose(arquivo);
    
    do
    {
            
        menu();

        printf("Opcao: ");
        scanf(" %c", &opcao);
        opcao = verificaEscolha(opcao);
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


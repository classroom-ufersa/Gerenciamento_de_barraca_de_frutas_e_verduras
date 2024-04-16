<h1 align="center">Dupla 19: Gerenciamento de Barracas de Frutas e Verduras</h1>

## Doscente da turma
- [Rosana Cibely Batista Rego](https://github.com/roscibely)

## Componentes da dupla
- [Francisco Lailson de Almeida](https://github.com/lailsonzw)
- [Tobias Fernandes Figueiredo](https://github.com/Tobias-fernandes)

## Linguagem utilizada

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

### Sobre o projeto

Projete um sistema na linguagem C para gerenciamento de uma barraca de frutas e verduras. Seu sistema deve ser capaz de manipular barracas e produtos.

A barraca deve ter os seguintes atributos:
- Nome;
- Localização;
- Produtos disponíveis.

Cada produto deve ter os seguintes atributos:
- Nome;
- Tipo (fruta ou verdura);
- Preço por unidade;
- Quantidade em estoque;

Um menu com as seguintes opções deverá ser apresentado:
  1. Adicionar produto;
  2. Remover produto;
  3. Adicionar produto;
  4. Remover produto;
  5. Realizar venda;
  6. Buscar produto;
  7. Listar todas as barracas e seus produtos;
  8. Sair

A opção Sair é a única que permite sair do programa. Sendo assim, após cada operação, o programa volta ao menu. Além disso, você deve levar em consideração o seguinte: a cada execução do seu programa, os dados devem ser carregados devem ser carregados (armazenados em um arquivo texto); cada novo produto ou barraca cadastrada deve ser inserido em ordem alfabética (para isso, você pode utilizar as funções da biblioteca padrão de C, string.h); você deve atualizar o arquivo texto para refletir o estado atual dos dados em virtude da adição, remoção ou venda de produtos.

## **5.0-Organização do Repositório**
A organização desse repositório foi desenvolvida da seguinte forma:

``` 
📁 - Gerenciamento_de_barraca_de_frutas_e_verduras
│
└─── bin
│
└─── include
        │
        ├──barraca.h
        ├──funcoes.h
        ├──produto.h
│
└─── src
        │
        ├──barraca.c
        ├──dados.txt
        ├──funcoes.c
        ├──main.c
        ├──produto.c
│
└───README.md
```

# Listas encadeadas simples
Foi escolhido a Lista Encadeada Simples, por se tratar de uma maneira mais simples, que ajude a solucionar o problema.

##  Vantagens
* Percebe-se nas vantagens sua eficiência na remoção e adição de dados, além da sua praticidade na realocação de memória, uma vez que listas não precisa de realocação de memória.
## Desvantagens
* Todavia, como desvantagens, temos seu acesso sequencial diminuindo seu desempenho e também listas encadeadas podem consumir mais memória do que outras estruturas, já que é necessário armazenar um ponteiro adicionar para cada novo elemento.

# TAD's
No desenvolvimemto desse projeto, foi utilizado 02 TAD's, uma para as barracas, e outra para os produtos de cada barraca.

## **Execução do projeto**
- Para executar o código pelo terminal, digite os comando abaixo.
```
cd src
gcc -o main.c -o main
./main
```


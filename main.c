#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"

typedef struct nodo{
    int peso;
    int valor;
    struct nodo *prox;
}nodo;

//void remove(int vertice1,int vertice2, nodo **lista);
void vizinho(int vertice, nodo **lista);
nodo *insere(int vertice1, int vertice2, int peso, nodo **lista);
void imprimir(int vertice1, int vertice2,nodo **lista);
void popular(nodo**lista, int x);
nodo* remove_aresta(int vertice, int vertice2, nodo **lista);
void matriz(nodo**lista, int n);
void dfs(nodo**lista, int n);
int visita_dfs(nodo ** lista , int * vetVisitados, int i, char a);

int bfs(nodo **lista,int n,  int A, int B);

nodo ** iniciaGrafo(int n );

void finalizaGrafo(nodo ** grafo, int tam);

int main()
{
   int n;
   char entrada[20];
   int vertice1;
   int vertice2;
   int tamanho;
   int peso;
   int i =0;
   //printf("Quantas arestas tera seu grafo:");
   scanf("%d", &n);

   nodo **vet = iniciaGrafo(n);

    while(strcmp(entrada,"F") != 0){
       scanf("%s",entrada);

        if(strcmp(entrada, "+") == 0){
            scanf("%d", &vertice1);
            scanf("%d", &vertice2);
            scanf("%d", &peso);
            insere(vertice1, vertice2, peso, vet);
            insere(vertice2, vertice1, peso, vet);

       }
        if(strcmp(entrada, "w") == 0){
            scanf("%d", &vertice1);
            scanf("%d", &vertice2);
            imprimir(vertice1, vertice2, vet);

       }
        if(strcmp(entrada, "matriz") == 0){
             matriz(vet, n);

       }
        if(strcmp(entrada, "vizinhos") == 0){
            scanf("%d", &vertice1);
            vizinho(vertice1, vet);

       }
        if(strcmp(entrada, "popular") == 0){
                popular(vet, n);

       }
        if(strcmp(entrada, "dfs") == 0){
            dfs(vet,n);

       }
        if(strcmp(entrada, "bfs") == 0){

            scanf("%d", &vertice1);
            scanf("%d", &vertice2);
            if(!bfs(vet, n, vertice1, vertice2))
                printf("(sem caminho)\n");
       }
        if(strcmp(entrada, "-") == 0){
            scanf("%d", &vertice1);
            scanf("%d", &vertice2);
            vet[vertice1 - 1] = remove_aresta(vertice1, vertice2, vet);
            vet[vertice2 - 1] = remove_aresta(vertice2, vertice1, vet);
        }
   }
   finalizaGrafo(vet, n);
    return 0;
}



int visita_dfs(nodo ** lista , int * vetVisitados, int i, char a)//i é a casa do vetor de listas
{
    nodo * aux = lista[i];
    if (aux == NULL)
    {
        printf("%d", i+1);
        return 0;
    }
        
    
    vetVisitados[i] = 1;//marca como visitado

    //printf("%d", i+1);
    if (a)
        printf("%d", i+1);
    else    
        printf(" %d", i+1);
    int peso = 0;
    
    while(aux!=NULL){//enquanto houver arestas neste vértice//anda na lista
        peso+= aux->peso;

        if (vetVisitados[aux->valor] == 0)//se o destino da aresta não foi visitado
        {
            peso += visita_dfs(lista, vetVisitados, aux->valor,0);
        }
        
        aux = aux->prox;
    }
    return peso;
}   

void dfs(nodo ** lista , int n)
{
    int * vetVisitados = (int*) calloc(sizeof(int), n);//0 se não visitado

    int i=0; 
    int c=0;

    int peso= 0;
    int peso2= 0;
    for (i=0; i<n; i++)//para cada VERTICE
    {
        peso = 0;
        
        if (vetVisitados[i]==0)//que não for visitado
        {
            c++;
            printf("[");
            peso = visita_dfs(lista,vetVisitados, i,1);//visite-o
            printf("], ");
            printf("peso total %d\n", peso/2);
        }

    }


    printf("%d componente(s)\n", c);

    free(vetVisitados);
}



nodo *insere(int vertice1, int vertice2, int peso, nodo **lista){
    nodo *novo= (nodo*) malloc(sizeof(nodo));
    novo->valor = vertice2 - 1;//atribuir um valor ao 2 vertice
    novo->peso = peso;//peso entre eles
    novo->prox= NULL;

    if(lista[vertice1 - 1] == NULL){//se minha lista no vertice ja estiver vazia so atribuo o valor
        lista[vertice1 - 1] = novo;
    }
    else{
        nodo *aux1 = lista[vertice1 - 1];
        while(aux1->prox != NULL){//uso um aux para percorrer essa lista
            aux1 = aux1->prox;
        }
        aux1->prox = novo;
    }

    return novo;
}

void imprimir(int vertice1, int vertice2,nodo **lista){//operacao W
    
    nodo *aux1 = lista[vertice1 - 1];

    if(lista[vertice1 - 1] == NULL){
        printf("aresta inexistente\n");
    }
    else{
        while(aux1->valor != vertice2 - 1 && aux1->prox!=NULL ){
            aux1 = aux1->prox;
        }

        if(aux1->valor == vertice2 - 1){
            printf("%d\n", aux1->peso);
        }
        else
            printf("aresta inexistente\n");
    }

}

void vizinho(int vertice, nodo **lista){
     nodo *aux = lista[vertice - 1];
     if(aux == NULL){
        printf("(nenhum)\n");
     }
     else{
         while(aux!= NULL){//uso um aux para percorrer essa lista
                printf("%d ", aux->valor + 1);
                aux = aux->prox;
            }
            printf("\n");
     }
}

void popular(nodo**lista, int x){
    nodo *aux;
    int i = 0;
    int tamanho;
    int maior;
    int posicao;
    for(i; i< x; i++){
        aux = lista[i];
        tamanho = 0;
        while(aux!= NULL){
            aux = aux->prox;
            tamanho++;
        }
        if(i == 0){
            maior = tamanho;
            posicao = i + 1;
        }
        if(maior < tamanho){
            maior = tamanho;
            posicao = i + 1;
        }
    }
    if(maior == 1){
        printf("%d (%d vizinho)\n", posicao, maior);
    }
    if(maior == 0){
        printf("nenhum dos vertices tem vizinhos\n");
    }
    if(maior > 1)
        printf("%d (%d vizinhos)\n", posicao, maior);
}
nodo *remove_aresta(int vertice, int vertice2, nodo **lista){
    nodo *atual = lista[vertice - 1];
    nodo *anterior = NULL;
    int cont =0;
    while(atual->valor != vertice2 - 1){
        anterior = atual;
        atual = atual->prox;
        cont++;
    }
    if(cont == 0){
        lista[vertice - 1] = atual->prox;
        free(atual);
    }
    else{
        anterior->prox = atual->prox;
        free(atual);

    }
    return lista[vertice - 1];
}
void matriz(nodo**lista, int n){
    int i = 0;
    int j = 0;

    int matriz[n][n]; //preencher matriz com o maior número que cabe num inteiro
    nodo *aux = lista[i];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matriz[i][j] = 2147483647;
        }
    }
    for(i = 0; i < n; i++){
        aux = lista[i];//faco um aux que vai percorrer todas as posicao da minha lista até diferente de NULL
        while(aux != NULL){
            for(j = 0; j < n; j++){
                if(j == aux->valor){//caso a posicao da minha matriz seja igual o valor da lista, coloque o peso nessa posicao
                    matriz[i][j] = aux->peso;
                }
            }
            aux = aux->prox;
        }
    }

    for(i= 0; i < n; i++){
        for(j= 0; j < n; j++){
            if(matriz[i][j] == 2147483647){
                printf("- ");
            }
            else
             printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

}


int bfs(nodo **lista,int n,  int B, int A)
{
    char * enfileirado = (char *) calloc(sizeof(char), n);
    int * vetPai = (int * ) calloc(sizeof(int), n);

    int * distancia = (int * ) calloc(sizeof(int), n);
    fila * f = iniciaFila();
    int vertice = 0;
    enfileirar(f, A-1);

    enfileirado[A-1] = 1;
    nodo * ver = NULL;//lista[A];
    int peso = 0;
    int vizinho;

    int ares = 0;
    for (vertice = 0; vertice<n; vertice++)
    {
        vetPai[vertice] = -1;
    }
    //printf("%d\t", A);
    while (!vazia(f))
    {
        
        vertice = desenfileirar(f);
        ver = lista[vertice];
        
        while(ver!=NULL)//p ver ios vizinhos 
        {
            vizinho = ver->valor;
            if (enfileirado[vizinho] == 0)
            {
                enfileirar(f, vizinho);
                //peso+=
                //ares++;
                enfileirado[vizinho] = 1;
                vetPai[vizinho] = vertice;
                distancia[vizinho] = distancia[vertice] + ver->peso;
            }
            ver = ver->prox;
        }
    }
    
    finalizaFila(f);
    f = iniciaFila();
    int i=B-1;
    
    while(i != A-1)
    {
        ares++;
        enfileirar(f, i);
        if (i == vetPai[i])
        {
            finalizaFila(f);
            return 0;
        }
        if (vetPai[i] == -1)
        {
            finalizaFila(f);
            return 0;
        }
        i = vetPai[i];
    }
    enfileirar(f, A-1);
    
    while(!vazia(f))
    {
        i = desenfileirar(f);
        printf("%d ", i+1);
    }
    peso = distancia[B-1];
    printf("\n%d aresta(s), peso total %d\n", ares, peso);
    
    finalizaFila(f);


    free(enfileirado);
    free(vetPai);
    free(distancia);
    return peso;
}

nodo ** iniciaGrafo(int n )
{
    return (nodo **) calloc(sizeof(nodo**) , n);
}

void finalizaGrafo(nodo ** grafo, int tam)
{
    int i=0;
    nodo * n  = NULL;
    nodo * aux =  NULL;
    for (i=0; i<tam; i++)
    {
        for (n=grafo[i]; n; )
        {
            aux = n;
            n=n->prox;
            free (aux);
        }
    }
}

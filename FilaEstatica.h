#ifndef FILAE
#define FILAE

#define MAX 100


typedef struct Fila
{
    int vet[MAX];
    int primeiro;
    int qtd;
}fila;





fila * iniciaFila();


int vazia(fila * f);
void enfileirar(fila * f, int valor);

int desenfileirar(fila * f);

void finalizaFila(fila * f);



#endif // !1#define FILAD
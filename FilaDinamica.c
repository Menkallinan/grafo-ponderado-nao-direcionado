
#include <stdlib.h>


#include "FilaDinamica.h"

fila * iniciaFila()
{
    fila * f = (fila*) malloc(sizeof(fila));
    f->primeiro = f->ultimo = NULL;
    f->qtd = 0;
    return f;
}

no * iniciaNo(int valor)
{
    no * n = (no* ) malloc(sizeof(no));
    n->atras = NULL;
    n->valor = valor;
    return n;
}

int vazia(fila * f)
{
    if (f->qtd == 0)
        return 1;
    return 0;
}
void enfileirar(fila * f, int valor)
{
    no * n  =  iniciaNo(valor);
    if (vazia(f))//se a fila erstiver vazia 
    {
        f->primeiro = f->ultimo = iniciaNo(valor);
    }
    else{
        f->ultimo = f->ultimo->atras = iniciaNo(valor);
    }
    f->qtd++;
}

int desenfileirar(fila * f)
{
    no * q = f->primeiro;
    int valor = 0;
    if (q == NULL)
        return -1;
    f->primeiro = f->primeiro->atras;
    f->qtd--;
    valor = q->valor;
    free(q);
    return valor;
}

void finalizaFila(fila * f)
{

    while (!vazia(f))
    {
        desenfileirar(f);
    }
    free(f);
}


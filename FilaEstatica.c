
#include <stdlib.h>


#include "FilaEstatica.h"


fila * iniciaFila()
{
    fila * f = (fila*) malloc(sizeof(fila));
    f->primeiro = 0;
    f->qtd = 0;
    return f;
}


int vazia(fila * f)
{
    if (f->qtd == 0)
        return 1;
    return 0;
}
void enfileirar(fila * f, int valor)
{
    if (vazia(f))//se a fila erstiver vazia 
    {
        f->primeiro = 0;
        f->vet[0] = valor;
        f->qtd=1;
    }
    else{
        f->vet[(f->primeiro+f->qtd)%MAX] = valor;
        f->qtd++;
    }
}

int desenfileirar(fila * f)
{
    int valor = f->vet[(f->primeiro)%MAX];
    f->primeiro = (f->primeiro+1)%MAX;
    f->qtd--;
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


#ifndef FILAD
#define FILAD


typedef struct No
{
    struct No * atras;
    int valor;
}no;



typedef struct Fila
{
    no * primeiro;
    no * ultimo;
    int qtd;
}fila;


fila * iniciaFila();


int vazia(fila * f);
void enfileirar(fila * f, int valor);

int desenfileirar(fila * f);

void finalizaFila(fila * f);



#endif // !1#define FILAD

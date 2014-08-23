#include <stdlib.h>
#include "lista.h"

typedef struct tLista{
  tAtrb atrb;
  struct tLista* prox;
} tLista;

// Constroi Cabeça, ou constrói um item da lista.
tLista* cLista(tAtrb atrb)
{
  tLista* l = (tLista*)malloc(sizeof(tLista));
  
  l->atrb = atrb;
  l->prox = NULL;
  
  return l;
}

tLista* tl(tLista* l)
{
  return (l?l->prox:NULL);
}

tAtrb hd(tLista* l)
{
  return (l?l->atrb:tAtrbInval);
}

// retorna tl(l) removendo o ponteiro de l->prox.
tLista* cuttl(tLista* l)
{
  tLista* aux = tl(l);
  
  // Se l!=NULL:
  if(l) l->prox = NULL;
  
  return aux;
}

// retorna hd(l) liberando o espaço de memoria da celula cabeça.
tAtrb rmhd(tLista* l)
{
  tAtrb aux = hd(l);
  
  // Se l!=NULL;
  if(l) free(l);
  
  return aux;
}

// Concatena duas listas.
// Atenção não use o cat sem o cuttl em uma operação de inserção.
// Isso poderá gerar uma lista circular e futuramente um loop infinito.
int cat(tLista* hd, tLista* l)
{
  // find the last item from hd:
  while(tl(hd)) hd=tl(hd);
  
  // Concatenate the two lists if hd!=NULL:
  if(hd) hd->prox = l;
  
  return 0;
}

// Liga um item cabeça de uma lista a outra lista.
// Cuidado se houver um tl()!=NULL para hd,
// salve esse tail antes de chamar a função link.
int link(tLista* hd, tLista* l)
{
  // Link the head to the list if hd!=NULL
  if(hd) hd->prox = l;
  
  return 0;
}

/* * * * * Operações de Pilha * * * * */

// Empilha um item em frente a cabeça de l.
tLista* push(tLista* l, tAtrb atrb)
{
  tLista* aux;
  link(aux=cLista(atrb), tl(l));
  link(l, aux);
  return l;
}

// Desempilha um item em frente a cabeça de l, liberando o espaço de memoria.
tAtrb pop(tLista* l)
{
  tLista* aux=tl(l);
  link(l, tl(aux));
  return rmhd(aux);
}


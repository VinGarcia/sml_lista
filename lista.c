#include <stdlib.h>
#include "lista.h"

typedef struct tLista{
  tAtrb atrb;
  struct tLista* prox;
} tLista;

// Build a node of the list.
tLista* cLista(tAtrb atrb)
{
  tLista* l = (tLista*)malloc(sizeof(tLista));
  
  l->atrb = atrb;
  l->prox = NULL;
  
  return l;
}

tLista* tail(tLista* l)
{
  return (l?l->prox:NULL);
}

tAtrb head(tLista* l)
{
  return (l?l->atrb:tAtrbInval);
}

// Return tail(l) and make l->prox = NULL.
tLista* cuttail(tLista* l)
{
  tLista* aux = tail(l);
  
  // If l!=NULL:
  if(l) l->prox = NULL;
  
  return aux;
}

// Returns head(l) and free the header cell memory space.
tAtrb rmhead(tLista* l)
{
  tAtrb aux = head(l);
  
  // If l!=NULL;
  if(l) free(l);
  
  return aux;
}

// Concatenate two lists into one -- Complexity O(list2.length).
// Beware this function may create a circular list thus: infinit loop.
// To insert a list inside another list do:
//   aux = cuttail(list1);
//   link(list1,list2);
//   cat(list2,aux);
int cat(tLista* head, tLista* tl)
{
  // find the last item from head:
  while(tail(head)) head=tail(head);
  
  // Concatenate the two lists if head!=NULL:
  if(head) head->prox = tl;
  
  return 0;
}

// Link the head node with the tail node. (head->prox = tail)
// Beware: If head is a list, the tail pointer will be overwrited.
int link(tLista* head, tLista* tail)
{
  // Link the head to the list if head!=NULL
  if(head) head->prox = tail;
  
  return 0;
}

/* * * * * Stack Operations * * * * */

// This operations assumes the header cell contains no value.
// The stack is built as the tail of the this cell.

// Insert an item in front of the header cell of l.
// (insert it on the top of the stack)
tLista* push(tLista* l, tAtrb atrb)
{
  tLista* aux;
  link(aux=cLista(atrb), tail(l));
  link(l, aux);
  return l;
}

// Remove and free the item in front of the header cell of l.
// Also links the header to the removed cell tail.
// (extract the item on the top of the stack)
tAtrb pop(tLista* l)
{
  tLista* aux=tail(l);
  link(l, tail(aux));
  return rmhead(aux);
}


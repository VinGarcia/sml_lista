
/* TAD Lista Simples */

// Essa lista contém apenas abstrações básicas deixando as demais a cargo
// do usuário. Todas as funções tratam parametros NULL para não causarem
// segmentation fault. O retorno delas é o retorno NULL ou tAtrbInval.
// Leia mais sobre tAtrbInval abaixo.

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LISTA
#define LISTA

  #ifdef __cplusplus
    extern "C" {
  #endif
  
  // O tipo "tAtrb" pode ser definido pelo usuário para o tipo desejado:
  #ifndef TIPOLISTA
    #define TIPOLISTA void* // Aceita somente inteiros, caracteres e ponteiros (não tente faze-lo com um struct).
  #endif
  typedef TIPOLISTA tAtrb;
  
  // Abaixo é o retorno de erro de todas as funções do tipo "tAtrb func()"
  // Altere-o caso o tipo tAtrb deixe de ser um ponteiro.
  #define tAtrbInval NULL
  
  typedef struct tLista tLista;
  
  /* Funções */
  
  // Função construtora de um bloco da lista:
  tLista* cLista(tAtrb atrb);
  
  // Função que retorna o "Tail" ou seja l->prox.
  tLista* tl(tLista* l);
  
  // Retorna o atributo contido na celula cabeça da lista l.
  tAtrb hd(tLista* l);
  
  // Retorna tl(l) e faz l->prox = NULL;
  tLista* cuttl(tLista* l);
  
  // Retorna hd(l) e faz free(l);
  tAtrb rmhd(tLista* l);
  
  // Concatena a lista hd e a lista l.
  int cat(tLista* hd, tLista* l);
  
  // linka hd com a lista l. (hd->prox = l)
  int link(tLista* hd, tLista* l);
  
  /* * * * * Operações de Pilha * * * * */
  
  // Insere um item de atributo = atrb imediatamente após a cel. cabeça de l
  tLista* push(tLista* l, tAtrb atrb);
  
  // Extrai e desaloca l->prox sem quebrar a lista, e retorna seu valor.
  tAtrb pop(tLista* l);
  
  #ifdef __cplusplus
    }
  #endif
#endif
 
// Extras:
// (as partes abaixo podem ser removidas do header, mas são úteis)

// Se quiser um novo nome pra lista, pode usar esse define, fica mais bonitinho.
#ifndef NOMELISTA
  #define NOMELISTA tLista;
#endif 
typedef struct tLista NOMELISTA;

#ifndef FORLISTA
  #define FORLISTA
  #define forLista(l,i) for(i=tl(l);i;i=tl(i))
  // O for abaixo faz o mesmo que o de cima, porém guarda em f o nó
  // pai de l a cada ciclo.
  #define forListaPai(l,i,f) for(f=l,i=tl(l);i;i=tl(i),f=tl(f))
#endif


/* Simple SML List */

// This list have only basic abstractions leaving the rest up to the
// programmer. All functions threat NULL parameters so they
// don't cause segmentation fault.
//
// All functions return value is tAtrb or tLista* in normal cases,
// and NULL or tAtrbInval when an error hapens.
//
// Read more about tAtrb and tAtrbInval below.

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LISTA
#define LISTA

  #ifdef __cplusplus
    extern "C" {
  #endif
  
	// `tAtrb` type may be custumized by the user:
  #ifndef TIPOLISTA
    // The tAtrb value can be set to:
		//   integers, characters and pointers.
		// Don't try inserting an entire struct it won't work.
    #define TIPOLISTA void*
  #endif
  typedef TIPOLISTA tAtrb;
  
	// Below is the error return value for functions that should return
	// an tAtrb, by default its NULL:
  // Change it if tAtrb is not a pointer.
  #define tAtrbInval NULL
  
  typedef struct tLista tLista;
  
  /* Functions */
  
	// Constructor function of a node on the list:
  tLista* cLista(tAtrb atrb);
  
	// Function that returns the `tail` i.e. `l->prox`
  tLista* tail(tLista* l);
  
	// Returns the tAtrb file on the header cell of the list.
  tAtrb head(tLista* l);
  
	// Returns the tail(l) and makes l->prox = NULL;
  tLista* cuttail(tLista* l);
  
	// Returns head(l) and call free(l);
  tAtrb rmhead(tLista* l);
  
	// Concatenates the two lists into one.
  int cat(tLista* head, tLista* tl);
  
  // link the head node to the list l (head->prox = l)
  int link(tLista* head, tLista* l);
  
  /* * * * * Stack Operations: * * * * */
  
	// Insert an item atrb right after the header cell of l.
  tLista* push(tLista* l, tAtrb atrb);
  
  // Extrai e desaloca l->prox sem quebrar a lista, e retorna seu valor.
	// Extract and unalloc l->prox cell an returns its value.
	// Also links the header cell with l->prox->prox.
  tAtrb pop(tLista* l);

  #ifdef __cplusplus
    }
  #endif
#endif
 
// Useful macros:

// For making an alias for the list:
#ifndef NOMELISTA
  #define NOMELISTA tLista;
#endif 
typedef struct tLista NOMELISTA;

// For iterating over the list:
#ifndef FORLISTA
  #define FORLISTA
  #define forLista(l,i) for(i=tail(l);i;i=tail(i))
  // The for below makes the same as the above, but keeps
	// track of the father node of the current loop node.
  #define forListaPai(l,i,f) for(f=l,i=tail(l);i;i=tail(i),f=tail(f))
#endif

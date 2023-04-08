#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
  celula *p1 = l1->prox, *p2 = l2->prox, *p3 = l3;

  while (p1 && p2) {
    celula **menor = (p1->dado < p2->dado) ? &p1 : &p2;
    p3->prox = *menor;
    *menor = (*menor)->prox;
    p3 = p3->prox;
  }

  p3->prox = p1 ? p1 : p2;
}
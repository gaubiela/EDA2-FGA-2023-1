// Listas encadeadas - Impressão

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void imprime(celula *le) {
  celula *inicio = le->prox;
  while (inicio != NULL) {
    printf("%d -> ", inicio->dado);
    inicio = inicio->prox;
  }
  printf("NULL\n");
}

void imprime_rec(celula *le) {
  if (le == NULL || le->prox == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d -> ", le->prox->dado);
  imprime_rec(le->prox);
}

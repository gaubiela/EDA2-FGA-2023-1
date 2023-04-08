#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int remove_depois(celula *p) {
  if (!p || !p->prox) {
    return 0;
  }
  celula *tmp = p->prox;
  p->prox = tmp->prox;
  int valor = tmp->dado;
  free(tmp);
  return valor;
}

void remove_elemento(celula *le, int x) {
  celula *p = le;
  while (p->prox && p->prox->dado != x) {
    p = p->prox;
  }
  if (p->prox) {
    celula *tmp = p->prox;
    p->prox = tmp->prox;
    free(tmp);
  }
}

void remove_todos_elementos(celula *le, int x) {
  celula *p = le;
  celula *tmp;
  while (p->prox) {
    if (p->prox->dado == x) {
      tmp = p->prox;
      p->prox = tmp->prox;
      free(tmp);
    } else {
      p = p->prox;
    }
  }
}
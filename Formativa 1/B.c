// Listas encadeadas - Inserção

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void insere_antes(celula *le, int x, int y) {
  celula *nova_celula = (celula *)malloc(sizeof(celula));
  nova_celula->dado = x;
  celula *p = le->prox;
  celula *ant = le;
  while (p && p->dado != y) {
    ant = p;
    p = p->prox;
  }
  nova_celula->prox = p;
  ant->prox = nova_celula;
}

void insere_inicio(celula *le, int x) {
  celula *nova_celula = (celula *)malloc(sizeof(celula));
  nova_celula->dado = x;
  nova_celula->prox = le->prox;
  le->prox = nova_celula;
}
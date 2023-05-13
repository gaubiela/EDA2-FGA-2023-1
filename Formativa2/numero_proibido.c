#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TABELA 1000000

typedef struct no No;
struct no {
  int valor;
  No *prox;
};

No *tabela_hash[MAX_TABELA];

int hash(int valor) { return abs(valor) % MAX_TABELA; }

void inserir(int valor) {
  int indice = hash(valor);
  No *novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->prox = tabela_hash[indice];
  tabela_hash[indice] = novo_no;
}

bool buscar(int valor) {
  int indice = hash(valor);
  No *no = tabela_hash[indice];
  while (no != NULL) {
    if (no->valor == valor) {
      return true;
    }
    no = no->prox;
  }
  return false;
}

void limpaHash() {
  for (int i = 0; i < MAX_TABELA; i++) {
    No *no = tabela_hash[i];
    while (no != NULL) {
      No *temp = no;
      no = no->prox;
      free(temp);
    }
    tabela_hash[i] = NULL;
  }
}

int main() {
  int n, valor;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &valor);
    inserir(valor);
  }

  while (scanf("%d", &valor) == 1) {
    printf("%s\n", buscar(valor) ? "sim" : "nao");
  }

  limpaHash();

  return 0;
}
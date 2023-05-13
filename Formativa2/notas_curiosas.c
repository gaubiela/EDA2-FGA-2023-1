#include <stdio.h>

#define MAX_TABELA 1005

int hash(int chave) { return chave % MAX_TABELA; }

int main() {
  int x;
  scanf("%d", &x);

  int tabela[MAX_TABELA] = {0};
  int recorrente = 0;

  for (int i = 0; i < x; i++) {
    int nota;
    scanf("%d", &nota);
    tabela[hash(nota)]++;
    if (tabela[hash(nota)] > tabela[hash(recorrente)]) {
      recorrente = nota;
    } else if (tabela[hash(nota)] == tabela[hash(recorrente)] &&
               nota > recorrente) {
      recorrente = nota;
    }
  }

  printf("%d\n", recorrente);
}
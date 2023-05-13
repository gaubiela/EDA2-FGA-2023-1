#include <stdio.h>
#include <string.h>

typedef struct {
  int flag;
  int hash;
  char s[20];
} No;

typedef struct TabelaHash {
  int tamanho;
  No entradas[101];
} TabelaHash;

int Hash(char *s) {
  long sum = 0;
  long i = 1;
  while (*s != '\0') {
    sum += (*s) * i;
    ++i;
    ++s;
  }
  return (19 * sum) % 101;
}

int encontra(TabelaHash *h, char *string) {
  int hash = Hash(string);
  int j;
  for (j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if (h->entradas[loc].flag == 0)
      return 0;
    if (h->entradas[loc].flag == 1)
      continue;
    if (h->entradas[loc].hash == hash &&
        (strcmp(h->entradas[loc].s, string) == 0)) {
      return 1;
    }
  }
  return 0;
}

void insere(TabelaHash *h, char *string) {
  int hash = Hash(string);
  int j;

  if (encontra(h, string) == 1)
    return;

  for (j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if (h->entradas[loc].flag == 0 || h->entradas[loc].flag == 1) {
      (h->tamanho)++;
      h->entradas[loc].flag = 2;
      h->entradas[loc].hash = hash;
      strcpy(h->entradas[loc].s, string);
      break;
    }
  }
  return;
}

void deleta(TabelaHash *h, char *string) {
  int hash = Hash(string);
  int j;
  for (j = 0; j < 20; ++j) {
    int loc = (hash + 23 * j + j * j) % 101;
    if (h->entradas[loc].flag == 0)
      return;
    if (h->entradas[loc].flag == 1)
      continue;
    if (h->entradas[loc].hash == hash &&
        (strcmp(h->entradas[loc].s, string) == 0)) {
      h->entradas[loc].flag = 1;
      (h->tamanho)--;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    TabelaHash tabela;

    int i, j;
    for (i = 0; i < 101; ++i) {
      tabela.entradas[i].flag = 0;
    }
    tabela.tamanho = 0;

    int n;
    scanf("%d", &n);

    char string[50];
    for (i = 0; i < n; ++i) {
      scanf("%s", string);
      if (string[0] == 'A') {
        insere(&tabela, string + 4);
      } else {
        deleta(&tabela, string + 4);
      }
    }

    printf("%d\n", tabela.tamanho);
    for (i = 0; i < 101; ++i) {
      if (tabela.entradas[i].flag == 2) {
        printf("%d:%s\n", i, tabela.entradas[i].s);
      }
    }
  }
  return 0;
}
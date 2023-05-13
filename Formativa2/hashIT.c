#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char str[18], indicador;
} No;

No *tabela;
int elementos;

int Hash(char *s) {
  char *aux = s;
  int n = 1, resultado = 0;
  while (*aux != '\0') {
    resultado += *aux * n;
    n++;
    aux++;
  }
  return (resultado * 19) % 101;
}

int procura(char *s, int chave) {
  No *busca;
  int posicao;
  for (int j = 0; j < 20; j++) {
    posicao = ((chave + j * j + 23 * j) % 101);
    busca = tabela + posicao;
    if (!strcmp(busca->str, s))
      return posicao;
  }
  return -1;
}

void insere(char *s) {
  if (elementos < 101) {
    No *novo;
    int chave = Hash(s), posicao = procura(s, chave);
    if (posicao != -1)
      return;
    for (int j = 0; j < 20; j++) {
      posicao = ((chave + j * j + 23 * j) % 101);
      novo = tabela + posicao;
      if (!novo->indicador) {
        strcpy(novo->str, s);
        elementos++;
        novo->indicador = 1;
        return;
      }
    }
  }
}

void deleta(char *s) {
  No *deletado;
  int chave = Hash(s), posicao = procura(s, chave);
  if (posicao == -1)
    return;
  deletado = tabela + posicao;
  deletado->indicador = 0;
  strcpy(deletado->str, "");
  elementos--;
}

int main(void) {
  int t, n;
  char comando[5], text[18];
  tabela = calloc(101, sizeof(No));
  scanf("%d", &t);
  while (getchar() != '\n')
    continue;
  while (t--) {
    elementos = 0;
    scanf("%d", &n);
    while (getchar() != '\n')
      continue;
    while (n--) {
      scanf(" %3[^:]:%s", comando, text);
      while (getchar() != '\n')
        continue;
      if (*comando == 'A') {
        insere(text);
      } else {
        deleta(text);
      }
    }
    printf("%d\n", elementos);
    for (int i = 0; i < 101; i++) {
      No *aux = tabela + i;
      if (aux->indicador) {
        printf("%d:%s\n", i, aux->str);
      }
    }
  }
  free(tabela);
  return 0;
}
// Jogo da Velha

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 3

// Desenha as colunas e fileiras do tabuleiro
void draw_tabuleiro(char tabuleiro[]) {
  system("clear");
  printf("# 1 2 3\n");

  // Fileiras (Estrutura de Iteração)
  for (int i = 0, n = 0; i < TAMANHO; i++) {
    // Colunas (Estruturas de Iteração)
    printf("%d ", i + 1);
    for (int j = 0; j < TAMANHO; j++) {
      printf("%c ", tabuleiro[n]);
      n++;
    }
    printf("\n");
  }
}

// Inicia o tabuleiro vazio (como o tabuleiro é um quadrado, seu conteúdo é a
// área do quadrado)
void init_tabuleiro(char tabuleiro[]) {
  for (int i = 0; i < TAMANHO * TAMANHO; i++) {
    tabuleiro[i] = '-';
  }
}

// Returns true if the piece was successfully posicionad,
// false if the position was invalid or already taken.
bool posiciona(char tabuleiro[], char jogador) {
  char posinput[64];

  printf("%c, ESCOLHA SUA POSIÇÃO NO TABULEIRO (COORDENADAS XY): ", jogador);
  scanf("%s", posinput); // LENDO CADA UM DOS CARACTERES (DIMENSAO X E Y)

  int row = (posinput[0] - '0') - 1;
  int col = (posinput[1] - '0') - 1;

  int pos = col + row * TAMANHO;

  if (pos >= 0 && pos < TAMANHO * TAMANHO) {
    if (tabuleiro[pos] == 'x' || tabuleiro[pos] == 'o')
      return false;

    tabuleiro[pos] = jogador;
    return true;
  }

  return false;
}

bool validar(char b[], char p) {
  // validar fileiras
  if (b[0] == p && b[1] == p && b[2] == p)
    return true;
  if (b[3] == p && b[4] == p && b[5] == p)
    return true;
  if (b[6] == p && b[7] == p && b[8] == p)
    return true;

  // validar colunas
  if (b[0] == p && b[3] == p && b[6] == p)
    return true;
  if (b[1] == p && b[4] == p && b[7] == p)
    return true;
  if (b[2] == p && b[5] == p && b[8] == p)
    return true;

  // validar diagonais
  if (b[0] == p && b[4] == p && b[8] == p)
    return true;
  if (b[2] == p && b[4] == p && b[6] == p)
    return true;

  // se ninguém ganhou retorna falso
  return false;
}

bool tabuleiro_cheio(char tabuleiro[]) {
  int tamanho_tabuleiro = TAMANHO * TAMANHO;
  for (int i = 0; i < tamanho_tabuleiro; i++) {
    if (tabuleiro[i] == '-')
      return false;
  }
  return true;
}

int main(void) {
  char tabuleiro[TAMANHO * TAMANHO];
  char jogador = 'x';
  bool velha = false;
  init_tabuleiro(tabuleiro);

  while (true) {
    draw_tabuleiro(tabuleiro);

    if (posiciona(tabuleiro, jogador)) {
      if (validar(tabuleiro, jogador))
        break;

      if (jogador == 'x')
        jogador = 'o';
      else
        jogador = 'x';
    } else {
      if (tabuleiro_cheio(tabuleiro)) {
        velha = true;
        printf("-----------------------------\n");
        printf("A velha venceu :C\n");
        printf("-----------------------------\n");
        break;
      }
    }
  }

  if (!velha) {
    draw_tabuleiro(tabuleiro);
    printf("-----------------------------\n");
    printf("Jogador %c venceu!!!\n", jogador);
    printf("-----------------------------\n");
  }
}

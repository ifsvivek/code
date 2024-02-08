// tic tac toe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(char board[3][3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

void init(char board[3][3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      board[i][j] = '-';
    }
  }
}

void input(char board[3][3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("Enter the value for board[%d][%d]: ", i, j);
      scanf(" %c", &board[i][j]);
    }
  }
}

void check(char board[3][3]) {
  int i, j, flag = 0;
  for (i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
        board[i][0] != '-') {
      printf("Player %c won\n", board[i][0]);
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    for (i = 0; i < 3; i++) {
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
          board[0][i] != '-') {
        printf("Player %c won\n", board[0][i]);
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[0][0] != '-') {
      printf("Player %c won\n", board[0][0]);
      flag = 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
        board[0][2] != '-') {
      printf("Player %c won\n", board[0][2]);
      flag = 1;
    }
    if (flag == 0) {
      printf("No one won\n");
    }
  }
  if (flag == 0) {
    printf("No one won\n");
  }
  return;
}

void main() {
  char board[3][3];
  init(board);
  input(board);
  display(board);
  check(board);
}

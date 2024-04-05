#include "Life.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
  Matrix m1 = newMatrix(10);

  m1.data[5][5] = true;
  m1.data[4][5] = true;
  m1.data[6][5] = true;

  Matrix m2 = newMatrix(20);
  Matrix oktagon = newMatrix(20);

  int i;
  for (i = 4; i < 8; i++)
  {
    oktagon.data[3][i] = true;
    oktagon.data[8][i] = true;
    oktagon.data[i][3] = true;
    oktagon.data[i][8] = true;
  }

  for (i = 5; i < 7; i++)
  {
    oktagon.data[4][i] = true;
    oktagon.data[7][i] = true;
    oktagon.data[i][4] = true;
    oktagon.data[i][7] = true;
  }

  char *ms = showMatrix(oktagon);
  printf("%s\n", ms);
  m1 = oktagon;
  printf("\033[H\033[J");

  while (true)
  {
    printf("\033[%d;%dH", 1, 1);
    printf("%s\n", ms);
    playGOLIn(m1, m2);
    showMatrixIn(m1, ms);
    Matrix tmp = m1;
    m1 = m2;
    m2 = tmp;
    sleep(1);
  }
  return 0;
}
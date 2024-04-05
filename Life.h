#ifndef LIFE__H
#define LIFE__H

#include <stdbool.h>

typedef struct
{
  unsigned int length;
  bool **data;
} Matrix;

/**
  Constructs a new Matrix with the given length. The matrix is empty.
*/
Matrix newMatrix(unsigned int length);

/**
  Deletes the given matrix on the heap.
*/
void deleteMatrix(Matrix m);

/**
  Returns a string representation of the matrix. In each line the value
  true is represented by the character '*' and the value false by the
  character ' '.
*/
char *showMatrix(Matrix m);

/**
  Like showMatrix, but the result is written to the parameter result.
  It is assumed that result has enough space allocated.
*/
void showMatrixIn(Matrix m, char *result);

/**
  Calculates the number of alive neighbours of the cell at position x,y.
*/
unsigned int calcAliveNeighbours(Matrix m, unsigned int x, unsigned int y);

/**
  Returns a new matrix that is filled according to the rules of the game of life.

  For a matrix cell that is occupied:
    Each cell with one or no neighbors dies.
    Each cell with four or more neighbors dies.
    Each cell with two or three neighbors survives.

  For a matrix cell that is empty:
    Each cell with three neighbors is resurrected.
*/
Matrix playGOL(Matrix m);

/**
  Like playGOL, but the result is written to the parameter result.
  It is assumed that m.length==result.length.
*/
void playGOLIn(Matrix m, Matrix result);
#endif
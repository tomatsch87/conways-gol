#include "Life.h"
#include <stdlib.h>
#include <stdio.h>

Matrix newMatrix(unsigned int length)
{
        int i;
        Matrix result;
        result.length = length;
        result.data = (bool **)calloc(length, sizeof(bool *));
        for (i = 0; i < length; ++i)
        {
                result.data[i] = (bool *)calloc(length, sizeof(bool));
        }
        return result;
}

void deleteMatrix(Matrix m)
{
        int i;
        for (i = 0; i < m.length; ++i)
        {
                free(m.data[i]);
        }
        free(m.data);
}

char *showMatrix(Matrix m)
{
        char *result = (char *)malloc(((m.length + 1) * m.length + 1) * sizeof(char));
        showMatrixIn(m, result);
        return result;
}

void showMatrixIn(Matrix m, char *result)
{
        int i;
        int j;
        int nextChar = 0;
        for (i = 0; i < m.length; ++i)
        {
                for (j = 0; j < m.length; ++j)
                {
                        if (m.data[i][j])
                        {
                                result[nextChar++] = '*';
                        }
                        else
                                result[nextChar++] = ' ';
                }
                result[nextChar++] = '\n';
        }
        result[nextChar] = '\0';
}

unsigned int calcAliveNeighbours(Matrix m, unsigned int x, unsigned int y)
{
        int i;
        int j;
        unsigned int neighbours = 0;

        for (i = -1; i < 2; ++i)
        {
                for (j = -1; j < 2; ++j)
                {
                        if ((x + i >= 0 && x + i < m.length) && (y + j >= 0 && y + j < m.length))
                        {
                                if (!(i == 0 && j == 0) && m.data[x + i][y + j])
                                {
                                        neighbours++;
                                }
                        }
                }
        }
        return neighbours;
}

Matrix playGOL(Matrix m)
{
        Matrix result = newMatrix(m.length);
        playGOLIn(m, result);
        return result;
}

void playGOLIn(Matrix m, Matrix result)
{
        int i;
        int j;
        unsigned int neighbours = 0;

        for (i = 0; i < m.length; ++i)
        {
                for (j = 0; j < m.length; ++j)
                {
                        neighbours = calcAliveNeighbours(m, i, j);
                        if (m.data[i][j] == true)
                        {
                                if (neighbours < 2 || neighbours > 3)
                                {
                                        result.data[i][j] = false;
                                }
                                else
                                {
                                        result.data[i][j] = true;
                                }
                        }
                        else
                        {
                                if (neighbours == 3)
                                {
                                        result.data[i][j] = true;
                                }
                                else
                                {
                                        result.data[i][j] = false;
                                }
                        }
                }
        }
}
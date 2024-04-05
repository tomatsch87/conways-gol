# Conway's Game of Life

## Introduction

Conway's Game of Life is a cellular automaton devised by the mathematician John Horton Conway. It is a zero-player game that simulates the evolution of a population of cells on a two-dimensional grid. The game evolves based on its initial state, requiring no further input from the user. It's an example of emergence and self-organization.

This project is an implementation of Conway's Game of Life in C. It provides a visual representation of the game in the terminal and allows users to observe the evolutions over time.

## Rules of the game

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead. Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1. Any live cell with fewer than two alive neighbours dies, as if by underpopulation.
2. Any live cell with two or three alive neighbours lives on to the next generation.
3. Any live cell with more than three alive neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three alive neighbours becomes a alive cell.

## Installation

To install and run the game, follow these steps:

1. Clone the repository:

      ```shell
      git clone https://github.com/tomatsch87/conways-gol.git
      ```

2. Navigate to the project directory:

      ```shell
      cd conways-gol
      ```

3. Compile the C files:

      ```shell
      gcc -o game Life.c Run.c
      ```

## How to run the game

To run the game, use the following command:

```shell
./game
```

The game will start and display the evolution of the cells in the terminal.

## How to stop the game

To stop the game, press `Ctrl + C`.

#include <stdio.h>
#include <stdlib.h>
#define UNASSIGNED 0
#define N 9
#include "Sudoku.h"

bool Sudoku::SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!Sudoku::FindUnassignedLocation(grid, row, col))
       return true;

    for (int num = 1; num <= 9; num++)
    {
        if (Sudoku::isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

bool Sudoku::FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}


bool Sudoku::UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool Sudoku::UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool Sudoku::UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

bool Sudoku::isSafe(int grid[N][N], int row, int col, int num)
{

    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num)&&
            grid[row][col]==UNASSIGNED;
}

void Sudoku::printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

int main()
{
	Sudoku sudoku=Sudoku();
    int **cubo;
    cubo=(int**)malloc(N*sizeof(int*));

    for(int i=0; i<N; i++)
    {
        *(cubo+i)=(int*)malloc(N*sizeof(int));
	}

 	 		cubo  = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (sudoku.SolveSudoku(cubo) == true)
         sudoku.printGrid(cubo);
         free(cubo);
    else
         printf("No solution exists");

    return 0;
}


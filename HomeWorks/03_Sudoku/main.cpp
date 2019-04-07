
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
 
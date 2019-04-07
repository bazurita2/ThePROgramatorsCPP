#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
	public:
		bool FindUnassignedLocation(int grid[N][N], int &row, int &col); 
		bool isSafe(int grid[N][N], int row, int col, int num); 
		bool SolveSudoku(int grid[N][N]);
		bool UsedInRow(int grid[N][N], int row, int num);
		bool UsedInCol(int grid[N][N], int col, int num);
		bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
		void printGrid(int grid[N][N]);
	protected:
};

#endif

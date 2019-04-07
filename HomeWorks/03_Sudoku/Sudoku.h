#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
	public:
		
	int principal();
	int buscar_num(int numero,int** arreglo,int tam,int j,int h);
	int moverx(int teclado,int a);
	int movery(int teclado,int b);
	void pintar(int teclado);
	void mundo(int opcion,int opcionn);
	void solucion(int** arreglo);
	void gotoxy(int x,int y);
	void pintar();
	void menu();
	int condicion(int b,int c);	
	protected:
};

#endif

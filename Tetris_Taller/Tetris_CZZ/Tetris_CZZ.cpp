// Tetris_CZZ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ListaDoble.h"
#include "TetrisFunction.h"
#include "Position.h"
int main()
{
	int n = 6;//Numero de elementos a insertar
	int m = 0;
	if (n >= 11) {
		m = 9;
	}
	else {
		m = n;
	}
	int MAXH = 0;
	bool escape=true;
	int cont = 0;
	int MAXV = 0;
	MAXH = 3 * (n - 1) + 8;
	MAXV = (int) (1 * MAXH);
	Position* pos = new Position();
	ListaDoble lista = ListaDoble();
	lista.listaDobleTetris(MAXH-7);
	system("color F0");
	TetrisFunction tetris = TetrisFunction(m+1,3);
	tetris.hideCursor();
	tetris.frame(MAXV, MAXH);
	do {
		if (lista.gano(n) == false) {
			escape = false;
		}
		if (lista.perdio(n) == false) {
			escape = false;
		}
		tetris.imprimir(MAXV, MAXH, pos);
		tetris.gotoxy(3, MAXV - 1);
		lista.imprimirLista();
		lista.insertarEnLista(pos, pos->getNum(), MAXV, MAXH);
		Sleep(100);
	} while (escape);

	tetris.gotoxy(0,MAXV+10);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

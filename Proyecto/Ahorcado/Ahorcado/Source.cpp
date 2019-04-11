#include <iostream>
#include <windows.h>
#include <stdio.h>


#define ARRIBA '8'
#define ABAJO '2'
#define ENTER 13


using namespace std;


char getch2()
{
	char c = 0;
	DWORD modo=0, contador;
	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

	
	SetConsoleMode(ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	ReadConsoleA(ih, &c, 1, &contador, NULL);

	if (c == 0) {
		ReadConsoleA(ih, &c, 1, &contador, NULL);
	}

	SetConsoleMode(ih, modo); 

	return c;
}



void gotoxy(USHORT x, USHORT y) {
	COORD cp = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}


int menu(const char titulo[], const char* opciones[], int n);
void menu_principal();
void menu_jugar();


int main()
{
	menu_principal();

	return 0;
}

void menu_principal()
{
	bool repite = true;
	int opcion;

	const char* titulo = "MENU DE OPCIONES";
	const char* opciones[] = { "Jugar", "Salir" };
	int n = 2;  

	do {
		opcion = menu(titulo, opciones, n);

		switch (opcion) {
		case 1:
			menu_jugar();
			break;

		case 2:
			cout << "\nEl programa se cerrara!! ADIOS" << endl;
			repite = false;
			system("pause>nul");
			break;
		}

	} while (repite);
}

void menu_jugar()
{
	bool repite = true;
	int opcion;

	// Titulo del menú y nombres de las opciones
	const char* titulo = "MENU PARA JUGAR";
	const char* opciones[] = { "FACIL", "MEDIO", "DIFICIL","Regresar" };
	int n = 4;  // Numero de opciones

	int a, b;
	float c, d;

	do {
		opcion = menu(titulo, opciones, n);

		system("cls");
		switch (opcion) {
		case 1:
			
			system("pause>nul");
			break;


		case 2:
			
			system("pause>nul");
			break;

		case 3:
			system("pause>nul");
			break;

		case 4:
			repite = false;
			break;
		}

	} while (repite);
}




int menu(const char titulo[], const char* opciones[], int n)
{
	int opcionSeleccionada = 1;  // Indica la opcionSeleccionada

	int tecla;

	bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER

	do {
		system("cls");
		system("color 1e");
		gotoxy(5, 3 + opcionSeleccionada); cout << "==>" << endl;

		// Imprime el título del menú
		gotoxy(15, 2); cout << titulo;

		// Imprime las opciones del menú
		for (int i = 0; i < n; ++i) {
			gotoxy(10, 4 + i); cout << i + 1 << ") " << opciones[i];
		}

		// Solo permite que se ingrese ARRIBA, ABAJO o ENTER

		do {
			tecla = getch2();
			// gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
		} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

		switch (tecla) {

		case ARRIBA:   // En caso que se presione ARRIBA

			opcionSeleccionada--;

			if (opcionSeleccionada < 1) {
				opcionSeleccionada = n;
			}

			break;

		case ABAJO:
			opcionSeleccionada++;

			if (opcionSeleccionada > n) {
				opcionSeleccionada = 1;
			}

			break;

		case ENTER:
			repite = false;
			break;
		}

	} while (repite);

	return opcionSeleccionada;
}



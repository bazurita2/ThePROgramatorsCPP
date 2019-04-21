#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

//Funcion para ubicar la posicion del Cursor(Gotoxy)
//Lee posiciones con espacios
void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void menu(){
	gotoxy(0,3);
	cout<<"\t ********        *  *********  *********  *  *********  *      *  *********  *********   *  *********"<<endl
	    <<"\t *        *      *  *          *          *  *       *  * *    *  *       *  *        *  *  *       *"<<endl
		<<"\t *          *    *  *          *          *  *       *  * *    *  *       *  *        *  *  *       *"<<endl
		<<"\t *           *   *  *          *          *  *       *  *  *   *  *       *  *        *  *  *       *"<<endl
		<<"\t *            *  *  *          *          *  *       *  *  *   *  *********  *********   *  *       *"<<endl
		<<"\t *           *   *  *          *          *  *       *  *   *  *  *       *  *     *     *  *       *"<<endl
		<<"\t *          *    *  *          *          *  *       *  *   *  *  *       *  *      *    *  *       *"<<endl
		<<"\t *        *      *  *          *          *  *       *  *    * *  *       *  *       *   *  *       *"<<endl
		<<"\t ********        *  *********  *********  *  *********  *      *  *       *  *        *  *  *********"<<endl;
	cout<<endl<<endl;
	cout<<"\t\t\t\t ******   ******                 ******  *     *"<<endl
	    <<"\t\t\t\t *       *            *    *     *       * *   *"<<endl
	    <<"\t\t\t\t ******   ******     ********    ******  *  *  *"<<endl
	    <<"\t\t\t\t *              *     *    *     *       *   * *"<<endl
	    <<"\t\t\t\t ******   ******                 ******  *     *"<<endl;
    gotoxy(47,21);
	cout<<"\t\tMENU"<<endl;
	gotoxy(47,23);
	cout<<"1. Opcion 1";
	gotoxy(47,24);
	cout<<"2. Opcion 2";
	gotoxy(47,25);
	cout<<"3. Opcion 3";
}

//Para seleccionar opcion
void Selector(int i){
	gotoxy(45,23+i);
}


int main(){
	int i = 0;
	char tecla;
	menu();
	Selector(i);
	while(true){
		tecla = getch(); //Detecta la flecha que presionemos
		switch(tecla){
			case ARRIBA:
				i--;
				if(i < 0){
					i = 2;
				}
				Selector(i);
				break;
			case ABAJO:
				i++;
				if(i == 0){
					i = 1;
				}
				if(i == 3){
					i = 0;
				}
				Selector(i);
				break;
			case ENTER:
				//Cuando presionemos enter se seleccionara este caso
				Selector(5);
				switch(i){
					//Aqui va las instrucciones de las opciones
					case 0:
						//Aqui van las instrucciones
						cout<<"Seleccion Opcion 1";
						break;
					case 1:
						//Aqui van las instrucciones
						cout<<"Seleccion Opcion 2";
						break;
					case 2:
						//Salir que puede ser otra opcion
						cout<<"Seleccion Opcion 3";
						break;
				}

				break;
		}
	}
	system("pause");
	exit(0);
	return 0;
}

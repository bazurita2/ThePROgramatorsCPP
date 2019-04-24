#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define N 7

using namespace std;


int main(){
	string provinciaPlaca;
	char *placa;
	placa=(char *)malloc(N*sizeof(char));
	cout<<"Ingrese la placa: ";
	for(int i=0;i<N;i++){
		cin>>*(placa+i);
//		toupper(*(placa+i));
//		if(i<3){
//			do{
//				cin>>*(placa+i);
//				system("cls");
//				cout<<"Verifique que los 3 primeros digitos que sean letras \nPor favor ingrese nuevamente su placa: ";
//			}while(*(placa+i) >= '1' &&  *(placa+i) <= '9');
//		}else{
//			do{
//				cin>>*(placa+i);
//				system("cls");
//				cout<<"Verifique que los 4 ultimos digitos que sean numeros \nPor favor ingrese nuevamente su placa:  ";
//			}while(*(placa+i) >= 'A' &&  *(placa+i) <= 'Z');
//		}
	}
	for(int i=0;i<N;i++){
		switch (*(placa+0)){
		case 'A':
		case 'a':
			provinciaPlaca="Azuay";
			break ;
		case 'B':
		case 'b':
			provinciaPlaca="Bolivar";
			break ;
		case 'U':
		case 'u':
			provinciaPlaca="Canar";
			break ;
		case 'C':
		case 'c':
			provinciaPlaca="Carchi";
			break ;
		case 'H':
		case 'h':
			provinciaPlaca="Chinborazo";
			break ;
		case 'X':
		case 'x':
			provinciaPlaca="Cotopaxi";
			break ;
		case 'O':
		case 'o':
			provinciaPlaca="El Oro";
			break ;
		case 'E':
		case 'e':
			provinciaPlaca="Esmeraldas";
			break ;
		case 'W':
		case 'w':
			provinciaPlaca="Galapagos";
			break ;
		case 'G':
		case 'g':
			provinciaPlaca="Guayas";
			break ;
		case 'I':
		case 'i':
			provinciaPlaca="Imbabura";
			break ;
		case 'L':
		case 'l':
			provinciaPlaca="Loja";
			break ;
		case 'R':
		case 'r':
			provinciaPlaca="Los Rios";
			break ;
		case 'M':
		case 'm':
			provinciaPlaca="Manabi";
			break ;
		case 'V':
		case 'v':
			provinciaPlaca="Morona Santiago";
			break ;
		case 'N':
		case 'n':
			provinciaPlaca="Napo";
			break ;
		case 'Q':
		case 'q':
			provinciaPlaca="Orellana";
			break ;
		case 'S':
		case 's':
			provinciaPlaca="Pastaza";
			break ;
		case 'P':
		case 'p':
			provinciaPlaca="Pichincha";
			break ;
		case 'Y':
		case 'y':
			provinciaPlaca="Santa Elena";
			break ;
		case 'J':
		case 'j':
			provinciaPlaca="Santo Domingo de los Tsachilas";
			break ;
		case 'K':
		case 'k':
			provinciaPlaca="Sucumbios";
			break ;
		case 'T':
		case 't':
			provinciaPlaca="Tungurahua";
			break ;
		case 'Z':
		case 'z':
			provinciaPlaca="Zamora Chinchipe";
			break ;
	}
	}
	cout<<"\nLa provincia es: "<<provinciaPlaca;
	return 0;
}


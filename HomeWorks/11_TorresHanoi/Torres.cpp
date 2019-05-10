#include <iostream>
#include "Torres.h"

using namespace std;

 
int main(){
	cout<<"\n\n\t\t\t\t\tUniversidad de las Fuerzas Armadas ESPE"<<endl;
	cout<<"\n\n\t\t\Tema: Torres de Hanoi."<<endl;
	cout<<"\n\n\t\t\Autores: Camilo Jimenez, Bryan Zurita,Sebastian Landazuri G."<<endl;
	cout<<"\n\t Fecha de creacion: 10-05-2019";
	cout<<"\n\t Fecha de presentacion: 12-05-2019";
	cout<<"\n\n\n\n\n"<<endl;

        int n;
        char A,B,C;
 
        cout<<"Los clavijas son A B C\n\n";
        cout<<"Ingrese el numero de discos: ";
        cin>>n;
        cout<<endl;
        Hanoi hanoi;
        hanoi.solucion(n,'A','C','B');
        return 0;
         
}

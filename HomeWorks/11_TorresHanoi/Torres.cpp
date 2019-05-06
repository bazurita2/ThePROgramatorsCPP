#include <iostream>
#include "Torres.h"

using namespace std;

 
int main(){
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

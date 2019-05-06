#include <iostream>


using namespace std;

class Hanoi{
	public:
		void solucion(int num,char A,char C,char B);
};

void Hanoi::solucion(int num,char A,char C,char B){
    if(num==1){
            cout<<"\tMueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
             
    }else{
        solucion(num-1,A,B,C);
        cout<<"\tMueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        solucion(num-1,B,C,A);
    }
}

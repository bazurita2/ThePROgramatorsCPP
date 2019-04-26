#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{

    string *placaLetra;
    placaLetra=(string*)calloc(tamanio,sizeof(string));
    int *placaNumero;
    placaNumero=(int*)calloc(tamanio,sizeof(int));
    int *arreglo;
    arreglo=(int*)calloc(tamanio,sizeof(int));

    string temp1=" ";
    int n=0;

    for(int i=0;i<tamanio;i++)
	{
        cout<<" Placa: "<<(i+1)<<endl;
        cout<<"Digite las letras de la placa: ";
        cin>>temp1;
        *(placaLetra+i)=temp1;
        cout<<"Digite el numero de la placa: ";
        cin>>n;
        *(placaNumero+i)=n;
        cout<<endl;
    }
    
        Hash ha = Hash(placaLetra,placaNumero,arreglo);
        ha.funcionHash();
        cout<<endl;
        ha.lectura();
        cout<<endl;
        ha.buscarClave();
        
  return 0;
  
}

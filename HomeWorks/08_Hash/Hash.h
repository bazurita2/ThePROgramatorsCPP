#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#define tamanio 8

using namespace std;

class Hash
{
    private:
        string *placaLetra;
        int *placaNumero;
        int *arreglo;

    public:
       Hash(string *,int *,int *);
       string *getPlacaLetra();
       int *getPlacaNumero();
       void setPlacaLetra(string*);
       void setPlacaNumero(int*);

       void funcionHash();
       void aniadir(int, int,string);
       void lectura();
       void buscarClave();
};


Hash::Hash(string *_placaLetra,int *_placaNumero,int *_arreglo)
{
	
    placaLetra=_placaLetra;
    placaNumero=_placaNumero;
    arreglo=_arreglo;
}

string *Hash::getPlacaLetra()
{
    return placaLetra;
}
int *Hash::getPlacaNumero()
{
    return placaNumero;
}

void Hash::setPlacaLetra(string *_placaLetra)
{
    placaLetra=_placaLetra;
}

void Hash::setPlacaNumero(int *_placaNumero)
{
    placaNumero=_placaNumero;
}


void Hash::funcionHash()
{
    int i;

    for(i=0;i<tamanio;i++)
	{
        *(arreglo+i)=0;
    }


    for(i=0;i<tamanio;i++)
	{

        int elemento=*(placaNumero+i);
        int indiceArreglo = elemento%(tamanio-1);
        cout<<" El indice es: "<<indiceArreglo<<" para el elemento: "<<elemento<<endl;

        do
		{
            indiceArreglo++;
            cout<<"Ocurrio una colision en el indice "<<(indiceArreglo-1)<<" cambiar al indice "<<indiceArreglo<<endl;
            indiceArreglo%=tamanio;
        }while(*(arreglo+indiceArreglo)>0);

        *(arreglo+indiceArreglo)=elemento; //ya calculo su clave, entonces pone el elemento
        string letra=*(placaLetra+i);

        aniadir(indiceArreglo,elemento,letra);
    }

}

void Hash::aniadir(int indiceArreglo,int elemento,string letra)
{
    ofstream agregarTxt;
        fflush(stdin);
    agregarTxt.open("TablaHash.txt",ios::app);
    agregarTxt<<"\n\tClave: "<<indiceArreglo;
    agregarTxt<<"\tPlaca: "<<letra;
    agregarTxt<<" - "<<elemento;
        agregarTxt.close();
}

void Hash::lectura()
{
     string txt;
     ifstream mostrarArchivo;
     mostrarArchivo.open("TablaHash.txt",ios::out);

    while(!mostrarArchivo.eof())
	{
        getline(mostrarArchivo,txt);
        cout<<txt<<endl;
    }
     mostrarArchivo.close();
}

void Hash::buscarClave()
{
    fstream archivo;
    string busca,linea1,linea2,linea3;
    int res=0;

    cout<<"Digite la clave a buscar: ";
    cin>>busca;

    if(!archivo.is_open())
	{
        archivo.open("TablaHash.txt",ios::in);
    }
    while(getline(archivo,linea1))
	{
        if(linea1.find(busca)!=string::npos)
		{
            cout<<linea1<<endl;
            getline(archivo,linea2);
            res=1;
        }
    }
    if(res==0)
	{
        cout<<"clave no encontrado"<<endl;
    }
}

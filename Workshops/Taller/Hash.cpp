#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

using namespace std;

int Hash::hash(string clave){
	int hash=0;
	int indice;
	
	for(int i=0;i<clave.length();i++){
		hash+=(int)clave[i];
		cout<<"hash = "<<hash<<endl;
	}
	
	indice=hash % tablaTam;
	
	return indice;
}

void Hash::insertarPlaca(string serial){
	int indice = hash(serial);
	string provincia;
	if(HashTable[indice] -> serial == "vacia"){
		HashTable[indice] -> serial = serial;
		switch (HashTable[indice] -> serial[0]){
		case 'A':
		case 'a':
			provincia="Azuay";
			break ;
		case 'B':
		case 'b':
			provincia="Bolivar";
			break ;
		case 'U':
		case 'u':
			provincia="Canar";
			break ;
		case 'C':
		case 'c':
			provincia="Carchi";
			break ;
		case 'H':
		case 'h':
			provincia="Chinborazo";
			break ;
		case 'X':
		case 'x':
			provincia="Cotopaxi";
			break ;
		case 'O':
		case 'o':
			provincia="El Oro";
			break ;
		case 'E':
		case 'e':
			provincia="Esmeraldas";
			break ;
		case 'W':
		case 'w':
			provincia="Galapagos";
			break ;
		case 'G':
		case 'g':
			provincia="Guayas";
			break ;
		case 'I':
		case 'i':
			provincia="Imbabura";
			break ;
		case 'L':
		case 'l':
			provincia="Loja";
			break ;
		case 'R':
		case 'r':
			provincia="Los Rios";
			break ;
		case 'M':
		case 'm':
			provincia="Manabi";
			break ;
		case 'V':
		case 'v':
			provincia="Morona Santiago";
			break ;
		case 'N':
		case 'n':
			provincia="Napo";
			break ;
		case 'Q':
		case 'q':
			provincia="Orellana";
			break ;
		case 'S':
		case 's':
			provincia="Pastaza";
			break ;
		case 'P':
		case 'p':
			provincia="Pichincha";
			break ;
		case 'Y':
		case 'y':
			provincia="Santa Elena";
			break ;
		case 'J':
		case 'j':
			provincia="Santo Domingo de los Tsachilas";
			break ;
		case 'K':
		case 'k':
			provincia="Sucumbios";
			break ;
		case 'T':
		case 't':
			provincia="Tungurahua";
			break ;
		case 'Z':
		case 'z':
			provincia="Zamora Chinchipe";
			break ;
	}
		HashTable[indice] -> provincia = provincia;
	}else{
		placa *ptrPlaca = HashTable[indice];
		placa *n = new placa;
		n -> serial = serial;
		n -> provincia = provincia;
		n -> next = NULL;
		while(ptrPlaca -> next != NULL){
			ptrPlaca = ptrPlaca -> next;
		}
		ptrPlaca -> next = n;
	}
}

int Hash::numerarAtributosPlaca(int indice){
	int cont=0;
	if(HashTable[indice] -> serial == "vacia"){
		return cont;
	}else{
		cont++;
		placa* ptrPlaca = HashTable[indice];
		while(ptrPlaca -> next != NULL){
			cont++;
			ptrPlaca = ptrPlaca -> next;
		}
	}
	return cont;
}

void Hash::imprimirTabla(){
	int num;
	for(int i=0;i<tablaTam;i++){
		num=numerarAtributosPlaca(i);
		cout<<"----------------------\n";
		cout<<"indice = "<<i<<endl;
		cout<<HashTable[i] -> serial<<endl;
		cout<<HashTable[i] -> provincia<<endl;
		cout<<"# de atributos de placa = "<<num<<endl;
		cout<<"----------------------\n";
	}
}

void Hash::buscarPorIndice(int indice){
	placa* ptrPlaca = HashTable[indice];
	if(ptrPlaca -> serial == "vacia"){
		cout<<"indice = "<<indice<<" esta vacia"<<endl;
	}else{
		cout<<"indice = "<<indice<<" contiene la siguiente placa: "<<endl;
		while(ptrPlaca != NULL){
			cout<<"----------------------\n";
			cout<<ptrPlaca -> serial<<endl;
			cout<<ptrPlaca -> provincia<<endl;
			cout<<"----------------------\n";
			ptrPlaca = ptrPlaca -> next;
		}
	}
}

void Hash::eliminarPlaca(string serial){
	int indice = hash(serial);
	placa* eliminarPtr;
	placa* P1;
	placa* P2;
	if(HashTable[indice] -> serial == "vacia" && HashTable[indice] -> provincia == "vacia"){
		cout<<serial<<" no se encontro en la tabla hash"<<endl;
	}else if(HashTable[indice] -> serial == serial && HashTable[indice] -> next == NULL){
		HashTable[indice] -> serial = "vacia";
		HashTable[indice] -> provincia = "vacia";
	}else if(HashTable[indice] -> serial == serial){
		eliminarPtr = HashTable[indice];
		HashTable[indice] = HashTable[indice] -> next;
		delete eliminarPtr;
		cout<<serial<<" la placa ha sido removida de la tabla hash"<<endl;
	}else{
		P1 = HashTable[indice] -> next;
		P2 = HashTable[indice];
		while(P1 != NULL && P1 -> serial != serial){
			P2 =P1;
			P1 = P1 -> next;
		}
		if(P1 == NULL){
			cout<<serial<<" no se encontro en la tabla hash"<<endl;
		}else{
			eliminarPtr = P1;
			P1 = P1 -> next;
			P2 -> next = P1;
			delete eliminarPtr;
			
		}
	}
}

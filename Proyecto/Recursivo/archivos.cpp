#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>

//class Archivo{
//	private:
//		string *textoRecuperado;
//	public:
//};
using namespace std;
int busquedaRecursiva(ifstream fileRead, string *textoRecuperado, int i){
	if(fileRead.is_open()){
		if(textoRecuperado[i]== "\0"){
			fileRead.close();
			return i;
		}else{
			i++;
		}
	}else{
		cout<<"error";
	}
}
void escribir(){
	ofstream file;
	string palabras;
	cout<<"ingrese una palabra: ";
	getline(cin,palabras);
	file.open("Dicionario.txt",ios::out);
	if(file.is_open()){
		file<<palabras;
	}
	file.close();
}
void leer(){
	ifstream fileRead;
	string *textoRecuperado;
	fileRead.open("DiccionarioEN.txt",ios::in);
	if(fileRead.is_open()){
		int i=0;
		while(!fileRead.eof()){
			busquedaRecursiva(fileRead,*(textoRecuperado+i),i);
			getline(fileRead,*(textoRecuperado+i));
			
			i++;
		}
	}
	fileRead.close();
	
}
int main (){
	//escribir();
	leer();
	
	return 0;
}



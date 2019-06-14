#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

class Contacto{
	
	public:
		long int cedula;
		long int telefonoCasa;
		int cumpleDia;
		int cumpleMes;
		int cumpleAnio;
		int aniverDia;
		int aniverMes;
		int aniverAnio;
		long int celular;
		string nombre;
		string apellido;
		string correo;
		string nota;
 		string direccion;

 		Contacto(long int, long int, int, int ,int ,int ,int ,int,long int, string, string, string, string, string);
 		
 		
	
	
};


Contacto::Contacto(long int cedula, long int telefonoCasa, int cumpleDia, int cumpleMes, int cumpleAnio, int aniverDia, int aniverMes, int aniverAnio, long int celular, string nombre, string apellido, string correo, string nota, string direccion){
	 
        this->cedula = cedula;
        this->telefonoCasa = telefonoCasa;
        this->cumpleDia = cumpleDia;
        this->cumpleMes = cumpleMes;
        this->cumpleAnio = cumpleAnio;
        this->aniverDia = aniverDia;
        this->aniverMes = aniverMes;
        this->aniverAnio = aniverAnio;
        this->celular = celular;
        this->nombre = nombre;
        this->apellido = apellido;
        this->correo = correo;
        this->nota = nota;
        this->direccion = direccion;
    
}




















#ifndef Alumno_H
#define Alumno_H
#include <iostream>
using namespace std;

class Alumno{
public:
   void setNombre(string nombre);
   string getNombre(void);
   void setApellido(string apellido);
   string getApellido(void);
   void setIndiceHash(int indiceHash);
   int getIndiceHash(void);
   void setCorreo(string correo);
   string getCorreo(void);

protected:
private:
   string nombre;
   string apellido;
   int indiceHash;
   string correo;


};

void Alumno::setNombre(string nombre){
   this->nombre=nombre;
}

string Alumno::getNombre(void){
   return nombre;
}

void Alumno::setApellido(string apellido){
   this->apellido=apellido;
}

string Alumno::getApellido(void){
   return apellido;
}

void Alumno::setIndiceHash(int indiceHash){
	this->indiceHash=indiceHash;
}

int Alumno::getIndiceHash(void){
	return indiceHash;
}

void Alumno::setCorreo(string correo){
	this->correo=correo;
}

string Alumno::getCorreo(void){
	return correo;
}

#endif // Alumno_H

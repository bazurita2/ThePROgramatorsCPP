#ifndef TablaHash_H
#define TablaHash_H

#include <iostream>

#include "Alumno.h"

using namespace std;

class TablaHash{
public:
   void iniciarTabla(string *alumnoTabla, int tamTabla);
   void ingresarAlumnos(string *alumnoTabla, int tamTabla, Alumno alumnos,string correoAlumno, int indiceHash);
   void imprimirTabla(string *alumnoTabla, int tamTabla, Alumno alumnos);
   void setTamTabla(int tamTabla);
   int getTamTabla(void);
   void setNAlumnos(int nAlumnos);
   int getNAlumnos(void);
   

protected:
private:
   int tamTabla;
   int nAlumnos;


};

void TablaHash::iniciarTabla(string *alumnoTabla, int tamTabla){
   for(int i=0;i<tamTabla;i++){
   	*(alumnoTabla+i)="vacia";
   }
}

void TablaHash::ingresarAlumnos(string *alumnoTabla, int tamTabla, Alumno alumnos,string correoAlumno, int indiceHash){
   bool validacionInsertar = false;
   int i=0;
   while(!validacionInsertar){
   	if(*(alumnoTabla+indiceHash)=="vacia"){
   		*(alumnoTabla+indiceHash)=alumnos.getCorreo();
   		validacionInsertar=true;
	   }else{
	   	indiceHash++;
	   	indiceHash%=tamTabla;
	   }
	   i++;
   }
}

void TablaHash::imprimirTabla(string *alumnoTabla, int tamTabla, Alumno alumnos){
   for(int i=0;i<tamTabla;i++){
   	if(*(alumnoTabla+i)=="vacia"){
   		cout<<"Tabla ["<<i<<"]\t"<<"---"<<endl;
	   }else{
	   	cout<<"Tabla ["<<i<<"]\t"<<*(alumnoTabla+i)<<"\t"<<alumnos.getIndiceHash()<<endl;
	   }
   }
}

void TablaHash::setTamTabla(int tamTabla){
   this->tamTabla=tamTabla;
}

int TablaHash::getTamTabla(void){
   return tamTabla;
}

void TablaHash::setNAlumnos(int nAlumnos){
	this->nAlumnos=nAlumnos;
}

int TablaHash::getNAlumnos(void){
	return nAlumnos;
}



#endif // TablaHash_H

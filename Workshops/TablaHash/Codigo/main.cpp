#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Alumno.h"
#include "TablaHash.h"

using namespace std;
int main(void){
	int n,k;
	string nombreAlumno;
	string apellidoAlumno;
	TablaHash tabla;
	cout<<"Ingrese el tamanio de la tabla: ";
	cin>>n;
	tabla.setTamTabla(n);
	string *alumnoTabla=new string[n];
	cout<<"Ingrese el numero de alumnos: ";
	cin>>k;
	tabla.setNAlumnos(k);
	Alumno alumnos[k];
	tabla.iniciarTabla(alumnoTabla,n);
	string cadena[k];
	int cont=0;
	for(int i=0;i<tabla.getNAlumnos();i++){
		cout<<"Ingrese el nombre del alumno["<<i<<"] :";
		cin>>nombreAlumno;
		alumnos[i].setNombre(nombreAlumno);
		cout<<"Ingrese el apellido del alumno["<<i<<"] :";
		cin>>apellidoAlumno;
		alumnos[i].setApellido(apellidoAlumno);
		cadena[i]=alumnos[i].getNombre();
		const string espe="@espe.edu.ec";
        int hash=0;
    	int indiceHash;
   //
   		string correoAlumno;
   		correoAlumno=alumnos[i].getNombre()[0]+alumnos[i].getApellido()+espe;
   		alumnos[i].setCorreo(correoAlumno);
   		cout<<correoAlumno<<endl;
   //
	   for(int z=0;z<correoAlumno.length();z++){
			hash+=(int)correoAlumno[z];
		}
		cout<<"hash = "<<hash<<endl;
		indiceHash=hash % n;
		cout<<"indiceHash = "<<indiceHash<<endl;
		alumnos[i].setIndiceHash(indiceHash);
		tabla.ingresarAlumnos(alumnoTabla,n,alumnos[i],correoAlumno,indiceHash);
		if(i<1){
		tabla.imprimirTabla(alumnoTabla,n,alumnos[i]);			
		}
	}
	for(int y=0;y<n;y++){
   	if(*(alumnoTabla+y)=="vacia"){
   		cout<<"Tabla ["<<y<<"]\t"<<"---"<<endl;
	   }else{
	   	cout<<"Tabla ["<<y<<"]\t"<<*(alumnoTabla+y)<<"\t"<<alumnos[y].getIndiceHash()<<endl;
	   }
   }
	
}


#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"
using namespace std;
class Persona
{
    public:
        char *nom;
        char *apell;
        int cedula;
		int telefonoCasa;
		int cumpleDia;
		int cumpleMes;
		int cumpleAnio;
		int aniverDia;
		int aniverMes;
		int aniverAnio;
		long int celular;
		char *correo;
		char *nota;
 		char *direccion;
    public:
        Persona();
};

Persona::Persona(){
}


#endif // PERSONA_H

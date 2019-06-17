#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include "Busqueda.h"

#define TAM 10

using namespace std;

int main() {
	Busqueda* b = new Busqueda("televition");
	b->leerArchivo();
	return 0;
}


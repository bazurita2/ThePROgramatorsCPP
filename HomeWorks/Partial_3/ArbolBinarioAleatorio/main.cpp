#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include "ArbolBinario.h"

using namespace std;



int main(){
	ArbolBinario *arbolBinario=new ArbolBinario();
	arbolBinario->menuArbol();
	cout<<"\n\n"<<endl;
	getch();
	return 0;
}


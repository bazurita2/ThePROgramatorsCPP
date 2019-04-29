#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define N 4

using namespace std;

class Dado
{
    public:
        Dado();
        int sumar();
        void contar(int a, int b, int c, int d);
        void mostrar();
        void pedirsuma();

    protected:

    private:
        int *dado;
        int suma;
};




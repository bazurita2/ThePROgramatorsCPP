//#ifndef CUADRADOL_H
#define CUADRADOL_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class CuadradoL{
    private:
        int dimension;
        int i,j,k;

    public:
        CuadradoL();

        void imprimir(CuadradoL );

        int **getCuadradoLMatriz();
        int getCuadradoLDimension();
        int getCuadradoI();
        int getCuadradoJ();
        int getCuadradoK();
        void setCuadradoLMatriz(int **);
        void setCuadradoLDimension(int);
        void setCuadradoI(int);
        void setCuadradoJ(int);
        void setCuadradoK(int);

};

CuadradoL::CuadradoL(){
}

int CuadradoL::getCuadradoLDimension(){
    return dimension;
}

int CuadradoL::getCuadradoI(){
    return i;
}

int CuadradoL::getCuadradoJ(){
    return j;
}

int CuadradoL::getCuadradoK(){
    return k;
}

void CuadradoL::setCuadradoLDimension(int dimension){
    this->dimension=dimension;
}

void CuadradoL::setCuadradoI(int i){
    this->i=i;
}

void CuadradoL::setCuadradoJ(int j){
    this->j=j;
}

void CuadradoL::setCuadradoK(int k){
    this->k=k;
}


void CuadradoL::imprimir(CuadradoL c){



    for(c.i=1;c.i<=c.dimension;c.i++)
        {
            for(c.j=c.i,c.k=1; c.k <=c.dimension ; c.k++,c.j++)
            {
                if (c.j>c.dimension)
                {
                        for(c.j=1; c.k <= c.dimension ; c.k++,c.j++)
                        {
                              cout<<"\t "<<c.j;
                        }
                }

                else
                    cout<<"\t "<<c.j;
            }
        cout<<endl;
        }
    system ("pause");
}






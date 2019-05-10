#include <stdlib.h>
#include "new 1.h"

int main(){
	cout<<"\n\n\t\t\t\t\tUniversidad de las Fuerzas Armadas ESPE"<<endl;
	cout<<"\n\n\t\t\Tema: Juego de dados, recursivo."<<endl;
	cout<<"\n\n\t\t\Autores: Camilo Jimenez, Bryan Zurita,Sebastian Landazuri G."<<endl;
	cout<<"\n\t Fecha de creacion: 04-05-2019";
	cout<<"\n\t Fecha de presentacion: 05-05-2019";
	cout<<"\n\n\n\n\n"<<endl;
    Dado dado=Dado();
    dado.pedirsuma();
    dado.contar(1,1,1,1);
    system("pause");
    return 0;

}


Dado::Dado()
{
    dado=(int *)malloc(N*sizeof(int));
}

void Dado::contar(int a, int b, int c, int d)
{
    if(!(a==6 && b==6 && c==6 && d==6))
    {
        *(dado+0)=a;
        *(dado+1)=b;
        *(dado+2)=c;
        *(dado+3)=d;
        d++;
        if(sumar()==suma)
        {
            mostrar();
        }

        if(d==7)
        {
            c++;
            d=1;
        }

       if(c==7)
       {
            b++;
       	    c=1;
       }
    	if(b==7)
        {
            a++;
            b=1;
        }
            contar(a,b,c,d);
    }
    else
    {
        if (suma==24)
		{
       	 	*(dado+0)=6;
        	*(dado+1)=6;
       		 *(dado+2)=6;
        	*(dado+3)=6;
        	mostrar();

    	}
    }

}


int Dado::sumar()
{
    int plus=0;
    
    for(int i=0;i<N;i++)
    {
        plus+=*(dado+i);
    }
    
    return plus;
}


void Dado::mostrar()
{
    cout<<"Combinación :";
    for(int i=0;i<N;i++)
        cout<<*(dado+i);
    }
    cout<<endl;
}

void Dado::pedirsuma()
{

	do
	{
   		cout<<"Escriba el valor total de la suma"<<endl;
   		cin>>suma;
  		if (suma < 4 || suma> 24)
		{
  	  		cout<<"Numero incorrecto, el valor debe ser entre 4 y 24"<<endl;
   		}
	}while(suma < 4 || suma> 24);

}


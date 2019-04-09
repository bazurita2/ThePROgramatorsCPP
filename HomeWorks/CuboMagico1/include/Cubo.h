#ifndef CUBO_H
#define CUBO_H

class Cubo
{
	public:
		void visualizar(Cubo );
		void inicializar(Cubo );
		void proceder(Cubo);
		void setMatriz(int **);
		int** getMatriz();
		void setN(int);
		int getN();
	protected:
		int** matriz;
		int n;

};


void Cubo::setMatriz(int** valor)
{
	this->matriz=valor;
}

void Cubo::setN(int n){
    this->n=n;
}

int **Cubo::getMatriz()
{
	return matriz;
}

int Cubo::getN(){
    return n;
}


void Cubo::proceder(Cubo c)
{
	int key,i,j,k,r;

    if(n%2!=0)
	{
      	*(*(c.matriz+0)+(n-1)/2)=1;
        key=2;
        i=0;
        j=(n-1)/2;

      while(key <= c.n*c.n)
	  {
		k=i-1;
		r=j-1;
		if(k<0)
			k=c.n-1;
		if(r<0)
		    r=c.n-1;
		if(*(*(c.matriz+k)+r)!=0)
			i=(i+1)%c.n;
		else
		{
	 	   i=k;
	       j=r;
		}
		*(*(c.matriz+i)+j)=key;
		key++;
      }

   }
   else
   {
   	  printf("ERROR: La dimension no es impar\n");
   	  exit(1);
   }

}

void Cubo::visualizar(Cubo c)
{
    int i,j;
   for(i=0;i<c.n;i++)
   {
     for(j=0;j<c.n;j++)
     {
      	 printf("%-3d" ,*(*(c.matriz+j)+i));
     }
    printf("\n");
   }
}

void Cubo::inicializar(Cubo c)
{
   int i,j;
   for(i=0;i<c.n;i++)
   {
   		for(j=0;j<c.n;j++)
   		{
   		  *(*(c.matriz+j)+i)=0;
	    }
   }
}


#endif

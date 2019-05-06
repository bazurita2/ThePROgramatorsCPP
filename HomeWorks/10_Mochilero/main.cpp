
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

void aniadir(int **A,int i,int j){
    ofstream agregarTxt;
        fflush(stdin);
    agregarTxt.open("Mochila.txt",ios::app);
    agregarTxt<<"\t"<<*(*(A+i)+j)<<" ";
        agregarTxt.close();
}

void aniadir2(){
    ofstream agregarTxt;
        fflush(stdin);
    agregarTxt.open("Mochila.txt",ios::app);
    agregarTxt<<"\n";
        agregarTxt.close();
}

void aniadir3(int v){
    ofstream agregarTxt;
        fflush(stdin);
    agregarTxt.open("Mochila.txt",ios::app);
    agregarTxt<<"\n";
    agregarTxt<<"El mayor beneficio es: "<<v<<endl;
        agregarTxt.close();
}



class Mochila{
    private:
        int n;
        int m;
        int *p;
        int *b;
        int **A;
    public:
        Mochila(int,int,int*,int*,int**);
        void pesoP();
        void beneficioB();
        void llenar();
        void mostrar();

};

Mochila::Mochila(int n,int m,int *p,int *b,int **A){
    this->m=m;
    this->n=n;
    this->p=p;
    this->b=b;
    this->A=A;
}

void Mochila::pesoP(){
    for(int q=1;q<n;++q){
 	
 	do{
 		cout<<"Ingrese peso para p["<<q<<"] : "<<endl;
 		cin>>*(p+q);
	 }while(*(p+q)<=0);
 	
 }
 	fflush(stdin);
 }


void Mochila::beneficioB(){
      for(int q=1;q<n;++q){
      	do{
      		cout<<"Ingrese beneficio para b["<<q<<"] : "<<endl;
			
			cin>>*(b+q);
	 }while(*(b+q)<=0);
 }
 	fflush(stdin);
 }


void Mochila::llenar(){
  for(int a=0;a<m;a++){
 	*(*(A+0)+a)=0;
 	if(a<n){
 		*(*(A+a)+0)=0;
	 }
 }
 for(int i=1;i<=n-1;++i){
    for(int j=1;j<=m-1;++j){
    	if(j-*(p+i)<0){
    			*(*(A+i)+j)=*(*(A+(i-1))+j);
		}
		else{
        *(*(A+i)+j)= max(*(*(A+(i-1))+j), *(*(A+(i-1))+(j-*(p+i))) + *(b+i));
    	}
    }
 }

}

void Mochila::mostrar(){

 int may=-1,V=0;
 for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        aniadir(A,i,j);
    	if(*(*(A+i)+j)>may){
    		may=*(*(A+i)+j);
    		V=*(*(A+i)+j);
		}

    }
    aniadir2();
}
aniadir3(V);
}





int main()
{
 int n,m;
 do{
 cout<<"Ingrese n y m de la matriz (n=cantidad de objetos)y (m=peso max): "<<endl;
 cin>>n>>m;		
	 }while(n<1 && m<1);
 
 n=n+1;
 m=m+1;

 int **A;

    A=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        *(A+i)=(int*)calloc(m,sizeof(int));
    }
 int *p;

    p=(int*)calloc(n+1,sizeof(int));

 int *b;

    b=(int*)calloc(n+1,sizeof(int));


 *(p+0)=0;
 *(b+0)=0;

    Mochila mo = Mochila(n,m,p,b,A);

  mo.pesoP();
  mo.beneficioB();
  mo.llenar();
  mo.mostrar();
}

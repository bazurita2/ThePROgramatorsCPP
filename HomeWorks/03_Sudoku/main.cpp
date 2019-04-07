#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "Sudoku.h"

char **mapa;
int **arreglo1;
int **arreglo2;
int **vista2;

int bandera=0,teclado=0,b,c,contadorx=0,contadory=0,xx=5,yy=5,jota,fstop=0,aleatorio,l=0,i,conta=0,conta2=0;
int opcion,opcionn,contadoryy,contadorxx;

int main()
{	
	mapa=(char**)malloc(9*sizeof(char*));
	arreglo1=(int**)malloc(9*sizeof(int*));
	arreglo2=(int**)malloc(9*sizeof(int*));
	vista2=(int**)malloc(9*sizeof(int*));
	
	for(int i=0; i<9; i++)
	{
		*(mapa+i)=(char*)malloc(9*sizeof(char));
		*(arreglo1+i)=(int*)malloc(9*sizeof(int));
		*(arreglo2+i)=(int*)malloc(9*sizeof(int));	
		*(vista2+i)=(int*)malloc(9*sizeof(int));	
	}
	Sudoku sudoku=Sudoku();

	while(bandera==0)
	{
		bandera=0;teclado=0;contadorx=0;contadory=0;xx=5;yy=5;jota=0;fstop=0;aleatorio=0;opcion=0;opcionn=0;
		sudoku.menu();
		sudoku.solucion(arreglo1);
		sudoku.mundo(opcion,opcionn);
		bandera=sudoku.principal();
	}
}
int Sudoku::principal()
{
	gotoxy(xx,yy);
	while(teclado!=27 && teclado!=120)
		{
		   				teclado=getch();
					    if(teclado==97 || teclado==100)
					    {
					    		xx=moverx(teclado,xx);
					    		gotoxy(xx,yy);
					    		if(teclado==100){contadorx=contadorx+1;}
					    		else if(teclado==97){contadorx=contadorx-1;}
								if(contadorx>8){contadorx=0;}
							    if(contadorx<0){contadorx=8;}
					    }
					    else if(teclado==119 || teclado==115)
					    {
					    		yy=movery(teclado,yy);
					    		gotoxy(xx,yy);
					    		if(teclado==115){contadory=contadory+1;}
					    		else if(teclado==119){contadory=contadory-1;}
					    		if(contadory>8){contadory=0;}
							    if(contadory<0){contadory=8;}
					    }
						if((teclado==49||teclado==50||teclado==51||teclado==52||teclado==53||
							teclado==54||teclado==55||teclado==56||teclado==57) && mapa[contadory][contadorx]=='°')
						{
							if(teclado==49)jota=1;
							if(teclado==50)jota=2;
							if(teclado==51)jota=3;
							if(teclado==52)jota=4;
							if(teclado==53)jota=5;
							if(teclado==54)jota=6;
							if(teclado==55)jota=7;
							if(teclado==56)jota=8;
							if(teclado==57)jota=9;
							fstop=0;
							fstop=buscar_num(jota,arreglo2,9,contadory,contadorx);
							arreglo2[contadory][contadorx]=jota;
							if(fstop==1){pintar(2);}
							else{pintar(1);}
							printf("%d",jota);
							gotoxy(xx,yy);	
						}	
						if(teclado==8 && mapa[contadory][contadorx]=='°')
						{
							pintar(3);
							gotoxy(xx,yy);
							printf("°");
							mapa[contadory][contadorx]='°';
							arreglo2[contadory][contadorx]=0;
							gotoxy(xx,yy);		
						}					
		}
		if(teclado==120)
		{
			system("CLS");
			return 0;	
		}
		else
		{
			gotoxy(5,27);
			return 1;
		}
}

int Sudoku::moverx(int teclado,int x) 
{                                                        
						if(teclado==97)
						{
							x-=6;
							if(x==23){x=17;}
							else if(x==47){x=41;}
							else if(x<5){x=65;}
						}
						if(teclado==100)
						{
							x+=6;
							if(x==23){x=29;}
							else if(x==47){x=53;}
							else if(x>65){x=5;}
						}
return	x;
}

int Sudoku::movery(int teclado,int y) 
{
						if(teclado==119)
						{
								y-=2;
								if(y==11){y=9;}
								else if(y==19){y=17;}
								else if(y<5){y=25;}
						}
						else if(teclado==115)
						{
								y+=2;
								if(y==11){y=13;}
								else if(y==19){y=21;}
								else if(y>25){y=5;}	
						}
return	y;
}
void Sudoku::gotoxy(int x,int y)
{
	HANDLE hCon; 
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos); 
}
void Sudoku::mundo(int opcion,int opcionn)
{
pintar(3);
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° SUDOKU °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n \n");
srand(time(NULL));
for(b=0;b<9;b++)
{
	printf("\n \n");
	if(b==3 || b==6){printf("---------------------------------------------------------------------\n\n");}
	for(c=0;c<9;c++)
	{
		if(c==3 || c==6){printf("     |");}
		if(opcion!=1)
		{
			*(*(arreglo2+b)+c)=0;
			*(*(mapa+b)+c)='°';

			if(rand()%(opcionn+1)==1)
			{
				printf("%6d",*(*(arreglo1+b)+c));
				*(*(arreglo2+b)+c)=*(*(arreglo1+b)+c);
				*(*(mapa+b)+c)='|';
			}
			else{printf("%6c",mapa[b][c]);}	
		}
		else*(*(mapa+b)+c)='|'; printf("%6d",*(*(arreglo1+b)+c));}
	}
}						
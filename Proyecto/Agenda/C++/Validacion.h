#ifndef VALIDACION_H
#define VALIDACION_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>

int entero2(){

	char *pass = new char[20];
	int i = 0;
	while (i<1){
		pass[i] = _getch();
		if ((pass[i]>32 && i<20) && (pass[i] >= 48 && pass[i] <= 57))
		{
			printf("%c", pass[i]);
			i++;
		}
        else if (pass[i] == 8 && i>0)
		{
			putchar(8);
			putchar(' ');
			putchar(8);
			i--;
    }
	}
	pass[i] = '\0';
	int entero = atoi(pass);
	return entero;
    }

    float validarFlotante(){
	char *pass = new char[10];
	int i = 0, punto = 0, acm = 0;
	while (pass[i] != 13 || i<1){
		if ((pass[i]>32 && i<20) && (pass[i] >= 48 && pass[i] <= 57) || pass[i] == 46){
			if (pass[i] == 46){
				punto++;
				if (punto>1)
					acm++;
			}
			if (acm > 0)
			{
				if (pass[i] != 46)
				{
					printf("%c", pass[i]);
					i++;
				}
			}
			else
			{
				printf("%c", pass[i]);
				i++;
			}
		}
		else if (pass[i] == 8 && i>0)
		{
			if (pass[i - 1] == 46)acm = 0;
			putchar(8);
			putchar(' ');
			putchar(8);
			i--;
			if (pass[i] == 46)
			{
				punto = 0;
			}
		}
	}
	pass[i] = '\0';
	float flotante = atof(pass);
	return flotante;
}

char* ingresarLetras(){
	char *dato,c;
	string dato2;
	dato=(char*)malloc(15*sizeof(char));
	int i=0;
	while((c=getch())!=13){
		if((c>='A' && c<='Z')||(c>='a'&&c<='z')){
			printf("%c",c);
			*(dato+(i++))=c;
		}
	}
	*(dato+i)='\0';
	return dato;
}

char *ingresarNumeros(int &cont){
	char *dato,c;
	dato=(char*)malloc(10*sizeof(char));
	int i=0;
	while((c=getch())!=13){
		if(c=='0' || c=='1'|| c=='2'|| c=='3'|| c=='4'|| c=='5'|| c=='6'|| c=='7'|| c=='8'|| c=='9'){
			printf("%c",c);
			*(dato+(i++))=c;
			cont++;
		}
	}
	*(dato+i)='\0';
	return dato;
}

int validarCedula(){
   int cedula,ced,pares,impares,total,dec=0,cedulaValida;
        int a,b,c,d,e,f,g,h,i,j,k;
        int cont=0;
        char *ingreso;
        cout<<"\nIngrese su cedula: ";
        ingreso = ingresarNumeros(cont);//Ingreso de solo números
        cedula = atoi(ingreso); //Transdorma de char a int
        ced=cedula;

        a=cedula/1000000000;
        cedula=cedula-(a*1000000000);
        b=cedula/100000000;
        cedula=cedula-(b*100000000);
        c=cedula/10000000;
        cedula=cedula-(c*10000000);
        d=cedula/1000000;
        cedula=cedula-(d*1000000);
        e=cedula/100000;
        cedula=cedula-(e*100000);
        f=cedula/10000;
        cedula=cedula-(f*10000);
        g=cedula/1000;
        cedula=cedula-(g*1000);
        h=cedula/100;
        cedula=cedula-(h*100);
        i=cedula/10;
        cedula=cedula-(i*10);
        j=cedula/1;
        cedula=cedula-(j*1);

        if (cedula>2400000000){
                cout<<"Numero de cedula invalido."<<endl;
        }else{

                pares=b+d+f+h;

                a=a*2;
                if (a>9){
                        a=a%10+a/10;
                }

                c=c*2;
                if (c>9){
                        c=c%10+c/10;
                }

                e=e*2;
                if (e>9){
                        e=e%10+e/10;
                }

                g=g*2;
                if (g>9){
                        g=g%10+g/10;
                }

                i=i*2;
                if (i>9){
                        i=i%10+i/10;
                }

                impares=a+c+e+g+i;

                total=pares+impares;

                while (dec-total!=j && dec<total+10){
                        dec=dec+10;
                }

                if (dec-total==j && ced != NULL && cont==10){
                        cout<<"   Cedula valida";
                        return ced;
                }else {
                        cout<<"   Cedula erronea";
                        validarCedula();
                }
        }
}

char *ingresarNumerosFlotantes(){
	char *dato,c;
	dato=(char*)malloc(10*sizeof(char));
	int i=0;
	int cont=0;
	while((c=getch())!=13){
		if((c=='0' || c=='1'|| c=='2'|| c=='3'|| c=='4'|| c=='5'|| c=='6'|| c=='7'|| c=='8'|| c=='9') && cont<3){
			printf("%c",c);
			*(dato+(i++))=c;
                    if(cont!=0) cont++;
		}
		if(cont==0&& c=='.'){
        printf("%c",c);
        *(dato+(i++))=c;
        cont++;
		}
	}
	*(dato+i)='\0';
	return dato;
}
float validarFloat(){
    float numero;
    char *ingreso;
    ingreso = ingresarNumerosFlotantes();
    numero = atof(ingreso);
    return numero;
}

#endif // VALIDACION_H

#ifndef VALIDACION_H
#define VALIDACION_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>

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
int ingresarSoloNumeros(){
	int num;
	char *dato,c;
	dato=(char*)malloc(10*sizeof(char));
	int i=0;
	while((c=getch())!=13){
		if(c=='0' || c=='1'|| c=='2'|| c=='3'|| c=='4'|| c=='5'|| c=='6'|| c=='7'|| c=='8'|| c=='9'){
			printf("%c",c);
			*(dato+(i++))=c;
		}
	}
	*(dato+i)='\0';
    num= atoi(dato);
	return num;
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


//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURAS DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA


#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

using namespace std;

class Persona{
	private:
		string cedula;
		string nombre;
		string apellido;
		string telefonoCasa;
		string cumpleDia;
		string cumpleMes;
		string cumpleAnio;
		string cumpleanios;
		string aniverDia;
		string aniverMes;
		string aniverAnio;
		string aniversario;
		string celular;
		string correo;
		string nota;
 		string direccion;

		
	public:
		void setCedula(string);
		void setNombre(string);
		void setApellido(string);
		void setTelefonoCasa(string);
		//
		void setCumpleDia(string);
		void setCumpleMes(string);
		void setCumpleAnio(string);
		void setCumpleanios(string);
		//
		void setAniverDia(string);
		void setAniverMes(string);
		void setAniverAnio(string);
		void setAniversario(string);
		//
		void setCelular(string);
		void setCorreo(string);
		void setNota(string);
		void setDireccion(string);
		string getCedula();
		string getNombre();
		string getApellido();
		string getTelefonoCasa();
		string getCumpleDia();
		string getCumpleMes();
		string getCumpleAnio();
		string getCumpleanios();
		string getAniverDia();
		string getAniverMes();
		string getAniverAnio();
		string getAniversario();
		string getCelular();
		string getCorreo();
		string getNota();
		string getDireccion();
		bool validacionCedula(string);
};

void Persona::setCedula(string cedula){
//	bool band=true;
//	band=validacionCedula(cedula);
//	if(band==false||cedula.length()!=10){
//		for(int i=0;i<cedula.length();i++){
//		if(!(cedula[i]>='0'&&cedula[i]<='9')||band==0){
//		band=true;
//		cedula="0";
//		cout<<"\tIngrese un cedula real. Vuelva a intentarlo"<<endl<<endl;
//		cout<<"\tIngrese la cedula: ";
//		cin>>cedula;
//		fflush(stdin);
//		setCedula(cedula);
//		}
//	  }
//	}
	this->cedula=cedula;
}
void Persona::setNombre(string nombre){
	for(int i=0;i<nombre.length();i++){
		if(!(nombre[i]>='A'&&nombre[i]<='Z'||nombre[i]>='a'&&nombre[i]<='z')){
			nombre="0";
			cout<<"\tIngrese solo letras. Vuelva a intentarlo"<<endl<<endl;
			cout<<"\tIngrese el nombre de la persona: ";
			cin>>nombre;
			fflush(stdin);
			setNombre(nombre);
		}
	}
	this->nombre=nombre;
}
void Persona::setApellido(string apellido){
	for(int i=0;i<apellido.length();i++){
		if(!(apellido[i]>='A'&&apellido[i]<='Z'||apellido[i]>='a'&&apellido[i]<='z')){
			apellido="0";
			cout<<"\tIngrese solo letras. Vuelva a intentarlo"<<endl<<endl;
			cout<<"\tIngrese el apellido de la persona: ";
			cin>>apellido;
			fflush(stdin);
			setApellido(apellido);
		}
	}
	this->apellido=apellido;
}

void Persona::setTelefonoCasa(string telefonoCasa){
//	if(telefonoCasa.length()!=9){
//		for(int i=0;i<telefonoCasa.length();i++){
//			if(!(telefonoCasa[i]>='0'&&telefonoCasa[i]<='9')||telefonoCasa.length()!=9){
//			telefonoCasa="";
//			cout<<"\tIngrese un telefono de Casa real. Vuelva a intentarlo"<<endl<<endl;
//			cout<<"\tIngrese el telefono de Casa: ";
//			cin>>telefonoCasa;
//			setTelefonoCasa(telefonoCasa);
//			fflush(stdin);
//			}else{
//				
//			}
//		}
//	}else{
//		
//	}
	this->telefonoCasa=telefonoCasa;
}

void Persona::setCumpleDia(string cumpleDia){
	if(cumpleDia.length()!=2){
		for(int i=0;i<cumpleDia.length();i++){
		if(!(cumpleDia[i]>='0'&&cumpleDia[i]<='9')||cumpleDia.length()!=2){
		cumpleDia="";
		cout<<"\tIngrese un cumple Dia real. Vuelva a intentarlo"<<endl<<endl;
		cout<<"\tIngrese el cumple Dia: ";
		cin>>cumpleDia;
		fflush(stdin);
		setCumpleDia(cumpleDia);
		}
	  }
	}
	this->cumpleDia=cumpleDia;
}

void Persona::setCumpleMes(string cumpleMes){
	if(cumpleMes.length()!=2){
		for(int i=0;i<cumpleMes.length();i++){
		if(!(cumpleMes[i]>='0'&&cumpleMes[i]<='9')||cumpleMes.length()!=2){
		cumpleMes="";
		cout<<"\tIngrese un cumple Mes real. Vuelva a intentarlo"<<endl<<endl;
		cout<<"\tIngrese el cumple Mes: ";
		cin>>cumpleMes;
		fflush(stdin);
		setCumpleMes(cumpleMes);
		}
	  }
	}
	this->cumpleMes=cumpleMes;
}

void Persona::setCumpleAnio(string cumpleAnio){
	if(cumpleAnio.length()!=4){
		for(int i=0;i<cumpleAnio.length();i++){
		if(!(cumpleAnio[i]>='0'&&cumpleAnio[i]<='9')||cumpleAnio.length()!=4){
		cumpleAnio="0";
		cout<<"\tIngrese un cumple Anio real. Vuelva a intentarlo"<<endl<<endl;
		cout<<"\tIngrese el cumple Anio: ";
		cin>>cumpleAnio;
		fflush(stdin);
		setCumpleAnio(cumpleAnio);
		}
	  }
	}
	this->cumpleAnio=cumpleAnio;
}

void Persona::setCumpleanios(string cumpleanios){
	this->cumpleanios=cumpleanios;
}

void Persona::setAniverDia(string aniverDia){
	if(aniverDia.length()!=2){
		for(int i=0;i<aniverDia.length();i++){
		if(!(aniverDia[i]>='0'&&aniverDia[i]<='9')||aniverDia.length()!=2){
		aniverDia="0";
		cout<<"\tIngrese un aniver Dia real. Vuelva a intentarlo"<<endl<<endl;
		cout<<"\tIngrese el aniver Dia: ";
		cin>>aniverDia;
		fflush(stdin);
		setAniverDia(aniverDia);
		}
	  }
	}
	this->aniverDia=aniverDia;
}

void Persona::setAniverMes(string aniverMes){
	if(aniverMes.length()!=2){
		for(int i=0;i<aniverMes.length();i++){
		if(!(aniverMes[i]>='0'&&aniverMes[i]<='9')||aniverMes.length()!=2){
		aniverMes="0";
		cout<<"\tIngrese un aniver Mes real. Vuelva a intentarlo"<<endl<<endl;
		cout<<"\tIngrese la aniver Mes: ";
		cin>>aniverMes;
		fflush(stdin);
		setAniverMes(aniverMes);
		}
	  }
	}
	this->aniverMes=aniverMes;
}

void Persona::setAniverAnio(string aniverAnio){
	if(aniverAnio.length()!=4){
		for(int i=0;i<aniverAnio.length();i++){
		if(!(aniverAnio[i]>='0'&&aniverAnio[i]<='9')||aniverAnio.length()!=4){
		aniverAnio="0";
		cout<<"\tIngrese un aniver Anio real. Vuelva a intentarlo"<<endl<<endl;
		cout<<"\tIngrese la aniver Anio: ";
		cin>>aniverAnio;
		fflush(stdin);
		setAniverAnio(aniverAnio);
		}
	  }
	}
	this->aniverAnio=aniverAnio;
}

void Persona::setAniversario(string aniversario){
	this->aniversario=aniversario;
}

void Persona::setCelular(string celular){
//	if(celular.length()!=10){
//		for(int i=0;i<celular.length();i++){
//		if(!(celular[i]>='0'&&celular[i]<='9')||celular.length()!=10){
//		celular="0";
//		cout<<"\tIngrese un celular real. Vuelva a intentarlo"<<endl<<endl;
//		cout<<"\tIngrese la celular: ";
//		cin>>celular;
//		fflush(stdin);
//		setCelular(celular);
//		}
//	  }
//	}
	this->celular=celular;
}

void Persona::setCorreo(string correo){
	this->correo=correo;
}

void Persona::setNota(string nota){
	this->nota=nota;
}

void Persona::setDireccion(string direccion){
	this->direccion=direccion;
}


string Persona::getCedula(){
	return cedula;
}

string Persona::getNombre(){
	return nombre;
}

string Persona::getApellido(){
	return apellido;
}

string Persona::getTelefonoCasa(){
	return telefonoCasa;
}

string Persona::getCumpleDia(){
	return cumpleDia;
}

string Persona::getCumpleMes(){
	return cumpleMes;
}

string Persona::getCumpleAnio(){
	return cumpleAnio;
}

string Persona::getCumpleanios(){
	return cumpleanios;
}

string Persona::getAniverDia(){
	return aniverDia;
}

string Persona::getAniverMes(){
	return aniverMes;
}

string Persona::getAniverAnio(){
	return aniverAnio;
}

string Persona::getAniversario(){
	return aniversario;
}

string Persona::getCelular(){
	return celular;
}

string Persona::getCorreo(){
	return correo;
}

string Persona::getNota(){
	return nota;
}

string Persona::getDireccion(){
	return direccion;
}

bool Persona::validacionCedula(string cedulaStr){
	int cedula=atoi(cedulaStr.c_str());
	bool validar=false;
	int res=0,cont=0,i=0,suma=0,dig=0;
    int* vector;
    vector=(int*)malloc(10*sizeof(int));
    for(i=0; i<=9; i++){
        *(vector+i)=cedula%10;
        cedula=cedula/10;
        cont++;
    }
    if (((*(vector+9)*2)>9)||((*(vector+7)*2)>9)||((*(vector+5)*2)>9)||((*(vector+3)*2)>9)||((*(vector+1)*2)>9)){
        if ((*(vector+9)*2)>9){
        *(vector+9)=(*(vector+9)*2)-9;
    }
    else{
        *(vector+9)=*(vector+9)*2;
    }
    if ((*(vector+7)*2)>9){
        *(vector+7)=(*(vector+7)*2)-9;
    }
    else{
        *(vector+7)=*(vector+7)*2;
    }
    if ((*(vector+5)*2)>9){
        *(vector+5)=(*(vector+5)*2)-9;
    }
    else{
        *(vector+5)=*(vector+5)*2;
    }
    if ((*(vector+3)*2)>9){
        *(vector+3)=(*(vector+3)*2)-9;
    }
    else{
        *(vector+3)=*(vector+3)*2;
    }
    if ((*(vector+1)*2)>9){
        *(vector+1)=(*(vector+1)*2)-9;
    }
    else{
        *(vector+1)=*(vector+1)*2;
    }
    suma=(*(vector+9))+(*(vector+7))+(*(vector+5))+(*(vector+3))+(*(vector+1))+*(vector+8)+*(vector+6)+*(vector+4)+*(vector+2);
        res= suma%10;
        if(res!=0){
            dig=10-res;
            if (*(vector+0)==dig){
                printf ("\tEl numero de cedula es correcto...\n");
                validar=true;
            }
            else{
                printf ("\tEl numero de cedula es incorrecto...\n");
                validar=false;
            }
        }
        else{
        dig=res;
        printf ("\ndig: %i",dig);suma=(*(vector+9)*2)+(*(vector+7)*2)+(*(vector+5)*2)+(*(vector+3)*2)+(*(vector+1)*2)+*(vector+8)+*(vector+6)+*(vector+4)+*(vector+2);
        res= suma%10;
        if(res!=0){
            dig=10-res;
            if (*(vector+0)==dig){
                printf ("\tEl numero de cedula es correcto...\n");
                validar=true;
            }
            else{
                printf ("\tEl numero de cedula es incorrecto...\n");
                validar=false;
            }
        }
        else{
        dig=res;
        if (*(vector+0)==dig){
                printf ("\tEl numero de cedula es correcto...\n");
                validar=true;
            }
            else{
                printf ("\tEl numero de cedula es incorrecto...\n");
                validar=false;
            }
        }
        }
    }
    else{
        suma=(*(vector+9)*2)+(*(vector+7)*2)+(*(vector+5)*2)+(*(vector+3)*2)+(*(vector+1)*2)+*(vector+8)+*(vector+6)+*(vector+4)+*(vector+2);
        res= suma%10;
        if(res!=0){
            dig=10-res;
            if (*(vector+0)==dig){
                printf ("\tEl numero de cedula es correcto...\n");
                validar=true;
            }
            else{
                printf ("\tEl numero de cedula es incorrecto...\n");
                validar=false;
            }
        }
        else{
        dig=res;
        if (*(vector+0)==dig){
                printf ("\tEl numero de cedula es correcto...\n");
                validar=true;
            }
            else{
                printf ("\tEl numero de cedula es incorrecto...\n");
                validar=false;
            }
        }
    }
	return validar;
}

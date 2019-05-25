//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//27/05/2019

class Nodo
{		
	public:
		int dato;
		Nodo *sig;
		Nodo ();
		void insertarInicio(Nodo *&,int);
		
		int getDato()
		{
			return dato;
		}
		Nodo *getSig()
		{
			return sig;
		}
		
		void setDato(int dat)
		{
			dato=dat;
		}
		void setSig(Nodo *s)
		{
			sig = s;
		}
		
};

void Nodo::insertarInicio(Nodo *&lista,int n)
{
	Nodo *nuevo = new Nodo();
	nuevo->dato=n;
	nuevo->sig=lista;
	lista=nuevo;
}

Nodo::Nodo()
{
	
}

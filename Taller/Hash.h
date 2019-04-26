#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Hash{
	private:
		static const int tablaTam=10;
		
		struct placa{
			string serial;
			string provincia;
			placa* next;
		};
		
		placa* HashTable[tablaTam];
		
	public:
		Hash(){
			for(int i=0;i<tablaTam;i++){
				HashTable[i] = new placa;
				HashTable[i] -> serial = "vacia";
				HashTable[i] -> provincia = "vacia";
				HashTable[i] -> next = NULL;
			}
		}
		int hash(string clave);
		void insertarPlaca(string serial);
		int numerarAtributosPlaca(int indice);
		void imprimirTabla();
		void buscarPorIndice(int indice);
		void eliminarPlaca(string serial);
		
};

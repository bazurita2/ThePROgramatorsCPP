#ifndef CUBO_H
#define CUBO_H

class Cubo
{
	public:
		void visualizar(int n);
		void inicializar(int n);
		void proceder(int n);
		void setMatriz(int** valor);
		int** getMatriz();
	protected:
		int** matriz;
		
};

#endif

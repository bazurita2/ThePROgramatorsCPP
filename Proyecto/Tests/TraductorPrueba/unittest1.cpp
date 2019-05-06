#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BusquedaBinaria/Busqueda.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TraductorPrueba
{		
	TEST_CLASS(UnitTest1)
	{

	private:

	public:
		
		TEST_METHOD(TestMethod1)
		{
			int num1 = 9;
			Busqueda b= Busqueda("televition");
			b.leerArchivo();
			Assert::AreEqual(num1, b.numero);
		}

	};
}
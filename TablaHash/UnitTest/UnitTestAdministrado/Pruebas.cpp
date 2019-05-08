//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//INTEGRANTES: VICTOR JIMENEZ, BRYAN ZURITA, SEBASTIAN LANDAZURI
//FECHA 08/05/2019

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CorreoTest/Validacion.h"
#include <string.h>
#pragma comment(lib,"d3d11.lib")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAdministrado
{		

	TEST_CLASS(UnitTest1)
	{

	public:

		TEST_METHOD(Enter)
		{
			char test = 13;
			Validacion val = Validacion();
			Assert::AreEqual(true, val.validarPlaca(test));
		}
		TEST_METHOD(simbolo)
		{
			char test = '*';
			Validacion val = Validacion();
			Assert::AreEqual(true, val.validarPlaca(test));
		}
		TEST_METHOD(zeta)
		{
			char test = 'Z';
			Validacion val = Validacion();
			Assert::AreEqual(true, val.validarPlaca(test));
		}
		TEST_METHOD(num1)
		{
			char test = '1';
			Validacion val = Validacion();
			Assert::AreEqual(true, val.validarPlaca(test));
		}
		TEST_METHOD(num2)
		{
			char test = '2';
			Validacion val = Validacion();
			Assert::AreEqual(true, val.validarPlaca(test));
		}
		TEST_METHOD(character1)
		{
			char test = 'a';
			Validacion val = Validacion();
			Assert::AreEqual(true, val.validarPlaca(test));
		}
		TEST_METHOD(num4)
		{
			char test = '3';
			Validacion val = Validacion();
			Assert::AreEqual(true, val.validarPlaca(test));
		}
		/*TEST_METHOD(comparar1)
		{
			int test1 = 1;
			Validacion* val = new Validacion();
		
			Assert::AreEqual(test1, val->registro("jose", "perez"));
		}*/
	
	};
}
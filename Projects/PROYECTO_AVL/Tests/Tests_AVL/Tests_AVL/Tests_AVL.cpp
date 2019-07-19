//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//19/07/2019


#include "pch.h"
#include "CppUnitTest.h"
#include "../../../../PROYECTO_AVL/ArbolAVL.h";
#include "../../../../PROYECTO_AVL/Nodo.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsAVL
{
	TEST_CLASS(TestsAVL)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Nodo* a = NULL;
			int num1 = 0;
			ArbolAVL b = ArbolAVL();

			Assert::AreEqual(num1, b.altura(a));
		}
		TEST_METHOD(TestMethod2)
		{
			Nodo* a = NULL;
			int num1 = -2;
			ArbolAVL b = ArbolAVL();

			Assert::AreEqual(num1, b.altura(a));
		}
		TEST_METHOD(TestMethod3)
		{
			Nodo* a = NULL;
			int num1 = 0;
			ArbolAVL b = ArbolAVL();

			Assert::AreEqual(num1, b.Balancear(a));
		}
		TEST_METHOD(TestMethod4)
		{
			Nodo* a = NULL;
			int num1 = -2;
			ArbolAVL b = ArbolAVL();

			Assert::AreEqual(num1, b.Balancear(a));
		}
	};
}

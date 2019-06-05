//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//Fecha de creacion: 03/05/2019   Fecha de entrega: 04/05/2019
#include<bits/stdc++.h> 
#include<iostream>
#include<stack>
#include<string>
#include<string.h>
using namespace std; 



int evaluarPosfijo(string expresion);
int realizarOperacion(char operacion, int operando1, int operando2);
bool EsOperador(char C);
bool esNumero(char C);



bool esOperacion(char c) 
{ 
	return isdigit(c); 
} 

double evaluarPrefijo(string expresion) 
{ 
	stack<double> Stack; 

	for (int j = expresion.size() - 1; j >= 0; j--) { 

		if (esOperacion(expresion[j])) 
			Stack.push(expresion[j] - '0'); 
		
		else { 
 
			double o1 = Stack.top(); 
			Stack.pop(); 
			double o2 = Stack.top(); 
			Stack.pop(); 

			switch (expresion[j]) { 
			case '+': 
				Stack.push(o1 + o2); 
				break; 
			case '-': 
				Stack.push(o1 - o2); 
				break; 
			case '*': 
				Stack.push(o1 * o2); 
				break; 
			case '/': 
				Stack.push(o1 / o2); 
				break; 
			case '^': 
				Stack.push(pow(o1,o2)); 
				break; 
			case 's': 
				Stack.push(pow(o1,1/2)); 
				break; 		
			} 
		} 
	} 

	return Stack.top(); 
} 



int prec(char c) 
{ 
	if(c == '^') 
	return 3; 
	else if(c == '*' || c == '/') 
	return 2; 
	else if(c == '+' || c == '-') 
	return 1; 
	else if(c == 's') 
	return 4;
	else
	return -1; 
} 

int prioridad(char C) 
{ 
	if (C == '-' || C == '+') 
		return 1; 
	else if (C == '*' || C == '/') 
		return 2; 
	else if (C == '^') 
		return 3; 
	else if (C == 's') 
		return 4; 	
	return 0; 
} 

bool esOperador(char c) 
{ 
	return (!isalpha(c) && !isdigit(c)); 
}

string haciaPosfijo(string infijo) 
{ 
	infijo = '(' + infijo + ')'; 
	int l = infijo.size(); 
	stack<char> char_stack; 
	string salida; 

	for (int i = 0; i < l; i++) { 

		if (isalpha(infijo[i]) || isdigit(infijo[i])) 
			salida += infijo[i]; 

		else if (infijo[i] == '(') 
			char_stack.push('('); 

		else if (infijo[i] == ')') { 

			while (char_stack.top() != '(') { 
				salida += char_stack.top(); 
				char_stack.pop(); 
			} 

			char_stack.pop(); 
		} 

		else { 
			
			if (esOperador(char_stack.top())) { 
				while (prioridad(infijo[i]) 
				<= prioridad(char_stack.top())) { 
					salida += char_stack.top(); 
					char_stack.pop(); 
				} 

				char_stack.push(infijo[i]); 
			} 
		} 
	} 
	return salida; 
} 

string haciaPrefijo(string infijo) 
{ 
	int l = infijo.size(); 

	reverse(infijo.begin(), infijo.end()); 

	for (int i = 0; i < l; i++) { 

		if (infijo[i] == '(') { 
			infijo[i] = ')'; 
			i++; 
		} 
		else if (infijo[i] == ')') { 
			infijo[i] = '('; 
			i++; 
		} 
	} 

	string prefijo = haciaPosfijo(infijo); 

	reverse(prefijo.begin(), prefijo.end()); 

	return prefijo; 
}  

int main() 
{ 
	string expresion, aux;

				cout<<"Ingrese la expresion en infijo: ";
				cin>>expresion;
				aux = haciaPrefijo(expresion);
				cin.ignore();
				cout<<"Posfija: "<<endl<<haciaPosfijo(expresion)<<endl;
				aux = haciaPrefijo(expresion);
				cin.ignore();
				cout<<"Prefija: "<<endl<<aux<<endl;
				cout<<"Resultado: "<<evaluarPrefijo(aux)<<endl;

	return 0; 
} 

int evaluarPosfijo(string expresion)
{
	stack<int> S;

	for(int i = 0;i< expresion.length();i++) {

		if(expresion[i] == ' ' || expresion[i] == ',') continue; 

		else if(EsOperador(expresion[i])) {
			int operando2 = S.top(); S.pop();
			int operando1 = S.top(); S.pop();
			int resultado = realizarOperacion(expresion[i], operando1, operando2);
			S.push(resultado);
		}
		else if(esNumero(expresion[i])){ 
			int operando = 0; 
			while(i<expresion.length() && esNumero(expresion[i])) {
				operando = (operando*10) + (expresion[i] - '0'); 
				i++;
			}
			i--;
			S.push(operando);
		}
	}
	return S.top();
}

bool esNumero(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

bool EsOperador(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/'||C=='^'||C=='s')
		return true;

	return false;
}

int realizarOperacion(char operacion, int operando1, int operando2)
{
	if(operacion == '+') return operando1 +operando2;
	else if(operacion == '-') return operando1 - operando2;
	else if(operacion == '*') return operando1 * operando2;
	else if(operacion == '/') return operando1 / operando2;
	else if(operacion == '^') return pow(operando1,operando2);
	else if(operacion == 's') return pow(operando1,1/2);


	else cout<<"Error \n";
	return -1; 
}




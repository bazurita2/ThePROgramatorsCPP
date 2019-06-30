#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>

using namespace std;

class Dato
{
	private:
		string num;
	public:
		void setNum(string);
		string getNum();
};


void Dato::setNum(string num)
{
	this->num=num;
}

string Dato::getNum()
{
	return num;
}

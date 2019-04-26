#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class  Transporte{

private:
    int misionero;
    int canibal;
    bool bote=false;


public:
    Transporte();
    void moverBote();
    void regresarBote();

    int getMisionero();
    int getCanibal();
    void setMisionero(int);
    void setCanibal(int);


};
Transporte::Transporte(){

}

int Transporte::getMisionero(){
    return misionero;
}
int Transporte::getCanibal(){
    return canibal;
}

void Transporte::setCanibal(int _canibal){
    canibal=_canibal;
}

void Transporte::setMisionero(int _misionero){
    misionero=_misionero;
}

void Transporte::moverBote(){
    cout<<"Se esta moviendo el bote con "<<getCanibal()<<" canibales y "<<getMisionero()<<" misioneros"<<endl;
}

void Transporte::regresarBote(){
    cout<<"Se esta regresando el bote con "<<getCanibal()<<" canibales y "<<getMisionero()<<" misioneros"<<endl;
}

void aniadirLadoA(Transporte bote){
    ofstream agregarTxt;

    fflush(stdin);
    agregarTxt.open("Juego.txt",ios::app);
    agregarTxt<<"\n\tMisioneros: "<<bote.getMisionero()<<endl;
    agregarTxt<<"\n\tCanibales: "<<bote.getCanibal()<<endl;
        agregarTxt.close();
}

void moverLadoA(Transporte bote){
    ofstream agregarTxt;
    fflush(stdin);
    agregarTxt.open("Juego.txt",ios::app);
    agregarTxt<<"\n\tSe esta moviendo el bote con "<<bote.getCanibal()<<" canibales y "<<bote.getMisionero()<<" misioneros"<<endl;
        agregarTxt.close();

}

void moverLadoB(Transporte bote){
    ofstream agregarTxt;
    fflush(stdin);
    agregarTxt.open("Juego.txt",ios::app);
    agregarTxt<<"\n\t\t\t\t\tSe esta regresando el bote con "<<bote.getCanibal()<<" canibales y "<<bote.getMisionero()<<" misioneros"<<endl;
        agregarTxt.close();
}

void aniadirLadoB(Transporte bote){
    ofstream agregarTxt;

    fflush(stdin);
    agregarTxt.open("Juego.txt",ios::app);
    agregarTxt<<"\n\t\t\t\t\tMisioneros: "<<bote.getMisionero()<<endl;
    agregarTxt<<"\n\t\t\t\t\tCanibales: "<<bote.getCanibal()<<endl;
        agregarTxt.close();
}

int main()
{
    Transporte bote = Transporte();

    bote.setCanibal(3);
    bote.setMisionero(3);
    aniadirLadoA(bote);

    bote.setCanibal(1);
    bote.setMisionero(1);
    bote.moverBote();
    moverLadoA(bote);

    bote.setCanibal(1);
    bote.setMisionero(1);
    aniadirLadoB(bote);

    bote.setCanibal(0);
    bote.setMisionero(1);
    bote.regresarBote();
    moverLadoB(bote);

    bote.setMisionero(3);
    bote.setCanibal(2);
    aniadirLadoA(bote);

    bote.setCanibal(2);
    bote.setMisionero(0);
    bote.moverBote();
    moverLadoA(bote);

    bote.setCanibal(3);
    bote.setMisionero(0);
    aniadirLadoB(bote);

    bote.setCanibal(1);
    bote.setMisionero(0);
    bote.regresarBote();
    moverLadoB(bote);

    bote.setCanibal(1);
    bote.setMisionero(3);
    aniadirLadoA(bote);

    bote.setCanibal(0);
    bote.setMisionero(2);
    bote.moverBote();
    moverLadoA(bote);

    bote.setCanibal(2);
    bote.setMisionero(2);
    aniadirLadoB(bote);

    bote.setCanibal(1);
    bote.setMisionero(1);
    bote.regresarBote();
    moverLadoB(bote);

    bote.setCanibal(2);
    bote.setMisionero(2);
    aniadirLadoA(bote);

    bote.setCanibal(0);
    bote.setMisionero(2);
    bote.moverBote();
    moverLadoA(bote);

    bote.setCanibal(1);
    bote.setMisionero(3);
    aniadirLadoB(bote);

    bote.setCanibal(1);
    bote.setMisionero(0);
    bote.regresarBote();
    moverLadoB(bote);

    bote.setCanibal(3);
    bote.setMisionero(0);
    aniadirLadoA(bote);

    bote.setCanibal(2);
    bote.setMisionero(0);
    bote.moverBote();
    moverLadoA(bote);

    bote.setCanibal(2);
    bote.setMisionero(3);
    aniadirLadoB(bote);

    bote.setCanibal(1);
    bote.setMisionero(0);
    bote.regresarBote();
    moverLadoB(bote);

    bote.setCanibal(2);
    bote.setMisionero(0);
    aniadirLadoA(bote);

    bote.setCanibal(2);
    bote.setMisionero(0);
    bote.moverBote();
    moverLadoA(bote);

    bote.setCanibal(3);
    bote.setMisionero(3);
    aniadirLadoB(bote);




    return 0;
}





























#include <iostream>
using namespace std;

class Piloto {
private:
    int energiaPiloto;
    int escudoPiloto;
public:
    Piloto();
    Piloto(int, int);
    
    //getters
    int getEscudoPiloto();
    int getEnergiaPiloto();
    
    //setters
    void setEscudoPiloto(int ep);
    void setEnergiaPiloto(int escudop);
    
    //void imprimirStatus();
    void botiquin();
};

Piloto::Piloto(int ep, int escudop): energiaPiloto(ep), escudoPiloto(escudop) {}

//getters
int Piloto::getEscudoPiloto() {
    return escudoPiloto;
}

int Piloto::getEnergiaPiloto() {
    return energiaPiloto;
}

//setters
void Piloto::setEnergiaPiloto(int ep){
    energiaPiloto = ep;
}

void Piloto::setEscudoPiloto(int escudop){
    escudoPiloto = escudop;
}



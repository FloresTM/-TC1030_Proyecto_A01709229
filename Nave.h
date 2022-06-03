#include <iostream>
using namespace std;
#include "Armas.h"


class Nave
{
private:
    string nombreNave;
    int energiaNave;
    int escudoNave;
    Piloto piloto;
public:
    Nave();
    Nave (string nombreNave, int energiaNave, int escudoNave, int energiaPiloto, int escudop);
  Piloto getPiloto();
  void imprimirInfo();
  void conditional(); 
  void escogerArma();
  void atacar (Nave&);
  
  //getters
  string getNombreNave();
  int getEnergiaNave();
  int getEscudoNave();
  
  //setters
  void setNombreNave(string nombren);
  void setEnergiaNave(int energian);
  void setEscudoNave(int escudon);
};

//constructor
Nave::Nave (string nombren, int energian, int escudon, int ep, int escudop):
nombreNave (nombren),
energiaNave (energian),
escudoNave (escudon),
piloto (ep, escudop)
{
}

//getters
string Nave::getNombreNave(){
    return nombreNave;
}

int Nave::getEnergiaNave(){
    return energiaNave;
}

int Nave::getEscudoNave(){
    return escudoNave;
}

Piloto
Nave::getPiloto ()
{
  return piloto;
}

//setters
void Nave::setNombreNave(string nombren){
    nombreNave = nombren;
}

void Nave::setEnergiaNave(int energian){
    energiaNave = energian;
}

void Nave::setEscudoNave(int escudon){
    escudoNave = escudon;
}

void Nave::imprimirInfo (){
  cout << "\nEl nombre de la nave es: " << nombreNave << endl;
  cout << "El nivel de energia de la nave es de: " << energiaNave << endl;
  cout << "El escudo de la nave es de: " << escudoNave << endl;
  cout << "El escudo del piloto es: " << piloto.getEscudoPiloto () << endl;
  cout << "La energia del piloto es: " << piloto.getEnergiaPiloto () << endl;
}

/*
void Nave::escogerArma(){
    
}
*/

/*void Nave::conditional ()
{
    if(escudoNave >= 0)
    {
        escudoNave = escudoNave - 50;
        cout << "Escudo nuevo de la nave: " << escudoNave << endl;
    }
    
    else{
        cout << "prueba";
    }
}
*/
 void Nave::atacar(Nave& naveAtacada) {

    if(escudoNave > 0)
    {
        naveAtacada.setEscudoNave( getEscudoNave() - 2 );
    }
    
    else if(escudoNave <= 0) 
    {
        cout << "Esta nave ya no tiene escudo" << endl;
        naveAtacada.setEnergiaNave( getEnergiaNave() - 2 );
        
        if(piloto.getEscudoPiloto() > 0)
        {
            naveAtacada.piloto.setEscudoPiloto( piloto.getEscudoPiloto () - 2 );
        }
        
        else if(piloto.getEscudoPiloto() <= 0){
            naveAtacada.piloto.setEnergiaPiloto( piloto.getEnergiaPiloto () - 2 );
        }
    }
}
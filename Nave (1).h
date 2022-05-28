#include <iostream>
using namespace std;

class Nave {
    
private:
    string colorNave;
    int energiaNave;
    int escudoNave;
    Piloto piloto; 
    //Arma arma; 
    
public:
    Nave();
    Nave(string colorNave, int energiaNave, int escudoNave, int energiaPiloto, int escudop); //c
    Piloto getPiloto();
    //Arma getArma();
    void imprimirInfo();
    void conditional();
    void escogerArma();
    void atacar (Nave&);
    
    //getters
    string getColorNave();
    int getEnergiaNave();
    int getEscudoNave();
  
    //setters
    void setColorNave(string colorn);
    void setEnergiaNave(int energian);
    void setEscudoNave(int escudon); 
};

//constructor
Nave::Nave (string colorn, int energian, int escudon, int ep, int escudop):
colorNave (colorn),
energiaNave (energian),
escudoNave (escudon),
piloto (ep, escudop)
{
}

//getters
string Nave::getColorNave(){
    return colorNave;
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
void Nave::setColorNave(string colorn){
    colorNave = colorn;
}

void Nave::setEnergiaNave(int energian){
    energiaNave = energian;
}

void Nave::setEscudoNave(int escudon){
    escudoNave = escudon;
}

void
Nave::imprimirInfo ()
{
  cout << "\nEl nombre de la nave es: " << colorNave << endl;
  cout << "El nivel de energia de la nave es de: " << energiaNave << endl;
  cout << "El escudo de la nave es de: " << escudoNave << endl;
  cout << "El escudo del piloto es: " << piloto.getEscudoPiloto () << endl;
  cout << "La energia del piloto es: " << piloto.getEnergiaPiloto () << endl;
}

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



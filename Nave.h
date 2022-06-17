/*
 *
 * Proyecto Juego Naves clase Nave
 * Sebastian Armando Flores Lemus
 * A01709229
 * 16/06/2022
 * version : 1
 * Esta clase defina objeto de tipo Nave que contiene el proceso de addArma
 * y todo el proceso para atacar, que sera usado en nuestro main y es de lo 
 * mas importante en el proyecto Juego de naves, tambien llama el objeto Piloto 
 * creado en el documento 'Piloto', y se anade al constructor de Nave.
 */

#include <iostream>

#include "Arma.h"

using namespace std;

// Declaracion de clase Nave
class Nave{
    
    // Declaro las variables privadas de instancia
    private:
        string colorNave;
        double energiaNave;
        double escudoNave;
        double ataque;
        Piloto piloto; // Objeto Piloto para accesar a su informacion
        Arma *arma_; // apuntador usado en addArma
        
    // Declaro constructor por default y metodos públicos.    
    public:
        Nave (); //constructor por defualt
        Nave (string, double, double, double, int);
        void atacar (Nave& naveAtacada, int);
        void addArma(int num);
        double getAtaque() {
            return ataque;
        }
        string getColorNave () {
            return colorNave;
        }
        double getEnergiaNave () {
            return energiaNave;
        }
        double getEscudoNave () {
            return escudoNave;
        }
        Piloto getPiloto () {
            return piloto;
        }
        void setEnergiaNave (double _energiaNave);
        void setEscudoNave (double _escudoNave);
};

/* Constructor de objeto Nave
 *
 * @param
 * @return
 */
Nave::Nave (string _colorNave, double _energiaNave, double _escudoNave, double _ataque, int _energiaPiloto):piloto(_energiaPiloto)
{
    colorNave = _colorNave;
    energiaNave = _energiaNave;
    escudoNave = _escudoNave;
    ataque = _ataque;
}

/* Setter setEnergiaNave usado en metodo atacar
 *
 * @param
 * @return
 */
void Nave::setEnergiaNave (double _energiaNave)
{
    energiaNave = _energiaNave;
}

/* Setter setEscudoNave usado en metodo atacar
 *
 * @param
 * @return
 */
void Nave::setEscudoNave (double _escudoNave)
{
    escudoNave = _escudoNave;
}

/* addArma genera o crea objetos heredados de arma a las naves.
 *
 * Hay dos diferentes opciones que seran elegidas por el jugador.
 *
 * Dependiendo de su eleccion, se hara diferente dano por arma.
 *
 * @param
 * @return
 */
void Nave::addArma(int num){
    
    // Las condicionales son para cubrir la eleccion del usuario
    if (num == 2){
        
        // new crea el objeto en tiempo de ejecución para usar polimorfismo
        arma_ = new Missil(01, 3);
        cout << "Se agrego un missil a la nave" << endl;
        Arma *armas[1];
        armas[0] = new Missil(01,2);
        
        // metodo donde se implemento polimorfismo
        armas[0]->mostrarArma();
    }
    else {
        arma_ = new Ametralladora(02, 4);
        cout << "Se agrego una ametralladora a la nave\n" << endl;
        Arma *armas[1];
        armas[0] = new Ametralladora(02,4);
        armas[0]->mostrarArma();
    }
}

/* atacar realiza toda la operacion necesario para que las naves ataquen.
 *
 * Usamos & y la naveAtacada deseada para poder infligir dano a la nave correcta.
 * 
 * @param
 * @return
 */
void Nave::atacar (Nave& naveAtacada, int num){
    
    if (num == 2) {
        if (escudoNave > 0 ) {
            if (escudoNave-naveAtacada.getAtaque()<0)
                escudoNave = 0;
            else
                escudoNave = escudoNave - (naveAtacada.getAtaque() * 0.2);
                piloto.setEnergiaPiloto(piloto.getEnergiaPiloto() - (naveAtacada.getAtaque() * 0.2));
        }
    
        if (escudoNave == 0 && energiaNave>0) {
            if (energiaNave-naveAtacada.getAtaque()<0)
                energiaNave = 0;
            else
                energiaNave = energiaNave - (naveAtacada.getAtaque() * 0.2);
                piloto.setEnergiaPiloto(piloto.getEnergiaPiloto() - (naveAtacada.getAtaque() * 0.2));
    
        }
        if (escudoNave == 0 && energiaNave==0) {
            if (piloto.getEnergiaPiloto()-naveAtacada.getAtaque()<0)
                piloto.setEnergiaPiloto(0);
            else
                piloto.setEnergiaPiloto(piloto.getEnergiaPiloto() - naveAtacada.getAtaque());
        }
    }
    
    else{
        
        if (escudoNave > 0 ) {
            if (escudoNave-naveAtacada.getAtaque()<0)
                escudoNave = 0;
            else
                escudoNave = escudoNave - (naveAtacada.getAtaque() * 0.3);
                
        }
    
        if (escudoNave == 0 && energiaNave>0) {
            if (energiaNave-naveAtacada.getAtaque()<0)
                energiaNave = 0;
            else {
                energiaNave = energiaNave - (naveAtacada.getAtaque() * 0.3);
                piloto.setEnergiaPiloto(piloto.getEnergiaPiloto() - (naveAtacada.getAtaque() * 0.3));
            }
        }
        if (escudoNave == 0 && energiaNave==0) {
            if (piloto.getEnergiaPiloto()-naveAtacada.getAtaque()<0)
                piloto.setEnergiaPiloto(0);
            else
                piloto.setEnergiaPiloto(piloto.getEnergiaPiloto() - naveAtacada.getAtaque());
        }
    }    
}

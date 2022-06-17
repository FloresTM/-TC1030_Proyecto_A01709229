/*
 *
 * Proyecto Juego Naves clase Piloto
 * Sebastian Armando Flores Lemus
 * A01709229
 * 16/06/2022
 * version : 1
 * Esta clase define objeto tipo Piloto que contiene la energia(vida) del Piloto
 * ademas de los getters y setters para que se pueda utilizar en el metodo
 * atacar para accesar la vida, poder modificarla, e imprimirla en el main.cpp,
 * ya que es esencial en nuestro proyecto.
 */
 
#include <iostream>

using namespace std;

//Declaracion de clase Piloto
class Piloto {
    
    //Declaro las variables privadas de instancia
    private:
    
    double energiaPiloto;
    
    //Declaro constructor por default y metodos públicos.
    
    public:
        Piloto();  //constructor por defualt
        Piloto(double);

    double getEnergiaPiloto() {
        return energiaPiloto;
    }
    void setEnergiaPiloto(double _energiaPiloto);
};

/* Se crea constructor con tipo y nombre de los astributos
 *
 * @param
 * @return
 */
Piloto::Piloto(double _energiaPiloto){
    energiaPiloto = _energiaPiloto;
}

/* Se usa setEnergiaPiloto para modificar esta infomracion en el metodo atacar
 * en el archivo 'Nave.h'
 *
 * @param
 * @return
 */
void Piloto::setEnergiaPiloto(double _energiaPiloto){
    energiaPiloto = _energiaPiloto;
}

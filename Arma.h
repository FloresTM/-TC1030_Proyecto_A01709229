/*
 *
 * Proyecto Juego Naves clase Arma
 * Sebastian Armando Flores Lemus
 * A01709229
 * 16/06/2022
 * version : 1
 * Esta clase defina objeto de tipo Arma que contiene las clases heredadas
 * Missil, Ametralladora.
 */
 
#include <iostream>

using namespace std;

//Declaracion de clase Arma que es abstracta
class Arma {
    
    //Declaro variables de instancia
    private:
        int id;
        
    //Declaro los métodos que va a tener el objeto    
    public:
        Arma(){} //constructor por defualt
        Arma(int);
        virtual void mostrarArma() = 0; //método abstracto será sobreescrito
};

// Declaro objeto Missil que hereda de Arma
class Missil:public Arma {
    
    //Variables de instancia del objeto
    private:
        int splashDamage;
        
    //Metodos del objeto
    public:
        Missil(){} //constructor por defualt
        Missil(int, int);
        void mostrarArma();
};

// Declaro objeto Ametralladora que hereda de Arma
class Ametralladora:public Arma {
    
    //Variables de instancia del objeto
    private:
        int directDamage;
        
    //Metodos del objeto
    public:
        Ametralladora(){} //constructor por defualt
        Ametralladora(int, int);
        void mostrarArma();
};

/* Constructor de objeto padre Arma 
 *
 * @param
 * @return
 */
Arma::Arma(int _id){
    id = _id;
}

/* Contructor objeto Missil que hereda de Arma
 *
 * @param
 * @return
 */
Missil::Missil(int _id, int _splashDamage):Arma(_id){
    splashDamage = _splashDamage;
}

/* Constructor objeto Ametralladora que hereda de Arma
 *
 * @param
 * @return
 */
Ametralladora::Ametralladora(int _id, int _directDamage):Arma(_id){
    directDamage = _directDamage;
}

/* mostrarArma muestra la informacion(id, dano) de cada Arma.
 *
 * Permite imprimir la informacion en el main para que el jugador eliga su Arma.
 *
 * Tambien, imprime la informacion en addArma para confirmar que se haya 
 * agregado de manera correcta.
 *
 * @param
 * @return
 */
void Arma::mostrarArma(){
    cout << "Id del arma: " << id << endl;
}

/* mostrarArma muestra la informacion(id, dano) de cada Arma.
 *
 * Permite imprimir la informacion en el main para que el jugador eliga su Arma.
 *
 * Tambien, imprime la informacion en addArma para confirmar que se haya 
 * agregado de manera correcta, usamos mismo metodo para el hijo.
 *
 * @param
 * @return
 */
void Missil::mostrarArma(){
    Arma::mostrarArma();
    cout << "El splashDamage del missil es: " << splashDamage << "\n" << endl;
}

/* mostrarArma muestra la informacion(id, dano) de cada Arma.
 *
 * Permite imprimir la informacion en el main para que el jugador eliga su Arma.
 *
 * Tambien, imprime la informacion en addArma para confirmar que se haya 
 * agregado de manera correcta, usamos mismo metodo para el hijo.
 *
 * @param
 * @return
 */
void Ametralladora::mostrarArma(){
    Arma::mostrarArma();
    cout << "El dano directo de la Ametralladora es: " << directDamage << "\n" << endl;
}
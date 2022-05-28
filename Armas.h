/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Arma {
private:
    int id;
public:
    Arma(int); //contructor
    void mostrarArma();
    void disparar();
    //getters
    int getArmaId();
    int getDamage();
};

class Missil:public Arma {
private:
    int splashDamage;
public:
    Missil(int, int); // contructor Alumno
    void mostrarMissil();
};

class Ametralladora:public Arma {
private:
    int directDamage;
public:
    Ametralladora(int, int); // contructor Alumno
    void mostrarAmetralladora();
};

// constructor padre
Arma::Arma(int _id){
    id = _id;
}

// contructor clase hijo
Missil::Missil(int _id, int _splashDamage):Arma(_id){
    splashDamage = _splashDamage;
}

// contructor clase hijo
Ametralladora::Ametralladora(int _id, int _directDamage):Arma(_id){
    directDamage = _directDamage;
}

//metodo padre
void Arma::mostrarArma(){
    cout << "Id: " << id << endl;
}

//metodo hijo
void Missil::mostrarMissil(){
    mostrarArma();
    cout << "Su splashDamage es: " << splashDamage << endl;
}

void Ametralladora::mostrarAmetralladora(){
    mostrarArma();
    cout << "Su dano directo es: " << directDamage << endl;
}


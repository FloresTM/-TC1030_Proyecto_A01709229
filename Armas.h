#include <iostream>

using namespace std;

class Arma {
private:
    int id;
public:
    Arma(){}   //constructor defualt
    Arma(int); //contructor
    virtual void mostrar()=0; 
    //void disparar();
    //getters
    int getArmaId();
    int getDamage();
    //setters
};

class Missil:public Arma {
private:
    int splashDamage;
public:
    Missil(int, int); // contructor Alumno
    void mostrar();
};

class Ametralladora:public Arma {
private:
    int directDamage;
public:
    Ametralladora(int, int); // contructor Alumno
    void mostrar();
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
void Arma::mostrar(){
    cout << "Id: " << id << endl;
}

//metodo hijo
void Missil::mostrar(){
    Arma::mostrar();
    cout << "El splashDamage del missil es: " << splashDamage << endl;
}

void Ametralladora::mostrar(){
    Arma::mostrar();
    cout << "El dano directo de la Ametralladora es: " << directDamage << endl;
}

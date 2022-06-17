/*
 *
 * Proyecto Juego Naves
 * Sebastian Armando Flores Lemus
 * A01709229
 * 16/06/2022
 * version : 1
 * Este es un proyecto de juego de Naves. Es un programa que permite a tres 
 * jugadores jugar con tres naves diferentes cada una contiene un Piloto
 * y una arma elegida por el jugador la cual sera usada en la partida.
 * 
 */

#include <iostream>

#include "Piloto.h"

#include "Nave.h"

using namespace std;

int main()
{
    int numArma[3]; // arreglo para elecciones de arma de jugadores
    
    int i;
    int inputUsuarioAtaque, inputUsuarioDefensa, inputUsuario, inputUsuarioArma;
    string colorNave0, colorNave1, colorNave2;
    
    cout << "Bienvenido al juego de Naves"<< endl;
    cout << "Decide la informacion de las naves: \n" << endl;
       
    cout << "Introduzca color para la nave 0: " << endl;
    cin >> colorNave0;
    cout << "Introduzca color para la nave 1: " << endl;
    cin >> colorNave1;
    cout << "Introduzca color para la nave 2: " << endl;
    cin >> colorNave2;
    
    cout << "\nInformacion de las naves: \n" << endl;
    
    // arreglo de apuntadores para nuestras armas
    Arma *_armas[2];
    
    // new crea el objeto en tiempo de ejecución para usar polimorfismo
    _armas[0] = new Missil(01,2);
    
    // metodo donde se implemento polimorfismo
    _armas[0]->mostrarArma();
    
    _armas[1] = new Ametralladora(02,4);
    
    _armas[1]->mostrarArma();
    
    cout << "Escoge 2 para missil o 4 para Ametralladora: "<< endl;
    cout << "escoge para nave 0: ";
    cin >> numArma[0];
    if(numArma[0] != 2 && numArma[0] != 4){
        
        // verificacion de que la eleccion sea correcta
        while(true){
            cout << "Escoga una arma valida: " << endl;
            cin >> numArma[0];
            break;
        }    
    }
    
    cout << "escoge para nave 1: ";
    cin >> numArma[1];
    if(numArma[1] != 2 && numArma[1] != 4){
        
        // verificacion de que la eleccion sea correcta
        while(true){
            cout << "Escoga una arma valida: " << endl;
            cin >> numArma[1];
            break;
        }    
    }
    
    cout << "escoge para nave 2: ";
    cin >> numArma[2];
    if(numArma[2] != 2 && numArma[2] != 4){
        
        // verificacion de que la eleccion sea correcta
        while(true){
            cout << "Escoga una arma valida: " << endl;
            cin >> numArma[2];
            break;
        }    
    }
    
    // se definen los datos de las naves
    Nave nave0(colorNave0, 10, 5, numArma[0], 8);
    Nave nave1(colorNave1, 10, 5, numArma[1], 8);
    Nave nave2(colorNave2, 10, 5, numArma[2], 8);

    // arreglo para imprimir las naves    
    Nave naves[] = {
                       nave0,
                       nave1,
                       nave2
    };
    
    // anadimos tipo de arma deseado al objeto nave
    nave0.addArma(numArma[0]);
    
    // anadimos tipo de arma deseado al objeto nave
    nave1.addArma(numArma[1]); 
    
    // anadimos tipo de arma deseado al objeto nave
    nave2.addArma(numArma[2]); 
    
    // se crea while loop para que el menu siga corriendo
    i = 0;

    while (i<100){                   
    
        cout << "\nMenu juego Naves:" << endl;
        cout << "Eliga una de las siguientes opciones: " << endl;
        cout << "1. Mostrar Indicaciones del juego" << endl;
        cout << "2. Atacar" << endl;
        cout << "3. Mostrar reporte de todas las naves" << endl;
        cout << "4. Salir del juego" << endl;

        // usuario elige lo que quire hacer en el menu
        cin >> inputUsuario;
    
        if(inputUsuario == 1){
            cout << "\nIndicaciones del juego:" << endl;
            cout << "1. Una nave espacial tiene un color, un nivel de energía inicial , un escudo, un piloto con energia y una arma que sera elegida entre dos opciones. " << endl;
            cout << "2. Cada que una nave ataque a otra, se restarán puntos a la nave, a su escudo y al piloto con las siguientes reglas" << endl;
            cout << "a. Si la nave tiene su escudo disponible, un ataque le restará cierta cantidad de puntos a su escudo. El piloto no recibirá daño alguno si se usa la ametralladora como arma, en caso de que se use el missil el piloto si recibira dano." << endl;
            cout << "b. Si la nave ya no tiene escudo, un ataque le restará una cantidad de puntos a la nave y el piloto también saldrá dañado." << endl;
            cout << "c. Hay dos tipos de arma, el Missil hace dano a la nave y su explosion le hara dano a la energia del piloto, la ametralladora solo puede danar a un objeto pero hace mayor dano."<<endl;
            cout << "d. Cuando el piloto no tenga vida esa nave saldra del juego" << endl;
        }
        
        else if(inputUsuario == 2){
            for (int i = 0; i<3; i++){
                
                // buscamos cuando un piloto no tenga vida para indicarlo
                if (naves[i].getPiloto().getEnergiaPiloto() == 0){
                    cout << "\nEl piloto de la nave " << i << " ya no tiene vida" << endl;
                }
            }
                
                // se decide que nave va atacar
                cout << "\nElige a que nave le toca atacar: " << endl;
                cin >> inputUsuarioAtaque;
        
                // se decide que nave va a defender
                cout << "Elige que nave sera atacada: " << endl;
                cin >> inputUsuarioDefensa;
            
                // indica que nave esta defendiendo y cual esta atacando
                naves[inputUsuarioDefensa].atacar(naves[inputUsuarioAtaque], numArma[inputUsuarioAtaque]);
         
                // ciclamos la informacion de cada nave y la imprimimos
                for(int i = 0; i < 3; i++){
                    cout << "\nNave: " << i << endl;
                    cout << "Color de la nave: " << naves[i].getColorNave() << endl;
                    cout << "Vida de la nave: " << naves[i].getEnergiaNave() << endl;
                    cout << "Escudo de la nave: " << naves[i].getEscudoNave() << endl;
                    cout<<"Dano de ataque de la nave: "<<naves[i].getAtaque()<<endl;
                    cout << "Vida del Piloto: " << naves[i].getPiloto().getEnergiaPiloto() << endl;
                }
        }
        
        else if(inputUsuario == 3){
            cout << "\nInformacion de las Naves:" << endl;
           
            // ciclamos la informacion de cada nave y la imprimimos
            for(int i = 0; i < 3; i++){
                cout << "\nNave: " << i << endl;
                cout << "Color de la nave: " << naves[i].getColorNave() << endl;
                cout << "Vida de la nave: " << naves[i].getEnergiaNave() << endl;
                cout << "Escudo de la nave: " << naves[i].getEscudoNave() << endl;
                cout<<"Dano de ataque de la nave: "<<naves[i].getAtaque()<<endl;
                cout << "Vida del Piloto: " << naves[i].getPiloto().getEnergiaPiloto() << endl;
            }

        }
        
        // salimos del juego
        else if(inputUsuario == 4){
            cout << "\nHaz decidido salir del juego" << endl;
            exit;
            return 0;
        }
        
        else{
            cout << "Introduzca una opcion del menu que sea valida" << endl;
        }
        
        i++;
    }
}
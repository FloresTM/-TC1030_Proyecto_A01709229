#include <iostream>
#include "Piloto.h"
#include "Nave.h"

using namespace std;

int main()
{
    int inputUsuarioAtaque, inputUsuarioDefensa, inputUsuario;
    int contador = 0;
    string colorNave1, colorNave2, colorNave3, colorNave4;
    
    //nombre, vida nave, escudo nave, vida piloto, escudo piloto
       
       /*
        cout << "Introduzca color para la nave 1: " << endl;
        cin >> colorNave1;
        cout << "Introduzca color para la nave 2: " << endl;
        cin >> colorNave2;
        cout << "Introduzca color para la nave 3: " << endl;
        cin >> colorNave3;
        cout << "Introduzca color para la nave 4: " << endl;
        cin >> colorNave4;
*/
       
       Nave nave1(colorNave1, 10, 0, 6, 3);
       Nave nave2(colorNave2, 10, 0, 6, 0);
       Nave nave3(colorNave3, 10, 0, 6, 0);
       Nave nave4(colorNave4, 10, -1, 2, 0);
        
       Nave naves[] = {
                       nave1,
                       nave2,
                       nave3,
                       nave4};
                       
    
    cout << "Menu juego Naves:" << endl;
    cout << "Eliga una de las siguientes opciones: " << endl;
    cout << "1. Mostrar Indicaciones del juego" << endl;
    cout << "2. Atacar" << endl;
    cout << "3. Mostrar reporte de todas las naves" << endl;
    cout << "4. Salir del juego" << endl;
    cout << "5. Probar Armas (herencia y polimorfismo)" << endl;

    cin >> inputUsuario;
    

    if(inputUsuario == 1){
        cout << "\nIndicaciones del juego:" << endl;
        cout << "1. Una nave espacial tiene un nombre, un nivel de energía inicial , un escudo, y un piloto. " << endl;
        cout << "2. Cada que una nave ataque a otra, se restarán puntos a la nave, a su escudo y al piloto con las siguientes reglas" << endl;
        cout << "a. Si la nave tiene su escudo disponible, un ataque le restará cierta cantidad de puntos a su escudo y cierta cantidad de puntos a la nave. El piloto no recibirá daño alguno." << endl;
        cout << "b. Si la nave ya no tiene escudo, un ataque le restará una cantidad mayor de puntos a la nave y el piloto también saldrá dañado." << endl;
        cout << "c. Si el piloto tiene un nivel de energía crítico, podrá utilizar su botiquín médico una sola vez, lo cual le aumentará su nivel de energía (se deberá mostrar en pantalla cuando esto ocurra)." << endl;
        cout << "d. Si la nave tiene energía pero su piloto ya no, se considera destruida." << endl;
    }
    else if(inputUsuario == 2){
        while(contador <= 4){
        cout << "\nElige a que nave le toca atacar: " << endl;
        cin >> inputUsuarioAtaque;
    
        cout << "Elige que nave sera atacada: " << endl;
        cin >> inputUsuarioDefensa;
   
        naves[inputUsuarioAtaque].atacar(naves[inputUsuarioDefensa]);
     
        for (int i = 0; i<5; i++){
            if (naves[i].getPiloto().getEnergiaPiloto() <= 0){
                    cout << "el piloto de la nave " 
                    // naves[i]
                    << "ya no tiene vida" << endl;
                    
                    contador = contador + 1;
            }
        }
        
        for(int i = 0; i < 5; i++){
            cout << "\nNave: " << i << endl;
            cout << "Color de la nave: " << naves[i].getNombreNave() << endl;
            cout << "Vida de la nave: " << naves[i].getEnergiaNave() << endl;
            cout << "Escudo de la nave: " << naves[i].getEscudoNave() << endl;
            cout << "Vida del Piloto: " << naves[i].getPiloto().getEnergiaPiloto() << endl;
            cout << "Escudo del Piloto: " << naves[i].getPiloto().getEscudoPiloto() << endl;
            
        }
        }
    }
    
    else if(inputUsuario == 3){
        cout << "\nInformacion de las Naves:" << endl;
       
        for(int i = 0; i < 5; i++){
            cout << "\nNave: " << i << endl;
            cout << "Color de la nave: " << naves[i].getNombreNave() << endl;
            cout << "Vida de la nave: " << naves[i].getEnergiaNave() << endl;
            cout << "Escudo de la nave: " << naves[i].getEscudoNave() << endl;
            cout << "Vida del Piloto: " << naves[i].getPiloto().getEnergiaPiloto() << endl;
            cout << "Escudo del Piloto: " << naves[i].getPiloto().getEscudoPiloto() << endl;
        }
    }
    
    else if(inputUsuario == 4){
        cout << "\nHaz decidido salir del juego" << endl;
        exit;
    }
    
    // polimorfismo
    else if(inputUsuario == 5){
        
        Arma *armas[2];
        armas[1] = new Missil(16,70);
        armas[2] = new Ametralladora(15,85);
        armas[1]->mostrar();
        armas[2]->mostrar();
    }
         
    else{
        cout << "Introduzca una opcion del menu que sea valida" << endl;
    }       
    
    return 0;
}


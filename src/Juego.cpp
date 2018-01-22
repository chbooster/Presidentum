 /*
 * Copyright 2018, Carlos Aniorte Llanes <carlos.aniortellanes@gmail.com>
 * Copyright 2016, BitCrushers Team
 *
 * This file is part of Presidentum
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "Juego.h"

#include "EMenu.h"
#include "EInGame.h"
#include "ECargando.h"
#include "Mundo.h"

using namespace std;

Juego* Juego::pinstance = 0;
Juego* Juego::Instance(){

    if(pinstance == 0) pinstance = new Juego();

    return pinstance;
}

Juego::Juego(){

    _state = 0;

}

void Juego::Init(){
    //VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings(
    window = new sf::RenderWindow(sf::VideoMode(this->windowWidth, this->windowHeight), "Presidentum");
    window->setFramerateLimit(60);
    sf::Clock reloj;

    //Asignamos icono a la ventana
    sf::Image icon;
    icon.loadFromFile("resources/icon.png");
    window->setIcon(16,16,icon.getPixelsPtr());

    std::cout << "Instancia de Juego: " << this  << std::endl;

    ECargando::Instance(this);
    EInGame::Instance(this);
    EMenu::Instance(this)->Handle();

    while(window->isOpen()){

        //Bucle de obtención de eventos

        while (window->pollEvent(event)){

            switch(event.type){
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    _state = 0;
                    window->close();
                    break;

                default:
                break;
            }
        }

        if(_state!=0){ //Con el valor 0, el juego dejará de pintar

            Update();
        }
    }
}

void Juego::Update(){

    _state->Update();

}

Escena* Juego::currentState(){

    return _state;

}

void Juego::setState(Escena* state){

    _state = state;

}

Juego::~Juego() {

   delete EInGame::Instance(this);
   std::cout << "Juego ha sido eliminado."   << std::endl;


}

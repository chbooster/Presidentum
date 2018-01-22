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


#include <stdio.h>
#include <iostream>
#include <fstream>
#include "EInGame.h"
#include "Juego.h"
#include "Jugador.h"
#include "Escena.h"
#include "ECargando.h"
#include <string>
#include <cstring>

using namespace std;

using std::ifstream;
using std::cout;
using std::endl;


const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = "\""; //IMPORTANTE, cada elemento de las lineas del XML van separados por comillas (")

EInGame* EInGame::pinstance = 0;
EInGame* EInGame::Instance(Juego* context){

    if(pinstance == 0) pinstance = new EInGame(context);

    return pinstance;
}

EInGame::EInGame(Juego* context){ //CONSTRUCTOR REAL

    _context = context; //En el momento en el que se crea el estado, se asigna su contexto.

}

void EInGame::Handle(){

    std::cout << "EInGame: "  << this << std::endl;
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.

}

void EInGame::Init(){

   // NADA DE MOMENTO


}

void EInGame::Update(){

    if(!initState){
        Init();
        initState = true;
    }

    if(!eliminandoMundo){

        Mundo::Instance()->Update();

        Render();

    }

}

void EInGame::Render(){

    _context->window->clear(sf::Color::White); //COLOR DE FONDO BLANCO
    Mundo::Instance()->Render();
    _context->window->display();

}

Juego* EInGame::getContext(){

    return _context;    //Para recuperar el contexto

}

void EInGame::eliminarMundo(){

    std::cout<<"Pues parece que va"<<std::endl;

    eliminandoMundo = true;

    Mundo::Instance()->musica->stop();
    Mundo::Instance()->faseActual++;
    Mundo::Instance()->eliminarMundo();
    Mundo::Instance()->mundoCreado = false;
    ECargando::Instance(Juego::Instance())->Handle();

}

EInGame::~EInGame(){
                            //Destruccion de la instancia



    //delete Jugador::Instance();
    _context = 0;
    pinstance = 0;
    std::cout << "EInGame ha sido eliminada. "  << std::endl;

}

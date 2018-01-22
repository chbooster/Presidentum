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
#include <SFML/Graphics.hpp>

#include "Juego.h"
#include "ECargando.h"
#include "EInGame.h"
#include "EMenu.h"
#include "Mundo.h"
#include "Camara.h"

using namespace std;

ECargando* ECargando::pinstance = 0;
ECargando* ECargando::Instance(Juego* context){

    if(pinstance == 0) pinstance = new ECargando(context);

    return pinstance;
}

ECargando::ECargando(Juego* context){ //CONSTRUCTOR REAL

    initState = false;
    _context = context; //En el momento en el que se crea el estado, se asigna su contexto.

}

void ECargando::Handle(){

    std::cout << "ECargando: "  << this << std::endl;
    if(!initState)Init();
    _context->setState(this);   //Al hacer Handle, se activa este estado en el contexto.

}

void ECargando::Init(){


    int width = Juego::Instance()->windowWidth;
    int height = Juego::Instance()->windowHeight;

    // Texto
    font.loadFromFile("resources/fonts/alterebro-pixel-font.ttf");

    std::string lines = std::string("Preparando las cortes...");
    lines+="\nPreparando diputados... ";
    lines+="\nPreparando simpatizantes... ";
    lines+="\nPreparando votos... ";
    lines+="\nPreparando jefes... ";

    tituloText.setFont(font);
    tituloText.setCharacterSize(30);
    tituloText.setString("CARGANDO...");

    cuerpoText.setFont(font);
    cuerpoText.setCharacterSize(30);
    cuerpoText.setString(lines);


    bgCartel.setFillColor(sf::Color(180,50,50,200));
    bgCartel.setSize(sf::Vector2f((float)width, (float)height));

    bgCartel.setOrigin((float)bgCartel.getSize().x/2, (float)bgCartel.getSize().y/2);
    bgCartel.setPosition((float)bgCartel.getSize().x/2, (float)bgCartel.getSize().y/2);


    cartel.setFillColor(sf::Color(255,255,255,200));
    cartel.setSize(sf::Vector2f((float)width/1.4, (float)height/1.4));
    cartel.setOrigin((float)cartel.getSize().x/2, (float)cartel.getSize().y/2);
    cartel.setPosition((float)bgCartel.getSize().x/2, (float)bgCartel.getSize().y/2);
    cartel.setOutlineColor(sf::Color::Black);
    cartel.setOutlineThickness(2);



    tituloText.setPosition(cartel.getOrigin().x+40,cartel.getOrigin().y-140);
    tituloText.setPosition((float)bgCartel.getSize().x/2-130,(float)bgCartel.getSize().y/2-230);
    tituloText.setCharacterSize(70);
    tituloText.setFillColor(sf::Color::Black);


    //cuerpoText.setPosition(cartel.getOrigin().x-100,cartel.getOrigin().y-70);
    cuerpoText.setPosition((float)bgCartel.getSize().x/2-160,(float)bgCartel.getSize().y/2-110);

    cuerpoText.setCharacterSize(50);
    cuerpoText.setFillColor(sf::Color::Black);

    entryPoint = true;
}

void ECargando::Update(){

    Render();

    Mundo::Instance()->crearMundo(EMenu::Instance(_context)->partidoSeleccionado);

    EInGame::Instance(_context)->eliminandoMundo = false;
    Mundo::Instance()->musica->play();
    EInGame::Instance(_context)->Handle();

}


void ECargando::Render(){

    _context->window->clear(sf::Color::Black);

    _context->window->draw(bgCartel);
    _context->window->draw(cartel);
    _context->window->draw(tituloText);
    _context->window->draw(cuerpoText);

    _context->window->display();

}

ECargando::~ECargando() {


}


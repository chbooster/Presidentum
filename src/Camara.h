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

#ifndef CAMARA_H
#define CAMARA_H
#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Jugador.h"
 #include <string>

class Camara {
public:
    Camara();
    Camara(const Camara& orig);
    virtual ~Camara();

    void draw();
    void moveRight();
    void moveLeft();
    void sumaVotos(int votos);
    void actualizarVidas(int v, int pol, int seleccionJugador);
    void actualizarVidasPrincipales(int vp, int seleccionJugador);
    void actualizarVidasMiniaturas(int vm, int pol, int seleccionJugador);
    void actualizarVidasMiniaturas2(int vm, int pol, int seleccionJugador);
    void cartelFinal();
    void cartelGameOver();
    void setLastTime(int c);
    void mostrarLlave();
    void setCameraPos(int x);
    void setCameraOrigin();

    //void setHudVotosValue(int votoObtenido);
    int getPosx();
    sf::Sprite getHudVotos();
    sf::Text getHudVotosValue();
    sf::Sprite getContador();
    sf::Text getContadorValue();
    sf::Sprite getVidasPrincipales();
    sf::Sprite getSpriteVidaAlbert2();
    sf::Sprite getVidas();
    sf::Sprite getBarraVida();
    sf::Sprite getMiniatura1();
    sf::Sprite getMiniatura1vida();
    sf::Sprite getMiniatura2();
    sf::Sprite getMiniatura2vida();

//    sf::Clock getClock();
    void actualizarTiempo();
    void resetearCamara();
    int desplazamientoCamara;
    int posicionOrigenCamara;
    int lastTime;
    int countdown;
    sf::Text hudVotosValue; //Numero de votos
private:

    int ancho;
    int alto;


    int kVel;
    //sf::Time time; //PRUEBA INTERPOLACION

    sf::View *camara;

    sf::Font font;
    sf::Font fontpixelated;
    sf::Sprite hudVotos; //Fuente VOTOS:

    sf::Sprite background;

    sf::Clock clock; //Tiempo HUD
    //int countdown; //Cuenta atras HUD
    sf::Sprite contador; //Reloj
    sf::Text contadorValue; //Valor cuenta atras
    std::string convertTime;  //Para convertir de int a String el tiempo
    int votosConseguidos;
    std::string convertVotos;

    int **matriz; //Para el spritesheet del HUD
    int posX;
    int linea;

    float aceleracion = 0.0; //Aceleracion del movimiento de la camara
    float increment = 0.2; //Incrementos de camara
    bool isMoving;  //Controla si se está moviendo el jugador (de momento no se usa)

    sf::Sprite vidas;
    sf::Sprite barraVida;
    sf::Sprite vidasPrincipales;
    sf::Sprite miniatura1;
    sf::Sprite miniatura1vida;
    sf::Sprite miniatura2;
    sf::Sprite miniatura2vida;

    sf::Texture texturaHUD;

};

#endif /* CAMARA_H */


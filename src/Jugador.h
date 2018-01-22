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


#ifndef JUGADOR_H
#define JUGADOR_H

#include <SFML/Audio.hpp>

#include "Mapa.h"
#include "Proyectil.h"
#include <vector>

class Camara;

class Jugador {
public:
    static Jugador* Instance();
    Jugador();
    Jugador(const Jugador& orig);
    void iniciarJugador(float x, float y, int politic, int politic2, int politic3, bool activado);//1.Pablo 2.Albert 3.Rajoy 4.Pedro
    ~Jugador();
    sf::Sprite getSprite();
    void leerXML();
    void draw();
    void dibujarProyectiles();
    void handle();
    void disparar();
    bool isMoving();
    void golpeando();
    void comprobarCelda();
    void resetearJugador();

    bool invencible;
    bool peleaBoss;
    bool salto;
    int alturaSuelo;
    sf::Vector2f posicionAnterior;
    sf::Vector2f posicionJugador;
    float velocidadSalto;
    float velocidadMovimiento;
    sf::Vector2f velocidadJugador;
    bool muerto;
    bool golpeado;
    std::vector<Proyectil*>* proyectiles;//para poder acceder desde otras clases
    float paso;
    sf::Clock pasoTime;
    int col;
    int direccion;
    sf::Clock golpeosSegundo;
    float golpeoXseg;
    int vidas;
    int vidasPrincipales;
    int seleccionJugador;
    int vidasMiniaturas1;
    int vidasMiniaturas2;
    int ultimo;
    int politico;
    int eliminadoC;
    int eliminadoA;

    int enemigosEliminados=0;
    int estadoDelPacto; //0 no se muestra el dialogo. 1 Se muestra. 2 Si. 3 NO
    int prueba;
    int prueba2;

    bool tieneLLave;
    bool dialogo;
    sf::Sprite *dialogoCerrado;
    sf::Sprite *dialogoAbierto;
    bool carcelAbierta;
    int controllerIndex; // identificador de mando
    bool bossTocado;
    sf::SoundBuffer bufferSalto;
    sf::Sound soundSalto;
    sf::SoundBuffer bufferAtaque;
    sf::Sound soundAtaque;
    sf::SoundBuffer bufferHurt;
    sf::Sound soundHurt;

private:

    int direccionPro;
    sf::Sprite sprite;

    bool activo;

     sf::Clock clockpausa;

    int** matriz;
    sf::Texture texturaJugador;
    sf::Clock aparicionProyectil;

    static Jugador* pinstance;

};

#endif /* JUGADOR_H */


/**/

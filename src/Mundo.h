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


#ifndef MUNDO_H
#define MUNDO_H
#include "Mapa.h"
#include "BossFinal.h"
#include "Enemigo.h"
#include "Proyectil.h"

class Mundo {

public:
    static Mundo* Instance();

    Mundo();

    bool crearMundo(int l);

    void Update();

    void Render();

    void eliminarMundo();

    void reset();

    void sumarValoresTotales();
    void actualizarVidas();

    ~Mundo();

    int nivel;

    bool mundoCreado = false;

    //RELOJES//////////////////////


    sf::Clock relojGolpe;
    sf::Clock clock;
    sf::Clock updateClock;
    sf::Time timeElapsed;

    float tiempo;

    //MUSICA//////////////////////

    sf::SoundBuffer* buffer;
    sf::Sound* musica;
    sf::SoundBuffer* bufferSobre;
    sf::SoundBuffer* bufferHurt;
    sf::Sound* soundSobre;
    sf::Sound* soundHurt;


    //ENEMGOS////////////////////

    BossFinal* jefefinal;

    std::vector<Enemigo*>* enemigosAdistancia;  //array de enemigos a distancia

    std::vector<Enemigo*>* enemigosCuerpo;  //array de enemigos cuerpo a cuerpo


    //Simpatizante** simpatizantes; //array de simpatizantes

    //Proyectil** proyectiles5; //array de proyectiles

    Mapa* mapa;

    //CAMARA

    Camara* camara; //Apuntador al objeto camara
    int camaraVel;  //desplzamiento de la camara
    sf::Vector2i* camRes; //Resolucion de la camara

    //VARIABLES DE PROGRESION DE JUEGO

    int lugaresVisitados[4]; //niveles a descartar


    int faseActual=0;

    bool mostrarKey;
    sf::Sprite *llave;
    bool pausa;

    /*****Varaibles para guardar informacion*****/
    int votosTotales =0;
    int enemigosTotalesEliminados=0;
    int numPactosRealizados=0;
    int numSimpatizantesLiberados=0;
    int tiempoEmpleado=0;

    int corazonesPrincipal = 3;
    int barrasPrincipal = 10;
    int barrasSecundario1 = 10;
    int barrasSecundario2 = 10;

    int secundario1 = 0;
    int secundario2 = 0;

    bool resetSeq;

private:


       static Mundo* pinstance;

};

#endif /* MUNDO_H */


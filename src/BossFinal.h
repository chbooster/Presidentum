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


#ifndef BOSSFINAL_H
#define BOSSFINAL_H
#include "NPC.h"
#include "Jugador.h"
#include "Proyectil.h"

class BossFinal: public NPC {
public:
    BossFinal();
    BossFinal(bool valorPatrullaje, float posx, float posy, int type);
    bool getPatrullaje();
    void setPatrullaje(bool valorPatrullaje);
    void leerXML();
    ~BossFinal();
    void draw();
    void handle();
    void disparar();
    sf::Sprite* getSprite();

    int hp;
    std::vector<Proyectil*>* proyectiles;
    float paso;
    sf::Clock pasoTime;
    sf::Clock golpeosSegundo;
    float golpeoXseg;
    bool muerto;

private:
    sf::Clock aparicionProyectil;
    int direccion;//0 derecha. 1 izquierda
    int tipo;//partido politico
    bool patrullaje;
    int **matriz;
    sf::Texture *texturaEnemigo;
    bool golpeado;
    bool activado;

};

#endif /* ENEMIGO_H */


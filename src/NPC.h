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


#include <SFML/Graphics.hpp>
#ifndef NPC_H
#define NPC_H


class NPC {
public:
    NPC();
    virtual int getX();
    virtual int getY();
    virtual int getAtaque();
    virtual int getHp();
    virtual void atacar();
    sf::Sprite* spriteSheet; // spritesheet que usará el sprite
    //virtual Mundo* getMundo();
    virtual ~NPC();
protected:

    int x; //posicion del personaje en x
    int y; //posicion del personaje en y
    int ataque; // daño que el NPC inflinje al jugador
    int hp; // vida que tiene el NPC
    //Mundo* mundo;
    //IA* ia;


};

#endif /* NPC_H */


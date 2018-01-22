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


#ifndef PROYECTIL_H
#define	PROYECTIL_H
#include <SFML/Graphics.hpp>

class Proyectil {
public:
    Proyectil();
    Proyectil(int direccion, sf::Vector2f pospersonaje, int **mat, int politic);
    Proyectil(const Proyectil& orig);
    virtual ~Proyectil();

    bool destruir();
    void leerSprite();
    sf::Sprite getSprite();
    void dibuja();
    Proyectil crearPro();
    bool aparece;

private:
    int posx;
    int posy;
    int dir; //0 izq, 1 der
    int **matriz; //Para leer spritesheet
    int disRecorrida; //Destruir el proyectil al haber recorrido 450 de distancia
    sf::Sprite spritePro;
    sf::Texture* texPro;
    int politico;

    //Tiempo en el que se van desplazando los proyectiles
    sf::Clock proyectilClock;
    float disparoTime;
    float disparoAparicion;

};

#endif	/* PROYECTIL_H */


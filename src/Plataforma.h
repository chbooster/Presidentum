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

#ifndef PLATAFORMA_H
#define	PLATAFORMA_H
#include <SFML/Graphics.hpp>

class Plataforma {
public:
    Plataforma(int x, int y, int numMapa, int tipo);
    Plataforma(const Plataforma& orig);
    virtual ~Plataforma();

    sf::Sprite spritePlat;
    sf::Texture texPlat;
    void moves();
    void romperPlataforma();
    void regeneracionPlataforma();

    int direccion;
    int tipo; //0 horizontal, 1 vertical, 2 rompible
    bool rota;
    int romper;
    float tiempoRotura;
private:
    int posx;
    int posy;
    float recorrido;



    sf::Clock tiempoRecorrido;
    float tiempo;

    sf::Color colorInicial;

};

#endif	/* PLATAFORMA_H */


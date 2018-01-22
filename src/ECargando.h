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


#ifndef ECARGANDO_H
#define ECARGANDO_H

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Juego.h"


class ECargando: public Escena {
public:

    static ECargando* Instance(Juego* context);
    ECargando(Juego* context);
    void Handle();
    void Init();
    void Update();
    void Render();

    ~ECargando();

private:

    sf::Font font;
    sf::RectangleShape bgCartel;
    sf::RectangleShape cartel;


    sf::Text tituloText;
    sf::Text cuerpoText;

    bool entryPoint;

    static ECargando* pinstance;
    Juego* _context;

};

#endif /* ECARGANDO_H */


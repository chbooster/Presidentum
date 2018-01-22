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


#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include "Escena.h"

class Juego {

public:
    static Juego* Instance();
    Juego();
    void Init();

    Escena* currentState();

    void setState (Escena* state);

    void Update();

    virtual ~Juego();

    sf::RenderWindow* window;

    sf::Event event;

    int windowWidth = 1066; //Width de la window

    int windowHeight = 600; //Height de la window

private:
	Escena* _state;
        static Juego* pinstance;
};

#endif /* JUEGO_H */

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


#ifndef EINGAME_H
#define EINGAME_H

#include "Juego.h"
#include "Mundo.h"

class EInGame: public Escena {
public:

    static EInGame* Instance(Juego* context);
    void Handle();
    void Init();
    void Update();
    void Render();
    int** getRecorte();
    int** generarRecorte();
    Juego* getContext();
    void eliminarMundo();
    ~EInGame();

    bool eliminandoMundo; //PARA NO EJEGUTAR EL UPDATE/RENDER DE MUNDO MIENTRAS SE ELIMINA

protected:
    EInGame(Juego* context);
    EInGame(const EInGame &);
    EInGame &operator = (const EInGame &);

private:

    int** matrizRecorte;
    static EInGame* pinstance;
    Juego* _context;

};

#endif /* EINGAME_H */


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


#ifndef MAPA_H
#define	MAPA_H

#include <SFML/Graphics.hpp>
#include "Plataforma.h"


class Mapa {
public:
    Mapa();
    Mapa(const Mapa& orig);
    virtual ~Mapa();

    void leerMapa(int numMapa);
    int getTile(int x, int y);
    void dibuja();
    void dibujaEnemigosC();
    void dibujaEnemigosA();
    void dibujaVotos();
    void dibujaPlataformas();
    void reconstruirPlataformas();
    void dibujaSimpatizante(int politico, int fase);
    void dibujaCarcelCerrada();
    void dibujaCarcelAbierta();
    void dibujaDialogoAbierto();
    void dibujaDialogoCerrado();
    void dibujaDialogoPacto();
    void dibujaAyuda1();
    void dibujaAyuda2();
    void dibujaAyuda3();
    void dibujaAyuda4();
    void dibujaAyuda5();
    void dibujaMuro(int nivel);
    //FONDO///////////////
    int cuantasVecesDeboPintarElFondo;
    sf::Texture tex;
    std::vector<sf::Sprite*> fondos; //FONDO
    ////////////////////////

    sf::Sprite  fondo;
    int _width;
    int _tileWidth;
    std::vector<sf::RectangleShape*> arraySuelo;
    std::vector<sf::RectangleShape*> arrayParedes;
    std::vector<sf::RectangleShape*> arrayMuerte;

    std::vector<Plataforma*> arrayPlataformas;
    std::vector<sf::Sprite*>* arrayVotos;
//    std::vector<sf::RectangleShape*> arrayEnemigosC;
//    std::vector<sf::RectangleShape*> arrayEnemigosA;
    int** matrizEnemigosA;
    int** matrizEnemigosC;
    int posxBoss;
    int posyBoss;
    int numEnemigosC;
    int numEnemigosA;
    sf::Sprite *spriteCarcelCerrada;
    sf::Sprite *spriteCarcelAbierta;
    sf::Sprite *spriteBocadilloAbierta;
    sf::Sprite *spriteBocadilloCerrada;
    sf::Sprite *spriteDialogoPacto;
    sf::Sprite *spriteAyuda1;
    sf::Sprite *spriteAyuda2;
    sf::Sprite *spriteAyuda3;
    sf::Sprite *spriteAyuda4;
    sf::Sprite *spriteAyuda5;
    sf::Sprite *spriteMuro;
    int simpaX;
    int simpaY;
    int muroX;
    int muroY;
private:

    int ***_tilemap;
    int _numLayers;
    int _height;
    int _tileHeigth;

    int columnsSpriteSet;
    int rowsSpriteSet;
    bool simpatizanteLoaded;

    sf::Sprite ****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    sf::Sprite te;
    sf::Sprite *spriteVoto;

    sf::Sprite *spriteSimpa;

    sf::Texture _tilesetTexture;
    sf::Texture m_tileset;
    sf::Texture fond;
    sf::Texture texVoto;
    sf::Texture *texMuro;
    sf::Texture texDialogoPacto;
    sf::Texture *texSimpa;
    sf::Texture texBocadilloAbierta;
    sf::Texture texBocadilloCerrada;
    sf::Texture* texAyuda1;
    sf::Texture* texAyuda2;
    sf::Texture* texAyuda3;
    sf::Texture* texAyuda4;
    sf::Texture* texAyuda5;

    sf::Texture texCarcelCerrada;
    sf::Texture texCarcelAbierta;



    sf::VertexArray m_vertices;

};

#endif	/* MAPA_H */


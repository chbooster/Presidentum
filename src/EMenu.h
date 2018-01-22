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


#ifndef EMENU_H
#define EMENU_H

#define MAX_NUMBER_OF_ITEMS 6

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <string>

#include "Juego.h"

class EMenu: public Escena {
public:

    void Handle();
    void Init();
    void Update();

    Juego* getContext();
    static EMenu* Instance(Juego* context);

    void Render();
    void draw(sf::RenderWindow &window, std::vector<sf::Text*> menu);
    void moverMenu(int delta);
    void resetMenu();
    void moveUp(std::vector<sf::Text*> menu, int &iterator);
    void moveDown(std::vector<sf::Text*> menu, int &iterator);

    int run(sf::RenderWindow &window);
    void nuevaPartida(sf::RenderWindow &window);
    void cargarPartida(sf::RenderWindow &window);
    void controles(sf::RenderWindow &window);
    void opciones(sf::RenderWindow &window);
    void creditos(sf::RenderWindow &window);
    void seleccionPersonaje();
    //int pulsarTecla(sf::RenderWindow &window, sf::Event event);
    void submenu(sf::RenderWindow &window);
    void mostrarOpcionesInGame(sf::RenderWindow &window);
    void guardar(sf::RenderWindow &window);
    void setMenuPrincipal(){ mostrarMenuppal = true;}
    void salirAlMenuPrinc();
    void setCameraP();

     int GetPressedItem(){
        return selectedItemIndex;
    };
    int GetPressedItemInPausa(){
        return selectedItemIndexInPausa;
    };
    int GetPressedItemGuardar(){
        return selectedItemIndexGuardar;
    };
    int GetPressedItemSobreescribir(){
        return selectedItemIndexSobreescribir;
    };
    int GetPressedItemOpciones(){
        return selectedItemIndexOpciones;
    };
    void teclas(sf::RenderWindow &window, sf::Event event);

    void sobreescribir(sf::RenderWindow &window);
    void sobreescritocorrectamente(sf::RenderWindow &window);
    void reinicio();

    ~EMenu();


    int partidoSeleccionado;
    bool salida;
    sf::Clock pauseLimiter;


    bool mostrarMenuppal;
    bool enPartida;
    bool enCargar;
    bool enOpciones;
    bool enCreditos;
    bool enControles;
    bool enPausa;
    bool guardando;
    bool sobreescrito;
    bool enSonido;
    bool enMusica;
    bool pausaopciones;
    bool seleccion;

protected:
    EMenu(Juego* context);
    EMenu(const EMenu &);
    EMenu &operator = (const EMenu &);

private:

    uint8_t controllerIndex;
    bool controllerFound;
    sf::Clock clockpausa;
    int opcionMenuppal;
    int opcionMenuInGame;
    int selectedItemIndex;
    int selectedItemIndexInPausa;
    int selectedItemIndexGuardar;
    int selectedItemIndexSobreescribir;
    int selectedItemIndexOpciones;

    sf::Font fuente;

    std::vector<sf::Text*> menu;
    std::vector<sf::Text*> menuInGame;
    std::vector<sf::Text*> guardarsino;
    std::vector<sf::Text*> sobreescribirsino;
    std::vector<sf::Text*> opcionesMenu;


    int oldCameraPos;

    int separacion; //ESPACIO ENTRE LOS LOGOS
    int salto; //ESPACIO QUE DEJAN LOS LOGOS AL TITULO
    int personajeElegido;

    sf::SoundBuffer* bufferSobre;
    sf::Sound* soundSobre;


    sf::Sprite *background;

    sf::Texture texturaBackground;

    sf::Texture* texturaLogoEquipo;
    sf::Sprite* LogoEquipo;
    sf::Texture* texturaEquipo;
    sf::Sprite* imagenEquipo;


    sf::RectangleShape *FondomenuInPausa;
    sf::RectangleShape *barrasonido;
    sf::RectangleShape *barramusica;
    sf::RectangleShape *tiradorsonido;
    sf::RectangleShape *tiradormusica;
    sf::RectangleShape *fondo;
    sf::Color *transparente;


    sf::String interrogacion;
    sf::Text *desea;
    sf::Text *sobreescribirText;
    sf::Text *sobreescribir2Text;
    sf::Text *sobrescrita;
    sf::Text *izquierda ;
    sf::Text *derecha;
    sf::Text *saltar;
    sf::Text *golpear;
    sf::Text *personaje1;
    sf::Text *personaje2;
    sf::Text *personaje3;
    sf::String* stringRestoCreditos;
    sf::Text *textocreditos;
    sf::Text *textocreditosVolver;
    sf::Text *textoCargarPartida;
    sf::Text *valorsonido;
    sf::Text *valormusica;

    sf::Color* bgColor;

    sf::Texture* bgMenuTex;
    sf::Texture* logoMenuTex;

    sf::Texture* psoeSelTex;
    sf::Texture* ppSelTex;
    sf::Texture* ciudadanosSelTex;
    sf::Texture* podemosSelTex;

    sf::Font* font;
    sf::Text* tituloSel;
    sf::String* stringSel;

    sf::RectangleShape* cuadradoSel;

    sf::Sprite* logoMenu;
    sf::Sprite* bgMenu;

    sf::Sprite* psoeSelSprite;
    sf::Sprite* ppSelSprite;
    sf::Sprite* ciudadanosSelSprite;
    sf::Sprite* podemosSelSprite;




    static EMenu* pinstance;
    Juego* _context;

};

#endif /* EMENU_H */

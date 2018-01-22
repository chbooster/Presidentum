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

#include "Mapa.h"
#include "Plataforma.h"
#include "../tinyxml/tinystr.h"
#include "../tinyxml/tinyxml.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Enemigo.h"
#include "BossFinal.h"
#include "Juego.h"
#include "Mundo.h"
#include "math.h"

using namespace std;

Mapa::Mapa() {
    //constructor vacio
    matrizEnemigosA=new int*[99];
    for(int i=0; i<99;i++){
        matrizEnemigosA[i]=new int[4];
    }

    matrizEnemigosC=new int*[99];
    for(int i=0; i<99;i++){
        matrizEnemigosC[i]=new int[4];
    }

    arrayVotos = new vector<sf::Sprite*>();

}

Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa() {


    for(size_t i=0; i<arrayPlataformas.size();i++){
        delete arrayPlataformas.at(i);
    }
    for(size_t i=0; i<arrayVotos->size();i++){
        delete arrayVotos->at(i);
    }
    delete arrayVotos;

    for(size_t i=0; i<arraySuelo.size();i++){
        delete arraySuelo.at(i);
    }
    for(size_t i=0; i<arrayParedes.size();i++){
        delete arrayParedes.at(i);
    }
    for(size_t i=0; i<arrayMuerte.size();i++){
        delete arrayMuerte.at(i);
    }
    for(size_t i=0; i<fondos.size();i++){
        delete fondos.at(i);
    }


    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            delete[] _tilemap[l][y];
        }
        delete[] _tilemap[l];
    }
/*
    for(int l=0; l<_numLayers; l++){
            delete _tilemapSprite[l];
        for(int y=0; y<_height; y++){
            delete _tilemapSprite[l][y];
            for(int x=0; x<_width; x++){
                delete _tilemapSprite[l][y][x];
            }
        }
    }
*/


    //delete _tilemapSprite;

    //if(spriteVoto!=nullptr)                 delete spriteVoto;
    //if(spriteSimpa!=nullptr)                delete spriteSimpa;
    if(spriteCarcelCerrada!=nullptr)        delete spriteSimpa;
    if(spriteCarcelAbierta!=nullptr)        delete spriteCarcelAbierta;
    if(spriteBocadilloAbierta!=nullptr)     delete spriteBocadilloAbierta;
    if(spriteBocadilloCerrada!=nullptr)     delete spriteBocadilloCerrada;
    if(spriteDialogoPacto!=nullptr)         delete spriteDialogoPacto;
    if(texMuro!=nullptr)                    { delete texMuro; delete spriteMuro;}
    if(texAyuda1!=nullptr)                  { delete texAyuda1; delete spriteAyuda1; }
    if(texAyuda2!=nullptr)                  { delete texAyuda2; delete spriteAyuda2; }
    if(texAyuda3!=nullptr)                  { delete texAyuda3; delete spriteAyuda3; }
    if(texAyuda4!=nullptr)                  { delete texAyuda4; delete spriteAyuda4; }
    if(texAyuda5!=nullptr)                  { delete texAyuda5; delete spriteAyuda5; }

   // delete _tilemap;
   // delete _tilemapSprite;
   // delete _tilesetSprite;

}

void Mapa::leerMapa(int numMapa){

    spriteCarcelCerrada     = nullptr;
    spriteCarcelAbierta     = nullptr;
    spriteBocadilloAbierta  = nullptr;
    spriteBocadilloCerrada  = nullptr;
    spriteDialogoPacto      = nullptr;
    spriteMuro              = nullptr;
    spriteVoto              = nullptr;
    spriteSimpa             = nullptr;
    texMuro                 = nullptr;
    spriteAyuda1            = nullptr;
    spriteAyuda2            = nullptr;
    spriteAyuda3            = nullptr;
    spriteAyuda4            = nullptr;
    spriteAyuda5            = nullptr;
    texAyuda1               = nullptr;
    texAyuda2               = nullptr;
    texAyuda3               = nullptr;
    texAyuda4               = nullptr;
    texAyuda5               = nullptr;

    _numLayers=0;
    //cargo la textura del fondo
    if(!fond.loadFromFile("resources/PP/background.jpg")){
        std::cerr << "Error cargando la imagen background.png";
        exit(0);
    }
    fondo.setTexture(fond);

    /*
     * numMapa| niv1-niv2-niv3
     * ------------------------
     * numMapa| 1-5-9 -> PP
     * numMapa| 2-6-10 -> PSOE
     * numMapa| 3-7-11 -> CIUDADANOS
     * numMapa| 4-8-12 -> PODEMOS
     */


    string filename;

    filename = "resources/";

    //creo el objeto xml
    TiXmlDocument doc;

    //NIVEL 1
    if(numMapa==1)doc.LoadFile("resources/PP/nivel1PP.tmx");
    if(numMapa==2)doc.LoadFile("resources/PSOE/nivel1PSOE.tmx");
    if(numMapa==3)doc.LoadFile("resources/CIUDADANOS/nivel1CIUDADANOS.tmx");
    if(numMapa==4)doc.LoadFile("resources/PODEMOS/nivel1PODEMOS.tmx");

    //NIVEL 2
    if(numMapa==5)doc.LoadFile("resources/PP/nivel2PP.tmx");
    if(numMapa==6)doc.LoadFile("resources/PSOE/nivel2PSOE.tmx");
    if(numMapa==7)doc.LoadFile("resources/CIUDADANOS/nivel2CIUDADANOS.tmx");
    if(numMapa==8)doc.LoadFile("resources/PODEMOS/nivel2PODEMOS.tmx");

    //NIVEL 3
    if(numMapa==9)doc.LoadFile("resources/PP/nivel3PP.tmx");
    if(numMapa==10)doc.LoadFile("resources/PSOE/nivel3PSOE.tmx");
    if(numMapa==11)doc.LoadFile("resources/CIUDADANOS/nivel3CIUDADANOS.tmx");
    if(numMapa==12)doc.LoadFile("resources/PODEMOS/nivel3PODEMOS.tmx");

    TiXmlElement* mapTix = doc.FirstChildElement("map");

    //leo sus atributos
    mapTix->QueryIntAttribute("width",&_width);
    mapTix->QueryIntAttribute("height",&_height);
    mapTix->QueryIntAttribute("tilewidth",&_tileWidth);
    mapTix->QueryIntAttribute("tileheight",&_tileHeigth);


    //Leemos las diferentes imagenes que nos sirven para hacer el rect de las texturas
    TiXmlElement *img = mapTix->FirstChildElement("tileset");

    int numTil=0;
    while(img){
        numTil++;
        img=img->NextSiblingElement("tileset");
    }

    switch(numMapa){

        case 1: case 5: case 9:  { filename+="PP/";          break;  }
        case 2: case 6: case 10: { filename+="PSOE/";        break;  }
        case 3: case 7: case 11: { filename+="CIUDADANOS/";  break;  }
        case 4: case 8: case 12: { filename+="PODEMOS/";     break;  }
        default: break;

    }


    img = mapTix->FirstChildElement("tileset");
    //guardamos en filename el spritesheet
    while(img){
        filename+=(string)img->FirstChildElement("image")->Attribute("source");
        img=img->NextSiblingElement("tileset");
    }

    //leemos las diferentes capas
    _tilesetTexture.loadFromFile(filename);
    TiXmlElement *layer = mapTix->FirstChildElement("layer");
    while(layer){
        _numLayers++;
        layer= layer->NextSiblingElement("layer");
    }

    //Reserva de memoria para saber el numnero de capas y el tamaño
    _tilemap=new int**[_numLayers];
    for(int i=0; i<_numLayers; i++){
        _tilemap[i]=new int*[_height];
    }

    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            _tilemap[l][y]=new int[_width];
        }
    }

    TiXmlElement *data;
    //leemos el atributo imagen
    layer = mapTix->FirstChildElement("layer");
    string *name=new string[_numLayers];
    int j=0;
    int l=0;
    //leo los tiles del xml y avanzo a la siguiente posicion
    while(layer){
        data= layer->FirstChildElement("data")->FirstChildElement("tile");
        name[j]= (string)layer->Attribute("name");
            while(data){
                for(int y=0; y<_height; y++){
                    for(int x=0; x<_width;x++){
                        data->QueryIntAttribute("gid",&_tilemap[l][y][x]);
                        data=data->NextSiblingElement("tile");
                    }
                }
            }
        l++;
        layer= layer->NextSiblingElement("layer");
        j++;
    }

    //Reserva de memoria para los sprites
    _tilemapSprite=new sf::Sprite***[_numLayers];

    for(int l=0; l<_numLayers; l++){
        _tilemapSprite[l]=new sf::Sprite**[_height];
    }

    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            _tilemapSprite[l][y]= new sf::Sprite*[_width];
            for(int x=0; x<_width; x++){
                _tilemapSprite[l][y][x]=new sf::Sprite();
            }
        }
    }
    sf::Texture aux;

    //falta el corte

    int columns = _tilesetTexture.getSize().x / _tileWidth;
    int rows = _tilesetTexture.getSize().y / _tileHeigth;

    columnsSpriteSet = columns;
    rowsSpriteSet = rows;
//    cout<<columns<<" "<<rows<<endl;

    _tilesetSprite =new sf::Sprite[columns*rows];
    int t=0;
    for(int y=0; y<rows; y++){
        for(int x=0; x<columns;x++){
              _tilesetSprite[t].setTexture(_tilesetTexture);
              //_tilesetSprite[t].setTextureRect(sf::IntRect(left,top,width,height));//ojo si hay dos imagenes
              _tilesetSprite[t].setTextureRect(sf::IntRect(x*_tileWidth,y*_tileHeigth,_tileWidth,_tileHeigth));
              t++;
        }
    }


    /**
    for(int y=0; y<t; y++)
    {
     cout<<_tilesetSprite[y].getTextureRect().left<<" ";
     cout<<_tilesetSprite[y].getTextureRect().top<<" ";
      cout<<_tilesetSprite[y].getTextureRect().width<<" ";
       cout<<_tilesetSprite[y].getTextureRect().height<<endl;
    }**/

    //cout<<t<<endl;

    //asignacion sprite

    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width;x++){
                int gid=_tilemap[l][y][x]-1;
                if(gid>=rows*columns){
//                    cout<<gid<<endl;
//                    cout<<rows<<endl;
//                    cout<<columns<<endl;
//                    cout<<"Error aaaa"<<endl;
                }
                else if(gid>0){

                    _tilemapSprite[l][y][x]=new sf::Sprite(_tilesetTexture,_tilesetSprite[gid].getTextureRect());
                    _tilemapSprite[l][y][x]->setPosition(x*_tileWidth,y*_tileHeigth);
                }
                else{
                    _tilemapSprite[l][y][x]=NULL;
                }
            }
        }
    }

    /////////////////////Resumen
//    cout<<endl;
//    cout<<"Resumen:"<<endl;
//    cout<<"Heigth= "<<_height<<endl;
//    cout<<"Width= "<<_width<<endl;
//    cout<<"TileWidth= "<<_tileWidth<<endl;
//    cout<<"TileHeigth= "<<_tileHeigth<<endl;
//    cout<<"Numero de capas= "<<_numLayers<<endl;
//    cout<<"Nombre del tileset= "<<filename[0]<<endl;
//    cout<<"Nombre del tileset= "<<filename[1]<<endl;
//    cout<<endl;

     TiXmlElement *suelo = mapTix->FirstChildElement("objectgroup");
     string nombre;
     int filas=0;
     string xString, yString, widthString, heightString;
     int x, y, width, height = 0;


     while(suelo){
         nombre=(string) suelo->Attribute("name");
         if(nombre=="Suelo"){
//             cout<<"nombre: "<<nombre<<endl;
             TiXmlElement *object = suelo->FirstChildElement("object");
             while(object){

                xString = (string) object->Attribute("x");
                yString = (string) object->Attribute("y");
                widthString = (string) object->Attribute("width");
                heightString = (string) object->Attribute("height");

                x=atoi(xString.c_str());
                y=atoi(yString.c_str());
                width=atoi(widthString.c_str());
                height=atoi(heightString.c_str());

                /*Se crean los rectangulos que colisionan*/
                sf::RectangleShape* colision = new sf::RectangleShape(sf::Vector2f(width, height));
                colision->setPosition(x,y);
                arraySuelo.push_back(colision);



                /*cout<<"x: "<<x<<endl;
//                cout<<"y: "<<y<<endl;
//                cout<<"width: "<<width<<endl;
//                cout<<"heigth: "<<height<<endl;
//                cout<<"----"<<endl;*/
                object = object->NextSiblingElement("object");
                filas++;
             }
         }
         suelo = suelo->NextSiblingElement("objectgroup");
     }

     TiXmlElement *paredes = mapTix->FirstChildElement("objectgroup");

     while(paredes){
         nombre=(string) paredes->Attribute("name");
         if(nombre=="Paredes"){
//              cout<<"nombre: "<<nombre<<endl;
              TiXmlElement *object = paredes->FirstChildElement("object");
              while(object){
                xString = (string) object->Attribute("x");
                yString = (string) object->Attribute("y");
                widthString = (string) object->Attribute("width");
                heightString = (string) object->Attribute("height");

                x=atoi(xString.c_str());
                y=atoi(yString.c_str());
                width=atoi(widthString.c_str());
                height=atoi(heightString.c_str());

                sf::RectangleShape* colision = new sf::RectangleShape(sf::Vector2f(width, height));
                colision->setPosition(x,y);
                arrayParedes.push_back(colision);

                /*cout<<"x: "<<x<<endl;
//                cout<<"y: "<<y<<endl;
//                cout<<"width: "<<width<<endl;
//                cout<<"heigth: "<<height<<endl;
//                cout<<"----"<<endl;
                */
                object = object->NextSiblingElement("object");
                filas++;
              }
         }
         paredes = paredes->NextSiblingElement("objectgroup");
     }

     TiXmlElement *muerte = mapTix->FirstChildElement("objectgroup");

     while(muerte){
         nombre=(string) muerte->Attribute("name");
         if(nombre=="Colision muerte"){
              cout<<"nombre: "<<nombre<<endl;
              TiXmlElement *object = muerte->FirstChildElement("object");
              while(object){
                xString = (string) object->Attribute("x");
                yString = (string) object->Attribute("y");
                widthString = (string) object->Attribute("width");
                heightString = (string) object->Attribute("height");

                x=atoi(xString.c_str());
                y=atoi(yString.c_str());
                width=atoi(widthString.c_str());
                height=atoi(heightString.c_str());

                sf::RectangleShape* colision = new sf::RectangleShape(sf::Vector2f(width, height));
                colision->setPosition(x,y);
                arrayMuerte.push_back(colision);

                /*cout<<"x: "<<x<<endl;
                cout<<"y: "<<y<<endl;
                cout<<"width: "<<width<<endl;
                cout<<"heigth: "<<height<<endl;
                cout<<"----"<<endl;
                */
                object = object->NextSiblingElement("object");
                filas++;
              }
         }
         muerte = muerte->NextSiblingElement("objectgroup");
     }

//     cout<<"width "<<arrayColisiones[0]->getScale()<<endl;
//     cout<<"height "<<arrayColisiones[0]->height<<endl;

        TiXmlElement *plataformas = mapTix->FirstChildElement("objectgroup");
        while(plataformas){

            nombre=(string) plataformas->Attribute("name");

            if(nombre=="Plataforma horizontal"){
//                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = plataformas->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());

                        Plataforma *plataforma = new Plataforma(x, y, numMapa, 0);
                        arrayPlataformas.push_back(plataforma);

                        /*cout<<"x: "<<x<<endl;
//                        cout<<"y: "<<y<<endl;
//                        cout<<"----"<<endl;
                        */
                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             plataformas = plataformas->NextSiblingElement("objectgroup");
         }

        TiXmlElement *plataformas2 = mapTix->FirstChildElement("objectgroup");
        while(plataformas2){

            nombre=(string) plataformas2->Attribute("name");

            if(nombre=="Plataforma vertical"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = plataformas2->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());

                        Plataforma *plataforma = new Plataforma(x, y, numMapa, 1);
                        arrayPlataformas.push_back(plataforma);

                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             plataformas2 = plataformas2->NextSiblingElement("objectgroup");
         }


        TiXmlElement *plataformas3 = mapTix->FirstChildElement("objectgroup");
        while(plataformas3){

            nombre=(string) plataformas3->Attribute("name");

            if(nombre=="Plataforma rompible"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = plataformas3->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());

                        Plataforma *plataforma = new Plataforma(x, y, numMapa, 2);
                        arrayPlataformas.push_back(plataforma);

                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             plataformas3 = plataformas3->NextSiblingElement("objectgroup");
         }


         TiXmlElement *votos = mapTix->FirstChildElement("objectgroup");
        while(votos){

            nombre=(string) votos->Attribute("name");

            if(nombre=="Votos"){
//                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = votos->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());



                        if (!texVoto.loadFromFile("resources/common/voto.png")) {
                                std::cerr << "Error cargando la imagen voto.png";
                                exit(0);
                        }

                        spriteVoto = new sf::Sprite(texVoto);
                        spriteVoto->setPosition(x, y);
                        //spriteVoto.setTexture(texVoto);
                        //spriteVoto.setPosition(x, y);

                        arrayVotos->push_back(spriteVoto);

                        /*cout<<"x: "<<x<<endl;
//                        cout<<"y: "<<y<<endl;
//                        cout<<"----"<<endl;
                        */
                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             votos = votos->NextSiblingElement("objectgroup");
         }

     int iC=0;
        TiXmlElement *enemigosC = mapTix->FirstChildElement("objectgroup");
        while(enemigosC){

            nombre=(string) enemigosC->Attribute("name");

            if(nombre=="Enemigos C"){
//                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = enemigosC->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());

                        matrizEnemigosC[iC][0]=x;
                        matrizEnemigosC[iC][1]=y;

//                        cout<<"-----Pos x enemC:-------- "<<matrizEnemigosC[iC][0]<<endl;
//                        cout<<"-----Pos y enemC:-------- "<<matrizEnemigosC[iC][1]<<endl;
                        iC++;


                       // sf::RectangleShape* enemigosC = new sf::RectangleShape(sf::Vector2f(40, 110));
                        //enemigosC->setFillColor(sf::Color::Red);
                        //enemigosC->setPosition(x,y);
                        //arrayEnemigosC.push_back(enemigoC);

                        /*cout<<"x: "<<x<<endl;
//                        cout<<"y: "<<y<<endl;
//                        cout<<"----"<<endl;
                        */
                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             enemigosC = enemigosC->NextSiblingElement("objectgroup");
         }
        numEnemigosC=iC;

        int iA=0;
        TiXmlElement *enemigosA = mapTix->FirstChildElement("objectgroup");
        while(enemigosA){

            nombre=(string) enemigosA->Attribute("name");

            if(nombre=="Enemigos A"){
//                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = enemigosA->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());

                        matrizEnemigosA[iA][0]=x;
                        matrizEnemigosA[iA][1]=y;

//                        cout<<"-----Pos x enemA:-------- "<<matrizEnemigosA[iA][0]<<endl;
//                        cout<<"-----Pos y enemA:-------- "<<matrizEnemigosA[iA][1]<<endl;
                        iA++;

                        /*cout<<"x: "<<x<<endl;
//                        cout<<"y: "<<y<<endl;
//                        cout<<"----"<<endl;
                        */
                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             enemigosA = enemigosA->NextSiblingElement("objectgroup");
         }
        numEnemigosA=iA;

        TiXmlElement *boss = mapTix->FirstChildElement("objectgroup");
        while(boss){

            nombre=(string) boss->Attribute("name");

            if(nombre=="BOSS FINAL"){
//                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = boss->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


        /***************************CREACION DEL BOSS FINAL!!**********************************/
                        posxBoss=x;
                        posyBoss=y;


//                        cout<<"-----Pos x JEFE:-------- "<<posxBoss<<endl;
//                        cout<<"-----Pos y JEFE:-------- "<<posyBoss<<endl;



                        /*cout<<"x: "<<x<<endl;
                        cout<<"y: "<<y<<endl;
                        cout<<"----"<<endl;
                        */
                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             boss = boss->NextSiblingElement("objectgroup");
         }

        TiXmlElement *simpa = mapTix->FirstChildElement("objectgroup");
        while(simpa){

            nombre=(string) simpa->Attribute("name");

            if(nombre=="Simpatizante"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = simpa->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());

                        simpaX=x;
                        simpaY=y;

        /***************************SIMPATIZANTE**********************************/
                        texSimpa = new sf::Texture();
                        if (!texSimpa->loadFromFile("resources/simpatizantes/RITA.png")) {
                                std::cerr << "Error cargando la imagen RITA.png";
                                exit(0);
                        }
                        spriteSimpa = new sf::Sprite(*texSimpa);
                        spriteSimpa->setPosition(x, y);

                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             simpa = simpa->NextSiblingElement("objectgroup");
         }


        TiXmlElement *carcel = mapTix->FirstChildElement("objectgroup");
        while(carcel){

            nombre=(string) carcel->Attribute("name");

            if(nombre=="Carcel"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = carcel->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


        /***************************CARCEL**********************************/
                        if (!texCarcelCerrada.loadFromFile("resources/common/CarcelCerrada.png")) {
                                std::cerr << "Error cargando la imagen CarcelCerrada.png";
                                exit(0);
                        }

                        spriteCarcelCerrada = new sf::Sprite(texCarcelCerrada);
                        spriteCarcelCerrada->setPosition(x, y);

                         if (!texCarcelAbierta.loadFromFile("resources/common/CarcelAbierta.png")) {
                                std::cerr << "Error cargando la imagen CarcelAbierta.png";
                                exit(0);
                        }

                        spriteCarcelAbierta = new sf::Sprite(texCarcelAbierta);
                        spriteCarcelAbierta->setPosition(x, y);

                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             carcel = carcel->NextSiblingElement("objectgroup");
         }

        TiXmlElement *bocadillo = mapTix->FirstChildElement("objectgroup");
        while(bocadillo){

            nombre=(string) bocadillo->Attribute("name");

            if(nombre=="Bocadillo"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = bocadillo->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


        /***************************SIMPATIZANTE**********************************/

                        if (!texBocadilloAbierta.loadFromFile("resources/common/carcelAbiertaDialog.png")) {
                                std::cerr << "Error cargando la imagen carcelAbiertaDialog.png";
                                exit(0);
                        }

                        if (!texBocadilloCerrada.loadFromFile("resources/common/carcelCerradaDialog.png")) {
                                std::cerr << "Error cargando la imagen carcelCerradaDialog.png";
                                exit(0);
                        }

                        spriteBocadilloAbierta = new sf::Sprite(texBocadilloAbierta);
                        spriteBocadilloAbierta->setPosition(x, y);

                        spriteBocadilloCerrada = new sf::Sprite(texBocadilloCerrada);
                        spriteBocadilloCerrada->setPosition(x, y);

                        cout<<"BOCATAS CHORISO x: "<<x<<endl;
                        cout<<"y: "<<y<<endl;
                        cout<<"----"<<endl;


                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             bocadillo = bocadillo->NextSiblingElement("objectgroup");
         }

        TiXmlElement *pacto = mapTix->FirstChildElement("objectgroup");
        while(pacto){

            nombre=(string) pacto->Attribute("name");

            if(nombre=="DialogoPacto"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = pacto->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


        /***************************SIMPATIZANTE**********************************/

                        if (!texDialogoPacto.loadFromFile("resources/common/dialogoPACTO.png")) {
                                std::cerr << "Error cargando la imagen carcelAbiertaDialog.png";
                                exit(0);
                        }

                        spriteDialogoPacto = new sf::Sprite(texDialogoPacto);
                        spriteDialogoPacto->setPosition(x, y);


                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             pacto = pacto->NextSiblingElement("objectgroup");
         }

        TiXmlElement *ayuda1 = mapTix->FirstChildElement("objectgroup");
        while(ayuda1){

            nombre=(string) ayuda1->Attribute("name");

            if(nombre=="aprendeAndar"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = ayuda1->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


                        texAyuda1 = new sf::Texture();
                        if (!texAyuda1->loadFromFile("resources/common/aprendeAndar.png")) {
                                std::cerr << "Error cargando la imagen aprendeAndar.png";
                                exit(0);
                        }

                        spriteAyuda1 = new sf::Sprite(*texAyuda1);
                        spriteAyuda1->setPosition(x, y);


                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             ayuda1 = ayuda1->NextSiblingElement("objectgroup");
         }

        TiXmlElement *ayuda2 = mapTix->FirstChildElement("objectgroup");
        while(ayuda2){

            nombre=(string) ayuda2->Attribute("name");

            if(nombre=="aprendeSaltar"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = ayuda2->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


                        texAyuda2 = new sf::Texture();
                        if (!texAyuda2->loadFromFile("resources/common/aprendeSaltar.png")) {
                                std::cerr << "Error cargando la imagen aprendeSaltar.png";
                                exit(0);
                        }

                        spriteAyuda2 = new sf::Sprite(*texAyuda2);
                        spriteAyuda2->setPosition(x, y);


                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             ayuda2 = ayuda2->NextSiblingElement("objectgroup");
         }

         TiXmlElement *ayuda3 = mapTix->FirstChildElement("objectgroup");
        while(ayuda3){

            nombre=(string) ayuda3->Attribute("name");

            if(nombre=="aprendeAtacar"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = ayuda3->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


                        texAyuda3 = new sf::Texture();
                        if (!texAyuda3->loadFromFile("resources/common/aprendeAtacar.png")) {
                                std::cerr << "Error cargando la imagen aprendeSaltar.png";
                                exit(0);
                        }

                        spriteAyuda3 = new sf::Sprite(*texAyuda3);
                        spriteAyuda3->setPosition(x, y);


                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             ayuda3 = ayuda3->NextSiblingElement("objectgroup");
         }

          TiXmlElement *ayuda4 = mapTix->FirstChildElement("objectgroup");
        while(ayuda4){

            nombre=(string) ayuda4->Attribute("name");

            if(nombre=="aprendeVotar"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = ayuda4->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


                        texAyuda4 = new sf::Texture();
                        if (!texAyuda4->loadFromFile("resources/common/aprendeVotar.png")) {
                                std::cerr << "Error cargando la imagen aprendeSaltar.png";
                                exit(0);
                        }

                        spriteAyuda4 = new sf::Sprite(*texAyuda4);
                        spriteAyuda4->setPosition(x, y);


                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             ayuda4 = ayuda4->NextSiblingElement("objectgroup");
         }

            TiXmlElement *ayuda5 = mapTix->FirstChildElement("objectgroup");
        texAyuda5 = nullptr;
        while(ayuda5){

            nombre=(string) ayuda5->Attribute("name");

            if(nombre=="aprendeCambiar"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = ayuda5->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());


                        texAyuda5 = new sf::Texture();
                        if (!texAyuda5->loadFromFile("resources/common/aprendeCambiar.png")) {
                                std::cerr << "Error cargando la imagen aprendeSaltar.png";
                                exit(0);
                        }

                        spriteAyuda5 = new sf::Sprite(*texAyuda5);
                        spriteAyuda5->setPosition(x, y);


                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             ayuda5 = ayuda5->NextSiblingElement("objectgroup");
         }

            TiXmlElement *muro = mapTix->FirstChildElement("objectgroup");
        while(muro){

            nombre=(string) muro->Attribute("name");

            if(nombre=="Muro"){
                    cout<<"nombre: "<<nombre<<endl;
                    TiXmlElement *object = muro->FirstChildElement("object");
                    while(object){
                        xString = (string) object->Attribute("x");
                        yString = (string) object->Attribute("y");

                        x=atoi(xString.c_str());
                        y=atoi(yString.c_str());

                        muroX=x;
                        muroY=y;

                         texMuro = new sf::Texture();
                         if (!texMuro->loadFromFile("resources/PSOE/MUROPSOE.png")) {
                                std::cerr << "Error cargando la imagen voto.png";
                                exit(0);
                        }

                        spriteMuro = new sf::Sprite(*texMuro);
                        spriteMuro->setPosition(x, y);

                        object = object->NextSiblingElement("object");
                        filas++;
                    }
                }
             muro = muro->NextSiblingElement("objectgroup");
         }

//     TiXmlElement *properties = colisiones->FirstChildElement("properties");
//     string atributo;
//     while(properties){
//         atributo = properties->FirstChildElement("property")->Attribute("name");
//         cout<<"hola"<<endl;
//     }
//     cout<<"atributo: "<<atributo<<endl;




    //guardamos en filename el spritesheet
//    while(img){
//        filename=(string)img->FirstChildElement("image")->Attribute("source");
//        img=img->NextSiblingElement("tileset");
//    }
    /*cout<<"Gid de las capas"<<endl;
   for(int l=0; l<_numLayers; l++)
    {
       cout<<name[l]<<endl;
        for(int y=0; y<_height; y++)
        {
            for(int x=0; x<_width;x++)
            {
                cout<<_tilemap[l][y][x]<<" ";

                if(x==_width-1)
                {
                    cout<<endl;
                }
            }
        }
   }*/

        //CREACION DEL FONDO

        if(Mundo::Instance()->nivel==1 || Mundo::Instance()->nivel==5 || Mundo::Instance()->nivel==9){
                if (!tex.loadFromFile("resources/PP/background.jpg"))
            {
              std::cerr << "Error cargando la imagen background.jpg";
               exit(0);
            }
        }

        if(Mundo::Instance()->nivel==2 || Mundo::Instance()->nivel==6 || Mundo::Instance()->nivel==10){
               if (!tex.loadFromFile("resources/PSOE/backgroundPSOE.jpg"))
            {
              std::cerr << "Error cargando la imagen background.jpg";
               exit(0);
            }
        }

        if(Mundo::Instance()->nivel==3 || Mundo::Instance()->nivel==7 || Mundo::Instance()->nivel==11){
               if (!tex.loadFromFile("resources/CIUDADANOS/backgroundCS.jpg"))
            {
              std::cerr << "Error cargando la imagen background.jpg";
               exit(0);
            }
        }

        if(Mundo::Instance()->nivel==4 || Mundo::Instance()->nivel==8 || Mundo::Instance()->nivel==12){
               if (!tex.loadFromFile("resources/PODEMOS/backgroundPODEMOS.jpg"))
            {
              std::cerr << "Error cargando la imagen background.jpg";
               exit(0);
            }
        }

        int cuantasVecesDeboPintarElFondo=(Mundo::Instance()->mapa->_tileWidth*Mundo::Instance()->mapa->_width)/Mundo::Instance()->mapa->fondo.getGlobalBounds().width;
        cuantasVecesDeboPintarElFondo=trunc(cuantasVecesDeboPintarElFondo)+1;

        for(int i=0; i<cuantasVecesDeboPintarElFondo; i++){
        fondos.push_back(new sf::Sprite());
        fondos[i]->setTexture(tex);
        fondos[i]->setPosition(Mundo::Instance()->mapa->fondo.getGlobalBounds().width*i, 0);
    }

    delete layer;
    delete data;
    delete name;
    delete suelo;
    delete paredes;
    delete muerte;
    delete plataformas;
    delete plataformas2;
    delete plataformas3;
    delete votos;
    delete enemigosA;
    delete boss;
    delete simpa;
    delete bocadillo;
    delete pacto;
    delete ayuda1;
    delete ayuda2;
    delete ayuda3;
    delete ayuda4;
    delete ayuda5;

}


void Mapa::dibuja(){

    //dibujo los fondos
        for(sf::Sprite* q : fondos){
            Juego::Instance()->window->draw(*q);
        }

    //dibujamos el mapa
    for(int t=0; t<_numLayers; t++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[t][y][x]!=NULL){
                    Juego::Instance()->window->draw(*(_tilemapSprite[t][y][x]));
                }
            }
        }
    }




}

int Mapa::getTile(int posx, int posy){

    int resultado= _tilemap[0][posy/32][posx/32];

    return resultado;
}

//std::vector<sf::RectangleShape*> Mapa::getEnemigosC(sf::RenderWindow& window){
//    for(int j=0; j<arrayEnemigosC.size();j++){
//           window.draw(*arrayEnemigosC[j]);
//    }
//}

//std::vector<sf::RectangleShape*> Mapa::getEnemigosA(sf::RenderWindow& window){
//    for(int j=0; j<arrayEnemigosA.size();j++){
//           window.draw(*arrayEnemigosA[j]);
//    }
//}

void Mapa::dibujaVotos(){
    if(arrayVotos!=NULL){
        for(sf::Sprite* i : *arrayVotos){
             Juego::Instance()->window->draw(*i);
        }
    }
}

void Mapa::dibujaSimpatizante(int politico, int fase){

    if(!simpatizanteLoaded){

        if(politico==1){ //SIMPATIZANTES DE IGLESIAS
            if(fase==1){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/CHAVEZ.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);

            }

            if(fase==2){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/MONEDERO.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);
            }

            if(fase==3){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/ERREJON.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);
            }
        }

        if(politico==2){ //SIMPATIZANTES DE RIVERA
            if(fase==1){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/ARRIMADAS.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);

            }

            if(fase==2){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/BEGONA.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);
            }

            if(fase==3){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/AGUIRRE.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);
            }
        }

        if(politico==3){ //SIMPATIZANTES DE RAJOY
            if(fase==1){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/RITA.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);

            }

            if(fase==2){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/BOTELLA.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);
            }

            if(fase==3){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/BARCENAS.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);
            }
        }

        if(politico==4){ //SIMPATIZANTES DE SANCHEZ
            if(fase==1){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/RUBALCABA.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);

            }

            if(fase==2){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/FELIPEGONZALEZGafas.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);
            }

            if(fase==3){
                texSimpa = new sf::Texture();
                if (!texSimpa->loadFromFile("resources/simpatizantes/ZAPATERO.png")) {
                        std::cerr << "Error cargando la imagen RITA.png";
                        exit(0);
                }

                spriteSimpa = new sf::Sprite(*texSimpa);
                spriteSimpa->setPosition(simpaX, simpaY);
            }
        }
        simpatizanteLoaded = true;
    }

    Juego::Instance()->window->draw(*spriteSimpa);



}

void Mapa::dibujaCarcelCerrada(){
    Juego::Instance()->window->draw(*spriteCarcelCerrada);

}

void Mapa::dibujaCarcelAbierta(){
    Juego::Instance()->window->draw(*spriteCarcelAbierta);
}

void Mapa::dibujaDialogoAbierto(){
    Juego::Instance()->window->draw(*spriteBocadilloAbierta);
}

void Mapa::dibujaDialogoPacto(){
    Juego::Instance()->window->draw(*spriteDialogoPacto);
}

void Mapa::dibujaDialogoCerrado(){
    Juego::Instance()->window->draw(*spriteBocadilloCerrada);
}

void Mapa::dibujaAyuda1(){
    Juego::Instance()->window->draw(*spriteAyuda1);
}

void Mapa::dibujaAyuda2(){
    Juego::Instance()->window->draw(*spriteAyuda2);
}

void Mapa::dibujaAyuda3(){
    Juego::Instance()->window->draw(*spriteAyuda3);
}

void Mapa::dibujaAyuda4(){
    Juego::Instance()->window->draw(*spriteAyuda4);
}

void Mapa::dibujaAyuda5(){
    Juego::Instance()->window->draw(*spriteAyuda5);
}

void Mapa::dibujaMuro(int nivel){

    if(nivel==1 || nivel==5 || nivel==9){ //MURO PP
        if (!texMuro->loadFromFile("resources/PP/MUROPP.png")) {
                std::cerr << "Error cargando la imagen del muro";
                exit(0);
        }
    }

    if(nivel==2 || nivel==6 || nivel==10){ //MURO PSOE
         if (!texMuro->loadFromFile("resources/PSOE/MUROPSOE.png")) {
                std::cerr << "Error cargando la imagen del muro";
                exit(0);
        }
    }
    if(nivel==3 || nivel==7 || nivel==11){ //MURO CS
        if (!texMuro->loadFromFile("resources/CIUDADANOS/MUROCIUDADANOS.png")) {
                std::cerr << "Error cargando la imagen del muro";
                exit(0);
        }
    }
    if(nivel==4 || nivel==8 || nivel==12){ //MURO PODEMOS
        if (!texMuro->loadFromFile("resources/PODEMOS/MUROPODEMOS.png")) {
                std::cerr << "Error cargando la imagen del muro";
                exit(0);
        }

    }

    spriteMuro = new sf::Sprite(*texMuro);
    spriteMuro->setPosition(muroX, muroY);
    Juego::Instance()->window->draw(*spriteMuro);
}

void Mapa::dibujaEnemigosC(){
//    for(int j=0; j<arrayEnemigosC.size();j++){
//           window.draw(arrayEnemigosC[j]->getSprite());
//    }
}

void Mapa::dibujaEnemigosA(){
//    for(int j=0; j<arrayEnemigosA.size();j++){
//           window.draw(arrayEnemigosA[j]->getSprite());
//    }
}

void Mapa::dibujaPlataformas(){
    for(size_t j=0; j<arrayPlataformas.size();j++){
        if(arrayPlataformas[j]->tipo!=2){
            Juego::Instance()->window->draw(arrayPlataformas[j]->spritePlat);
        }
        else
            if(!arrayPlataformas[j]->rota)
                Juego::Instance()->window->draw(arrayPlataformas[j]->spritePlat);


        arrayPlataformas[j]->moves();
    }
}

void Mapa::reconstruirPlataformas(){
    for(size_t j=0; j<arrayPlataformas.size();j++){
        if(arrayPlataformas[j]->rota==true){
            arrayPlataformas[j]->regeneracionPlataforma();
        }
    }
}

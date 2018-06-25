#ifndef CMAP_H
#define CMAP_H
#include <deque>
#include "cfield.h"

/**
* \file cmap.h
* \brief Plik nagłówkowy klasy CMap.
*
*/

//! Klasa symbolizująca obiekt zawierający elementy typu CObject oraz ich typ graficzny CField.
/*!
    Klasa logiczna,definiująca obiekt zawierający liste obiektyw logicznych klasy CObject oraz liste obiektów graficznych typu CField. Zawiera również dwie grające strony typu CGracz oraz metody potrzebne do rozgrywki.
    \param CGracz *player Gracz1, sterowany przez człowieka.
    \param CGracz *PC Gracz 2, sterowany przez komputer.
    \param std::deque <CField*>Lista2 Lista obiektów graficznych.
    \param std::deque <CObject*>Lista Lista obiektów.
*/

class CMap
{
private:
    CGracz *player;                         //!<Gracz1, sterowany przez człowieka.
    CGracz *PC;                             //!<Gracz 2, sterowany przez komputer.

    void del_object(CObject *obj);          //!<Usuwa obiekt CObiekt z listy logicznej.
    void del_field(CField *obj);            //!Usuwa obiekt CField z listy graficznej.

public:
    std::deque <CField*>Lista2;             //!<Lista obiektów graficznych.
    std::deque <CObject*>Lista;             //!<Lista obiektów.

    CMap();                                 //!<Konstruktor.
    ~CMap();                                //!<Dekonstruktor.
    void create_unit();                     //!<Dodaje jednostki do mapy.
    CObject *get_objects_act();             //!<Zwraca obiekt aktualnie wybrany przez gracza.
    void update();                          //!<Usuwa obiekty nieistniejące z listy.
    void set_object(CObject *obj);          //!<Dodaje obiekt do Listy obiektów i tworzy obiekt graficzny.
    void reset();                           //!<Resetuje.
    CGracz* get_gracz(std::string nazwa);   //!<Zwraca nazew gracza.


    std::deque<CObject*>podaj_obiekty_zasieg(CMovable *obj, int _zasieg, bool tryb);
                                            //!<Zwraca liste obiektów w zasiegu obiektu zadanego.

    std::deque<CObject*>get_objects(int x, int y);
                                            //!<Zwraca obiekty o połozeniu x i y.
};
/////////////////////////////////////////////////////////////////////////////////////
#endif // CMAP_H

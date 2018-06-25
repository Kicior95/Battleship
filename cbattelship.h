#ifndef CBATTELSHIP_H
#define CBATTELSHIP_H
#include "cmap.h"

/**
* \file cbattelship.h
* \brief Plik nagłówkowy klasy  CBattelship.
*
*/

//!Główna klasa logiczna programu.
/*!
Główna klasa programu, zawierająca:
   \param CMap Mapa Mapa gry.
   \param bool czy_koniec()Zmienna logiczna
   \param int licznik Licznik tur wykonanych przez gracza.
   \param CObject *End Wybray obiekt docelowy.
   \param CObject *Akt Wybrany obiekt inicjujący.
*/



class CBattelship
{
public:
    CBattelship(int faza_ruch=1,int _licznik=0);    //!<Konstruktor.
    CMap *Mapa;                                      //!<Mapa gry.
    bool czy_koniec();                              //!<Zmienna logiczna


private:
    int licznik;                //!<Licznik tur wykonanych przez gracza.
    CObject *End;               //!<Wybray obiekt docelowy.
    CObject *Akt;               //!<Wybrany obiekt inicjujący.
    int faza_ruch;              //!<Faza wykonywanej tury.
    void tura(CGracz *gracz);   //!<Tura gracza CGracz *gracz.


public slots:
    void dzialaj();             //!<Głowny program.
};
#endif // CBATTELSHIP_H

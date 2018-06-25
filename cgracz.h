#ifndef CGRACZ_H
#define CGRACZ_H
#include <string>

/**
* \file cgracz.h
* \brief Plik nagłówkowy klasy bazowej CGracz.
*
*/

//! Klasa określająca zawodnika.
/*!
 Klasa definiująca obiekt Gracza, posiadającego parametry:
    \param std::string nazwa Nazwa gracza.
    \param int liczba_jed Liczba jednostek gracza.
*/
class CGracz
{
private:
    std::string nazwa;                  //!<Nazwa gracza.
    int liczba_jedn;                    //!<Liczba jednostek gracza.

public:
    CGracz(std::string _nazwa="");      //!<Konstruktor.
    ~CGracz();                          //!<Dekonstruktor.
    std::string get_nazwa();            //!<Zwraca nazwe gracza.
    void add_liczba_jedn();             //!<Liczba jednostek ++.
    void min_liczba_jedn();             //!<Liczba jednostek --.
    int get_liczba_jedn();              //!<Zwraca lizbe jednostek.

};
#endif // CGRACZ_H

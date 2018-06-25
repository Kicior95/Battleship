#ifndef CFIELD_H
#define CFIELD_H

#include <QProgressBar>
#include <QPushButton>
#include <QImage>
#include "cobject.h"

/**
* \file cfield.h
* \brief Plik nagłówkowy klasy bazowej CField oraz wszytskich klas pochodnych.
*
*/

//!   Podstawowa klasa symbolizująca obiekt graficzny zawierający obiekt logiczny typu CObject.
/*!
    Klasa graficzna, definiująca parametry graficzne logicznego obiektu CObject.
    \param QImage img Obraz podstawowy.
    \param QImage img_2 Obraz po zadaniu akcji.
    \param CObject *typ Typ logiczny obiektu.
*/

class CField : public QPushButton
{
    Q_OBJECT

friend class MyWindow;
protected:
    void paintEvent(QPaintEvent *pEvent);   //!<Funkcja rysująca.
    QImage img;                             //!<Obraz podstawowy.
    QImage img_2;                           //!<Obraz po zadaniu akcji.
    CObject *typ;                           //!<Typ logiczny obiektu.
public:
    CField(QWidget *parent = 0);            //!<Konstruktor.
    ~CField();                              //!<Dekonstruktor.
    int get_x();                            //!<Zwraca położenie x CObject.
    int get_y();                            //!<Zwraca położenie y CObject.
    int get_hp();                           //!<Zwraca wartość zycia CUnit.
    CObject *get_typ();                     //!<Zwraca obiekt logiczny.


signals:
    void mouseClicked(int, int);            //!<Sygnał wybrania obiekty klasy CField.

private slots:
    void clickEvent();                      //!<Akcja wykonywana po działaniu gracza.
};

//! Klasa symbolizująca obiekt graficzny przedstawiający obiekt typu CWater.
/*!
    Klasa graficzna, definiująca parametry graficzne logicznego obiektu CWater.

*/
class CGraphicWater  :public CField
{
public:
    CGraphicWater (CWater *objekt=0); //!<Konstruktor.
};
//! Klasa symbolizująca obiekt graficzny przedstawiający obiekt typu CRock.
/*!
    Klasa graficzna, definiująca parametry graficzne logicznego obiektu CRock.

*/
class CGraphicRock :public CField
{
public:
    CGraphicRock (CRock *objekt=0); //!<Konstruktor.
};
//! Klasa graficzna obiektów posiadająca cechy CUnit.
/*!
    Klasa graficzna,przedstawiająca wartość poziomu zycia jednostki CUnit.
    \param QProgressBar *wsk ProgressBar wskazujacy poziom zycia.

*/
class CGraphicUnit :public CField
{   
public:
    CGraphicUnit();         //!<Konstruktor.
    ~CGraphicUnit();        //!<Dekonstruktor.
    QProgressBar *wsk;      //!<ProgressBar wskazujacy poziom zycia.
    void update();          //!<Aktualizacja ProgresBar.
    bool czyj();            //!<Zwraca przynależność do Gracza.
};
//! Klasa symbolizująca obiekt graficzny przedstawiający obiekt typu CFregata.
/*!
    Klasa graficzna, definiująca parametry graficzne logicznego obiektu CFregata.

*/
class CGraphicFregata :public CGraphicUnit
{
public:
CGraphicFregata (CFregata *objekt=0);   //!<Konstruktor.
~CGraphicFregata();                     //!<Dekonstruktor.
};
//! Klasa symbolizująca obiekt graficzny przedstawiający obiekt typu CDestroyer.
/*!
    Klasa graficzna, definiująca parametry graficzne logicznego obiektu CDestroyer.

*/
class CGraphicDestroyer :public CGraphicUnit
{

public:
    CGraphicDestroyer (CDestroyer *objekt=0);   //!<Konstruktor.
    ~CGraphicDestroyer();                       //!<Dekonstruktor.
};

#endif // CFIELD_H

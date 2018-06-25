#ifndef COBJECT_H
#define COBJECT_H
#include <string>
#include <cgracz.h>
#include<deque>

class CMap;
/**
* \file cobject.h
* \brief Plik nagłówkowy klasy bazowej CObject oraz wszytskich klas pochodnych.
*
*/



//!   Podstawowa klasa symbolizująca obiekt istniejący w przestrzeni w określonym stanie logicznym.
/*!
    Klasa logiczna, definiująca nierzeczywisty obiekt o zadanym położeniu i parametrach stanu.
    \param int x Pozycja na osi odciętych w układzie kartezjańskim.
    \param int y Pozycja na osi rzędnych w układzie kartezjańskim.
    \param  bool pos_a  Możliwość ataku.
    \param  bool pos_r  Możliwość ruchu.
    \param bool active Aktywność obiektu.
    \param bool enable Dostępność obiektu.
*/

class CObject
{

protected:
    CMap *Mapa;
private:
    int x;                      //!<Pozycja x obiektu.
    int y;                      //!<Pozycja y obiektu.
    bool pos_a;                 //!<Możliwość ataku.
    bool pos_r;                 //!<Możliwość ruchu.
    bool active;                //!<Aktywność obiektu.
    bool enable;                //!<Dostępność obiektu.

public:
    CObject(CMap *_Mapa,int _x=0, int _y=0, bool _active=0, bool _pos=0, bool _pos_a=0, bool _enable=1);
                                //!<Konstruktor.
    ~CObject();                 //!<Dekonstruktor.

    int get_x();                //!<Zwraca x.
    int get_y();                //!<Zwraca y.
    void set_x(int _x);         //!<Ustawia x.
    void set_y(int _y);         //!<Ustawia y.
    bool get_active();          //!<Zwraca aktywność.
    void set_active();          //!<Ustawia aktywność.
    bool get_pos_a();           //!<Zwraca możliwość ataku.
    void set_pos_a();           //!<Ustawia możliwość ataku.
    bool get_pos_r();           //!<Zwraca możliwość ruchu.
    void set_pos_r();           //!<Ustawia możliwość ruchu.


    void reset();               //!<Ustawia parametry obiektu do wartości domyślnych.
    void set_enable(bool _enable); //!<Ustawia dostępność obiektu.
    bool get_enable();             //!<Zwraca dostępność obiektu.
    virtual void   do_it(CObject *obj)=0; //!<Funkcja wirtualna. Działanie obiektu.
};

//!   Klasa obiektów nieruchomych.
/*!
    Klasa logiczna, definiująca nierzeczywisty obiekt nie posiadający możliwości ruchu. Klasa pochodna od klasy bazowej CObjekt.

*/

class CNonMovable :public CObject
{
public:
    CNonMovable(CMap *_Mapa, int _x=999, int _y=999);    //!<Konstruktor.
    ~CNonMovable();                         //!<Dekonstruktor.
};

//!   Klasa przedstawiająca obiekt symbolizuący wode.
/*!
    Klasa logiczna, definiująca rzeczywisty obiekt nie posiadający możliwości ruchu. Klasa przedstawiająca obiekt określany jako woda.

*/
class CWater :public CNonMovable
{
public:
    CWater(CMap *_Mapa, int _x=999, int _y=999);         //!<Konstruktor.
    ~CWater();                              //!<Dekonstruktor.
    void do_it(CObject *obj);               //!<Akcja obiektu typu woda .

};
//!   Klasa przedstawiająca obiekt symbolizuący skałe.
/*!
    Klasa logiczna, definiująca rzeczywisty obiekt nie posiadający możliwości ruchu. Klasa przedstawiająca obiekt określany jako skała.

*/
class CRock :public CNonMovable
{
public:
    CRock(CMap *_Mapa, int _x=999, int _y=999);          //!<Konstruktor.
    ~CRock();                               //!<Dekonstruktor.
    void do_it(CObject *obj);               //!<Akcja obiektu typu skała.

};

//!   Klasa obiektów ruchomych.
/*!
    Klasa logiczna, definiująca nierzeczywisty obiekt  posiadający możliwości ruchu. Klasa pochodna od klasy bazowej CObjekt.
    \param int zasieg_ruchu Wartość całkowita pól o ile może sie przemieścić obiekt w jednej turze.

*/
class CMovable :public CObject
{

protected:
    int zasieg_ruchu;                       //!<Zasieg ruchu jednostek.
public:
    CMovable(CMap *_Mapa, int _x=999, int _y=999);       //!<Konstruktor.
    ~CMovable();                            //!<Dekonstruktor.
    int get_zasieg_ruchu();                 //!<Zwraca zasieg ruchu jednostki.
    std::deque<CObject*>Lista_ruchu;        //!<Lista obiektów CObietk w zasiegu ruchu.
    void aktualizuj_ruch();                 //!<Aktualizuje położenie jednostek.
};

//!   Klasa obiektów posiadających umiejętność ataku.
/*!
    Klasa logiczna, definiująca nierzeczywisty obiekt  posiadający możliwości ruchu oraz ataku. Obiekt posiada następujące parametry:
    \param CGracz *Gracz Gracz posiadający tą jednostke.
    \param int zycie Poziom zycia jednostki.
    \param int moc Poziom mocy ataku jednostki.
    \param int zasieg_strzal Zasieg strzału jednostki.

*/
class CUnit:public CMovable
{
protected:
    CGracz *Gracz;                           //!<Gracz posiadający tą jednostke
    int zycie;                               //!<Poziom zycia jednostki..
    int moc;                                 //!<Poziom mocy ataku jednostki.
    int zasieg_strzal;                       //!<Zasieg strzału jednostki.

public:
    CUnit(CMap *_Mapa,int _x=999, int _y=999,CGracz *_Gracz=new CGracz);
                                            //!<Konstruktor.
    ~CUnit();                               //!<Kekonstruktor.
    CGracz* get_gracz();                    //!<Zwraca gracza.
    int get_zycie();                        //!<Zwraca poziom zycia.
    int get_moc();                          //!<Zwraca poziom mocy ataku.
    int get_zasieg_strzal();                //!<Zwraca zasieg strzału jednostki.
    void hit(int _moc, int _odl);           //!<Otrzymanie obrażeń od jednostki.
    std::deque<CObject*>Lista_ataku;
    void aktualizuj_atak();
};

//!   Klasa obiektów rzeczywistych, symbolizująca statek Fregata.
/*!
    Klasa logiczna, definiująca rzeczywisty obiekt  posiadający możliwości ruchu oraz ataku. Obiekt ma z góry zadane parametry.         Brak możliwości zmiany.

*/
class CFregata :public CUnit
{
public:
    CFregata(CMap *_Mapa, int _x=999, int _y=999, CGracz *gracz=new CGracz);
                                            //!<Konstruktor
    ~CFregata();                            //!<Dekonstruktor
    void do_it(CObject *obj);               //!<Akcja obiektu typu Fregata
};
//!   Klasa obiektów rzeczywistych, symbolizująca statek Niszczyciel.
/*!
    Klasa logiczna, definiująca rzeczywisty obiekt  posiadający możliwości ruchu oraz ataku. Obiekt ma z góry zadane parametry.         Brak możliwości zmiany.

*/
class CDestroyer :public CUnit
{
public:
    CDestroyer(CMap *Mapa, int _x=999, int _y=999, CGracz *gracz=new CGracz);
                                            //!<Konstruktor.
    ~CDestroyer();                          //!<Dekonstruktor.
    void do_it(CObject *obj);               //!<Akcja obiektu typu Fregata.
};
#endif // COBJECT_H

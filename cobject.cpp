#include "cobject.h"
#include <typeinfo>
#include <cmath>
#include "cmap.h"

/**
* \file cobject.cpp
* \brief Plik źródłowy klasy bazowej CObject oraz wszytskich klas pochodnych.
*
*/

/*!
Konstruktor klasy CObject.
*/

CObject::CObject(CMap *_Mapa, int _x, int _y, bool _active, bool _pos_r, bool _pos_a, bool _enable){
    x=_x;
    y=_y;
    active=_active;
    pos_r=_pos_r;
    pos_a=_pos_a;
    enable=_enable;
    Mapa=_Mapa;
}
/*!
Dekosntruktor klasy CObject.
*/
CObject::~CObject() {}

/*!
Funkcja zwracająca wartość x w przestrzeni 2D.
\return int x.
*/

int CObject:: get_x(){
    return x;
}
/*!
Funkcja zwracająca wartość y w przestrzeni 2D.
\return int y.
*/
int CObject::get_y(){
  return y;
}
/*!
Funkcja ustawiająca wartość x w przestrzeni 2D.
\param _x Wartość parametru x.
*/
void CObject:: set_x(int _x){
    x=_x;
}
/*!
Funkcja ustawiająca wartość int y w przestrzeni 2D.
\param _y Wartość parametru int y.
*/
void CObject:: set_y(int _y){
    y=_y;
}
/*!
Funkcja zwracająca wartosc logiczna parametru bool active
\return Wartość logiczna active.
*/
bool CObject:: get_active()
{
    return active;
}
/*!
Funkcja ustawiająca wartosc logiczna parametru  bool active

*/
void CObject:: set_active()
{
     active=1;
}
/*!
Funkcja resetująca wartości bool active,  bool pos_r,  bool pos_a na wartości domyślne.

*/
void CObject::reset()
{
    active=false;
    pos_r=false;
    pos_a=false;
}
/*!
Funkcja zwracająca wartosc logiczna parametru  pos_a.
\return Wartość logiczna  pos_a.
*/
bool CObject::get_pos_a()
{
    return pos_a;
}
/*!
Funkcja ustawiająca wartosc logiczna parametru  pos_a.

*/
void CObject::set_pos_a()
{
    pos_a=true;
}
/*!
Funkcja zwracająca wartosc logiczna parametru  pos_r.
\return Wartość logiczna pos_r.
*/
bool CObject::get_pos_r()
{
    return pos_r;
}
/*!
Funkcja ustawiająca wartosc logiczna parametru  pos_r.

*/
void CObject::set_pos_r()
{
    pos_r=true;
}
/*!
Funckja ustawiająca wartosc logiczna parametru  enable.

*/
void CObject::set_enable(bool _enable)
{
    enable=_enable;
}
/*!
Funkcja ustawiająca wartosc logiczna parametru  pos_r.

*/
bool CObject::get_enable()
{
    return enable;
}
/*!
Konstruktor klasy CNonMovable.
*/
CNonMovable::CNonMovable(CMap *_Mapa,int _x, int _y):CObject(_Mapa,_x,_y)
{

}
/*!
Dekonstruktor klasy CNonMovable.
*/
CNonMovable::~CNonMovable(){}
/*!
Konstruktor klasy CWater.
*/
CWater::CWater(CMap *_Mapa,int _x, int _y):CNonMovable(_Mapa,_x,_y)
{

}
/*!
Dekonstruktor klasy CWater.
*/
CWater::~CWater(){}
/*!
Funkcja określająca akcje obiektu typu CWater.
*/
void CWater::do_it(CObject *obj)
{

}
/*!
Konstruktor klasy CRock.
*/
CRock::CRock(CMap *_Mapa,int _x, int _y):CNonMovable(_Mapa,_x,_y)
{

}
/*!
Dekonstruktor klasy CRock.

*/
CRock::~CRock(){}
/*!
Funkcja określająca akcje obiektu typu CRock.
*/
void CRock::do_it(CObject *obj)
{

}
/*!
Konstruktor klasy CMovable.
*/
CMovable::CMovable(CMap *_Mapa,int _x, int _y):CObject(_Mapa,_x,_y)
{

}
/*!
Dekonstruktor klasy CMovable.

*/
CMovable::~CMovable(){}
int CMovable:: get_zasieg_ruchu()
{
    return zasieg_ruchu;
}


 void CMovable::aktualizuj_ruch()
 {
this->Lista_ruchu=this->Mapa->podaj_obiekty_zasieg(this,this->zasieg_ruchu,0);
 }




/*!
Konstruktor klasy CUnit.
*/
CUnit::CUnit(CMap *_Mapa,int _x, int _y, CGracz *_Gracz ):CMovable(_Mapa,_x,_y)
{
Gracz=_Gracz;

Gracz->add_liczba_jedn();
}
/*!
Dekonstruktor klasy CUnit.

*/
CUnit::~CUnit()
{

}
/*!
Funckja zwracająca wartosc parametru gracz.
\return Zwraca wartość CGracz gracz.

*/
CGracz* CUnit:: get_gracz()
{
    return this->Gracz;
}
/*!
Funckja zwracająca wartosc parametru zycie.
\return Zwraca wartość int zycie.

*/
int CUnit:: get_zycie()
{
    return this->zycie;
}
/*!
Funckja zwracająca wartosc parametru moc.
\return Zwraca wartość int moc.

*/
int CUnit:: get_moc()
{
    return this->moc;
}
/*!
Funckja zwracająca wartosc parametru zasieg_strzal.
\return Zwraca wartość int zasieg_strzal.

*/
int CUnit::get_zasieg_strzal()
{
    return this->zasieg_strzal;
}

/*!
Funckja realizująca obniżenie poziomu życia jednostki typu CUnit o zadaną wartość.
*/
void CUnit::hit(int _moc, int _odl)
{
    this->zycie=floor(((this->zycie)- (_moc/_odl)));

}

void CUnit:: aktualizuj_atak()
{
 this->Lista_ataku=this->Mapa->podaj_obiekty_zasieg(this,this->zasieg_strzal,1);
}


/*!
Konstruktor klasy CFregata.
*/

CFregata::CFregata(CMap *_Mapa,int _x, int _y, CGracz *gracz) :CUnit(_Mapa,_x,_y,gracz)
{
   this->zycie=100;
   this->moc=50;
   this->zasieg_strzal=3;
   this->zasieg_ruchu=2;
}
/*!
Dekonstruktor klasy CFregata.
*/
CFregata::~CFregata()
{

}
/*!
Funkcja określająca akcje obiektu typu CFregata.
*/
void CFregata::do_it(CObject *obj)
{   this->aktualizuj_atak();
    this->aktualizuj_ruch();

    if(obj==this)
    {
        int petla=1;
        while(petla)
        {
            size_t rh=(std::rand() % this->Lista_ruchu.size());
            CObject *zd2=this->Lista_ruchu[rh];
            int x=zd2->get_x();
            int y=zd2->get_y();
            if(this->Mapa->get_objects(x,y).size()==1)
            {
                obj=zd2;
                petla=0;
            }
        }

      for( size_t z = 0; z < this->Lista_ataku.size(); z++ )
      {
          CObject *d=this->Lista_ataku[z];
          CUnit *d1 = dynamic_cast<CUnit*>(d);
  if(d1->get_gracz()->get_nazwa()!="PC")
          obj=d1;
       }
    }
    if(typeid(*obj).name()==typeid(CWater).name())
    {
        this->set_x(obj->get_x());
        this->set_y(obj->get_y());
    }

  if(dynamic_cast<CUnit*>(obj))
  {
      CUnit *f2 = dynamic_cast<CUnit*>(obj);

      int odl;
      if(abs(f2->get_x()-this->get_x())>abs(f2->get_y()-this->get_y()))
      {
          odl=abs(f2->get_x()-this->get_x());
      }
      else
          odl=abs(f2->get_y()-this->get_y());
  f2->hit(this->get_moc(),odl);

  }
}
/*!
Konstruktor klasy CDestroyer.
*/
CDestroyer::CDestroyer(CMap *_Mapa,int _x, int _y, CGracz *gracz) :CUnit(_Mapa,_x,_y,gracz)
{
    this->zycie=100;
    this->moc=300;
    this->zasieg_strzal=6;
    this->zasieg_ruchu=1;
}
/*!
Dekonstruktor klasy CDestroyer.
*/
CDestroyer::~CDestroyer(){}
/*!
Funkcja określająca akcje obiektu typu CDestroyer.
*/
void CDestroyer::do_it(CObject *obj)
{
    this->aktualizuj_atak();
    this->aktualizuj_ruch();

    if(obj==this)
    {
        int petla=1;
        while(petla)
        {
            size_t rh=(std::rand() % this->Lista_ruchu.size());
            CObject *zd2=this->Lista_ruchu[rh];
            int x=zd2->get_x();
            int y=zd2->get_y();
            if(this->Mapa->get_objects(x,y).size()==1)
            {
                obj=zd2;
                petla=0;
            }
        }

      for( size_t z = 0; z < this->Lista_ataku.size(); z++ )
      {
          CObject *d=this->Lista_ataku[z];
          CUnit *d1 = dynamic_cast<CUnit*>(d);
  if(d1->get_gracz()->get_nazwa()!="PC")
          obj=d1;
       }
    }



    if(typeid(*obj).name()==typeid(CWater).name())
    {
        this->set_x(obj->get_x());
        this->set_y(obj->get_y());
    }


  if(dynamic_cast<CUnit*>(obj))
  {
      CUnit *f2 = dynamic_cast<CUnit*>(obj);

      int odl;
      if(abs(f2->get_x()-this->get_x())>abs(f2->get_y()-this->get_y()))
      {
          odl=abs(f2->get_x()-this->get_x());
      }
      else
          odl=abs(f2->get_y()-this->get_y());
           f2->hit(this->get_moc(),odl);

  }

}

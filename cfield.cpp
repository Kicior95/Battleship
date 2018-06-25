#include"cfield.h"
#include <QPainter>
#include <QProgressBar>
#include <typeinfo>

/**
* \file cfield.cpp
* \brief Plik źródłowy klasy bazowej CField oraz wszytskich klas pochodnych.
*
*/

/////////////////////////////////////////////////////////////////////////////////////////
/*!
  Funkcja określająca konstruktor klasy CField.
*/
CField::CField(QWidget *parent) :QPushButton(parent)
{
}
/*!
  Funkcja określająca dekonstruktor klasy CField.
*/
CField::~CField(){}
/*!
  Funkcja rysująca, wykonywana po modyfikacji danego obiektu klasy CField.
*/
void CField::paintEvent(QPaintEvent *pEvent ){
    QPushButton::paintEvent(pEvent);

    QPainter painter( this );





    if((this->get_typ())->get_pos_r())
    {

        if(typeid(*this).name()==typeid(CGraphicWater).name())
        {

        img_2.load((QString)":/morze_2.png");

        painter.drawImage(width()/2-img_2.width()/2, height()/2-img_2.height()/2,img_2);
        }
        else  if(typeid(*this).name()==typeid(CGraphicRock).name())
        {
        img_2.load((QString)":/rock_2.png");

        painter.drawImage(width()/2-img_2.width()/2, height()/2-img_2.height()/2,img_2);
        }
        else  if(typeid(*this).name()==typeid(CGraphicFregata).name())
        {

        img_2.load((QString)":/statek2_2.png");

        painter.drawImage(width()/2-img_2.width()/2, height()/2-img_2.height()/2,img_2);
        }
        else  if(typeid(*this).name()==typeid(CGraphicDestroyer).name())
        {

        img_2.load((QString)":/destr_2.jpg");

        painter.drawImage(width()/2-img_2.width()/2, height()/2-img_2.height()/2,img_2);
        }

    }
    else if(this->get_typ()->get_pos_a())

    {
        img_2.load((QString)":/statek_cel.png");

        painter.drawImage(width()/2-img_2.width()/2, height()/2-img_2.height()/2,img_2);
    }
        else

   painter.drawImage(width()/2-img.width()/2, height()/2-   img.height()/2,img);


}
/*!
  Funckja wykonywana jako SLOT. Wykonywana po wybraniu przez uzytkownika obiektu klasy CField.
  Wykonuje akcje zmiany parametry active w obiekcie typu CObiect.
*/
void CField::clickEvent()
{
this->typ->set_active();
}
/*!
  Funckja zwracająca parametr położenia w przestrzeni kartezjańskiej obiektu CObject.
  \return Zwraca wartość parametry int x obiektu klasy CObject.
*/
int CField::get_x()
{
    return this->typ->get_x();
}
/*!
  Funckja zwracająca parametr położenia w przestrzeni kartezjańskiej obiektu CObject.
  \return Zwraca wartość parametry int y obiektu klasy CObject.
*/
int CField::get_y()
{
    return this->typ->get_y();


}
/*!
  Funckja zwracająca obiekt klasy CObject.
  \return Zwraca obiekt typu CObject.
*/
CObject* CField::get_typ()
{
    return this->typ;
}
/*!
  Funckja zwracająca wartość życia obiekty klasy CUnit. Jeżeli typ obiektu inny zwraca wartość 999.
  \return Zwraca wartość punktów życia obiektu klasy CUnit.
*/
int CField::get_hp()
 {
     CObject *w=this->get_typ();

     if(dynamic_cast<CUnit*>(w))
     {
         CUnit *w1=dynamic_cast<CUnit*>(w);
         if(w1->get_zycie()<0)
         {
         return 0;
         }
         else
             return w1->get_zycie();
     }
     else
         return 999;
}

/*!
  Funckja określająca konstruktor klasy CGraphicWater.
   CWater *objekt Obiekt logiczny klasy CWater.

*/

/////////////////////////////////////////////////////////////////////////////////////////

CGraphicWater::CGraphicWater( CWater *objekt) :CField()
{
    typ=objekt;
    QImage imga;
    imga.load((QString)":/morze.png");

    this->img=imga;

}
/*!
  Funckja określająca konstruktor klasy CGraphicRock.
   CRock *objekt Obiekt logiczny klasy CRock.

*/
CGraphicRock::CGraphicRock( CRock *objekt) :CField()
{
    typ=objekt;
    QImage imga;
    imga.load((QString)":/rock.png");
    this->img=imga;

}
/////////////////////////////////////////////////////////////////////////////////////////////
/*!
  Funckja określająca konstruktor klasy CGraphicFregata.
   CFregata *objekt Obiekt logiczny klasy CFregata.

*/
CGraphicFregata::CGraphicFregata( CFregata *objekt) :CGraphicUnit()
{
    typ=objekt;
    QImage imga;

    CUnit *w=dynamic_cast<CUnit*>(typ);
if(w->get_gracz()->get_nazwa()=="PC")
{
    imga.load((QString)":/statek_2.png");
}
else
    imga.load((QString)":/statek.png");

    this->img=imga;

}
/*!
  Funkcja określająca dekonstruktor klasy CGraphicFregata.
*/
CGraphicFregata::~CGraphicFregata(){}
/*!
  Funckja określająca konstruktor klasy CGraphicDestroyer.
   CDestroyer *objekt Obiekt logiczny klasy CDestroyer.

*/
CGraphicDestroyer::CGraphicDestroyer( CDestroyer *objekt) :CGraphicUnit()
{
    typ=objekt;
    QImage imga;


    CUnit *w=dynamic_cast<CUnit*>(typ);
if(w->get_gracz()->get_nazwa()=="PC")
{
    imga.load((QString)":/destr2.jpg");
}
else
    imga.load((QString)":/destr.jpg");

    this->img=imga;

}

/*!
  Funkcja określająca dekonstruktor klasy CGraphicDestroyer.
*/
CGraphicDestroyer::~CGraphicDestroyer()
{


}
/*!
  Funkcja określająca konstruktor klasy CGraphicUnit.
*/

CGraphicUnit::CGraphicUnit() :CField()
{
    QProgressBar *wsk1=new QProgressBar;
    wsk=wsk1;
    wsk->setMaximum(200);


}

/*!
  Funkcja zwracająca informacje o przynależności obiektu do danego gracza.
  /return Zwraca wartość true jeżeli typ obiektu CUnit należy do gracza PC. Zwraca false jeżeli do Player.
*/
 bool CGraphicUnit:: czyj()
 {
 CObject *w=this->get_typ();
 CUnit *w1=dynamic_cast<CUnit*>(w);
 if(w1->get_gracz()->get_nazwa()=="PC")
 {
     return 1;
 }
 else return 0;
 }
 /*!
   Funkcja określająca dekonstruktor klasy CGraphicUnit.
 */
CGraphicUnit::~CGraphicUnit()
{

}
/*!
  Funkcja zmieniająca wartość liczbową wskaźnika typu ProgresBar na aktualna wartość punktów życia jednostki.
*/
void CGraphicUnit::update()
{

    int x=this->get_hp();
    if(x<0)
    {
        wsk->setValue(0);

    }
    else
    wsk->setValue(x);


}


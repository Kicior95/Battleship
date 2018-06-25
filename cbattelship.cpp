#include "cbattelship.h"
#include <typeinfo>


/**
* \file cbattelship.cpp
* \brief Plik źródłowy klasy  CBattelship.
*
*/

/*!
   Konstruktor klasy CBattelship. Tworzy domyślną mape oraz dodaje domyślne jednostki.
*/

CBattelship::CBattelship(int _faza_ruch, int _licznik)
{
    faza_ruch=_faza_ruch;
    licznik=_licznik;
    CMap *_mapa=new CMap;
    Mapa=_mapa;
    Mapa->create_unit();
}
/*!
   Główna funkcja programu. Funckja wywołuje tury kolejnych graczy.
   \see void CBattelship::tura(CGracz *gracz)
*/
void CBattelship::dzialaj()
{
    if(licznik<this->Mapa->get_gracz("Player")->get_liczba_jedn())
    {
    tura(this->Mapa->get_gracz("Player"));
    }
    else
    {
        tura(this->Mapa->get_gracz("PC"));

        licznik=0;
    }
}

/*!
   Funckja sprawdzająca stan liczbowy jednostek graczy. Jeżeli jeden z Graczy nie posiada jednostek CUnit to zostaje zwrócona wartość 0 oznaczająca koniec gry.
   \return Zwraca 1 jeżeli Gracze posiadają jednostki CUnit. Zwraca 0 jeżeli Gracz nie posiada jednostek CUnit.

*/
bool CBattelship::czy_koniec()
{
    if(this->Mapa->get_gracz("PC")->get_liczba_jedn()==0)
        return 0;
    else
    if(this->Mapa->get_gracz("Player")->get_liczba_jedn()==0)
        return 0;
    else
        return 1;
}

/*!
  Funkcja wykonująca ture zawodnika.
   CGracz* gracz Wskaźnik na gracza wykonującego ture.
*/
void CBattelship::tura(CGracz *gracz)
{
    if(gracz==this->Mapa->get_gracz("Player"))
    {
        if(faza_ruch%2==1)
            {
            CObject *w=this->Mapa->get_objects_act();
            this->Akt=w;
            this->Mapa->reset();

            if(CUnit *f = dynamic_cast<CUnit*>(w))
           {
                    if(f->get_gracz()==gracz&&f->get_enable())
                        {
                            f->aktualizuj_ruch();
                            f->aktualizuj_atak();
                            for( size_t z = 0; z <f->Lista_ruchu.size(); z++ )
                            {
                                CObject *d=f->Lista_ruchu[z];
                                d->set_pos_r();
                             }
                            for( size_t z = 0; z < f->Lista_ataku.size(); z++ )
                            {
                                CObject *d=f->Lista_ataku[z];
                                CUnit *d1 = dynamic_cast<CUnit*>(d);
                        if(d1->get_gracz()!=gracz)
                                d->set_pos_a();
                             }
                            faza_ruch++;
                        }
            }
        }
    else if(faza_ruch%2==0)
        {
            CObject *w=this->Mapa->get_objects_act();
            this->End=w;
        if(w->get_pos_a()||w->get_pos_r())
            {
            Akt->do_it(End);
            Akt->set_enable(false);
            this->licznik++;
            }
            faza_ruch=1;
            this->Mapa->reset();
        }
    }
    else if(gracz==this->Mapa->get_gracz("PC"))
    {
            for( size_t z = 0; z < this->Mapa->Lista.size(); z++ )
            {

             CObject *w=this->Mapa->Lista[z];
             if(CUnit *f = dynamic_cast<CUnit*>(w))
             {
                f->aktualizuj_atak();
                f->aktualizuj_ruch();

                  if(f->get_gracz()==this->Mapa->get_gracz("Player"))
                  {
                      w->set_enable(true);
                  }
                  if(f->get_gracz()->get_nazwa()=="PC")
                  {
                    this->Akt=w;
                    Akt->do_it(Akt);
                  }


             this->Mapa->reset();
        }
       }
    }
}

#include "cmap.h"
#include <typeinfo>

/**
* \file cmap.cpp
* \brief Plik źródłowy klasy CMap.
*
*/
/*!
Konstruktor klasy CMap.
*/
CMap::CMap()
{
    CGracz *w=new CGracz("PC");
    CGracz *p=new CGracz("Player");
    player=p;
    PC=w;


}
/*!
Dekonstruktor klasy CMap.
*/
CMap::~CMap(){}
/*!
Funckja dodająca do mapy jednostki typu CUnit.
\see set_object(CObject*)
*/
void CMap::create_unit()
{


    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if((i==2&&j==1)||(i==3&&j==2)||(i==3&&j==1)||(i==4&&j==3)||(i==3&&j==4)||(i==8&&j==8)||(i==7&&j==8)||(i==8&&j==7)||(i==6&&j==3)||(i==4&&j==2))
            {
               CRock *w=new CRock(this,i,j);
               this->set_object(w);
            }
            else
            {
           CWater *w=new CWater(this,i,j);
           this->set_object(w);
            }
        }
    }
    CFregata *g1=new CFregata(this,6,1,player);
    this->set_object(g1);

    CFregata *g2=new CFregata(this,8,1,player);
    this->set_object(g2);

    CFregata *g3=new CFregata(this,8,3,player);
    this->set_object(g3);



    CFregata *g4=new CFregata(this,1,8,PC);
    this->set_object(g4);

    CFregata *g5=new CFregata(this,1,6,PC);
    this->set_object(g5);

    CFregata *g6=new CFregata(this,3,8,PC);
    this->set_object(g6);

    CDestroyer *g7=new CDestroyer(this,7,2,player);
    this->set_object(g7);

    CDestroyer *g8=new CDestroyer(this,2,7,PC);
    this->set_object(g8);
}

/*!
Funkcja dodająca obiekt logiczny CObject do listy Lista oraz tworzący odpowiedni typ obiektu typu CField i dodający do Lista2.
*/
void CMap::set_object(CObject *obj)
{



     if(CWater *f2 = dynamic_cast<CWater*>(obj))
     {
         Lista.push_back(obj);
         CField *f=new CGraphicWater(f2);
         Lista2.push_back(f);

     }
     else if( CFregata *f2 = dynamic_cast<CFregata*>(obj))
     {
         Lista.push_back(obj); 
         CField *f=new CGraphicFregata(f2);
         Lista2.push_back(f);

     }
     else if(CDestroyer *f2 = dynamic_cast<CDestroyer*>(obj))
     {

         Lista.push_back(obj);
         CField *f=new CGraphicDestroyer(f2);
         Lista2.push_back(f);

     }
     else if(CRock *f2 = dynamic_cast<CRock*>(obj))
     {
         Lista.push_back(obj);
         CField *f=new CGraphicRock(f2);
         Lista2.push_back(f);

     }
}
/*!
Funkcja usuwająca obiekt logiczny CObject z listy Lista.
*/
void CMap::del_object(CObject *obj)
{
    for(size_t z = 0; z <this->Lista.size(); z++ )
    {
        CObject *w=this->Lista[z];
        if(w==obj)
        {
            Lista.erase(Lista.begin()+z);
            w->~CObject();

        }
    }
}
/*!
Funkcja usuwająca obiekt logiczny CObject z listy Lista oraz usuwający obiekt graficzny CField z Lista2.
*/
void CMap::del_field(CField *obj)
{
    for(size_t z = 0; z <this->Lista2.size(); z++ )
    {
        CField *w=this->Lista2[z];
        if(w==obj)
        {
            CObject *w1=w->get_typ();
            del_object(w1);
            Lista2.erase(Lista2.begin()+z);
            w->~CField();


        }
    }
}
/*!
Funkcja usuwająca obiekty ligiczne oraz graficzne z List po utracie przez nich punktów życia..
*/
void CMap::update()
{
    for( size_t z = 0; z < this->Lista2.size(); z++ )
    {

       CField *w=this->Lista2[z];
       if(dynamic_cast<CGraphicUnit*>(w))
       {    CGraphicUnit *d=dynamic_cast<CGraphicUnit*>(w);
           d->update();

         CObject *w1=d->get_typ();

         if(d->get_hp()<=0)
         {
             CUnit *w2=dynamic_cast<CUnit*>(w1);
             w2->get_gracz()->min_liczba_jedn();
             del_field(w);
         }
       }

    }

 }
/*!
Funkcja zwracająca liste obiektów Cobject będących w zasięgu obiektu CMovable *obj.
*/
std::deque<CObject*>CMap::podaj_obiekty_zasieg(CMovable *obj,int _zasieg,bool tryb)
 {

    int x=obj->get_x()-_zasieg;
    int y=obj->get_y()-_zasieg;

    std::deque <CObject*>lista_zwrotna;


for(int i=0;i<=2*_zasieg;i++)
{
    for(int j=0;j<=2*_zasieg;j++)
    {

        for( size_t z = 0; z < (get_objects(x+i,y+j)).size(); z++ )
            {

               CObject *w=get_objects(x+i,y+j)[z];
               if((x+i!=(obj->get_x()))||(y+j!=(obj->get_y())))
               {
                   if(tryb&&dynamic_cast<CUnit*>(w))
                   {

                    lista_zwrotna.push_back(w);
                   }
                           if(!tryb&&dynamic_cast<CWater*>(w))
                           {

                            lista_zwrotna.push_back(w);
                           }
               }
            }



    }
}

return lista_zwrotna;
 }
/*!
Funkcja zwracająca liste obiektów będących na polu o położeniu int x, int y.
*/
std::deque<CObject*> CMap:: get_objects(int x, int y)
{

    std::deque <CObject*>lista_zwrotna;
    for( size_t z = 0; z < this->Lista.size(); z++ )
    {
       CObject *w=this->Lista[z];
       if(w->get_x()==x && w->get_y()==y)
       {
           lista_zwrotna.push_back(w);
       }
    }


    return lista_zwrotna;
}
/*!
Funkcja zwracająca aktualnie wybrany obiekt.
\see get_active().
*/
CObject* CMap:: get_objects_act()
{


    for( size_t z = 0; z < Lista.size(); z++ )
    {
       CObject *w=this->Lista[z];

       if(w->get_active())
       {

           return w;
       }

    }


return 0;
}
/*!
Funkcja ustawiająca parametry logiczne jednostek do stanu podstawowego.
\see reset().
*/
void CMap::reset()
{
    for( size_t z = 0; z < Lista.size(); z++ )
    {
       CObject *w=this->Lista[z];
       w->reset();

    }
}
/*!
Funkcja zwracająca Gracza o zadanej nazwie.
*/
CGracz* CMap:: get_gracz(std::string nazwa)
{
    if(nazwa=="Player")
    {
        return player;
    }
    else if(nazwa=="PC")
    {
        return PC;
    }
    else
        return 0;
}

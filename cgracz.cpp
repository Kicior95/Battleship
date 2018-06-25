#include "cgracz.h"


/**
* \file cgracz.cpp
* \brief Plik źródłowy klasy bazowej CGracz.
*
*/

/*!
  Konstruktor obiekty klasy CGracz.
   std::string _nazwa Nazwa gracza.
*/
CGracz::CGracz(std::string _nazwa)
{
    nazwa=_nazwa;
    liczba_jedn=0;
}
/*!
  Dekonstruktor obiekty klasy CGracz.

*/
CGracz::~CGracz()
{

}
/*!
 Funckja zwracająca nazwe gracza typu string.
 \return Zwraca wartość typu string określająca nazwe obiekty CGracz.
*/
 std::string CGracz:: get_nazwa()
 {
     return nazwa;
 }
 /*!
  Funckja zmieniająca parametr należący do obiektu liczba_jedn.
  Wyukonuje sie dodanie wartości liczbowej jeden do parametru Liczba_jedn.
 */
 void CGracz::add_liczba_jedn()
 {
     liczba_jedn++;
 }
 /*!
  Funckja zmieniająca parametr należący do obiektu liczba_jedn.
  Wyukonuje sie odjęcie wartości liczbowej jeden do parametru Liczba_jedn.
 */
 void CGracz::min_liczba_jedn()
 {
     liczba_jedn--;
 }
 /*!
  Funckja zwracająca wartosć parametry liczba_jedn.
 \return Zwraca wartość parametry liczba_jedn.
 */
 int CGracz::get_liczba_jedn()
 {
     return liczba_jedn;
 }

#include "mainwindow.h"
#include <QApplication>
#include <cstdlib>
#include <ctime>


/**
* \mainpage
* \par Battelship
* Program umożliwia prowadzenie rozgrywki w grę strategiczną Okręty
*

\par Zasady gry

Battelship to gra strategiczna dla jednej osoby. Gracz zmierzy sie z komputerem posiadający szczątkową inteligencje.
Gra odbywa sie na planszy złożonej z pól owymiarach 10x10. Każda ze stron posiada swoje własne jednostki. Jednostki Gracza oznaczone są kolorem białym. Jednostki przeciwnika mają zabarwienie czerwone

Każdy z graczy ma do dyspozycji \b 4 okręty:
\li Trzy statki klasy Fregata
\li Jeden statek klasy Niszczyciel


Gra polega na zniszczeniu floty przeciwnika, poprzez zatapianie poszczególnych okrętów.



Wygrywa ten z graczy, który jako pierwszy zatopi flotę przeciwnika.


* \author Łukasz Kiciński gr 37
* \date 2017.06.10
* \version 1.44.2
* \par Kontakt:
* \a kicinski.lukasz@gmail.com
*/



/**
* \file main.cpp
* \brief Plik źródłowy programu.
*
*/



int main(int argc, char *argv[])
{
    srand( time( NULL ) );
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

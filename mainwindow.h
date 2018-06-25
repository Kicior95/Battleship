#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"cbattelship.h"
class CMap;

/**
* \file mainwindow.h
* \brief Plik nagłówkowy klasy MainWindow.
*
*/


//!Przestrzeń nazw Ui.
/*!
Przestrzeń nazw Interfejsu graficznego UI.
*/

namespace Ui {class MainWindow;}

//!Główna klasa graficzna programu.
/*!
Klasa definiująca obiekt graficzny przedstawiający zadaną logike.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

     friend class CBattelship;
public:
    explicit MainWindow(QWidget *parent = 0);   //!<Konstruktor.
    ~MainWindow();                              //!<Dekonstruktor.

private:
    Ui::MainWindow *ui;                         //!<Interfejs.
    CBattelship Gra;                            //!<Obiekt zawierający część logiczną gry CBattelship
    void rysuj();                               //!<Rysuje CWIDGET
    void usun();                                //!<Usuwa CWIDGET
    void interfejs();                           //!<Dodaje CPROGRESBAR


    private slots:
    void dzialaj();                             //!<Akcja po interakcji gracza z mapą.
};

#endif // MAINWINDOW_H

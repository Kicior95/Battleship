#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>
#include <typeinfo>

/**
* \file mainwindow.cpp
* \brief Plik źródłowy klasy MainWindow.
*
*/

/*!
 Konstruktor klasy graficznej MainWindow
 Konstruktor tworzy obiekt logiczny Cbattelshp oraz tworzy mape oraz interfejs
 \see rysuj().
 \see interfejs().
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayout->setSpacing(1);

    CBattelship _play;
    Gra=_play;
    rysuj();
    interfejs();
}

/*!
 Dekonstruktor klasy MainWindow.
*/
MainWindow::~MainWindow()
{
    delete ui;
}
/*!
Funckja dodająca do interfejsu graficznego wskaźniki typu ProgresBar.
*/
void MainWindow::interfejs()
{
    for( size_t z = 0; z < Gra.Mapa->Lista2.size(); z++ )

    {
        CField *kwadracik=Gra.Mapa->Lista2[z];
    if(dynamic_cast<CGraphicUnit*>(kwadracik))
        {
        CGraphicUnit *w=dynamic_cast<CGraphicUnit*>(kwadracik);
        w->wsk->setMaximum(100);
        if(w->czyj())
            {
            ui->verticalLayout_2->addWidget(w->wsk);
            }
        else
            ui->verticalLayout->addWidget(w->wsk);
        }
    }
}
/*!
 Funckja dodająca do interfejsu tablice pół CField symbolizujących poszczególne pola na mapie.
*/
void MainWindow::rysuj()
{
    for( size_t z = 0; z < Gra.Mapa->Lista2.size(); z++ )
    {
            CField *kwadracik=Gra.Mapa->Lista2[z];
            int i=kwadracik->get_x();
            int j=kwadracik->get_y();
            kwadracik->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            ui->gridLayout->addWidget(kwadracik,i,j);
            connect(kwadracik,SIGNAL(clicked()),kwadracik,SLOT(clickEvent()));
            connect(kwadracik,SIGNAL(clicked()),this,SLOT(dzialaj()));
           }
}
/*!
 Funckja usuwająca z interfejsu tablice pół CField symbolizujących poszczególne pola na mapie.
*/
void MainWindow::usun()
{

for( size_t z = 0; z < Gra.Mapa->Lista2.size(); z++ )
{   CField *kwadracik=Gra.Mapa->Lista2[z];
    disconnect(kwadracik,SIGNAL(clicked()),kwadracik,SLOT(clickEvent()));
    disconnect(kwadracik,SIGNAL(clicked()),this,SLOT(dzialaj()));
    ui->gridLayout->removeWidget(kwadracik);

}
}
/*!
 Głowna funckja w części graficznej. Inicjuje rozpoczęcie akcji części logicznej programu.
*/
void MainWindow::dzialaj()
{
    if(Gra.czy_koniec())
    {
    this->update();
    Gra.dzialaj();
    Gra.Mapa->update();
    this->usun();
    this->rysuj();
    this->update();
    }
    else
        this->close();
}



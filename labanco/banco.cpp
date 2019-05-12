#include "banco.h"
#include "ui_banco.h"
#include <iostream>
#include <QLabel>
#include <QList>
#include <QVector>
#include <istream>
#include <iostream>
#include <iosfwd>
#include <QPixmap>
#include <QBitmap>
#include <QScrollArea>
#include <QWidget>
#include <QMainWindow>

#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <thread>
#include <QtGui>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

banco::banco(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::banco)

{
     ui->setupUi(this);


}

banco::~banco()
{

    delete ui;
    shm_unlink(name);


}


void banco::mostrarcajas()
{

    int x = atoi(cajas);

    QPixmap test = QPixmap(QString::fromUtf8("/home/juan/labanco/office.png"));
    QVector<QLabel*> numcajas(x);
    for(int k=0; k < x; k++)
    {
        i += 70;
        QLabel  *Caj = new QLabel(this);
        int w = Caj->width();
        int h = Caj->height();
        Caj -> setGeometry(10+i,100,50,50);
        Caj -> setPixmap(test);
        Caj ->setPixmap(test.scaled(w,h,Qt::KeepAspectRatio));
        Caj->show();
        numcajas.insert(k,Caj);
    }

}

void banco::leermemoria()
{
    int conta;
    while(conta < 200);
    {
        Shared_mem men_memoria;

        shm_fd_memoria = shm_open(name, O_RDWR, 0666);
        ptr_memoria = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd_memoria, 0);
        ((Shared_mem*)ptr_memoria)->nombre;

        printf("%c\n", men_memoria.nombre);
        printf("%i\n", men_memoria.quantity);
        usleep(200*1000);

        conta ++;
    }


}

void banco::on_pushButton_clicked()
{
    leermemoria();
}

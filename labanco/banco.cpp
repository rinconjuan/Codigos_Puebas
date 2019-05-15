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
#include <QTimer>
#include <QDebug>


using namespace std;

banco::banco(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::banco)

{
     ui->setupUi(this);

     timermem = new QTimer(this);
     connect(timermem, SIGNAL(timeout()), this, SLOT(leermemoria()));
     timermem-> start(1000);


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
    shm_fd_memoria = shm_open(name, O_RDWR, 0666);
    ptr_memoria =mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd_memoria, 0);
    name1= (char *)ptr_memoria;
    apellido1 = (char *)name1 + sizeof(name1);
    id1 = (char *)apellido1 + sizeof(apellido1);
    estado = (int *)id1 + sizeof(id1);

    if(*estado == 1)
    {

        printf("HOLA\n");
        //MOSTRAR CLIENTE EN GIU
        i += 70;
        QVector<QLabel*> numclientes(1000);

        QLabel  *Cliente = new QLabel(this);
        Cliente->setGeometry(10+i,100,100,100);

        Cliente->setText(name1);
        Cliente->show();
        numclientes.insert(numc,Cliente);
        numc += 1;

    }else
    {
        printf(" FAIL\n");
    }


    estado = 0;
    printf("NOMBRE = %s\n", name1);
    printf("APELLIDO = %s\n", apellido1);
    printf("ID= %s\n", id1);

    //memo.nombre = ((Shared_mem*)ptr_memoria)->nombre;
    //memo.apellido = ((Shared_mem*)ptr_memoria)->apellido;
    //memo.id = ((Shared_mem*)ptr_memoria)->id
    //((Shared_mem*)ptr_memoria)->nombre;


}

void banco::iniciar()
{
    shm_fd_memoria = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd_memoria, SIZE);
    sem_t *sem_id = sem_open(semaforomem, O_CREAT, 0644, 1);
    sem_init(sem_id,1,1);


}

void banco::mostrarclientes()
{





}



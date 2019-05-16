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
     timermem-> start(10);




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
        //ui->label->deleteLater();
    }

}

void banco::leermemoria()
{
    ptr_memoria =mmap(0, SIZE, PROT_READ |  PROT_WRITE, MAP_SHARED, shm_fd_memoria, 0);
    ptr_aviso =mmap(0, SIZE, PROT_READ |  PROT_WRITE, MAP_SHARED, shm_fd_aviso, 0);

    // MEMORIA GENERAL

    QLabel  *Cliente = new QLabel(this);

    name1= (char *)ptr_memoria;
    apellido1 = (char *)name1 + sizeof(name1);
    id1 = (char *)apellido1 + sizeof(apellido1);
    estado = (int *)id1 + sizeof(id1);


    reset = (int *)ptr_aviso;
    printf("RESET= %i\n", *reset);


    printf("ESTADO %i\n", *estado);

    if(*estado == 1)
    {
        j += 70;
        nucli << new QLabel(this);

        QPixmap pix("/home/juan/labanco/person.png");
        QPixmap ima = pix.scaled(120,120);
        nucli.at(numc) -> setPixmap(ima);
        int w = Cliente->width();
        int h = Cliente->height();
        nucli.at(numc) -> setGeometry(10+j,175,50,50);
        nucli.at(numc) -> setPixmap(ima);
        nucli.at(numc) -> setPixmap(ima.scaled(w,h,Qt::KeepAspectRatio));

        nombrescliente << new QLabel(this);

        nombrescliente.at(numc) -> setGeometry(10+j,250,50,50);
        nombrescliente.at(numc)->setText(name1);



        idsclientes << new QLabel(this);
        idsclientes.at(numc) -> setGeometry(10+j,215,50,50);
        idsclientes.at(numc) ->setText(id1);


        nombrescliente.at(numc)->show();
        idsclientes.at(numc)->show();
        nucli.at(numc) -> show();

        numc ++;

        //QPixmap clien = QPixmap(QString::fromUtf8("/home/juan/labanco/person.png"));
        /*int w = Cliente->width();
        int h = Cliente->height();
        nucli.at(0) -> setGeometry(10+i,100,50,50);
        nucli.at(0) -> setPixmap(clien);
        nucli.at(0) -> setPixmap(clien.scaled(w,h,Qt::KeepAspectRatio));
        nucli.at(0) -> show();*/




        //nucli.at(0) -> setText(" 1111111111111234567890-");
        //nucli.at(0)-> show();


        //QVector<QLabel*> numclientes(1000);
        //Cliente -> setGeometry(10+i,100,50,50);
        //Cliente -> setPixmap(clien);
        //Cliente ->setPixmap(clien.scaled(w,h,Qt::KeepAspectRatio));

        //Cliente->setGeometry(10+i,100,100,100);

        // Cliente->setText(name1);
        //Cliente->show();

        //numclientes.insert(numc,Cliente);
        //numc += 1;


        // MEMORIA AVISOS

    }
    else
    {
        printf(" FAIL\n");

    }
    if(*reset == 2)
    {
       printf("-------------------------------------------------------------------------\n");

       nucli.at(ethan)->setText(" ");
       nucli.at(ethan)->show();
       nombrescliente.at(ethan)->setText(" ");
       idsclientes.at(ethan) -> setText(" ");
       ethan ++;


    }

    if (*reset==0)
    {

        printf("ETAHN MK");


    }

    /*
    printf("NOMBRE = %s\n", name1);
    printf("APELLIDO = %s\n", apellido1);
    printf("ID= %s\n", id1);
    *estado = 0;
    *reset = 0;*/

     //unlink()

    //memo.nombre = ((Shzzared_mem*)ptr_memoria)->nombre;
    //memo.apellido = ((Shared_mem*)ptr_memoria)->apellido;
    //memo.id = ((Shared_mem*)ptr_memoria)->id
    //((Shared_mem*)ptr_memoria)->nombre;

    *reset = 0;
    *estado = 0;



}

void banco::iniciar()
{

    sem_t *sem_id = sem_open(semaforomem, O_CREAT, 0644, 1); // CREACION DE SEMAFORO MEMORIA
    sem_init(sem_id,1,1); // INICIALIZACION DE SEMAFORO

    sem_t *sem_idc = sem_open(semaforocajas, O_CREAT, 0644, atoi(cajas));
    sem_init(sem_idc,atoi(cajas),atoi(cajas));

    shm_fd_memoria = shm_open(name, O_RDWR, 0666);


    shm_fd_aviso = shm_open(aviso, O_RDWR, 0666);




}

void banco::mostrarclientes()
{    


    //Cliente-> hide();



}

void banco::avisos()
{


}





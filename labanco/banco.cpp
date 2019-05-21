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
#include <semaphore.h>



using namespace std;

banco::banco(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::banco)

{
     ui->setupUi(this);

     timermem = new QTimer(this);
     connect(timermem, SIGNAL(timeout()), this, SLOT(leermemoria()));
     timermem-> start(100);




}

banco::~banco()
{

    delete ui;
    shm_unlink(name);


}


void banco::mostrarcajas()
{



    QPixmap test = QPixmap(QString::fromUtf8("/home/juan/labanco/office.png"));
    int x = atoi(cajas);
    for(int k=0; k < x; k++)
    {
        i += 150;



        QLabel  *Caj = new QLabel(this);
        int w = Caj->width();
        int h = Caj->height();
        Caj -> setObjectName(cajas+QString(ggcaja));
        Caj -> setGeometry(pox + i,poy,tah,tal);
        Caj -> setPixmap(test);
        Caj ->setPixmap(test.scaled(w+20,h+20,Qt::KeepAspectRatio));
        //Caj->setText(Caj->objectName());
        Caj->show();
        numcajas.insert(k,Caj);
        ggcaja ++;



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
    muffler = (int *)reset + sizeof(reset);

    envio =(int *)muffler + 64;
    cajarecibo = (int *)muffler + 96;

    //posicion =(int *)muffler + sizeof(muffler);

    printf("RESET= %i\n", *reset);
    printf("ESTADO %i\n", *estado);

    *muffler = numc;

    ggcaja = 0;

    if(*estado == 1)
    {

        j+=70;

        nombreenvio = (int *)muffler + 80;


        nucli << new QLabel(this);

        QPixmap pix("/home/juan/labanco/person.png");
        QPixmap ima = pix.scaled(10,10);
        nucli.at(numc) -> setPixmap(ima);
        int w = 10;
        int h = 10;

        nucli.at(numc) -> setPixmap(ima);

        nombrescliente << new QLabel(this);
        nombrescliente.at(numc) -> setGeometry(10+j,280,50,15);
        nombrescliente.at(numc)->setText(name1);
        idsclientes << new QLabel(this);
        idsclientes.at(numc) -> setGeometry(10+j,300,50,15);
        idsclientes.at(numc) ->setText(id1);



        printf("******* CAJA ES = %i\n", ggcaja);

        bool final = 0;
        printf("%i\n", final);
        int o;
        ggcaja = 0;

        while(final == 0)
        {
            for(o = 0; o < (atoi(cajas)); o++)
            {

                printf("%i\n", atoi(cajas));


                if(numcajas.at(o)->objectName() == cajas + QString(ggcaja))
                {

                    numcajas.at(o)->setObjectName("OCUPADO" + QString(ggcaja));
                    printf("FUNCIONO");

                    nucli.at(numc) -> setGeometry(numcajas.at(o)->geometry());
                    nucli.at(numc) -> setPixmap(ima.scaled(w,h,Qt::KeepAspectRatio));



                    numcajas.at(o) -> setText(numcajas.at(o)->objectName());
                    numcajas.at(o) -> show();
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``%i\n", ggcaja);


                    o = atoi(cajas);
                    final = 1;
                    ggcaja++;


                }
                else
                {
                    ggcaja++;

                    printf("AUMENTO CAJA = %i\n", ggcaja);

                    if( ggcaja > atoi(cajas) )
                    {
                        final = 1;

                    }

                }



            }
            o = 0;

        }

        nombrescliente.at(numc)->show();
        idsclientes.at(numc)->show();
        nucli.at(numc) -> show();

        *nombreenvio = ggcaja;


        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> %i\n", *nombreenvio);
        ggcaja = 0;
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


      printf("__________________________________________________________--%i\n",*muffler);
      *reset = 0;

      printf("RECBIO = %i\n", *envio);
      printf(" / / / / / / / / CAJA A DESBLOQUEAR = %i\n", *cajarecibo);
      //nucli.at(*envio)->setText(" ");


      for(int yy = 0; yy < atoi(cajas); yy++)
      {
          if(numcajas.at(yy)-> objectName() == "OCUPADO" + QString(*cajarecibo))
          {
              numcajas.at(yy)-> setObjectName(cajas + QString(*cajarecibo));

              nucli.at(*envio)->setVisible(false);
              nombrescliente.at(*envio)->setText(" ");
              idsclientes.at(*envio) -> setText(" ");
              nombrescliente.at(*envio)-> show();
              idsclientes.at(*envio)-> show();

              ggcaja = 0;
              //i = i - i*(*cajarecibo + 100);
              //poyc = poyc - poyc*(*cajarecibo + 1);
              printf("*  *   *   *   * %i\n", pox);
              printf("*  *   *   *   * %i\n", poyc);




              numcajas.at(yy)->setText(numcajas.at(yy)->objectName());
              numcajas.at(yy)->show();
          }

      }


    }

    if (*reset==0)
    {


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

    sem_t *sem_muffler = sem_open(semaforomuffler, O_CREAT, 0644, 1);
    sem_init(sem_muffler,1,1);

    sem_init(sem_lynn,atoi(cajas),atoi(cajas));





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





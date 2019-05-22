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
        int w = 10;
        int h = 10;
        Caj -> setObjectName("0");
        Caj -> setGeometry(pox + i,poy,tah,tal);
        Caj -> setPixmap(test);
        Caj ->setPixmap(test.scaled(w+20,h+20,Qt::KeepAspectRatio));
        //Caj->setText(Caj->objectName());
        Caj->show();
        numcajas.insert(k,Caj);

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

        sem_wait(sem_muffler);
        j+=70;

        nombreenvio = (int *)muffler + 80;

        nucli << new QLabel(this);
        QPixmap pix("/home/juan/labanco/person.png");
        QPixmap ima = pix.scaled(10,10);
        nucli.at(numc) -> setPixmap(ima);
        int w = 10;
        int h = 10;
        nucli.at(numc) -> setPixmap(ima);
        nucli.at(numc)->setObjectName(QString(numc));
        nombrescliente << new QLabel(this);

        idsclientes << new QLabel(this);



        printf("******* CAJA ES = %i\n", ggcaja);

        bool final = 0;
        printf("%i\n", final);
        int o;

        while(final == 0)
        {
            for(o = 0; o <= (atoi(cajas)); o++)
                 {

                     printf("ERROR = %i\n", atoi(cajas));

                     if(numcajas.at(o)->objectName() == "0")
                     {
                         numcajas.at(o)->setObjectName("1");
                         printf("FUNCIONO");

                         nucli.at(numc) -> setGeometry(numcajas.at(o)->geometry().x(), numcajas.at(o)->geometry().y()+75,numcajas.at(o)->geometry().width(),numcajas.at(o)->geometry().height());
                         nucli.at(numc) -> setPixmap(ima.scaled(w,h,Qt::KeepAspectRatio));
                         numcajas.at(o) -> setText(numcajas.at(o)->objectName());
                         numcajas.at(o) -> show();
                         printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``%i\n", ggcaja);

                         nombrescliente.at(numc) -> setGeometry(numcajas.at(o)->geometry().x(), numcajas.at(o)->geometry().y()+100,numcajas.at(o)->geometry().width(),numcajas.at(o)->geometry().height());
                         nombrescliente.at(numc)->setText(name1);

                         idsclientes.at(numc) -> setGeometry(numcajas.at(o)->geometry().x(), numcajas.at(o)->geometry().y()+ 175,numcajas.at(o)->geometry().width(),numcajas.at(o)->geometry().height());
                         idsclientes.at(numc) ->setText(id1);

                         nombrescliente.at(numc)->show();
                         idsclientes.at(numc)->show();
                         nucli.at(numc) -> show();


                         sem_wait(sem_lynn);

                         enquecaja[numc] = numc + 1;
                         *nombreenvio = enquecaja[o];
                         sem_post(sem_lynn);

                         printf("NUMERO DE CAJA = %i\n", *nombreenvio);


                         o = atoi(cajas);
                         final = 1;

                     }
                     else
                      {
                         //ggcaja++;

                         //printf("AUMENTO CAJA = %i\n", ggcaja);

                         //if( ggcaja + 1> atoi(cajas) )
                         //{
                            // ggcaja = 0;
                            // o = atoi(cajas);
                             //final = 1;

                         //}
                    }

                 }
        }




        printf(">>>>>>>>>>>>>>>> CLIEN TE VERGA >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> %i\n");
        numc ++;
        sem_post(sem_muffler);

    }
    else
    {
        printf(" FAIL\n");

    }


    /*
    if(*reset == 2)
    {
        *reset =0;

        for(int r = 0; r < atoi(cajas); r++)
        {
            if(numcajas.at(r)->objectName() == "1")
            {
                numcajas.at(r)->setObjectName("0");
                ui->cliente1->setVisible(false);
            }

        }

    }*/


    if(*reset == 2)
    {


      printf("__________________________________________________________--%i\n",*muffler);
      *reset = 0;

      printf("RECBIO = %i\n", *envio);
      printf(" / / / / / / / / CAJA A DESBLOQUEAR = %i\n", *cajarecibo);
      //nucli.at(*envio)->setText(" ");




      sem_wait(sem_muffler);

      for(int yy = 0; yy < atoi(cajas); yy++)
      {

              for(int tt = 0   ; tt < numc; tt++)
              {
                  printf("ENCONTRO CAJAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
                  printf("ENVIO ES ANTES DEL IF = %i\n",(*envio));

                  if(nucli.at(tt)->objectName() == QString(*envio) && numcajas.at(yy)-> objectName() == "1");
                  {
                      printf("ENVIO ES = %i\n",*envio);

                      numcajas.at(*cajarecibo)-> setObjectName("0");

                      nucli.at(*envio)->setVisible(false);
                      nombrescliente.at(*envio)->setText(" ");
                      idsclientes.at(*envio) -> setText(" ");
                      nombrescliente.at(*envio)-> show();
                      idsclientes.at(*envio)-> show();

                      enquecaja[*envio] = 0;
                      //i = i - i*(*cajarecibo + 100);
                      //poyc = poyc - poyc*(*cajarecibo + 1);
                      printf("*  *   *   *   * %i\n", pox);
                      printf("*  *   *   *   * %i\n", poyc);

                      numcajas.at(*cajarecibo)->setText(numcajas.at(*cajarecibo)->objectName());
                      numcajas.at(*cajarecibo)->show();

                      yy = atoi(cajas);
                      tt = numc;
                      sem_post(sem_muffler);
                  }



              }



      }






    }

    *reset = 0;
    *estado = 0;
}

void banco::iniciar()
{

    sem_t *sem_id = sem_open(semaforomem, O_CREAT, 0644, 1); // CREACION DE SEMAFORO MEMORIA
    sem_init(sem_id,1,1); // INICIALIZACION DE SEMAFORO

    //sem_t *sem_idc = sem_open(semaforocajas, O_CREAT, 0644, atoi(cajas)); // SEMAFORO DE CAJAS
    sem_init(sem_idc,atoi(cajas),atoi(cajas));


    sem_init(sem_muffler,1,1);

    sem_init(sem_lynn,1,1);

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





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
    ui->cliente1->setVisible(false);
    ui->cliente2->setVisible(false);
    ui->cliente3->setVisible(false);
    ui->cliente4->setVisible(false);
    ui->cliente5->setVisible(false);
    ui->cliente6->setVisible(false);
    ui->cliente7->setVisible(false);
    ui->cliente8->setVisible(false);
    ui->cliente9->setVisible(false);
    ui->cliente10->setVisible(false);

    numeclientes.insert(0,ui->cliente1);
    numeclientes.insert(1,ui->cliente2);
    numeclientes.insert(2,ui->cliente3);
    numeclientes.insert(3,ui->cliente4);
    numeclientes.insert(4,ui->cliente5);
    numeclientes.insert(5,ui->cliente6);
    numeclientes.insert(6,ui->cliente7);
    numeclientes.insert(7,ui->cliente8);
    numeclientes.insert(8,ui->cliente9);
    numeclientes.insert(9,ui->cliente10);





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

    /*

    if(atoi(cajas) == 1)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(false);
        ui->caja3->setVisible(false);
        ui->caja4->setVisible(false);
        ui->caja5->setVisible(false);
        ui->caja6->setVisible(false);
        ui->caja7->setVisible(false);
        ui->caja8->setVisible(false);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else if(atoi(cajas) == 2)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(false);
        ui->caja4->setVisible(false);
        ui->caja5->setVisible(false);
        ui->caja6->setVisible(false);
        ui->caja7->setVisible(false);
        ui->caja8->setVisible(false);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else if(atoi(cajas) == 3)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(true);
        ui->caja4->setVisible(false);
        ui->caja5->setVisible(false);
        ui->caja6->setVisible(false);
        ui->caja7->setVisible(false);
        ui->caja8->setVisible(false);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else if(atoi(cajas) == 4)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(true);
        ui->caja4->setVisible(true);
        ui->caja5->setVisible(false);
        ui->caja6->setVisible(false);
        ui->caja7->setVisible(false);
        ui->caja8->setVisible(false);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else if(atoi(cajas) == 5)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(true);
        ui->caja4->setVisible(true);
        ui->caja5->setVisible(true);
        ui->caja6->setVisible(false);
        ui->caja7->setVisible(false);
        ui->caja8->setVisible(false);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else if(atoi(cajas) == 6)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(true);
        ui->caja4->setVisible(true);
        ui->caja5->setVisible(true);
        ui->caja6->setVisible(true);
        ui->caja7->setVisible(false);
        ui->caja8->setVisible(false);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else if(atoi(cajas) == 7)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(true);
        ui->caja4->setVisible(true);
        ui->caja5->setVisible(true);
        ui->caja6->setVisible(true);
        ui->caja7->setVisible(true);
        ui->caja8->setVisible(false);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);
    }
    else if(atoi(cajas) == 8)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(true);
        ui->caja4->setVisible(true);
        ui->caja5->setVisible(true);
        ui->caja6->setVisible(true);
        ui->caja7->setVisible(true);
        ui->caja8->setVisible(true);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else if(atoi(cajas) == 9)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(true);
        ui->caja4->setVisible(true);
        ui->caja5->setVisible(true);
        ui->caja6->setVisible(true);
        ui->caja7->setVisible(true);
        ui->caja8->setVisible(true);
        ui->caja9->setVisible(true);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else if(atoi(cajas) == 10)
    {
        ui->caja1->setVisible(true);
        ui->caja2->setVisible(true);
        ui->caja3->setVisible(true);
        ui->caja4->setVisible(true);
        ui->caja5->setVisible(true);
        ui->caja6->setVisible(true);
        ui->caja7->setVisible(true);
        ui->caja8->setVisible(true);
        ui->caja9->setVisible(true);
        ui->caja10->setVisible(true);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

    }
    else {
        ui->caja1->setVisible(false);
        ui->caja2->setVisible(false);
        ui->caja3->setVisible(false);
        ui->caja4->setVisible(false);
        ui->caja5->setVisible(false);
        ui->caja6->setVisible(false);
        ui->caja7->setVisible(false);
        ui->caja8->setVisible(false);
        ui->caja9->setVisible(false);
        ui->caja10->setVisible(false);

        ui->cliente1->setVisible(false);
        ui->cliente2->setVisible(false);
        ui->cliente3->setVisible(false);
        ui->cliente4->setVisible(false);
        ui->cliente5->setVisible(false);
        ui->cliente6->setVisible(false);
        ui->cliente7->setVisible(false);
        ui->cliente8->setVisible(false);
        ui->cliente9->setVisible(false);
        ui->cliente10->setVisible(false);

        ui->label->setText("CAJAS INSUFICIENTES");
        ui->label->show();
    }

    */




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
        /*
        for(int r = 0; r < atoi(cajas); r++)
        {
            if(numcajas.at(r)->objectName() == "0")
            {
                numcajas.at(r)->setObjectName("1");

                if(numc == 0 )
                {
                    numeclientes.at(0)->setVisible(true);
                }
            }

        }


    numc+=1;
    *estado = 0;*/







        /*
        if(atoi(cajas) == 2)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);
                estado =0;


            }
            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente1->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 6)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 7)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 8)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente2->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente1->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente1->setVisible(true);
            }
            else
            {
                    ui->cliente2->setVisible(false);
                    ui->cliente1->setVisible(false);
            }

    }
        if(atoi(cajas) == 3)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);

            }
            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 6)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 7)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 8)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente2->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente1->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente1->setVisible(true);
            }


    }
        if(atoi(cajas) == 4)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);

            }

            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 6)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 7)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 8)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente2->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente1->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 14)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 15)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 16)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 17)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 18)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 19)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 20)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 21)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 22)
            {
                ui->cliente3->setVisible(true);
            }



    }
        if(atoi(cajas) == 5)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);

            }

            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente5->setVisible(true);

            }
            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 6)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 7)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 8)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente5->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente3->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 14)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 15)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 16)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 17)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 18)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 19)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 20)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 21)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 22)
            {
                ui->cliente5->setVisible(true);
            }



    }

        if(atoi(cajas) == 6)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);

            }

            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente5->setVisible(true);

            }
            if(numc == 6)
            {
                ui->cliente6->setVisible(true);
            }
            if(numc == 7)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 8)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 10)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 11)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente4->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente1->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente6->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 14)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 15)
            {
                ui->cliente6->setVisible(true);
            }

            if(numc == 16)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 17)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 18)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 19)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 20)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 21)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 22)
            {
                ui->cliente5->setVisible(true);
            }



    }
        if(atoi(cajas) == 7)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);

            }

            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente5->setVisible(true);

            }
            if(numc == 6)
            {
                ui->cliente6->setVisible(true);
            }
            if(numc == 7)
            {
                ui->cliente7->setVisible(true);
            }
            if(numc == 8)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 10)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 11)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente7->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente6->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 14)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 15)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 16)
            {
                ui->cliente6->setVisible(true);
            }

            if(numc == 17)
            {
                ui->cliente7->setVisible(true);
            }

            if(numc == 18)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 19)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 20)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 21)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 22)
            {
                ui->cliente5->setVisible(true);
            }



    }
        if(atoi(cajas) == 8)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);

            }

            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente5->setVisible(true);

            }
            if(numc == 6)
            {
                ui->cliente6->setVisible(true);
            }
            if(numc == 7)
            {
                ui->cliente7->setVisible(true);
            }
            if(numc == 8)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 10)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 11)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente7->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente6->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 14)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 15)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 16)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 17)
            {
                ui->cliente7->setVisible(true);
            }

            if(numc == 18)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 19)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 20)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 21)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 22)
            {
                ui->cliente5->setVisible(true);
            }



    }

        if(atoi(cajas) == 9)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);

            }

            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente5->setVisible(true);

            }
            if(numc == 6)
            {
                ui->cliente6->setVisible(true);
            }
            if(numc == 7)
            {
                ui->cliente7->setVisible(true);
            }
            if(numc == 8)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente9->setVisible(true);
            }

            if(numc == 10)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 11)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente7->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente9->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 14)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 15)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 16)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 17)
            {
                ui->cliente7->setVisible(true);
            }

            if(numc == 18)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 19)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 20)
            {
                ui->cliente9->setVisible(true);
            }

            if(numc == 21)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 22)
            {
                ui->cliente5->setVisible(true);
            }



    }

        if(atoi(cajas) == 10)
        {
            if(numc == 1)
            {
                ui->cliente1->setVisible(true);

            }

            if(numc == 2)
            {
                ui->cliente2->setVisible(true);
            }
            if(numc == 3)
            {
                ui->cliente3->setVisible(true);
            }
            if(numc == 4)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 5)
            {
                ui->cliente5->setVisible(true);

            }
            if(numc == 6)
            {
                ui->cliente6->setVisible(true);
            }
            if(numc == 7)
            {
                ui->cliente7->setVisible(true);
            }
            if(numc == 8)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente9->setVisible(true);
            }

            if(numc == 10)
            {
                ui->cliente10->setVisible(true);
            }

            if(numc == 11)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 9)
            {
                ui->cliente7->setVisible(true);
            }


            if(numc == 10)
            {
                ui->cliente9->setVisible(true);
            }

             if(numc == 11)
            {
                ui->cliente3->setVisible(true);
            }

            if(numc == 12)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 13)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 14)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 15)
            {
                ui->cliente5->setVisible(true);
            }

            if(numc == 16)
            {
                ui->cliente8->setVisible(true);
            }

            if(numc == 17)
            {
                ui->cliente10->setVisible(true);
            }

            if(numc == 18)
            {
                ui->cliente1->setVisible(true);
            }

            if(numc == 19)
            {
                ui->cliente2->setVisible(true);
            }

            if(numc == 20)
            {
                ui->cliente9->setVisible(true);
            }

            if(numc == 21)
            {
                ui->cliente4->setVisible(true);
            }

            if(numc == 22)
            {
                ui->cliente3->setVisible(true);
            }



    }*/


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

                     printf("ERROR = %i\n", atoi(cajas));

                     if(numcajas.at(o)->objectName() == "0")
                     {
                         numcajas.at(o)->setObjectName("1");
                         printf("FUNCIONO");

                         nucli.at(numc) -> setGeometry(numcajas.at(o)->geometry().x(), numcajas.at(o)->geometry().y()+75,numcajas.at(o)->geometry().width(),numcajas.at(1)->geometry().height());
                         nucli.at(numc) -> setPixmap(ima.scaled(w,h,Qt::KeepAspectRatio));
                         numcajas.at(o) -> setText(numcajas.at(o)->objectName());
                         numcajas.at(o) -> show();
                         printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``%i\n", ggcaja);

                         nombrescliente.at(numc)->show();
                         idsclientes.at(numc)->show();
                         nucli.at(numc) -> show();

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

      for(int tt = 0   ; tt < numc; tt++)
      {
          if(nucli.at(tt)->objectName() == QString(*cajarecibo))
          {
              for(int yy = 0; yy <atoi(cajas); yy++)
              {
                  printf("ENCONTRO CAJAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA%c\n");
                  printf("%c\n",(char)(*cajarecibo));

                  if(numcajas.at(yy)-> objectName() == "1" && QString(*envio) ==  QString(*cajarecibo))
                  {

                      numcajas.at(yy)-> setObjectName("0");

                      nucli.at(tt)->setVisible(false);
                      nombrescliente.at(tt)->setText(" ");
                      idsclientes.at(tt) -> setText(" ");
                      nombrescliente.at(tt)-> show();
                      idsclientes.at(tt)-> show();

                      ggcaja = 0;
                      //i = i - i*(*cajarecibo + 100);
                      //poyc = poyc - poyc*(*cajarecibo + 1);
                      printf("*  *   *   *   * %i\n", pox);
                      printf("*  *   *   *   * %i\n", poyc);

                      numcajas.at(yy)->setText(numcajas.at(yy)->objectName());
                      numcajas.at(yy)->show();

                      yy = atoi(cajas);
                      tt = numc;

                      sem_post(sem_muffler);
                  }



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





#include "banco.h"
#include "ui_banco.h"
#include <QApplication>
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
#include <semaphore.h>
#include <QTimer>

using namespace std;


int main(int argc, char *argv[])
{



    if (argc == 2)
    {
        // PARTE DE MEMORIA COMPARTIDA.


        // CONTROL DE VENTANA.
        QApplication a(argc, argv);
        banco w;
        w.cajas = argv[1];
        w.mostrarcajas();
        w.iniciar();

        shm_unlink(w.name);

        w.shm_fd_memoria = shm_open(w.name, O_CREAT | O_RDWR, 0666); // CREACION DE MEMORIA
        w.shm_fd_aviso = shm_open(w.aviso, O_CREAT | O_RDWR, 0666);

        ftruncate(w.shm_fd_memoria, w.SIZE);
        ftruncate(w.shm_fd_aviso, w.SIZE);



        w.show();
        w.setWindowTitle("BANCO");
        return a.exec();


    }
    else
    {
     printf("Ingrese un argumento\n");
    }


}



#include "banco.h"
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

typedef struct
{
int quantity;
int product_id;
char flag;
}Shared_mem;



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
        w.shm_fd_memoria = shm_open(w.name, O_CREAT | O_RDWR, 0666);
        ftruncate(w.shm_fd_memoria, w.SIZE);
        w.mostrarcajas();
        w.show();
        w.setWindowTitle("BANCO");



        return a.exec();
    }
    else
    {
     printf("Ingrese un argumento\n");
    }


}

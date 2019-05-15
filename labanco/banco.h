#ifndef BANCO_H
#define BANCO_H
#include <QMainWindow>
#include <QLabel>
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


namespace Ui {
class banco;
}

class banco : public QMainWindow
{
    Q_OBJECT

public:
    explicit banco(QWidget *parent = nullptr);
    char *cajas;
    QLabel Caja[100];
    int i = 0;
    int j =0;

    void mostrarcajas();
    void iniciar();
    void mostrarclientes();


    sem_t sem_memoria;
    sem_t sem_cajas;

    typedef struct
    {
        char *nombre;
        char *apellido;
        char *id;
    }Shared_mem;

    int shm_fd_memoria; // Descriptor of shared memory
    void *ptr_memoria; // Pointer to shared memory
    char *name1;
    char *apellido1;
    char *id1;
    int *estado = 0;
    int numc  = 0;

    const int SIZE = sizeof(Shared_mem); // Size in bytes of the shared memory section
    const char *name = "MemoriaCompartida"; // Name of the shared memory section

    const char *semaforomem = "smpmem"; // SEMAFORO DE LA MEMORIA
    const char *semaforocajas = "sempcajas"; // SEMAFORO DE LAS CAJAS

    char clientes[1000]; // IGNORE ESTA MIERDA

    Shared_mem memo;
    ~banco();

private slots:
    void leermemoria();


private:
    Ui::banco *ui;
    QTimer *timermem;
};

#endif // BANCO_H

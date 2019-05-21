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
    int j = 0;
    int u = 0;
    int ggcaja =0;

    void mostrarcajas();
    void iniciar();
    void mostrarclientes();


    typedef struct
    {
        char *nombre;
        char *apellido;
        char *id;
    }Shared_mem;

    int shm_fd_memoria; // Descriptor of shared memory
    int shm_fd_aviso;
    void *ptr_memoria; // Pointer to shared memory
    void *ptr_aviso;


    char *name1;
    char *apellido1;
    char *id1;
    int *estado = 0;


    int *reset = 0;
    int ethan = 0;
    int *muffler = 0;
    int *posicion = 0;
    int *envio = 0;
    int *nombreenvio = 0;
    int *cajarecibo =0;

    int pox= 0,poy= 100, poyc = 240,tah = 100,tal= 100;


    QVector<QLabel*> numcajas;



    int numc  = 0;

    const int SIZE = sizeof(Shared_mem); // Size in bytes of the shared memory section
    const char *name = "MemoriaCompartida"; // Name of the shared memory section
    const char *aviso = "MemoriaAviso";

    const char *semaforomem = "smpmem"; // SEMAFORO DE LA MEMORIA
    const char *semaforocajas = "sempcajas"; // SEMAFORO DE LAS CAJAS
    const char *semaforomuffler = "semmuffler"; // SEMAFORO DE MUFFLER

    const char *semaforolynn = "semlynn";

    sem_t *sem_lynn = sem_open(semaforolynn, O_CREAT, 0644,cajas);

    char clientes[1000]; // IGNORE ESTA MIERDA

    QList<QLabel*> nucli;



    QList<QLabel*> nombrescliente;
    QList<QLabel*> idsclientes;


    Shared_mem memo;


    /// INTENTO PRUEBA
    struct datescajas {
        bool state;
        int numerocaja;
    };
    ~banco();

private slots:
    void leermemoria();
    void avisos();


private:
    Ui::banco *ui;
    QTimer *timermem;
};

#endif // BANCO_H

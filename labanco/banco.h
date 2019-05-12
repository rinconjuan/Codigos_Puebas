#ifndef BANCO_H
#define BANCO_H

#include <QMainWindow>
#include <QLabel>

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
    void leermemoria();
    int shm_fd_memoria; // Descriptor of shared memory
    void *ptr_memoria; // Pointer to shared memory
    const int SIZE = 4096; // Size in bytes of the shared memory section
    const char *name = "MemoriaCompartida"; // Name of the shared memory section

    typedef struct
    {
        int quantity;
        int product_id;
        char flag;
        char *nombre;
    }Shared_mem;





    ~banco();

private slots:
    void on_pushButton_clicked();

private:
    Ui::banco *ui;
};

#endif // BANCO_H

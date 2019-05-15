#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <semaphore.h>

using namespace std;


typedef struct{
	char *nombre;
	char *apellido;
	char *id;
}Shared_mem;

const int SIZE = sizeof(Shared_mem); // Size in bytes of the shared memory section

const char *name = "MemoriaCompartida"; // Name of the shared memory section
const char *semaforomem = "smpmem";
const char *semaforocajas = "sempcajas";


int main(int argc, char *argv[])
{
	
	//sem_close(sem_id); // CERRANDO SEMAFORO POR SI FALLA EL PROGRAMA Y QUEDA ABIERTO;
	
	int shm_fd_memoria;
	void *ptr_memoria;
 
	char *nombrec;
	char *apellidoc;
	char *idc;

	char *name1;
	char *apellido1;
	char *ed1;
	int *estado = 0;
	
	nombrec = argv[1];	
	apellidoc = argv[2];
	idc = argv[3];
	
	shm_fd_memoria = shm_open(name, O_RDWR, 0666);

	if(shm_fd_memoria==-1){ 
		printf("Memoria NO existe\n");
	}
	if(shm_fd_memoria==-1){
		exit(1);
	}

	//((Shared_mem*)ptr_memoria)->nombre = nombrec;
	//((Shared_mem*)ptr_memoria)->apellido = apellidoc;
	//((Shared_mem*)ptr_memoria)->id = idc;
	int cont = 0;
	int inter = 0;

	sem_t *sem_id = sem_open(semaforomem, O_CREAT, 0600);
	 // CONSULTA DE SEMAFORO; 
	ptr_memoria = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd_memoria, 0);
	printf("SEM_ID = %i\n", sem_id);
	printf("ESPERANDO SEMAFORO...\n");	
	sem_wait(sem_id);
	printf("| TOMO TOKEN |\n");

    name1= (char *)ptr_memoria;
    apellido1 = (char *)name1 + sizeof(name1);
    ed1 = (char *)apellido1 + sizeof(apellido1);
    estado = (int *)ed1 + sizeof(ed1);



	sprintf(name1,nombrec);
	sprintf(apellido1,apellidoc);
	sprintf(ed1,idc);


	printf("ESPERANDO SUSCRIPCION ...\n");
	usleep(3000*1000);
	printf("CLIENTE SUSCRITO =) ");	
	sem_post(sem_id);
	printf("FINALIZO \n");
	*estado = 1;
	close(shm_fd_memoria);
	sem_close(sem_id);


	return 0;
}

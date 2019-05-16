#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <semaphore.h>
#include <time.h>
#include <math.h>
#include <ctime>
#include <cmath>
#include <iostream>

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
const char *aviso = "MemoriaAviso";


int main(int argc, char *argv[])
{
	
	//sem_close(sem_id); // CERRANDO SEMAFORO POR SI FALLA EL PROGRAMA Y QUEDA ABIERTO;
	
	int shm_fd_memoria;
	int shm_fd_aviso;
	void *ptr_memoria;
 	void *ptr_aviso;

	char *nombrec;
	char *apellidoc;
	char *idc;

	char *name1;
	char *apellido1;
	char *ed1;
	int *estado = 0;

	int  *reset = 0;

	srand(time(NULL));

	int tiempo = (5000000*10)+rand()%((2000001*10)-1);
	int tiempo2 = (500*1000)+rand()%((2001*1000)-1);
	int realsleep = tiempo2 * tiempo;

	//reloj 

	float x,y;

	clock_t time_req;

	time_req = clock();	

	
	nombrec = argv[1];	
	apellidoc = argv[2];
	idc = argv[3];
	
	shm_fd_memoria = shm_open(name, O_RDWR, 0666);

	shm_fd_aviso = shm_open(aviso, O_RDWR, 0666);

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
	sem_t *sem_idc = sem_open(semaforocajas, O_CREAT, 0600);
	 // CONSULTA DE SEMAFORO; 
	ptr_memoria = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd_memoria, 0);
	ptr_aviso = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd_aviso, 0);	


	printf("SEM_ID = %i\n", sem_id);
	printf("ESPERANDO SEMAFORO...\n");	
	sem_wait(sem_id);
	printf("| TOMO TOKEN |\n");

    name1= (char *)ptr_memoria;
    apellido1 = (char *)name1 + sizeof(name1);
    ed1 = (char *)apellido1 + sizeof(apellido1);
    estado = (int *)ed1 + sizeof(ed1);
    reset = (int *)ptr_aviso;



	sprintf(name1,nombrec);
	sprintf(apellido1,apellidoc);
	sprintf(ed1,idc);


	printf("ESPERANDO SUSCRIPCION ...\n");
	for(int h = 0; h < (1000*10000); h++)
	{
		
	}
	printf("CLIENTE SUSCRITO =) ");	
	sem_post(sem_id);
	printf("FINALIZO \n");
	


	sem_wait(sem_idc);
	*estado = 1;
	printf("TOMO %i\n", cont);

	for(int i=0; i< realsleep ; i++)
	{
		y = log(pow(i,500000));
	}
	time_req = clock();

	cout << "Using pow function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;

	sem_post(sem_idc);	
	*reset = 2;	
	close(shm_fd_memoria);

	return 0;
}

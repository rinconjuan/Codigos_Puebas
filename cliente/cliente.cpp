#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct 
{
int quantity;
int product_id;
char flag;
}Shared_mem;

const char *name = "MemoriaCompartida";

int main(int argc, char const *argv[])
{
	
	int shm_fd_memoria;
	void *ptr_memoria; 
	Shared_mem men_memoria;

	shm_fd_memoria = shm_open(name, O_RDWR, 0666);

	if(shm_fd_memoria==-1){ 
		printf("Memoria NO existe\n");
	}
	if(shm_fd_memoria==-1){
		exit(1);
	}

	printf("TOO NICE");




	return 0;
}

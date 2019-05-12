#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>

using namespace std;

#define BUFFER_SIZE 10

typedef unsigned char uchar;

const int SIZE = 4096; // Size in bytes of the shared memory section
const char *name = "MemoriaCompartida"; // Name of the shared memory section\

typedef struct{
	int number;
}item;

int main(int argc, char *argv[])
{
	

	shm_fd_memoria = shm_open(name, O_RDWR, 0666);

	if(shm_fd_memoria==-1){ 
		printf("Memoria NO existe\n");
	}
	if(shm_fd_memoria==-1){
		exit(1);
	}



	while(cont < 10)
	{

		int x = 10;

		
		in = (int*)((uchar*)ptr_memoria);
		queue[*in].number = x;

		usleep(200*1000); 
		cont ++;

	}

	close(shm_fd_memoria);
	
	



	return 0;
}


all: main 
	
main: cliente.o 
	g++ -o cliente cliente.o -lpthread -lrt

cliente.o: cliente.cpp
	g++ -c cliente.cpp 

run: cliente
	./cliente

.PHONY: clean

clean:
	rm -f cliente *.o
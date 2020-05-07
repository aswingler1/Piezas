Piezas: Piezas.o 
	g++ -Wall -pedantic -g -o Piezas Piezas.o

Piezas.o: Piezas.h Piezas.cpp
	g++ -Wall -pedantic -g -std=c++11 -c Piezas.cpp



clean:
	rm -f Piezas Piezas.exe Piezas.o PiezasTest.o
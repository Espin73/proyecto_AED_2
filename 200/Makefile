#Compilación 200

a.out: main.o Fecha.o Cuac.o DiccionarioCuacs.o
	g++ main.o Fecha.o Cuac.o DiccionarioCuacs.o -o a.out

main.o: main.cpp DiccionarioCuacs.h Cuac.h Fecha.h
	g++ -c main.cpp

Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp

Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp

DiccionarioCuacs.o: DiccionarioCuacs.cpp DiccionarioCuacs.h Cuac.h Fecha.h
	g++ -c DiccionarioCuacs.cpp

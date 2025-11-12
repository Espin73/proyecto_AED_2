#Compilación 300

a.out: main.o Fecha.o Cuac.o DiccionarioCuacs.o ArbolFechas.o
	g++ main.o Fecha.o Cuac.o DiccionarioCuacs.o ArbolFechas.o -o a.out

main.o: main.cpp DiccionarioCuacs.h Cuac.h Fecha.h ArbolFechas.h
	g++ -c main.cpp

Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp

Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp

ArbolFechas.o: ArbolFechas.cpp ArbolFechas.h Cuac.h Fecha.h
	g++ -c ArbolFechas.cpp

DiccionarioCuacs.o: DiccionarioCuacs.cpp DiccionarioCuacs.h Cuac.h Fecha.h ArbolFechas.h
	g++ -c DiccionarioCuacs.cpp
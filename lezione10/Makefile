main.exe: main.o forma.o triangolo.o cerchio.o
	g++ main.o forma.o triangolo.o cerchio.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

forma.o: forma.cpp
	g++ -c forma.cpp -o forma.o

triangolo.o: triangolo.cpp
	g++ -c triangolo.cpp -o triangolo.o

cerchio.o: cerchio.cpp
	g++ -c cerchio.cpp -o cerchio.o

.PHONY: clean

clean:
	rm *.exe *.o
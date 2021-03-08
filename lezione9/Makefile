all: start

start: main.o
	g++ -o start main.o


main.o: main.cpp dbuffer.h
	g++ -c main.cpp

clean:
	rm -f *.o
	rm -f *./start
	rm -f *~

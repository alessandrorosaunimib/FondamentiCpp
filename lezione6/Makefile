all: start

start: dbuffer.o main.o
	g++ -o start dbuffer.o main.o

dbuffer.o: dbuffer.cpp dbuffer.h

main.o: main.cpp dbuffer.h
	g++ -c main.cpp

clean:
	rm -f *.o
	rm -f *./start
	rm -f *~

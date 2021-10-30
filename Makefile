all: compile

compile: main main.o
	g++ -o main main.o
	
main: main.cpp
	g++ -c main.cpp
	
clean:
	rm -f *.o compile

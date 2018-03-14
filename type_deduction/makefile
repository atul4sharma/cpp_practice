

all: clean run.lab

clean:
	rm -f run.lab *.o

run.lab: main.cpp
	g++ -std=c++11 -Wall main.cpp typestring.hpp -I. -o run.lab

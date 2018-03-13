

all: clean run.lab

clean:
	rm -f run.lab *.o

run.lab: elision.cpp
	g++ -std=c++11 -fno-elide-constructors elision.cpp bar.cpp -I. -o run.lab
	#g++ -std=c++11 elision.cpp bar.cpp -I. -o run.lab

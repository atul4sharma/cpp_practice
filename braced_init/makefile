
all: clean run.lab

clean:
	rm -Rf *.o *.so *.lab

run.lab: main.cpp
	g++ -std=c++11 -fno-elide-constructors -Wall \
		-I.. \
		-L../elision/ -lbar \
		main.cpp -o run.lab

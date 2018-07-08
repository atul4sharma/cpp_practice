
all: clean run.lab

clean:
	rm -Rf *.o *.so *.lab

run.lab: main.cpp
	g++ -std=c++11 -Wall \
		-I ./\
		*.cpp -o run.lab

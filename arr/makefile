
all: clean run.lab

clean:
	rm -Rf *.o *.so *.lab

run.lab: main.cpp
	g++ -std=c++11 -fno-elide-constructors -Wall \
		-I/home/atul/cpp_practice_github/elision/ \
		-L/home/atul/cpp_practice_github/elision/ -lbar \
		main.cpp -o run.lab



all: clean run.lab

clean:
	rm -f run.lab *.o *.so

run.lab: main.cpp
	g++ -std=c++11 -I/home/at.sharma/cpp_practice_github/ -L/home/at.sharma/cpp_practice_github/elision/ -lbar main.cpp -o run.lab
	#g++ -std=c++11 -fno-elide-constructors -I/home/at.sharma/cpp_practice_github/ -L/home/at.sharma/cpp_practice_github/elision/ -lbar main.cpp -o run.lab

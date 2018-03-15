

all: clean libbar.so run.lab

clean:
	rm -f run.lab *.o *.so

libbar.so: bar.cpp
	g++ -std=c++11 -c -fPIC -shared -I. bar.cpp -o libbar.so

run.lab: elision.cpp
	g++ -std=c++11 -fno-elide-constructors -I. -L. -lbar elision.cpp -o run.lab
	#g++ -std=c++11 -I. -L. -lbar elision.cpp -o run.lab

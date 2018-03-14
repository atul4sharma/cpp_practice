

all: clean run.lab

clean:
	rm -f run.lab *.o

run.lab: main.cpp
	#g++ -std=c++11 -Wall main.cpp typestring.hpp -I. -o run.lab
	#g++ -std=c++11 -Wall -fno-elide-constructors use_cases_auto.cpp -o run.lab
	g++ -std=c++11 -Wall use_cases_auto.cpp -o run.lab

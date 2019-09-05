
all: cpp11

clean:
	rm -rf bin
	mkdir bin

cpp11:
	g++ -std=c++11 -Wall -Werror -I . tests/main.cpp tests/print.cpp -o bin/cpp11_print.out


cpp14:
	g++ -std=c++14 -Wall -Werror -I . tests/main.cpp tests/print.cpp -o bin/cpp14_print.out

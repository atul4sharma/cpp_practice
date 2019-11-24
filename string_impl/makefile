
all: cpp14

clean:
	rm -rf bin
	mkdir bin

libstring:
	g++ -std=c++14 -Wall -Werror -O2 -I . -c -fPIC include/string.cpp -o bin/string.o
	g++ -std=c++14 -Wall -Werror -O2 -I . -shared bin/string.o -o bin/libutils_string.so


cpp14: libstring
	g++ -std=c++14 -Wall -Werror -O2 -I . -L ./bin -l utils_string tests/main.cpp tests/string.cpp -o bin/cpp14_string.out


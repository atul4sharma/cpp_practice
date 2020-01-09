
all: cpp14

clean:
	rm -rf bin
	mkdir bin

cpp11:
	g++ -std=c++11 -Wall -Werror -I . tests/main.cpp tests/rel_op_generator.cpp -o bin/cpp11.out

cpp14:
	g++ -std=c++14 -Wall -Werror -I . tests/main.cpp tests/rel_op_generator.cpp -o bin/cpp14.out

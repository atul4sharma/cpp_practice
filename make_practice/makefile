
GCC_CMD = g++ -std=c++14 -Wall -Werror

cpp14: foo.o bar.o
	$(GCC_CMD) foo.o bar.o main.cpp -o cpp14.out


foo.o: foo.hpp foo.cpp
	$(GCC_CMD) -c foo.cpp -o foo.o

bar.o: bar.hpp bar.cpp
	$(GCC_CMD) -c bar.cpp -o bar.o

clean:
	rm -rf *.o *.so *.out


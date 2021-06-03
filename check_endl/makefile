
GCC_CMD = g++ -std=c++14 -Wall -Werror

cpp14: main.o
	$(GCC_CMD) -o cpp14.out main.o -L. -lbar

main.o: libbar.so
	$(GCC_CMD) -c -o main.o main.cpp

libbar.so: bar.o
	$(GCC_CMD) -shared bar.o -o libbar.so

bar.o: bar.hpp bar.cpp
	$(GCC_CMD) -fPIC -c bar.cpp -o bar.o

clean:
	rm -rf *.o *.so *.out

# set -x LD_LIBRARY_PATH (pwd) $LD_LIBRARY_PATH

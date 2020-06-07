

GCC_CMD = g++ -std=c++17 -Wall -Werror

cpp17: libfoo_bar.so
	$(GCC_CMD) -o cpp17.out main.cpp -ldl

cpp17_rdym: libfoo_bar.so
	$(GCC_CMD) -rdynamic -o cpp17_rdym.out main.cpp -ldl

libfoo_bar.so: foo.o bar.o
	$(GCC_CMD) -shared foo.o bar.o -o libfoo_bar.so

foo.o: foo.hpp foo.cpp
	$(GCC_CMD) -fPIC -c foo.cpp -o foo.o

bar.o: bar.hpp bar.cpp
	$(GCC_CMD) -fPIC -c bar.cpp -o bar.o

clean:
	rm -rf *.o *.so *.out


# set -x LD_LIBRARY_PATH (pwd) $LD_LIBRARY_PATH

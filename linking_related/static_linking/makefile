
GCC_CMD = g++ -std=c++17 -Wall -Werror

cpp17: libfoo_bar.a
	$(GCC_CMD) -o cpp17.out main.cpp -L. -lfoo_bar

libfoo_bar.a: foo.o bar.o
	ar rvs libfoo_bar.a foo.o bar.o

foo.o: foo.hpp foo.cpp
	$(GCC_CMD) -c foo.cpp -o foo.o

bar.o: bar.hpp bar.cpp
	$(GCC_CMD) -c bar.cpp -o bar.o

clean:
	rm -rf *.o *.so *.out *.a


# set -x LD_LIBRARY_PATH (pwd) $LD_LIBRARY_PATH

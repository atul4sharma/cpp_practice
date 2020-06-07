
GCC_CMD = g++ -std=c++17 -Wall -Werror

cpp17: libfoo_bar.so
	$(GCC_CMD) -o cpp17.out main.cpp -L. -lfoo_bar

rpath_build: libfoo_bar.so
	$(GCC_CMD) -o cpp17_rpath.out main.cpp -Wl,-rpath=. -L. -lfoo_bar

rpath_build_abs: libfoo_bar.so
	$(GCC_CMD) -o cpp17_rpath_abs.out main.cpp -Wl,-rpath=/home/atul/cpp_practice_github/linking_related/dynamic_linking -L. -lfoo_bar

libfoo_bar.so: foo.o bar.o
	$(GCC_CMD) -shared foo.o bar.o -o libfoo_bar.so

foo.o: foo.hpp foo.cpp
	$(GCC_CMD) -fPIC -c foo.cpp -o foo.o

bar.o: bar.hpp bar.cpp
	$(GCC_CMD) -fPIC -c bar.cpp -o bar.o

clean:
	rm -rf *.o *.so *.out


# set -x LD_LIBRARY_PATH (pwd) $LD_LIBRARY_PATH

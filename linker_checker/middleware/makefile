
all: foo.cpp
	g++ -std=c++14 -c -I/home/at.sharma/cpp_practice_github/linker_checker -fPIC foo.cpp -o ../objs/foo.o
	g++ -std=c++14 -shared ../objs/foo.o -o ../libs/libmiddleware.so -L/home/at.sharma/cpp_practice_github/linker_checker/libs -lservices
	@#g++ -std=c++14 -shared ../objs/foo.o -o ../libs/libmiddleware.so -Wl,-rpath=/home/at.sharma/cpp_practice_github/linker_checker/libs
	@#g++ -std=c++14 -shared ../objs/foo.o -o ../libs/libmiddleware.so


all: main.cpp
	g++ -std=c++14 -c -fPIC main.cpp -I/home/at.sharma/cpp_practice_github/linker_checker -o objs/main.o
	@#g++ -std=c++14 main.cpp -I/home/at.sharma/cpp_practice_github/linker_checker -L/home/at.sharma/cpp_practice_github/linker_checker/libs -lmiddleware -lservices
	@#export LD_LIBRARY_PATH=/home/at.sharma/cpp_practice_github/linker_checker/libs:${LD_LIBRARY_PATH}; g++ -std=c++14 main.cpp -I/home/at.sharma/cpp_practice_github/linker_checker -L/home/at.sharma/cpp_practice_github/linker_checker/libs -lmiddleware
	@#g++ -std=c++14 objs/main.o -o run.lab -L/home/at.sharma/cpp_practice_github/linker_checker/libs -lmiddleware -Wl,-rpath=/home/at.sharma/cpp_practice_github/linker_checker/libs
	g++ -std=c++14 objs/main.o -o run.lab -L/home/at.sharma/cpp_practice_github/linker_checker/libs -lmiddleware -lservices

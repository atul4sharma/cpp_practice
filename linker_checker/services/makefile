
.DEFAULT_GOAL := all

clean:
	@rm -rf ../libs
	@rm -rf ../objs

create_dir: clean
	@mkdir ../libs/
	@mkdir ../objs


all: clean create_dir bar.cpp
	g++ -std=c++14 -c -I/home/at.sharma/cpp_practice_github/linker_checker -fPIC bar.cpp -o ../objs/bar.o 
	g++ -std=c++14 -shared ../objs/bar.o -o ../libs/libservices.so

.PHONY:clean, create_dir


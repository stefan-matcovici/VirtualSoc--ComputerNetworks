LIBS=ServerLibs/Communication ServerLibs/Command ServerLibs/Handler ServerLibs/Server
INCLUDE_PATH=ServerLibs/

main_exec: build
	g++ main/main.cpp $(wildcard build/*) -I$(INCLUDE_PATH) -o server -ljansson -lsqlite3 -lpthread

build:
	mkdir build/
	for dir in $(LIBS); do \
		cd $$dir; \
		g++ -std=c++11 -c *.cpp -I../ -ljansson -lsqlite3 -lpthread; \
		mv *.o ../../build; \
		cd -; \
	done

.PHONY: clean
clean:
	rm -rf build/ server

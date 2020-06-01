FLAGS = -Wall -Werror 

all: bin build bin/calcFrequency

bin/calcFrequency: build/src/main.o build/src/func.o build/src/string.o
	gcc $(FLAGS) build/src/main.o build/src/func.o build/src/string.o -o bin/calcFrequency

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

build/src/func.o: src/func.c
	gcc $(FLAGS) -c src/func.c -o build/src/func.o

build/src/string.o: src/string.c
	gcc $(FLAGS) -c src/string.c -o build/src/string.o

bin:
	mkdir -p bin

build:
	mkdir -p build/src

run: all
	./bin/calcFrequency Input.txt Output.txt

.PHONY: clean

clean:
	rm -rf build bin
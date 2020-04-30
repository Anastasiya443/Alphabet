all:bin/program
bin/program:build/src/main.o build/src/fc.o build/src/ft.o
	gcc -Wall -Werror build/src/main.o build/src/fc.o build/src/ft.o -o bin/program -lm
build/src/fc.o:src/fc.c
	gcc -Wall -Werror -c src/fc.c -o build/src/fc.o
build/src/main.o:src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o
build/src/ft.o:src/ft.c
	gcc -Wall -Werror -c src/ft.c -o build/src/ft.o
run:
	./bin/program
clean:
	rm -rf build/src/*.o build/test/*.o bin/program
test:bin/program-test
bin/program-test:build/test/main.o build/test/fc.o build/test/ft.o
	gcc -Wall -Werror build/test/main.o build/test/fc.o build/test/ft.o -o bin/program-test -lm
build/test/fc.o:src/fc.c
	gcc -Wall -Werror -c src/fc.c -o build/test/fc.o
build/test/main.o:test/main.c
	gcc -I thirdparty src -c test/main.c -o build/test/main.o
build/test/ft.o:src/ft.c
	gcc -Wall -Werror -c src/ft.c -o build/test/ft.o

.PHONY: clean all run run_test
#all:bin/program bin/program_test
all:bin/program
#bin/program:build/src/main.o build/src/*.o build/src/*.o
#	gcc -Wall -Werror build/src/main.o build/src/*.o build/src/*.o -o bin/program -lm
bin/program:build/src/main.o
	gcc -Wall -Werror build/src/main.o -o bin/program -lm
#build/src/*.o:src/*.c
#	gcc -Wall -Werror -c src/*.c -o build/src/*.o
build/src/main.o:src/main.c
	gcc -I src -Wall -Werror -c src/main.c -o build/src/main.o
#build/src/*.o:src/*.c
#	gcc -Wall -Werror -c src/*.c -o build/src/*.o
#bin/program_test:build/test/main.o build/test/*.o build/test/*.o build/src/*.o build/src/*.o
#	gcc -Wall -Werror build/test/main.o build/test/*.o build/test/*.o build/src/*.o build/src/*.o -o bin/program-test -lm
#build/test/*.o:test/*.c
#	gcc -I thirdparty src -Wall -Werror -c test/*.c -o build/test/*.o
#build/test/main.o:test/main.c
#	gcc -I thirdparty src -Wall -Werror -c test/main.c -o build/test/main.o
#build/test/*.o:test/*.c
#	gcc -I thirdparty src -Wall -Werror -c test/*.c -o build/test/*.o
run:
	./bin/program
#run_test:
#	./bin/program_test
clean:
	rm -rf build/src/*.o build/test/*.o bin/program bin/program_test

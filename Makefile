.PHONY: clean all run run_test
all:bin/program bin/program_test
bin/program:build/src/main.o build/src/search_array.o build/src/sorting_and_write.o
	gcc -Wall -Werror build/src/main.o build/src/search_array.o build/src/sorting_and_write.o -o bin/program -lm
build/src/search_array.o:src/search_array.c
	gcc -Wall -Werror -c src/search_array.c -o build/src/search_array.o
build/src/main.o:src/main.c
	gcc -I src -Wall -Werror -c src/main.c -o build/src/main.o
build/src/sorting_and_write.o:src/sorting_and_write.c
	gcc -Wall -Werror -c src/sorting_and_write.c -o build/src/sorting_and_write.o
bin/program_test:build/test/main.o build/test/search_array.o build/test/sorting_and_write.o build/src/search_array.o build/src/sorting_and_write.o
	gcc -Wall -Werror build/test/main.o build/test/search_array.o build/test/sorting_and_write.o build/src/search_array.o build/src/sorting_and_write.o -o bin/program_test -lm
build/test/search_array.o:test/search_array_testing.c
	gcc -I thirdparty -I src -Wall -Werror -c test/search_array_testing.c -o build/test/search_array.o
build/test/main.o:test/main.c
	gcc -I thirdparty -I src -Wall -Werror -c test/main.c -o build/test/main.o
build/test/sorting_and_write.o:test/sorting_and_write_testing.c
	gcc -I thirdparty -I src -Wall -Werror -c test/sorting_and_write_testing.c -o build/test/sorting_and_write.o
run:
	./bin/program ./words.txt
run_test:
	./bin/program_test
clean:
	rm -rf build/src/*.o build/test/*.o bin/program bin/program_test out.txt

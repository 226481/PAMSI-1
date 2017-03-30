
FLAGS = -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/main.o obj/Tablica.o obj/Stoper.o
	g++ $(FLAGS) -o a.out obj/main.o obj/Tablica.o obj/Stoper.o

obj/main.o: src/main.cpp inc/Tablica.hh inc/Stoper.hh
	g++ $(FLAGS) -c -o obj/main.o src/main.cpp

obj/Stoper.o: src/Stoper.cpp inc/Stoper.hh inc/Testowalny.hh
	g++ $(FLAGS) -c -o obj/Stoper.o src/Stoper.cpp

obj/Tablica.o: src/Tablica.cpp inc/Tablica.hh inc/Testowalny.hh
	g++ $(FLAGS) -c -o obj/Tablica.o src/Tablica.cpp

clean:
	rm -f obj/*.o *.dat a.out


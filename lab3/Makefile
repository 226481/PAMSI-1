
FLAGS = -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/main.o obj/Elem.o obj/Lista.o obj/Stoper.o obj/Kolejka.o obj/Stos.o
	g++ $(FLAGS) -o a.out obj/main.o obj/Elem.o obj/Lista.o obj/Stoper.o obj/Kolejka.o obj/Stos.o

obj/main.o: src/main.cpp inc/Lista.hh inc/Stoper.hh inc/Libs.hh inc/Kolejka.hh inc/Stos.hh
	g++ $(FLAGS) -c -o obj/main.o src/main.cpp

obj/Lista.o: src/Lista.cpp inc/Lista.hh inc/ITestowalny.hh inc/IPojemnik.hh inc/Elem.hh inc/Libs.hh
	g++ $(FLAGS) -c -o obj/Lista.o src/Lista.cpp

obj/Kolejka.o: src/Kolejka.cpp inc/Kolejka.hh inc/ITestowalny.hh inc/IPojemnik.hh inc/Elem.hh inc/Libs.hh
	g++ $(FLAGS) -c -o obj/Kolejka.o src/Kolejka.cpp

obj/Stos.o: src/Stos.cpp inc/Stos.hh inc/ITestowalny.hh inc/IPojemnik.hh inc/Elem.hh inc/Libs.hh
	g++ $(FLAGS) -c -o obj/Stos.o src/Stos.cpp

obj/Elem.o: src/Elem.cpp inc/Elem.hh
	g++ $(FLAGS) -c -o obj/Elem.o src/Elem.cpp

obj/Stoper.o: src/Stoper.cpp inc/Stoper.hh inc/ITestowalny.hh inc/Libs.hh
	g++ $(FLAGS) -c -o obj/Stoper.o src/Stoper.cpp

clean:
	rm -f obj/*.o a.out


FLAGS = -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/main.o obj/Elem.o obj/Lista.o
	g++ $(FLAGS) -o a.out obj/main.o obj/Elem.o obj/Lista.o

obj/main.o: src/main.cpp inc/Lista.hh
	g++ $(FLAGS) -c -o obj/main.o src/main.cpp

obj/Lista.o: src/Lista.cpp inc/Lista.hh inc/ITestowalny.hh inc/IPojemnik.hh inc/Elem.hh
	g++ $(FLAGS) -c -o obj/Lista.o src/Lista.cpp

obj/Elem.o: src/Elem.cpp inc/Elem.hh
	g++ $(FLAGS) -c -o obj/Elem.o src/Elem.cpp

clean:
	rm -f obj/*.o a.out



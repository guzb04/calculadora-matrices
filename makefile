
./obj:
	mkdir ./obj

all: calculadoraMatriz

calculadoraMatriz: ./obj/main.o ./obj/matriz.o
	g++ ./obj/main.o ./obj/matriz.o -o calculadoraMatriz

./obj/main.o: main.cpp ./include/matriz.h
	g++ -c main.cpp -o ./obj/main.o

./obj/matriz.o: src/matriz.cpp include/matriz.h
	g++ -c src/matriz.cpp -o obj/matriz.o


clean:
	rm -f obj/*.o calculadoraMatriz


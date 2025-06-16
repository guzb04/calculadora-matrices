obj_dir := ./obj

$(obj_dir):
	mkdir -p $@

all: calculadoraMatriz

calculadoraMatriz: ./obj/main.o ./obj/matriz.o
	g++ $^ -o $@

./obj/main.o: main.cpp ./include/matriz.h | $(obj_dir)
	g++ -c $< -o $@

./obj/matriz.o: src/matriz.cpp include/matriz.h | $(obj_dir)
	g++ -c $< -o $@

clean:
	rm -f $(obj_dir)/*.o calculadoraMatriz


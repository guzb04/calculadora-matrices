obj_dir := ./obj

objects := $(obj_dir)/main.o $(obj_dir)/matriz.o $(obj_dir)/AVLMatrices.o

$(obj_dir):
	mkdir -p $@

all: calculadoraMatriz

calculadoraMatriz: $(objects)
	g++ $^ -o $@

./obj/main.o: main.cpp ./include/matriz.h ./include/AVLMatrices.h | $(obj_dir)
	g++ -c $< -o $@

./obj/matriz.o: src/matriz.cpp include/matriz.h | $(obj_dir)
	g++ -c $< -o $@

./obj/AVLMatrices.o: src/AVLMatrices.cpp include/matriz.h ./include/AVLMatrices.h | $(obj_dir)
	g++ -c $< -o $@ -I./include

clean:
	rm -f $(obj_dir)/*.o calculadoraMatriz


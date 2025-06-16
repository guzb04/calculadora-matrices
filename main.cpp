
#include "./include/matriz.h"
#include <cstdio>
int main () {
  
  TMatrizFloat matriz = crearMatrizFloatVacia(3, 4);
  printf("matriz de %d por %d", filasMatrizFloat(matriz), columnasMatrizFloat(matriz));
  liberarMatrizFloat(matriz);


  return 0;
}

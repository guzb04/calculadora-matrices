
#include "include/matriz.h"
#include <cstdio>
int main() {

  TMatriz m1 = crearMatrizVacia(3, 3);
  TMatriz m2 = crearMatrizVacia(3, 3);
  TMatriz m5 = crearMatrizVacia(4, 4);

  for (int i = 0; i < filasMatriz(m1); i++) {
    for (int j = 0; j < columnasMatriz(m1); j++) {
      cargarMatriz(m1, i, j, i + j);
    }
  }

  cargarMatriz(m5, 0, 0, 11);
  cargarMatriz(m5, 0, 1, 1);
  cargarMatriz(m5, 0, 2, 1);
  cargarMatriz(m5, 0, 3, 4);
  cargarMatriz(m5, 1, 0, 2);
  cargarMatriz(m5, 1, 1, -3);
  cargarMatriz(m5, 1, 2, -1);
  cargarMatriz(m5, 1, 3, 3);
  cargarMatriz(m5, 2, 0, 2);
  cargarMatriz(m5, 2, 1, 0);
  cargarMatriz(m5, 2, 2, 1);
  cargarMatriz(m5, 2, 3, 1);
  cargarMatriz(m5, 3, 0, -7);
  cargarMatriz(m5, 3, 1, -7);
  cargarMatriz(m5, 3, 2, 7);
  cargarMatriz(m5, 3, 3, 1);
  imprimirMatriz(m5);
  printf("Determinante: %.2f\n\n", calcularDeterminante(m5));


  for (int i = 0; i < filasMatriz(m2); i++) {
    for (int j = 0; j < columnasMatriz(m2); j++) {
      cargarMatriz(m2, i, j, i + j + 3);
    }
  }

  imprimirMatriz(m1);
  imprimirMatriz(m2);

  TMatriz m3 = multiplicarMatrices(m1, m2);

  if (m3 != NULL) {
    imprimirMatriz(m3);
  } else {
    printf("El producto de matriz devuelve NULL, revisar filas y columnas de "
           "las matrices");
  }

  TMatriz m4 = sumarMatrices(m1, m2);

  if (m4 != NULL) {
    imprimirMatriz(m4);
  } else {
    printf("la suma de matrices devuelve NULL, revisar filas y columnas");
  }

  return 0;
}

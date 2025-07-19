#include <cstdio>
#include <iostream>
#include "include/AVLMatrices.h"
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

  TMatriz m7 = calcularAdjunta(m5);
  printf("Adjunta: \n\n");
  imprimirMatriz(m7);
  TMatriz m8 = calcularInversa(m5);
  printf("Inversa: \n\n");
  imprimirMatriz(m8);
  TMatriz m9 = multiplicarMatrices(m5, m8);
  imprimirMatriz(m9);

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

  TMatriz m6 = calcularTraspuesta(m3);
  printf("la traspuesta de m3 es: \n");

  imprimirMatriz(m6);

  TMatriz m4 = sumarMatrices(m1, m2);

  if (m4 != NULL) {
    imprimirMatriz(m4);
  } else {
    printf("la suma de matrices devuelve NULL, revisar filas y columnas");
  }

  TAVLMatriz avl = crearAVLMatrices();
  insertar(avl, m1, 1);
  insertar(avl, m2, 2);
  insertar(avl, m3, 3);
  insertar(avl, m4, 4);
  insertar(avl, m5, 5);
  insertar(avl, m6, 6);
  insertar(avl, m7, 7);
  insertar(avl, m8, 8);
  insertar(avl, m9, 9);
  imprimirPreOrden(avl);



  liberarMatriz(m1);
  liberarMatriz(m2);
  liberarMatriz(m3);
  liberarMatriz(m4);
  liberarMatriz(m5);
  liberarMatriz(m6);
  liberarMatriz(m7);
  liberarMatriz(m8);
  liberarMatriz(m9);

  return 0;
}

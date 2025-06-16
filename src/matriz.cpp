#include "../include/matriz.h"
#include <cstddef>
struct matrizFloat {

  int filas, columnas;

  float **celdas;
};

TMatrizFloat crearMatrizFloatVacia(int n, int m) {

  TMatrizFloat nuevaMatriz = new matrizFloat;

  float **celdas = new float *[n];
  celdas[0] = new float[n * m];

  // como celdas es un array de punteros, reservo memoria para n*m floats y le
  // asigno a cada celda[i] la fila i, esto permite doble indice para acceder a
  // los valores de la matriz mas adelante

  for (int i = 1; i < n; i++) {
    celdas[i] = celdas[i - 1] + m;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      celdas[i][j] = 0;
    }
  }

  nuevaMatriz->celdas = celdas;
  nuevaMatriz->filas = n;
  nuevaMatriz->columnas = m;

  return nuevaMatriz;
}

void liberarMatrizFloat(TMatrizFloat &matriz) {
  delete[] matriz->celdas[0];
  delete[] matriz->celdas;

  delete matriz;

  matriz = NULL;
}

int filasMatrizFloat(TMatrizFloat matriz) { return matriz->filas; }

int columnasMatrizFloat(TMatrizFloat matriz) { return matriz->columnas; }

void cargarMatrizFloat(TMatrizFloat matriz, int fila, int columna,
                       float valor) {
  matriz->celdas[fila][columna] = valor;
}

TMatrizFloat escalarPorMatrizFloat(int n, TMatrizFloat matriz) {

  TMatrizFloat aRetornar =
      crearMatrizFloatVacia(matriz->filas, matriz->columnas);

  for (int i = 0; i < matriz->filas; i++) {
    for (int j = 0; j < matriz->columnas; j++) {

      aRetornar->celdas[i][j] = matriz->celdas[i][j] * n;
    }
  }

  return aRetornar;
}

float celdaMatrizFloat(int fila, int col, TMatrizFloat matriz) {
  return matriz->celdas[fila][col];
}

TMatrizFloat sumarMatricesFloat(TMatrizFloat m1, TMatrizFloat m2) {
  if (m1->filas != m2->filas || m2->columnas != m1->columnas) {
    return NULL;
  } else {
    TMatrizFloat nuevaMatriz = crearMatrizFloatVacia(m1->filas, m1->columnas);
    for (int i = 0; i < m1->filas; i++) {
      for (int j = 0; j < m1->columnas; j++) {
        nuevaMatriz->celdas[i][j] = m1->celdas[i][j] + m2->celdas[i][j];
      }
    }
    return nuevaMatriz;
  }
}

TMatrizFloat multiplicarMatrices(TMatrizFloat mIzq, TMatrizFloat mDer) {
  if (mIzq->columnas != mDer->filas) {
    return NULL;
  } else {
    TMatrizFloat nuevaMatriz =
        crearMatrizFloatVacia(mIzq->filas, mDer->columnas);

    float c = 0;

    for (int i = 0; i < mIzq->filas; i++) {
      for (int j = 0; j < mDer->columnas; j++) {
        for (int k = 0; k < mIzq->columnas; k++) {

          c = c + (mIzq->celdas[i][k] * mDer->celdas[k][j]);
        }
        cargarMatrizFloat(nuevaMatriz, i, j, c);
      }
    }
  }
}

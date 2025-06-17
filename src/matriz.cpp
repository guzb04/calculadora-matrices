#include "../include/matriz.h"
#include <cstddef>
#include <cstdio>
struct matriz {

  int filas, columnas;

  float **celdas;
};

TMatriz crearMatrizVacia(int n, int m) {

  TMatriz nuevaMatriz = new matriz;

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

void liberarMatriz(TMatriz &matriz) {
  delete[] matriz->celdas[0];
  delete[] matriz->celdas;

  delete matriz;

  matriz = NULL;
}

int filasMatriz(TMatriz matriz) { return matriz->filas; }

int columnasMatriz(TMatriz matriz) { return matriz->columnas; }

void cargarMatriz(TMatriz matriz, int fila, int columna, float valor) {
  matriz->celdas[fila][columna] = valor;
}

TMatriz escalarPorMatriz(int n, TMatriz matriz) {

  TMatriz aRetornar = crearMatrizVacia(matriz->filas, matriz->columnas);

  for (int i = 0; i < matriz->filas; i++) {
    for (int j = 0; j < matriz->columnas; j++) {

      aRetornar->celdas[i][j] = matriz->celdas[i][j] * n;
    }
  }

  return aRetornar;
}

float celdaMatriz(int fila, int col, TMatriz matriz) {
  return matriz->celdas[fila][col];
}

TMatriz sumarMatrices(TMatriz m1, TMatriz m2) {
  if (m1->filas != m2->filas || m2->columnas != m1->columnas) {
    return NULL;
  } else {
    TMatriz nuevaMatriz = crearMatrizVacia(m1->filas, m1->columnas);
    for (int i = 0; i < m1->filas; i++) {
      for (int j = 0; j < m1->columnas; j++) {
        nuevaMatriz->celdas[i][j] = m1->celdas[i][j] + m2->celdas[i][j];
      }
    }
    return nuevaMatriz;
  }
}

TMatriz multiplicarMatrices(TMatriz mIzq, TMatriz mDer) {
  if (mIzq->columnas != mDer->filas) {
    return NULL;
  } else {
    TMatriz nuevaMatriz = crearMatrizVacia(mIzq->filas, mDer->columnas);

    float c = 0;

    for (int i = 0; i < mIzq->filas; i++) {
      for (int j = 0; j < mDer->columnas; j++) {
        for (int k = 0; k < mIzq->columnas; k++) {

          c = c + (mIzq->celdas[i][k] * mDer->celdas[k][j]);
        }
        cargarMatriz(nuevaMatriz, i, j, c);
        c = 0;
      }
    }
    return nuevaMatriz;
  }
}

float calcularDeterminante1x1(TMatriz matriz) { return matriz->celdas[0][0]; }

float calcularDeterminante2x2(TMatriz matriz) {
  float c = (matriz->celdas[0][0] * matriz->celdas[1][1]) -
            (matriz->celdas[1][0] * matriz->celdas[0][1]);

  return c;
}

float calcularDeterminante(TMatriz matriz) {
  if (matriz->filas != matriz->columnas) {
    return 0;
  } else if (matriz->filas == 2) {
    return calcularDeterminante2x2(matriz);
  } else if (matriz->filas == 1) {
    return calcularDeterminante1x1(matriz);
  } else {

    float det = 0;

    for (int i = 0; i < matriz->columnas; i++) {
      float temp = matriz->celdas[0][i];
      TMatriz matrizRecursiva =
          crearMatrizVacia(matriz->filas - 1, matriz->columnas - 1);
      if (i % 2 == 1) {
        temp = -temp;
      }

      for (int j = 1; j < matriz->filas; j++) {
        for (int k = 0; k != i; k++) {
          cargarMatriz(matrizRecursiva, j - 1, k, matriz->celdas[j][k]);
        }
        for (int k = i + 1; k < matriz->columnas; k++) {
          cargarMatriz(matrizRecursiva, j-1, k-1, matriz->celdas[j][k]);
        }
      }

      temp = temp*calcularDeterminante(matrizRecursiva);
      det = det + temp;

    }

    return det;
  }

  return 0;
}

void imprimirMatriz(TMatriz matriz) {

  printf("Matriz de %d filas por %d columnas: \n", matriz->filas,
         matriz->columnas);

  for (int i = 0; i < matriz->filas; i++) {
    printf("[");

    for (int j = 0; j < matriz->columnas; j++) {
      printf("%.2f", matriz->celdas[i][j]);

      if (j != matriz->columnas - 1) {
        printf("  ");
      }
    }

    printf("]\n");
  }

  printf("\n");
}

#ifndef MATRIZ_H
#define MATRIZ_H

// TMatrizFLoat es un puntero a matriz.
typedef struct matriz *TMatriz;

// crea una matriz que toma valores de tipo float y tiene n filas y m columnas.
TMatriz crearMatrizVacia(int n, int m);

// recibe una matriz y borra la memoria, luego matriz == NULL.
void liberarMatriz(TMatriz &matriz);

// toma una matriz, una fila, columna y un valor e inserta ese valor a la
// posicion dada, no toma en consideracion si ya hay un valor en el indice.
void cargarMatriz(TMatriz matriz, int fila, int columna, float valor);

// multiplica cada valor de la matriz por un escalar dado.
TMatriz escalarPorMatriz(int n, TMatriz matriz);

// retorna el valor de la celda con fila y columna de los parametros.
float celdaMatriz(int fila, int col, TMatriz matriz);

// devuelve la cantidad de filas de una matriz de floats.
int filasMatriz(TMatriz matriz);

// devuelve la cantidad de columnas de una matriz de floats.
int columnasMatriz(TMatriz matriz);

// suma matrices de valores tipo float.
// en caso de que haya una discrepancia en la cantidad de filas o columnas,
// devuelve NULL
TMatriz sumarMatrices(TMatriz m1, TMatriz m2);

// multiplica matrices mIzq X mDer.
// en caso de que la cantidad de columnas de mIzq sea distinto a la cantidad de
// filas de mDer, devuelve NULL.
TMatriz multiplicarMatrices(TMatriz mIzq, TMatriz mDer);

// Calcula el determinante de una matriz, si no es cuadrada retorna 0 y no hace
// ningun chequeo extra, usa funciones auxiliares para2x2 y 1x1, en caso
// de ser mayor a 2x2 hace un llamado recursivo hasta llegar a 2x2.
float calcularDeterminante(TMatriz matriz);

// Imprime una matriz, una fila por renglon encerrada en "[], muestra dos
// digitos despues de la coma"
void imprimirMatriz(TMatriz matriz);

#endif // !MATRIZ_H

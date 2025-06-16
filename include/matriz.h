#ifndef MATRIZ_H
#define MATRIZ_H

//TMatrizFLoat es un puntero a matrizFloat.
typedef struct matrizFloat * TMatrizFloat;

//crea una matriz que toma valores de tipo float y tiene n filas y m columnas. 
TMatrizFloat crearMatrizFloatVacia(int n, int m);

//recibe una matriz y borra la memoria, luego matriz == NULL.
void liberarMatrizFloat(TMatrizFloat &matriz);

//toma una matriz, una fila, columna y un valor e inserta ese valor a la posicion dada, no toma en consideracion si ya hay un valor en el indice.
void cargarMatrizFloat(TMatrizFloat matriz, int fila, int columna, float valor);

//multiplica cada valor de la matriz por un escalar dado.
TMatrizFloat escalarPorMatrizFloat(int n, TMatrizFloat matriz);

//retorna el valor de la celda con fila y columna de los parametros. 
float celdaMatrizFloat(int fila, int col, TMatrizFloat matriz);

//devuelve la cantidad de filas de una matriz de floats.
int filasMatrizFloat(TMatrizFloat matriz);

//devuelve la cantidad de columnas de una matriz de floats.
int columnasMatrizFloat(TMatrizFloat matriz);

//suma matrices de valores tipo float.
//en caso de que haya una discrepancia en la cantidad de filas o columnas, devuelve NULL
TMatrizFloat sumarMatricesFloat(TMatrizFloat m1, TMatrizFloat m2);

//multiplica matrices mIzq X mDer.
//en caso de que la cantidad de columnas de mIzq sea distinto a la cantidad de filas de mDer, devuelve NULL.
TMatrizFloat multiplicarMatrices(TMatrizFloat mIzq, TMatrizFloat mDer);


#endif // !MATRIZ_H

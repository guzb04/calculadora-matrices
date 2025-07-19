#ifndef AVLMATRICES_H
#define AVLMATRICES_H


#include "./matriz.h"

// TAVLMatriz es un puntero a AVLMatriz
typedef struct AVLMatriz *TAVLMatriz;

// crea un avl vacio definido como puntero nulo
TAVLMatriz crearAVLMatrices();

// retorna la altura o 0 en caso de que a sea NULL
int calcularAltura(TAVLMatriz a);

// calcula si el arbol es balanceado o no tomando las alturas del subarbol
// izquierdo menos la altura del subarbol derecho, si el resultado es menor
// estricto que -1 o mayor estricto que 1, el arbol no es balanceado
int calcularBalance(TAVLMatriz a);

// imprime un arbol de matrices en pre orden
void imprimirPreOrden(TAVLMatriz a);

// inserta y aplica rotaciones a un arbol de matrices, usa rotarDer y rotarIzq
// como auxiliares
void insertar(TAVLMatriz &a, TMatriz m, int id);

#endif // !AVLMATRICES_H

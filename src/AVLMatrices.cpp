#include "../include/AVLMatrices.h"
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iostream>

struct AVLMatriz {

  int id, altura;
  TMatriz matriz;
  TAVLMatriz izq, der;
};

int obtenerAltura(TAVLMatriz a) {

  if (a == NULL) {
    return 0;
  }
  return a->altura;
}
TAVLMatriz crearAVLMatrices() { return NULL; }

// funciones auxiliares para ser usadas en la insercion mas adelante.
void rotarIzq(TAVLMatriz &raiz) {

  TAVLMatriz y = raiz->der;
  TAVLMatriz z = y->izq;

  y->izq = raiz;
  raiz->der = z;
  raiz = y;

  raiz->izq->altura =
      std::max(obtenerAltura(raiz->izq->der), obtenerAltura(raiz->izq->izq)) +
      1;
  raiz->altura =
      std::max(obtenerAltura(raiz->der), obtenerAltura(raiz->izq)) + 1;
}
void rotarDer(TAVLMatriz &raiz) {

  TAVLMatriz y = raiz->izq;
  TAVLMatriz z = y->der;

  y->der = raiz;
  raiz->izq = z;
  raiz = y;

  raiz->der->altura =
      std::max(obtenerAltura(raiz->der->der), obtenerAltura(raiz->der->izq)) +
      1;
  raiz->altura = std::max(obtenerAltura(raiz->izq), obtenerAltura(raiz->der)) + 1;
}

int calcularBalance(TAVLMatriz a) {
  int alturaIzq = obtenerAltura(a->izq);
  int alturaDer = obtenerAltura(a->der);

  return alturaIzq - alturaDer;
}

void insertar(TAVLMatriz &a, TMatriz m, int id) {
  if (a == NULL) {
    a = new AVLMatriz;
    a->matriz = m;
    a->id = id;
    a->altura = 1;
    a->izq = NULL;
    a->der = NULL;
    return;
  }

  if (id > a->id) {
    insertar(a->der, m, id);
  } else {
    insertar(a->izq, m, id);
  }
  a->altura = std::max(obtenerAltura(a->izq), obtenerAltura(a->der)) + 1;

  int balance = calcularBalance(a);

  // partimos en 4 casos para hacer rotaciones izquierda, derecha,
  // derecha-izquierda o izquierda-derecha
  //

  if (balance > 1 && id < a->izq->id) {
    rotarDer(a);
    return;
  }
  if (balance < -1 && id > a->der->id) {
    rotarIzq(a);
    return;
  }

  if (balance > 1 && id > a->izq->id) {
    rotarIzq(a->izq);
    rotarDer(a);
    return;
  }
  if (balance < -1 && id < a->der->id) {
    rotarDer(a->der);
    rotarIzq(a);
    return;
  }
}
void imprimirPreOrden(TAVLMatriz a) {
  if (a != NULL) {
    std::cout << a->id << " ";
    imprimirPreOrden(a->izq);
    imprimirPreOrden(a->der);
  }
}

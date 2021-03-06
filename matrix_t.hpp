// AUTOR: Emilio Rafael Estévez González
// FECHA: 8/2/21
// EMAIL: alu0101389240
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T> // plantilla de la clase de nombre: "T"
class matrix_t // clase de nombre: "matrix_t"
{
public: // De aquí en adelante los miembros son públicos a, no ser que se exprese lo contrario
  matrix_t(const int = 0, const int = 0); // constructor
  ~matrix_t(); // destructor
  
  void resize(const int, const int); // redimensión de matriz 
  
  // getters
  int get_m(void) const; // getter del numerador, de nombre: "get_num"
  int get_n(void) const; // getter del denominador, de nombre: "get_den"
  
  // getters-setters
  T& at(const int, const int); // setter de nombre: "at"
  T& operator()(const int, const int); // getter del operador, de nombre: "operator"
  
  // getters constantes
  const T& at(const int, const int) const; // getter constante de "at"
  const T& operator()(const int, const int) const; // getter constante de "operator"
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  void write(ostream& = cout) const;
  void read(istream& = cin);

private: // De aquí en adelante los miembros son privados, a no ser que se exprese lo contrario
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const; // función "pos" de tipo int
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n) // cálculo de redimensión de "matrix_t"
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
matrix_t<T>::~matrix_t() // llamada del destructor "~matrix_t()" que pertenece a la clase "matrix_t<T>"
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n) // llamada de la función "resize" que pertenece a la clase "matrix_t<T>"
{
  assert(m > 0 && n > 0); // si (m > 0) y (n > 0) son TRUE: continúa la ejecución, si uno es FALSE: para la ejecución
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
inline int
matrix_t<T>::get_m() const // llamada de "get_m" como constante, y que pertenece a la clase "matrix_t<T>"
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const // llamada de "get_n" como constante, y que pertenece a la clase "matrix_t<T>"
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j) // llamada del setter "at" que pertenece a la clase "matrix_t<T>"
{
  assert(i > 0 && i <= get_m()); // si (i > 0) y (i <= get_m()) son TRUE: continúa la ejecución, si uno es FALSE: para la ejecución
  assert(j > 0 && j <= get_n()); // si (j > 0) y (j <= get_m()) son TRUE: continúa la ejecución, si uno es FALSE: para la ejecución
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j) // llamada del getter "operator" que pertenece a la clase "matrix_t<T>"
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const // llamada de la función "at" como constante, y que pertenece a la clase "matrix_t<T>"
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}




template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const // llamada de la función "operator" como constante, y que pertenece a la clase "matrix_t<T>"
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const // salida de la matriz "matrix_t<T>" en consola
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is) // lectura de la matriz "matrix_t<T>" en consola
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}



template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const // llamada de la función "pos" como constante, y que pertenece a la clase "matrix_t<T>"
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) // producto matricial
{
  // rellenar código
}

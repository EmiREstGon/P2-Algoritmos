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

#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class vector_t  // clase de nombre: "vector_t"
{
 public:                    // De aquí en adelante los miembros son públicos a, no ser que se exprese lo contrario
  vector_t(const int = 0);  // constructor
  ~vector_t();              // destructor

  void resize(const int);  // redimensión del vector

  // getters
  T get_val(const int) const;  // getter del valor, de nombre: "get_val"
  int get_size(void) const;    // getter del tamaño, de nombre: "get_size"

  // setters
  void set_val(const int, const T);  // setter del valor, de nombre: "set_val"

  // getters-setters
  T& at(const int);          // setter de nombre: "at"
  T& operator[](const int);  // getter del operador, de nombre: "operator"

  // getters constantes
  const T& at(const int) const;          // getter constante de "at"
  const T& operator[](const int) const;  // getter constante de "operator"
  T scalar() const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

 private:  // De aquí en adelante los miembros son privados, a no ser que se exprese lo contrario
  T* v_;
  int sz_;

  void build(void);
  void destroy(void);
};

template <class T>
vector_t<T>::vector_t(const int n)  // llamada de "build()" que pertenece a la clase "vector_t<T>" para crear el vector "vector_t" de tamaño "sz_"
{
  sz_ = n;
  build();
}

template <class T>
vector_t<T>::~vector_t()  // llamada de "destroy()" que pertenece a la clase "vector_t<T>" para borrar el vector "vector_t" de tamaño "sz_"
{
  destroy();
}

template <class T>
void vector_t<T>::build()  // llamada de "build()" que pertenece a la clase "vector_t<T>" para crear el vector "vector_t" de tamaño "sz_" con condiciones
{
  v_ = NULL;       // "v_" tiene valor nulo "NULL"
  if (sz_ != 0) {  // si "sz_" es distinto de 0 continúa la ejecución
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template <class T>
void vector_t<T>::destroy()  // llamada de "destroy()" que pertenece a la clase "vector_t<T>" para borrar el vector "vector_t" de tamaño "sz_"
{
  if (v_ != NULL) {  // si "v_" es distinto de "NULL" continúa la ejecución
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template <class T>
void vector_t<T>::resize(const int n)  // llamada de la función "resize" que pertenece a la clase "vector_t<T>"
{
  destroy();
  sz_ = n;
  build();
}

template <class T>
inline T
vector_t<T>::get_val(const int i) const  // llamada de "get_val" como constante, y que pertenece a la clase "vector_t<T>"
{
  assert(i >= 0 && i < get_size());  // si (i >= 0) y (i < get_size()) son TRUE: continúa la ejecución, si uno es FALSE: para la ejecución
  return v_[i];
}

template <class T>
inline int
vector_t<T>::get_size() const  // llamada de "get_size" como constante, y que pertenece a la clase "vector_t<T>"
{
  return sz_;
}

template <class T>
void vector_t<T>::set_val(const int i, const T d)  // llamada del setter "set_val" que pertenece a la clase "vector_t<T>"
{
  assert(i >= 0 && i < get_size());  // si (i >= 0) y (i < get_size()) son TRUE: continúa la ejecución, si uno es FALSE: para la ejecución
  v_[i] = d;
}

template <class T>
T& vector_t<T>::at(const int i)  // llamada del setter "at" que pertenece a la clase "vector_t<T>"
{
  assert(i >= 0 && i < get_size());  // si (i >= 0) y (i < get_size()) son TRUE: continúa la ejecución, si uno es FALSE: para la ejecución
  return v_[i];
}

template <class T>
T& vector_t<T>::operator[](const int i)  // llamada del getter "operator" que pertenece a la clase "vector_t<T>"
{
  return at(i);
}

template <class T>
const T&
vector_t<T>::at(const int i) const  // llamada de la función "at" como constante, y que pertenece a la clase "vector_t<T>"
{
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T>
const T&
vector_t<T>::operator[](const int i) const  // llamada de la función "operator" como constante, y que pertenece a la clase "vector_t<T>"
{
  return at(i);
}

template <class T>
void vector_t<T>::write(ostream& os) const  // salida del vector "vector_t<T>" en consola
{
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}

template <class T>
void vector_t<T>::read(istream& is)  // lectura de la matriz "vector_t<T>" en consola
{
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}

// FASE II: producto escalar
template <class T>
T vector_t<T>::scalar() const { // producto escalar
  T resultado;
  if (sz_ != 0)
    resultado = v_[0];

  for (int i = 1; i < sz_; i++) { // se recorre el vector y se convierte a escalar (a^2 + b^2 + c^2 ... + n^2)
    resultado = resultado + v_[i] * v_[i];
  } 
  return resultado;
}

template <class T>
T scal_prod(const vector_t<T>& v, const vector_t<T>& w)  // producto escalar 
{
  return v.scalar() * w.scalar(); 
}

double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w)  // producto escalar
{
  return (v.scalar() * w.scalar()).value();
}
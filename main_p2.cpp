// AUTOR: Emilio Rafael Estévez González
// FECHA: 8/2/21
// EMAIL: alu0101389240
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

#include "vector_t.hpp"

#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3);

  // FASE I
  cout << "a + b: "; // suma
  (a+b).write();

  cout << "b - a: "; // resta
  (b-a).write();

  cout << "a * b: "; // multiplicación
  (a*b).write();
  
  cout << "a / b: "; // división
  (a/b).write();
  
  cout << endl; // fin de línea
  
  // FASE II
  vector_t<double> v, w; // vector_t de tipo double, con las variables "v" y "w"
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl; // escritura por pantalla del producto escalar: "scal_prod(v, w)"
  
  vector_t<rational_t> x, y; // vector_t en la clase "rational_t", con las variables "x" y "y"
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl; // escritura por pantalla del producto escalar: "scal_prod(x, y)" 
  
  
  // FASE III
  matrix_t<double> A, B, C; // matriz de tipo double, con las variables "A", "B", "C"
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl; // escritura por pantalla de la multiplicación matricial:
  C.write();
  
  return 0;
}

// Modificación
  vector_t<double> get_par_v, get_par_w;
  get_par_v.read(), get_par_v.write();
  get_par_w.read(), get_par_w.write();

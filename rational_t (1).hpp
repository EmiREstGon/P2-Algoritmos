// AUTOR: Emilio Rafael Estévez González
// FECHA: 8/2/21
// EMAIL: alu0101389240
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t // clase de nombre: "rational_t"
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public: // De aquí en adelante los miembros son públicos a, no ser que se exprese lo contrario
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // método: getters
  int get_num() const; // getter del numerador, de nombre: "get_num" 
  int get_den() const; // getter del denominador, de nombre: "get_den"
  
  // método: setters
  void set_num(const int); // setter del numerador, de nombre: "set_num"
  void set_den(const int); // setter del denominador, de nombre: "set_den"

  double value(void) const;
  rational_t opposite(void) const;
  rational_t reciprocal(void) const;

  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;

  rational_t add(const rational_t&) const;       // llamada a la función "add" o suma, para la clase "rational_t"
  rational_t substract(const rational_t&) const; // llamada a la función "substract" o resta, para la clase "rational_t"
  rational_t multiply(const rational_t&) const;  // llamada a la función "multiply" o multiplicación, para la clase "rational_t"
  rational_t divide(const rational_t&) const;    // llamada a la función "divide" o división, para la clase "rational_t"

  void write(ostream& os = cout) const; // escritura en consola y archivos => salida
  void read(istream& is = cin);         // lectura de consola y archivos => entrada
  
private: // De aquí en adelante los miembros son privados, a no ser que se exprese lo contrario
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_; // declaración variables "num_" (numerador) y "den_" (denominador) como tipo int
};


// sobrecarga de los operadores de Entrada / Salida (E/S)
ostream& operator<<(ostream& os, const rational_t&); // sobrecarga del operador (<<)
istream& operator>>(istream& is, rational_t&);       // sobrecarga del operador (>>)



// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&); // sobrecarga del operador (+)
rational_t operator-(const rational_t&, const rational_t&); // sobrecarga del operador (-)
rational_t operator*(const rational_t&, const rational_t&); // sobrecarga del operador (*)
rational_t operator/(const rational_t&, const rational_t&); // sobrecarga del operador (/)

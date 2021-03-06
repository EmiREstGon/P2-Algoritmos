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

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
inline
int
rational_t::get_num() const
{
  return num_;
}



inline
int
rational_t::get_den() const
{
  return den_;
}


  
void
rational_t::set_num(const int n)
{
  num_ = n;
}


  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



inline
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}



rational_t 
rational_t::opposite() const
{ 
  return rational_t((-1)*get_num(), get_den());
}



rational_t
rational_t::reciprocal() const
{ 
  return rational_t(get_den(), get_num());
}



// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ 
  return fabs(value() - r.value()) < precision;
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return (value() - r.value()) > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return r.is_greater(*this, precision);
}


// operaciones
rational_t
rational_t::add(const rational_t& r) const // suma
{
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}



rational_t
rational_t::substract(const rational_t& r) const // resta
{
  return add(r.opposite());
}



rational_t
rational_t::multiply(const rational_t& r) const // multiplicación
{
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}



rational_t
rational_t::divide(const rational_t& r) const // división
{
  return multiply(r.reciprocal());
}


// FASE I: operadores
rational_t
operator+(const rational_t& a, const rational_t& b) // operador suma (+)
{
  a + b;
  return(a+b);
}



rational_t
operator-(const rational_t& a, const rational_t& b) // operador resta (-)
{
  a - b;
  return(a-b);
}



rational_t
operator*(const rational_t& a, const rational_t& b) // operador multiplicación (*)
{
  a * b;
  return(a*b);
}



rational_t
operator/(const rational_t& a, const rational_t& b) // operador división (/)
{
  a / b;
  return(a/b);
}



// Entrada / Salida
void
rational_t::write(ostream& os) const // escritura en consola => salida
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void
rational_t::read(istream& is) // lectura de consola => entrada
{
  is >> num_ >> den_;
  assert(den_ != 0);
}



ostream&
operator<<(ostream& os, const rational_t& r) // salida de texto en consola (http://www.cplusplus.com/reference/ostream/ostream/)
{
  r.write(os);
  return os;
}



istream&
operator>>(istream& is, rational_t& r) // lectura de texto en consola (https://www.cplusplus.com/reference/istream/istream/)
{
  r.read(is);
  return is;
}

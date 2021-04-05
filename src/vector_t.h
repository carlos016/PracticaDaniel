// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 3.1
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
//

//Mensajes para el compilador, evita referencias repetidas y/o circulares, solo define la clase si no está definida//
#ifndef VECTORT_H_
#define VECTORT_H_

//Librerías incluídas//
#include <iostream>
#include <cassert>

//Declaración de la clase template Vector --> (Puntero transformado en Vector, Size del Vector)//
template<class T> class vector_t {
  //Atributos y métodos privados//
  private:
    //Atributos Privados//
    T *v_;                                                 //Vector de Valores T//
    int sz_;                                               //Size del Vector//

  //Atributos y métodos públicos//
  public:
    //Métodos Públicos//
    //Constructores
    vector_t(const int = 0);                               //Constructor por Defecto/Parámetros//
    vector_t(const vector_t&);                             //Constructor de Copia//
    //Destructor
    ~vector_t();
    //Métodos que construyen y destruyen el Vector//
    void build(void);
    void destroy(void);

    //Redimensionado del Vector//
    void resize(const int);

    //Getters y Setters//
    //Getters de los valores del Vector//
    T get_val(const int) const;                            //Getter del valor T de una posición del Vector//
    int get_size(void) const;                              //Getter del Size del Vector//
    //Setter de un valor T de una posición del Vector//
    void set_val(const int, const T);
    //Getter/Setter//
    T& at(const int);                                      //Getter/Setter de una referencia al valor T de una posición del Vector//
    T& operator[](const int);                              //Sobrecarga del operador [] que sirve como Getter/Setter de una referencia al valor T de una posición del Vector//
    //Getter constantes//
    const T& at(const int) const;                          //Getter constante de una referencia al valor T de una posición del Vector//
    const T& operator[](const int) const;                  //Sobrecarga del operador [] que sirve como Getter constante de una referencia al valor T de una posición del Vector//

    //Sobrecarga del operador de asignación de la clase Vector//
    vector_t<T>& operator=(const vector_t<T>&);

    //Entrada/Salida//
    void read(std::istream& = std::cin);                   //Entrada//
    void write(std::ostream& = std::cout) const;           //Salida//
};

//Implementación de la clase Par//
//Constructores//
//Constructor por Defecto/Parámetros//
template<class T> vector_t<T> :: vector_t (const int n):
  v_(NULL),
  sz_(n)
{
  build();
}
//Constructor de Copia//
template<class T> vector_t<T> :: vector_t (const vector_t<T>& w):
  v_(NULL),
  sz_(0)
{
  *this = w; // se invoca directamente al operator=
}
//Destructor//
template<class T> vector_t<T> :: ~vector_t() {
  destroy();
}
//Método que construye el Vector//
template<class T> void vector_t<T> :: build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}
//Método que destruye el Vector//
template<class T> void vector_t<T> :: destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

//Método que cambia el tamaño actual del Vector a un tamaño n//
template<class T> void vector_t<T> :: resize (const int n) {
  destroy();
  sz_ = n;
  build();
}

//Getters y Setters//
//Getters de los valores del Vector//
//Getter del valor T de una posición del Vector//
template<class T> inline T vector_t<T> :: get_val (const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}
//Getter del Size del Vector//
template<class T> inline int vector_t<T> :: get_size() const {
  return sz_;
}
//Setter de un valor T de una posición del Vector//
template<class T> void vector_t<T> :: set_val (const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}
//Getter/Setter//
//Getter/Setter de una referencia al valor T de una posición del Vector//
template<class T> T& vector_t<T> :: at (const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}
//Sobrecarga del operador [] que sirve como Getter constante de una referencia al valor T de una posición del Vector//
template<class T> T& vector_t<T> :: operator[] (const int i) {
  return at(i);
}
//Getter constantes//
//Getter constante de una referencia al valor T de una posición del Vector//
template<class T> const T& vector_t<T> :: at (const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}
//Sobrecarga del operador [] que sirve como Getter constante de una referencia al valor T de una posición del Vector//
template<class T> const T& vector_t<T> :: operator[] (const int i) const {
  return at(i);
}

//Sobrecarga del operador de asignación de la clase Vector//
template<class T> vector_t<T>& vector_t<T> :: operator= (const vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);

  return *this;
}

//Entrada/Salida//
//Entrada//
template<class T> void vector_t<T>::read(std::istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> at(i);
}
//Salida//
template<class T> void vector_t<T> :: write (std::ostream& os) const {
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

//Sobrecarga de operadores de flujo de entrada y salida//
//Sobrecarga de operadores de flujo de entrada//
template<class T> std::istream& operator>> (std::istream& is, vector_t<T>& v) {
  v.read(is);
  return is;
}
//Sobrecarga de operadores de flujo de salida//
template<class T> std::ostream& operator<<(std::ostream& os, const vector_t<T>& v) {
  v.write(os);
  return os;
}
//Mensajes para el compilador, termina definición de la clase Vector//
#endif  // VECTORT_H_

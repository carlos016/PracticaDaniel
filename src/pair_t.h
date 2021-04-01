// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
//

//Mensajes para el compilador, evita referencias repetidas y circulares, solo define la clase si no está definida//
#ifndef PAIRT_H_
#define PAIRT_H_

//Librerías incluídas//
#include <iostream>

//Declaración de la clase template Par --> (Valor, Índice)//
template<class T> class pair_t {
  //Atributos y métodos privados//
  private:
    //Atributos Privados//
    T val_;                                   //Valor del Par//
    int inx_;                                 //Índice del Par//

  //Atributos y métodos públicos//
  public:
    //Métodos Públicos//
    //Constructores//
    pair_t(void);                             //Constructor por Defecto//
    pair_t(T, int);                           //Constructor por Parámetros//
    //Destructor//
    ~pair_t(void);

    //Getters y Setters//
    T get_val(void) const;                    //Getter del Valor del Par//
    int get_inx(void) const;                  //Getter del Índice del Par//
    void set(T, int);                         //Setter del Valor y del Índice del Par//

    //Entrada/Salida//
    std::istream& read(std::istream& is = std::cin);            //Entrada//
    std::ostream& write(std::ostream& os = std::cout) const;    //Salida//
};

//Implementación de la clase Par//
//Constructores//
//Constructor por Defecto//
template<class T> pair_t<T> :: pair_t():
  val_(),
  inx_(-1)
{}
//Constructor por Parámetros//
template<class T> pair_t<T> :: pair_t (T val, int inx):
  val_(val),
  inx_(inx)
{}
//Destructor//
template<class T> pair_t<T> :: ~pair_t() {}

//Getters y Setters//
//Getter del Valor del Par//
template<class T> T pair_t<T> :: get_val() const {
  return val_;
}
//Getter del Índice del Par//
template<class T> int pair_t<T> :: get_inx() const {
  return inx_;
}
//Setter del Valor y del Índice del Par//
template<class T> void pair_t<T> :: set (T val, int inx) {
  val_ = val;
  inx_ = inx;
}

//Entrada/Salida//
//Entrada//
template<class T> std::istream& pair_t<T> :: read (std::istream& is) {
  return is >> inx_ >> val_;
}
//Salida//
template<class T> std::ostream& pair_t<T> :: write (std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}
//Sobrecarga del operador << (Salida)//
template<class T> std::ostream& operator<<(std::ostream& os, const pair_t<T>& p) {
  p.write(os);
  return os;
}
//Mensajes para el compilador, termina definición de la clase Par//
#endif  // PAIRT_H_

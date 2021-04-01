#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

#define _USE_MATH_DEFINES
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  const bool  operator == (  LZespolona  Skl2) const;

LZespolona  operator + ( LZespolona  Skl2);
LZespolona  operator - (  LZespolona  Skl2);
LZespolona  operator * (  LZespolona  Skl2);
LZespolona  operator / (  LZespolona  Skl2);
LZespolona  operator / ( double Skl2);
LZespolona  Sprzezenie();
double arg();
LZespolona operator +=(LZespolona Skl2);
LZespolona operator /=(LZespolona Skl2);
double Mod2();
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */



ostream & operator <<(ostream & Strm, const LZespolona  &Skl2);
istream & operator >>(istream & Strm,  LZespolona  &Skl2);
void Wczytaj( LZespolona  &Skl);
void Wyswietl( LZespolona  Skl);
#endif

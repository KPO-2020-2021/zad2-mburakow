#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

const bool  LZespolona::operator == (   LZespolona  Skl2) const
{
    
    if (abs(re - Skl2.re) <= MIN_DIFF && abs(im - Skl2.im) <= MIN_DIFF)
      return true;
    else
      return false;
    
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (   LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = re + Skl2.re;
    Wynik.im = im + Skl2.im;
    return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator / (   double  Skl2)
{
    LZespolona  Wynik;
    if(Skl2==0)
    throw "Dzielenie przez 0";
    Wynik.re = re / Skl2;
    Wynik.im = im / Skl2;
    return Wynik;
}

LZespolona  LZespolona::operator - (   LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = re - Skl2.re;
    Wynik.im = im - Skl2.im;
    return Wynik;
}
LZespolona  LZespolona::operator * (   LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = re * Skl2.re-im * Skl2.im;
    Wynik.im = re * Skl2.im+im * Skl2.re;
    return Wynik;
}

LZespolona  LZespolona::operator / (   LZespolona  Skl2)
{
    return *this*Skl2.Sprzezenie()/Skl2.Mod2();
}

LZespolona  LZespolona::Sprzezenie()
{
    im*=(-1);
    return *this;
}

double LZespolona::Mod2()
{
    return  pow(re,2)+pow(im,2);
}

ostream & operator <<(ostream & Strm, const LZespolona  &Skl2)
{
    Strm<<"("<<Skl2.re<<showpos<<Skl2.im<<noshowpos<<"i)";
    return Strm;
}
istream & operator >>(istream & Strm,  LZespolona  &Skl2)
{
    char symbol;
    Strm>>symbol;
    if(symbol!='(')
    {
        Strm.setstate(ios::failbit);
    }
    Strm>>Skl2.re;
    Strm>>Skl2.im;
    Strm>>symbol;
    if(symbol!='i')
    {
        Strm.setstate(ios::failbit);
    }
    Strm>>symbol;
    if(symbol!=')')
    {
        Strm.setstate(ios::failbit);
    }
    return Strm;
}
void Wczytaj( LZespolona  &Skl)
{
    cout<<"("<<Skl.re<<showpos<<Skl.im<<noshowpos<<"i)";

}
void Wyswietl( LZespolona  Skl)
{
    char symbol;
    cin>>symbol;
    if(symbol!='(')
    {
        cin.setstate(ios::failbit);
    }
    cin>>Skl.re;
    cin>>Skl.im;
    cin>>symbol;
    if(symbol!='i')
    {
        cin.setstate(ios::failbit);
    }
    cin>>symbol;
    if(symbol!=')')
    {
        cin.setstate(ios::failbit);
    }

}

double LZespolona::arg()
  {
      double wynik;
      if(re>0)
      {
          wynik=atan2(im,re) * 180 / M_PI;
      }
      else if (re<0)
      {
          wynik=atan2(im,re) + M_PI * 180 / M_PI;
      }
      else
      {
          throw " argument a jest zero wyjatek";
      }
      return wynik;

  }
LZespolona LZespolona::operator +=(LZespolona Lz1)
{
    *this=*this+Lz1;
    return *this;
}
LZespolona LZespolona::operator /=(LZespolona Lz1)
{
    *this=*this/Lz1;
    return *this;
}

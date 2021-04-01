#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
 
 ostream & operator <<(ostream & Strm, const WyrazenieZesp  &WyrZ)
{
    Strm<<WyrZ.Arg1;
    switch(WyrZ.Op)
    {
    case Op_Dodaj:
        Strm<<"+";
        break;
    case Op_Mnoz:
        Strm<<"*";
        break;
    case Op_Dziel:
        Strm<<"/";
        break;
    case Op_Odejmij:
        Strm<<"-";
        break;
    }
    Strm<<WyrZ.Arg2;
    return Strm;
}
istream & operator >>(istream & Strm,  WyrazenieZesp  &WyrZ)
{
    Strm>>WyrZ.Arg1;
    char symbol;
    Strm>>symbol;
    switch(symbol)
    {
    case '+':
        WyrZ.Op= Op_Dodaj;
                 break;
    case '*':
        WyrZ.Op= Op_Mnoz;
                 break;
    case '/':
        WyrZ.Op=Op_Dziel;
                break;
    case '-':
        WyrZ.Op=Op_Odejmij;
                break;
    default:
        Strm.setstate(ios::failbit);
        break;
    }
    Strm>>WyrZ.Arg2;
    return Strm;
}
void Wczytaj( WyrazenieZesp  &WyrZ)
{
  cin>>WyrZ.Arg1;
    char symbol;
    cin>>symbol;
    switch(symbol)
    {
    case '+':
        WyrZ.Op= Op_Dodaj;
                 break;
    case '*':
        WyrZ.Op= Op_Mnoz;
                 break;
    case '/':
        WyrZ.Op=Op_Dziel;
                break;
    case '-':
        WyrZ.Op=Op_Odejmij;
                break;
    default:
        cin.setstate(ios::failbit);
        break;
    }
    cin>>WyrZ.Arg2;

}
void Wyswietl(WyrazenieZesp  WyrZ)
{
    cout<<WyrZ.Arg1;
    switch(WyrZ.Op)
    {
    case Op_Dodaj:
        cout<<"+";
        break;
    case Op_Mnoz:
        cout<<"*";
        break;
    case Op_Dziel:
        cout<<"/";
        break;
    case Op_Odejmij:
        cout<<"-";
        break;
    }
    cout<<WyrZ.Arg2;

}
LZespolona WyrazenieZesp::Oblicz()
{
    LZespolona wynik;
    switch(Op)
    {
    case Op_Dodaj:
        wynik=Arg1+Arg2;
        break;
    case Op_Mnoz:
        wynik=Arg1*Arg2;
        break;
    case Op_Dziel:
        wynik=Arg1/Arg2;
        break;
    case Op_Odejmij:
        wynik=Arg1-Arg2;
        break;
    }
    return wynik;
}

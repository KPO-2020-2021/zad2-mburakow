#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

struct Statystyki
{
    int poprawna;
    int niepoprawna;
    double pop_procent;
    double niepop_procent;
};

void Wyswietl(Statystyki &st);
void dodaj_pop(Statystyki &st);
void dodaj_niepop(Statystyki &st);
void oblicz_pro_pop(Statystyki &st);
void oblicz_pro_niepop(Statystyki &st);
#endif


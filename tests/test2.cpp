#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"
TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;

    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;

    x.re = 2;
    x.im = 2;

    y.re = 0.666;
    y.im = 0.666;

    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;

    x.re = 2;
    x.im = 2;

   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;

    x.re = 2;
    x.im = 2;

    y.re = 0.666;
    y.im = 0.666;

    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dodawanie,znany wynik") {
    WyrazenieZesp x{{1,1},Op_Dodaj,{1,1}};
    LZespolona t ={2,2};


    CHECK(x.Oblicz()== t);
}

TEST_CASE("Test LZespolona odejmowanie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Odejmij,{1,1}};
    LZespolona t ={0,0};


    CHECK(x.Oblicz()== t);
}

TEST_CASE("Test LZespolona mnozenie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Mnoz,{1,1}};
    LZespolona t ={0,2};


    CHECK(x.Oblicz()== t);
}

TEST_CASE("Test LZespolona dzielenie, znany wynik") {
    WyrazenieZesp x{{1,1},Op_Dziel,{1,1}};
    LZespolona t ={1,0};


    CHECK(x.Oblicz()== t);
}


TEST_CASE("Test LZespolona dzielenie przez LZespolona") {
    LZespolona x, y;
    LZespolona t = {1,1};

    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 0;

    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez LZespolona") {
    LZespolona x, y;
    LZespolona t = {1,1};

    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 0;
x/=t;
    CHECK( x== y);
}



#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
int ile=0;
LZespolona odp;
odp={1,1};
cout<<odp.arg()<<endl; // 45 stopni
odp={1,0};
cout<<odp.arg()<<endl; // 0 stopni
  WyrazenieZesp   WyrZ_PytanieTestowe;
Statystyki st={0,0,0,0};
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe))
 {
   cout<<"oblicz wyrazenie"<<WyrZ_PytanieTestowe<<endl;
   ile=0;
   while(ile!=3)
   {
        ile++;
        cout<<"odpowiedz : ";
        cin>>odp;
        if(cin.good())
        {
            break;
        }
        cin.clear();
        cin.ignore(1024,'\n');

   }
   if(odp==WyrZ_PytanieTestowe.Oblicz())
   {
        cout<<"dobrze :) ";
       dodaj_pop(st);
   }
   else
   {
        cout<<"zle :( "<<WyrZ_PytanieTestowe.Oblicz()<<endl;
       dodaj_niepop(st);
   }
   oblicz_pro_pop(st);
  }
Wyswietl(st);

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}

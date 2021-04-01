#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
 
 void Wyswietl(Statystyki &st)
{
    cout<<"poprawne odpowiedzie : "<<st.poprawna<<endl;
    cout<<"niepoprawne odpowiedzie : "<<st.niepoprawna<<endl;
    cout<<"procent poprawne odpowiedzie : "<<st.pop_procent<<endl;
}
void dodaj_pop(Statystyki &st)
{
    st.poprawna++;

}
void dodaj_niepop(Statystyki &st)
{
    st.niepoprawna++;
}
void oblicz_pro_pop(Statystyki &st)
{
    st.pop_procent=st.poprawna*100.0/(st.niepoprawna+st.poprawna);
}
void oblicz_pro_niepop(Statystyki &st)
{
    st.niepop_procent=st.niepoprawna*100.0/(st.niepoprawna+st.poprawna);
}

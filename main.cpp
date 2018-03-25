#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "plansza.h"
#include "gra.h"
#define strzalka_lewo 0x25
#define strzalka_gora 0x26
#define strzalka_prawo 0x27
#define strzalka_dol 0x28
#define enter 0x0D



using namespace std;













int main(){
    int x2,y2,liczba2,ilosc2=0,koniec2=0;
    int w2,k2;
    int poz_x2 = 0, poz_y2 = 0, o_poz_x2 = 1, o_poz_y2 = 1;
    Komorka **a2;

    srand(time(0));
    cout << "Gra saper napisana przez Jan Szponar z asysystentem młodym tak o" << endl;
    cout<<"Podaj ile wierszy ma zawierac plansza"<<endl;
    cin>>w2;
    cout<<"Podaj ile kolumn ma zawierac plansza"<<endl;
    cin>>k2;
    cout<<endl<<endl<<endl;
    a2=new Komorka*[w2];
    for(int i=0;i<w2;i++){
        a2[i]=new Komorka[k2];
    }
    utworzplansze(a2,w2,k2);
    drukujplansze(a2,w2,k2);
    do{
    cout<<"Podaj ilosc min, ktora bedzie wystepowala na planszy"<<endl;
    cin>>liczba2;
    } while(liczba2>(w2*k2));
    ilosc2=liczba2;

    ustawianiebomb(a2,w2,k2,x2,y2,liczba2);
    drukujplansze(a2,w2,k2);

    while(koniec2==0)
    {
        Sleep(60);
        sterowanie(a2,w2,k2, poz_x2,poz_y2,o_poz_x2, o_poz_y2,koniec2);
        if (sprawdz_czy_wygrana(a2,w2,k2,ilosc2)==true) koniec2=1;
    }

    if (koniec2==1) cout << "Zwyciestwo!"<<endl;
    if (koniec2==2) cout << "Mina! Game over"<<endl;
    system ("pause >nul");
    for(int i=0;i<w2;i++){
        delete [] a2[i];
    }
    delete []a2;




    return 0;
}


#ifndef PLANSZA_H
#define PLANSZA_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <windows.h>
struct Komorka{
    int wartosc;
    bool odkryte;
};



void utworzplansze(Komorka **a,int w,int k);
void drukujplansze(Komorka **a,int w,int k);
void ustawianiebomb(Komorka **a,int w,int k,int x, int y, int liczba);

#endif // PLANSZA_H

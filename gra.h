#ifndef GRA_H
#define GRA_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "plansza.h"
#define strzalka_lewo 0x25
#define strzalka_gora 0x26
#define strzalka_prawo 0x27
#define strzalka_dol 0x28
#define enter 0x0D

void pokaz_plansze(Komorka **a, int w, int k, int poz_x,int poz_y);
void odkryj_plansze(Komorka a,int w, int k,int x1, int y1);
bool sprawdz_czy_wygrana(Komorka **a, int w, int k,int ilosc);
void sterowanie(Komorka **a, int w, int k, int poz_x, int poz_y,int o_poz_x,int o_poz_y,int koniec);

#endif // GRA_H

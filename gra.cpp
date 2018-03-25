#include "gra.h"
using namespace std;
void pokaz_plansze(Komorka **a, int w, int k, int poz_x,int poz_y)
{
    system ("cls");

    for (int i = 0; i<w; i++)
    {
        for (int j = 0; j<k; j++)
        {
            if (j==poz_x && i==poz_y)
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE  ), 0x02);
                cout << "o";
            }
            else
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE  ), 0x07);
                if (a[j][i].odkryte==true)
                {
                    if (a[j][i].wartosc==0)
                        cout << " ";
                    else
                        cout << a[j][i].wartosc;

                }
                if (a[j][i].odkryte==false)
                    cout << "#";
            }
        }
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
        cout << endl;
    }

    cout << "\npozycja kursora:\n";
    cout << "X: " << poz_x << endl;
    cout << "Y: " << poz_y << endl;
}


void odkryj_plansze(Komorka **a,int w, int k,int x1, int y1)
{
    if (x1<0 || x1>w-1) return;
    if (y1<0 || y1>k-1) return;
    if (a[x1][y1].odkryte==true) return;

    if(a[x1][y1].wartosc!=9 && a[x1][y1].odkryte==false)
        a[x1][y1].odkryte=true;

    if (a[x1][y1].wartosc!=0) return;

    odkryj_plansze(a,w,k,x1-1,y1-1);
    odkryj_plansze(a,w,k,x1-1,y1);
    odkryj_plansze(a,w,k,x1-1,y1+1);
    odkryj_plansze(a,w,k,x1+1,y1-1);
    odkryj_plansze(a,w,k,x1+1,y1);
    odkryj_plansze(a,w,k,x1+1,y1+1);
    odkryj_plansze(a,w,k,x1,y1-1);
    odkryj_plansze(a,w,k,x1,y1);
    odkryj_plansze(a,w,k,x1,y1+1);
}

bool sprawdz_czy_wygrana(Komorka **a, int w, int k,int ilosc)
{
    int miny = 0;
    for (int i = 0; i<w; i++)
    {
        for (int j = 0; j<k; j++)
        {
            if(a[i][j].odkryte==false)
                miny++;
        }
    }
    if (miny==ilosc) return true;
    return false;
}

void sterowanie(Komorka **a, int w, int k, int poz_x, int poz_y,int o_poz_x,int o_poz_y,int koniec)
{
    if ((GetKeyState(enter) & 0x8000))
    {
        if (a[poz_x][poz_y].wartosc==9)
            koniec=2;

        odkryj_plansze(a,w,k,poz_x, poz_y);
        pokaz_plansze(a,w,k,poz_x,poz_y);
    }

    if ((GetKeyState(strzalka_prawo) & 0x8000) && poz_x<k-1) poz_x++;
    if ((GetKeyState(strzalka_lewo) & 0x8000) && poz_x>0) poz_x--;
    if ((GetKeyState(strzalka_dol) & 0x8000) && poz_y<w-1) poz_y++;
    if ((GetKeyState(strzalka_gora) & 0x8000) && poz_y>0) poz_y--;

    if (o_poz_y==poz_y && o_poz_x==poz_x) return;

    o_poz_y = poz_y;
    o_poz_x = poz_x;


    pokaz_plansze(a,w,k,poz_x,poz_y);
}

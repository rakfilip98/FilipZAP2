#include "plansza.h"
using namespace std;

void utworzplansze(Komorka **a,int w,int k){
    for(int i=0;i<w;i++){
        for(int j=0;j<k;j++){
            a[i][j].wartosc=0;
            a[i][j].odkryte=false;
       }
    }
}

void drukujplansze(Komorka **a,int w,int k){
    for(int i=0;i<w;i++){
        cout<<setw(5);
        for(int j=0;j<k;j++){
            cout<<a[i][j].wartosc<<setw(1);
        }
        cout<<endl;
    }
}
void ustawianiebomb(Komorka **a,int w,int k,int x, int y, int liczba){
    while(liczba>0){
        x=0+rand()%(w-0);
        y=0+rand()%(k-0);
        if(a[x][y].wartosc!=9){
            a[x][y].wartosc=9;
            for(int p1=-1;p1<2;p1++ ){
                for(int p2=-1;p2<2;p2++){
                    if((x+p1)<0 ||(y+p2)<0)continue;
                    if((x+p1)>w-1 ||(y+p2)>k-1)continue;
                    if(a[x+p1][y+p2].wartosc==9)continue;
                    a[x+p1][y+p2].wartosc ++;
            }
            }

            liczba--;
        }

    }
}



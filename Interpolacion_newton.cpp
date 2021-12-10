#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100

//programa elaborado por: jorge alejandro martinez araujo
//fecha de elaboracion: 10 de noviembre del 2021
//nombre del programa: Interpolacion newton

/*
                                                _
                  ___                          (_)
                _/XXX\
 _             /XXXXXX\_                                    __
 X\__    __   /X XXXX XX\                          _       /XX\__      ___
     \__/  \_/__       \ \                       _/X\__   /XX XXX\____/XXX\
   \  ___   \/  \_      \ \               __   _/      \_/  _/  -   __  -  \__/
  ___/   \__/   \ \__     \\__           /  \_//  _ _ \  \     __  /  \____//
 /  __    \  /     \ \_   _//_\___     _/    //           \___/  \/     __/
 __/_______\________\__\_/________\_ _/_____/_____________/_______\____/_______
                                   /|\
                                  / | \
                                 /  |  \
                                /   |   \
                               /    |    \
                              /     |     \
                             /      |      \
                            /       |       \
                           /        |        \
                          /         |         \*/


double fnewton(float x[N], float y[N], int n, float xx);
int main()
{
    int n0, k;
    float x0[N], y0[N], xx0, res;
    printf("\n Especifique el grado de la funcion de interpolacion: ");
    scanf("%d", &n0);
    printf("\n Introduce los valores de x: \n");

    for (k = 0; k <= n0; k = k + 1)
    {
        printf(" X[%d]=", k);
        scanf("%f", &x0[k]);
    }
    printf("\n Introduce los valores de f(x): \n");

    for (k = 0; k <= n0; k = k + 1)
    {
        printf(" f(x[%d])=", k);
        scanf("%f", &y0[k]);
    }
    printf("\n Especifica en que valor  deseas evaluar a la funcion de interpolacion: ");
    scanf("%f", &xx0);
    res = fnewton(x0, y0, n0, xx0);
    printf("\n\n El resultado de evaluar a la funcion de interpolacion f_%d en x= %.3f es %.5f= ", n0, xx0, res);
    return 0;
}

double fnewton(float x[N], float y[N], int n, float xx)
{
    float fdd[n][n] = {0}, a[n] = {0}, fx;
    int i, j;
    for (i = 0; i <= n; i = i + 1)
    {
        fdd[i][0] = y[i];
    }
    for (j = 0; j <= n; j = j + 1)
    {
        for (i = 0; i <= n - j; i = i + 1)
        {
            fdd[i][j] = (fdd[i + 1][j - 1] - fdd[i][j - 1] / x[i + j] - x[i]);
        }
    }
    a[0] = 1;
    for (i = 1; i <= n; i = i + 1)
    {
        a[i] = (xx - x[i - 1]) * a[i - 1];
    }
    for (i = 0; i <= n; i = i + 1)
    {
        fx = fx + fdd[0][i] * a[i];
    }
    return fx;
}
/*                               _______
                           _,,ad8888888888bba,_
                        ,ad88888I888888888888888ba,
                      ,88888888I8神の力88888888888888,
                    ,d888888888I8888888888888888888888b,
                   d88888PP"""" ""YY88888888888888888888b,
                 ,d88"'__,,--------,,,,.;ZZZY8888888888888,
                ,8IIl'"                ;;l"ZZZIII8888888888,
               ,I88l;'                  ;lZZZZZ888III8888888,
             ,II88Zl;.                  ;llZZZZZ888888I888888,
            ,II888Zl;.                .;;;;;lllZZZ888888I8888b
           ,II8888Z;;                 `;;;;;''llZZ8888888I8888,
           II88888Z;'                        .;lZZZ8888888I888b
           II88888Z; _,aaa,      .,aaaaa,__.l;llZZZ88888888I888
           II88888IZZZZZZZZZ,  .ZZZZZZZZZZZZZZ;llZZ88888888I888,
           II88888IZZ<'(@@>Z|  |ZZZ<'(@@>ZZZZ;;llZZ888888888I88I
          ,II8n888;   `""" ;|  |ZZ; `"""     ;;llZ8888888888I888
          II888888l            `;;          .;llZZ8888888888I888,
         ,II88o888Z;           ;;;        .;;llZZZ8888888888I888I
         III888888Zl;    ..,   `;;       ,;;lllZZZ88888888888I888
         II888q8888Z;;...;(_    _)      ,;;;llZZZZ88888888888I888,
         II88888888Zl;;;;;' `--'Z;.   .,;;;;llZZZZ88888888888I888b
         ]I888u88888Z;;;;'   ";llllll;..;;;lllZZZ火の神の踊りZ88888,
         II888888888Zl.;;"Y88bd888P";;,..;lllZZZZZ88888888888I8888I
         II888e888888Zl;.; `"PPP";;;,..;lllZZZZZZZ88888888888I88888
         II888888888888Zl;;. `;;;l;;;;lllZZZZZZZZW88888888888I88888
         `II88d8888888888Zl;.    ,;;lllZZZZZZZZWMZ88888888888I88888
          II8888888888888888ZbaalllZZZZZZZZZWWMZZZ8888888888I888888,
          `II8a888888888888888b"WWZZZZZWWWMMZZZZZZI888888888I888888b
           `II88888888888888888;ZZMMMMMMZZZZZZZZllI888888888I8888888
            `II8888888888888888 `;lZZZZZZZZZZZlllll888888888I8888888,
             Im8888888888888888, `;lllZZZZllllll;;.Y88888888I8888888b,
            ,Ia8888888888888888b   .;;lllllll;;;.;..88888888I88888888b,
            IIs88888888888888PZI;.  .`;;;.;;;..; ...88888888I8888888888,
            II888888888888PZ;;';;.   ;. .;.  .;. .. Y8888888I88888888888b,
           ,IIq88888888PZ;;'                        `8888888I8888888888888b,
           II8u8888888'                              888888I8888888888888888b
          ,II8e8888888                              ,888888I88888888888888888
         ,d888r8888888                              dτην ομορφιά που κουβαλάς
      ,ad88888e888888I                              δεν είναι φυσιολογικόI8888
    ,d88888888c888888'                              888888IZZZZZZZZZZZZZZZZZZ
  ,d8888888888o8P'8P'                               Y888ZZZZZZZZZZZZZZZZZZZZZ
 ,888888888888r,  "                                 ,ZZZZZZZZZZZZZZZZZZZZZZZZ
d8888888888888d8,                                ,ZZZZZZZZZZZZZZZZZZZZZZZZZZZ
私はあなたを忘れます,      _                    ,ZZZZZZZZZZZZZZZZZZZZ888888888
88888888888888a888888ba,_d'                  ,ZZZZZZZZZZZZZZZZZ88888888888888
88888888888888r8888888888888bbbaaa,,,______,ZZZZZZZZZZZZZZZ888888888888888888
88888888888888888888888888888888888888888ZZZZZZZZZZZZZZZ888888888888888888888
88昨日は歴史888888888明日は我が身88888888888しかし、今日は贈り物だ888888888888888
88888888888888888888888888888JMA_BOB8888888ZZZZZZZZZZZZZZ88888888888888888888
8888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888
88888888888コードゴッド888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888
8888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888888 
888888どうやって伝えたらいいのかわからない 88888888888888888888888888ZZZZZZZZZZZ
8888888888888888888888888888888ZZZZZあなたへの思いを込めてZZZZZZZZZ888888888888*/
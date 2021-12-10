#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100

//programa elaborado por: jorge alejandro martinez araujo
//fecha de elaboracion: 10 de noviembre del 2021
//nombre del programa: Interpolacion de lagrange


int main()
{
    int n0, k, i, j;
    float x0[100], y0[100], xinterpol, yinterpol = 0, productosnum, productosDen;
    printf("Interpolacion de lagrange\n");
    printf("\n Especifique el grado de la funcion de interpolacion: ");
    scanf("%d", &n0);
    printf("\n Introduce los valores de x: \n");

    /*        _.---..._
           ./^         ^-._
         ./^C===.         ^\.   /\
        .|'     \\        _ ^|.^.|
   ___.--'_     ( )  .      ./ /||
  /.---^T\      ,     |     / /|||
 C'   ._`|  ._ /  __,-/    / /-,||
      \ \/    ;  /O  / _    |) )|,
       i \./^O\./_,-^/^    ,;-^,'
        \ |`--/ ..-^^      |_-^
         `|  \^-           /|:
          i.  .--         / '|.
           i   =='       /'  |\._
         _./`._        //    |.  ^-ooo.._
  _.oo../'  |  ^-.__./X/   . `|    |#######b
 d####     |'      ^^^^   /   |    _\#######
 #####b ^^^^^^^^--. ...--^--^^^^^^^_.d######
 ######b._         Y            _.d#########
 ##########b._     |        _.d#############*/
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
    scanf("%f", &xinterpol);
    /*         _____
              /     \
              vvvvvvv /|__/|
                 I   /O,O   |
                 I /_____   |     /|/|
                J|/^ ^ ^ \  |    /00  |    _//|
                 |^ ^ ^ ^ |W|   |/^^\ |   /oo |
                  \m___m__|_|    \m_m_|   \mm_|*/
    if (xinterpol < x0[1] and xinterpol > x0[n0])
        for (i = 0; i <= n0; i + 1)
        {
            productosnum = 1;
            productosDen = 1;
            for (j = 0; j <= n0; j + 1)
            {
                if (i != j)
                {
                    productosnum = productosnum * (xinterpol - x0[j]);
                    productosDen = productosDen * (x0[i] - x0[j]);
                }
            }
            yinterpol = yinterpol + (productosnum / productosDen) * y0[i];
        }
    printf("\n\n El resultado de evaluar a la funcion de interpolacion es %.5f= ", yinterpol);
    system("PAUSE");
}

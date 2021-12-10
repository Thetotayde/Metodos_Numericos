#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

/*          __
.-.__      \ .-.  ___  __
|_|  '--.-.-(   \/\;;\_\.-._______.-.
(-)___     \ \ .-\ \;;\(   \       \ \
 |   '---._\_((Q)) \;;\\ .-\     __(_)
 |           __'-' / .--.((Q))---'    \,
 |     ___.-:    \|  |   \'-'_          \
 |  .-'      \ .-.\   \   \ \ '--.__     '\
 |  |____.----((Q))\   \__|--\_      \     '
    ( )        '-'  \_  :  \-' '--.___\
     |                \  \  \       \(_)
     |                 \  \  \         \,
     |                  \  \  \          \
     |                   \  \  \          '\
     |              JMA  \  \__|           '
                           \_:.  \
                             \ \  \
                              \ \  \
                               \_\_|*/

int leerValorInt()
{
	int x;
	scanf("%d", &x);
	return x;
}
float leerValorFloat()
{
	float x;
	scanf("%f", &x);
	return x;
}
float calcularYPrima(float y)
{
	float yPrima = log(y);
	return yPrima;
}
float calcularValorElevadoPor2(float x)
{
	float valorElevado = pow(x,2);
	return valorElevado;
	
}
float multiplicarDosValores(float x, float y)
{
	float producto = x*y;
	return producto;
}
float calculoDeB(float n, float xy, float xi, float yi, float x2)
{
	float b = ((n*xy) - (xi*yi))/((n*x2)- calcularValorElevadoPor2(xi));
	return b;
}
float calcularDivision(float x, float n)
{
	float div = x/n;
	return div;
}
float calcularAprima(float y, float b, float x)
{
	float aPrima = y - (b*x);
	return aPrima;
}
void regresionExponencial()
{
	printf("Introduce el numero de valores para las x:\nj ");
	int numValores=leerValorInt();
	int xi[numValores];
	float yi[numValores];
	int i;
	printf("\n");
	for(i=0; i <= numValores; i++)
	{
		xi[i] = i;
		printf("Introduce y%d: ", i);
		yi[i] = leerValorFloat();
	}
	printf("\n");
	printf("  xi   |  yi\n");
	for(i=0; i <= numValores; i++)
	{
		
		printf("%d      |%.4f\n",xi[i], yi[i] );
	}
	printf("\nPulsa Enter");
	getch();
	system("cls");

	/*         ________
          _,.-Y  |  |  Y-._
      .-~"   ||  |  |  |   "-.
      I" ""=="|" !""! "|"[]""|     _____
      L__  [] |..------|:   _[----I" .-{"-.
     I___|  ..| l______|l_ [__L]_[I_/r(=}=-P
    [L______L_[________]______j~  '-=c_]/=-^
     \_I_j.--.\==I|I==_/.--L_]
       [_((==)[`-----"](==)j
          I--I"~~"""~~"I--I
          |[]|         |[]|
          l__j         l__j
          |!!|         |!!|
          |..|         |..|
          ([])         ([])
          ]--[         ]--[
          [_L]         [_L]  
         /|..|\       /|..|\
        `=}--{='     `=}--{='
       .-^--r-^-.   .-^--r-^-.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	int sumaTotalXi=0;
	float yPrima[numValores];
	float xElevadaPor2[numValores];
	float xiPorYprima[numValores];
	float sumaTotalYprima=0;
	float sumaTotalxElevadaPor2=0;
	float sumaTotalxiPorYprima=0;
	for(i=0; i <= numValores; i++)
	{
		yPrima[i] = calcularYPrima(yi[i]);
		xElevadaPor2[i] = calcularValorElevadoPor2(xi[i]);
		xiPorYprima[i] = multiplicarDosValores(xi[i], yPrima[i]);
		sumaTotalYprima += yPrima[i];
		sumaTotalxElevadaPor2 += xElevadaPor2[i];
		sumaTotalxiPorYprima += xiPorYprima[i];
		sumaTotalXi += xi[i];
	}
	/*                 .-.
                      |_:_|
                     /(_Y_)\
.                   ( \/M\/ )
 '.               _.'-/'-'\-'._
   ':           _/.--'[[[[]'--.\_
     ':        /_'  : |::"| :  '.\
       ':     //   ./ |oUU| \.'  :\
         ':  _:'..' \_|___|_/ :   :|
           ':.  .'  |_[___]_|  :.':\
            [::\ |  :  | |  :   ; : \
             '-'   \/'.| |.' \  .;.' |
             |\_    \  '-'   :       |
             |  \    \ .:    :   |   |
             |   \    | '.   :    \  |
             /       \   :. .;       |
            /     |   |  :__/     :  \\
           |  |   |    \:   | \   |   ||
          /    \  : :  |:   /  |__|   /|
      JMA |     : : :_/_|  /'._\  '--|_\
          /___.-/_|-'   \  \
                         '-'*/
	printf("  xi   |  yi      |y'=ln(yi) |  x^2      |  xi * y'\n");
	for(i=0; i <= numValores; i++)
	{
		printf("%d      |%.4f    |%.4f    |%.4f     |%.4f \n",xi[i], yi[i],	yPrima[i],xElevadaPor2[i],xiPorYprima[i] );
	}
	printf("\nSumas totales:\n");
	printf("xi = %d\ny' = %.4f \nx^2 = %.4f \nxi * yi = %.4f ", sumaTotalXi,sumaTotalYprima,sumaTotalxElevadaPor2,sumaTotalxiPorYprima);
	float expresionB = calculoDeB(numValores+1,sumaTotalxiPorYprima, 	sumaTotalXi, sumaTotalYprima, sumaTotalxElevadaPor2);
	printf("\n\nB = %.5f\n\n", expresionB);
	float xBarraBaja = calcularDivision(sumaTotalXi, numValores+1);
	float yBarraBaja = calcularDivision(sumaTotalYprima, numValores+1);
	printf("Medias:\nX = %.4f\nY = %.4f\n\n", xBarraBaja, yBarraBaja);
	float aPrima = calcularAprima(yBarraBaja, expresionB, xBarraBaja);
	printf("A' = %.5f\n\n", aPrima);
	float aChica = exp(aPrima);
	printf("a = %.5f\n\n", aChica);
	printf("y = %.5f * exp(%.5f * x)", aChica, expresionB);
}



int main()
{
	printf("[Regresion Exponencial]\n\n");
	regresionExponencial();
	return 0;
}

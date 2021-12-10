#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>



/*          |    |              _.-7
           |\.-.|             ( ,(_
           | a a|              \\  \,
           ) ["||          _.--' \  \\
        .-'  '-''-..____.-'    ___)  )\
       F   _/-``-.__;-.-.--`--' . .' \_L_
      |   l  {~~} ,_\  '.'.      ` __.' )\
      (    -.;___,;  | '- _       :__.'( /
      | -.__ _/_.'.-'      '-._ .'      \\
      |     .'   |  -- _                 '\,
      |  \ /--,--{ .    '---.__.       .'  .'
      J  ;/ __;__]. '.-.            .-' )_/
      J  (-.     '\'. '. '-._.-.-'--._ /
      |  |  '. .' | \'. '.    ._       \
      |   \   T   |  \  '. '._  '-._    '.
      F   J   |   |  '.    .  '._   '-,_.--`
      F   \   \   F .  \    '.   '.  /
     J     \  |  J   \  '.   '.    '/
     J      '.L__|    .   \    '    |
     |   .    \  |     \   '.   '. /
     |    '    '.|      |    ,-.  (
     F   | ' ___  ',._   .  /   '. \
     F   (.'`|| (-._\ '.  \-      '-\
     \ .-'  ( L `._ '\ '._ (
JMA  /'  |  /  '-._\      ''\
         `-'*/


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
float elevarValorPor2(float x)
{
	float xElevada = pow(x,2);
	return xElevada;
}
float multiplicarDosValores(float x, float y)
{
	float producto = x*y;
	return producto;
}
float calcularA1(int n, float xiYi, float xElevadaPor2, int xi, float yi)
{
	float a1 = ((n*xiYi)-(xi*yi))/((n*xElevadaPor2) - elevarValorPor2(xi));
	return a1;
}
float calcularBarraBaja(float x, int n)
{
	float xBarraBaja = x/n;
	return xBarraBaja;
}
float calcularA0(float y, float a1, float x)
{
	float a0 = y - (a1 * x);
	return a0;
}
void regresionPorMinimosCuadrados()
{
	printf("Introduce el numero de valores para las x: ");
	int numValores=leerValorInt();
	int   i         =  0;
	int   xi[numValores];
	float yi[numValores];
	printf("\n");
	for(i = 0; i < numValores; i++)
	{
		printf("Introduce el valor de y%d: ", i+1);
		xi[i] = i+1;
		yi[i] = leerValorFloat();
	}
	system("cls");
	printf("  xi  |  yi\n");	
	int   sumaTotalDeXi = 0;
	float sumaTotalDeYi = 0;
	for(i = 0; i < numValores; i++)
	{
		printf(" %d    |%f\n", xi[i], yi[i]);
		
		sumaTotalDeXi+=xi[i];
		sumaTotalDeYi+=yi[i];
	}
	/*    ____
          \__/         # ##
         `(  `^=_ p _###_
          c   /  )  |   /
   _____- //^---~  _c  3
 /  ----^\ /^_\   / --,-
(   |  |  O_| \\_/  ,/
|   |  | / \|  `-- /
(((G   |-----|
      //-----\\
     //       \\
   /   |     |  ^|
   |   |     |   |
   |____|    |____|
  /______)   (_____\*/
	printf("\n");
	float xiElevadaPor2[numValores];
	float productoDeXiYi[numValores];
	float sumaTotalXElevadaPor2=0;
	float sumaTotalProductoDeXiYi=0;
	printf("  xi  |  yi        |  x%ci       |  xi*yi\n", 253);	
	for(i = 0; i < numValores; i++)
	{
		xiElevadaPor2[i] = elevarValorPor2(xi[i]);
		productoDeXiYi[i] = multiplicarDosValores(xi[i],  yi[i]);
		printf(" %d    |%f    |%f    |%f    \n", xi[i], yi[i], xiElevadaPor2[i], productoDeXiYi[i]);
		sumaTotalXElevadaPor2   += xiElevadaPor2[i];
		sumaTotalProductoDeXiYi += productoDeXiYi[i];
	}
	printf("\n");
	printf("Sumas totales de:\nxi    = %d\nyi    = %f\nx%ci   = %f\nxi*yi = %f\n", sumaTotalDeXi, sumaTotalDeYi, 253, sumaTotalXElevadaPor2, sumaTotalProductoDeXiYi);
	float a1 = calcularA1(numValores,sumaTotalProductoDeXiYi, sumaTotalXElevadaPor2, sumaTotalDeXi, sumaTotalDeYi);
	printf("\n");
	printf ("a1 = %f\n", a1);
	printf("\n");
	printf("Medias:\n");
	float xBarraBaja = calcularBarraBaja(sumaTotalDeXi, numValores);
	printf("x = %f\n",xBarraBaja);
	float yBarraBaja = calcularBarraBaja(sumaTotalDeYi, numValores);
	printf("y = %f\n",yBarraBaja);
	printf("\n");
	float a0 = calcularA0(yBarraBaja, a1, xBarraBaja);
	printf ("a0 = %f\n", a0);
	printf("\n");
	printf("Ajuste por minimos cuadrados es:\ny = %f + %fx", a0, a1);
}
/*            *         *      *         *
          ***          **********          ***
       *****           **********           *****
     *******           **********           *******
   **********         ************         **********
  ****************************************************
 ******************************************************
**************************ボブ**************************
********************************************************
********************************************************
 ******************************************************
  ********      ************************      ********
   *******       *     *********      *       *******
     ******             *******              ******
       *****             *****              *****
          ***             ***              ***
            **             *              ***/
int main()
{
	printf("[Regresion por minimos cuadrados]\n\n");
	regresionPorMinimosCuadrados();
	return 0;
}

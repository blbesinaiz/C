/***********************************
Temp Conversion: This program converts
F to Celsius up to 300 
***************************************/

#include <stdio.h>

int main()
{
   float F = 0;
   float C = 0;
   float maxFloat = 0;
   float Increment = 0;
   float temp = 0;

   printf("Please enter how you would like to increment temperature(i.e. 50): ");
   scanf("%f", &Increment);
   printf("      F           C\n");
   while(maxFloat <= 300)
   {
      F = temp;
      C = (temp - 32.0)*5.0/9.0;
      printf("    %.1f        %.1f\n", F, C);
      temp += Increment;
      maxFloat = temp;
   }

   return 0;
}
/***********Results****************************************************
Please enter how you would like to increment temperature(i.e. 50): 25
      F           C
    0.0        -17.8
    25.0        -3.9
    50.0        10.0
    75.0        23.9
    100.0        37.8
    125.0        51.7
    150.0        65.6
    175.0        79.4
    200.0        93.3
    225.0        107.2
    250.0        121.1
    275.0        135.0
    300.0        148.9
*************************************************************************/

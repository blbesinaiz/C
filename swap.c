#include <stdio.h>

int main()
{
	int x = 50;
	int y = 100;
	
	printf("Current values for x: %d  y:  %d\n", x, y);
	
	swap(&x, &y);
	
	printf("Swapped values for x: %d  y:  %d\n", x, y);
	
	return 0;
}

void swap(int *x, int *y)
{
   int temp;
 
   temp  = *x;
   *x = *y;
   *y = temp;
}

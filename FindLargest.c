#include <stdio.h>
#include <time.h>
int findLargest(int[], int);
int main() {
   /* this program uses random genereator to generate 50 integers
      all < 100. 
	  the program than call a function findLarges which takes the 
	  array as inpt pamameter and returns the lagest in the array.
	  The main function then prints the largest number along with
	  the location in the array to the screen.
   */
   srand(time(0));
   int randNumArray[50];
   int i, maxLoc;
   for (i = 0; i < 50; i++)
   {
      randNumArray[i] = rand() %100;
   }
   int max = findLargest(randNumArray, 50);
   for (i = 0; i < 50; i++) 
   {
      if (randNumArray[i] == max)
	  {
	     maxLoc = i;
		 break;
	  }
   }
   printf("the largest number is %d and it is located at index %d\n", max,maxLoc);
   return 0;
}
int findLargest(int anyArray[], int len)
{
    int i, largest = anyArray[0];
	for (i = 1; i < len; i++) 
	{
	    if (largest < anyArray[i])
		   largest = anyArray[i];
	}
	return largest;
}

/* Prompt the user for a series of ints.
   Print the ints  out in reverse.*/ 

#include <stdlib.h>     //printf, scanf
#include <stdio.h>      //realloc, free

#define SIZE 5
 
void increase(int** arr)   //Function to reallocate more memory
{
   *arr = realloc(*arr, 5 * sizeof(int));
}

int main()
{
   int *arr = (int*) malloc(sizeof(int) *SIZE);
   int temp;        //holds input from user
   int i = 0;	    //Variable serves as counter

   printf("Please enter an integer; press a letter to stop: ");
   while (scanf("%d", &temp) > 0)
   {
      if(i > SIZE)       //If i > allocated memory
        increase(&arr);    //Calls function to reallocate

      arr[i] = temp;	 //Place number into array
      i++;               //Increment array placement

      printf("Please enter an integer; press a letter to stop: ");
   }

   i--;  	/* i now points past the last element */
   printf("\nInteger List printed in reverse: \n");
   for(; i >=0; i--)	/*points to last element*/
   {
      printf("%d\n", arr[i]);
   }
   free(arr);    //Free memory once completed

   return 0;
}

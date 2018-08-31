#include <stdio.h>
#include <stdlib.h>
/* Program generates two array. One array hold randomly generated
   values 0 - 599. The other array holds values of 0 - whatever
   the max array size. Prints arrays to console. 		*/

int main()
{
	int i;		//Variable acts as a counter
	int t;		//Variable holds value when swapping
	int arr_size;	//Variable holds array size from user

	printf("Please enter the desired size of the array: ");
	scanf("%d", &arr_size);

	int* a1 = (int*) malloc(sizeof(int) * arr_size);
	int* a2 = (int*) malloc(sizeof(int) * arr_size);

	/*Populate arrays */
	srand(time(NULL));
	for (i = 0; i <= arr_size; i++)
	{
		a1[i] = rand() % (599 + 1 - 0) + 0; 	//Range of 0 - 599
		a2[i] = i;
	}

	/*Swap the two arrays */
	for (i = 0; i <= arr_size; i++)
	{
		t = a1[i];
		a1[i] = a2[i];
		a2[i] = t;
	}

	/*Print the arrays */
	for (i = 0; i<= arr_size; i++)
	{
		printf("%d : %d\n", a1[i], a2[i]);
	}
	free(a1);
	free(a2);

	return 0;
}

/***********************************************************************
Brianna Besinaiz
CSC 292
Program Title: Sentence Length
Program Desription: This program takes in a sentence from the user and
				   printes the legnth of the sentence to the user
************************************************************************/

#include <stdio.h>

int main()
{
	char sentence[100];		//Array of char to hold characters
	
	printf("Please enter in a sentence: ");
	gets(sentence);			//Function gets whole line
	
	printf("\nSentence entered: \n %s", sentence);
																//Prints character length using strlen
	 printf ("\n\nThe sentence entered is %i characters long.\n",(int)strlen(sentence));
	
	return 0;
}

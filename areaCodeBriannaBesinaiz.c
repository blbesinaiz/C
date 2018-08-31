/*************************************
This program takes in area code and
then evaluates the area; outputs
location
*************************************/

#include<stdio.h>

int main()
{
   int areaCode;

   printf("Please enter an area code,0 to quit: ");
   scanf("%d", &areaCode);
   while(areaCode != 0)
   { 
      printf("Major City: ");
      switch(areaCode) 
      {
         case 229: printf("Albany \n");    break;
         case 404: printf("Atlanta \n");   break;
         case 470: printf("Atlanta \n");   break;
         case 478: printf("Macon \n");     break;
         case 678: printf("Atlanta \n");   break;
         case 706: printf("Columbus \n");  break;
         case 762: printf("Columbus \n");  break;
         case 770: printf("Atlanta \n");   break;
         case 912: printf("Savannah \n");  break;

         default: printf("Area code not recognized \n");   break;
       }
       printf("Please enter an area code,0 to quit: ");
       scanf("%d", &areaCode);
     }
    return 0;
}


/**********Results************************
Please enter an area code,0 to quit: 229
Major City: Albany
Please enter an area code,0 to quit: 478
Major City: Macon
Please enter an area code,0 to quit: 706
Major City: Columbus
Please enter an area code,0 to quit: 912
Major City: Savannah
Please enter an area code,0 to quit: 0
******************************************/

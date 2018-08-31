#include <stdio.h>
#include <stdlib.h>
typedef struct node{
        int data;		//Holds data
        struct node* next;	//Pointer to next node
}node;

node* buildList(node*,int);		//Function builds the list from command line arguments
void printList(node*);			//Function prints nodes in the list
void reverseList(node*,node**);		//Function reverses list by creating new list in reverse
node* insertLast(node*,node*);		//Function inserts a node at the end
node* insertFirst(node*, node*);		//Function inserts a node at the beginning
void morePositive(node*, node**, node**);	//Function compares the positive and negative nodes

int main(int argc,char *argv[])		//Accepts arguments from command line
{
        int i;
        node* head = NULL;		//Points to beginning of list
        node* positiveH = NULL;		//Points to beginning of positive node list
        node* negativeH =NULL;		//Points to beginning of negative node list
        node* rHead = NULL;		//Points to beginning of reverse list
        
        for(i = 1;i<argc;i++)		//Loops until all arguments in from command line added
        {
                int c = strtol(argv[i],NULL,10);	//Converts aregument into an integer
                head = buildList(head,c);		//Head always equals first node of list
        }
        
        printf("\n\nThe nodes in the current List:\n");	//Prints nodes in current list
		printList(head);
        
        morePositive(head,&positiveH,&negativeH);	//Determines more (+)/(-) nodes
        printf("The Positive List:\n");
        printList(positiveH);
        
        printf("The Negative List:\n");
        printList(negativeH);
        
        node* newNode = (node*)malloc(sizeof(node));	//Create new node to have user enter data into
        printf("Please enter an integer to insert into front of the list: ");
	scanf("%d",&newNode->data);	//Store input into new node
       
	 newNode->next = NULL;
         head = insertFirst(head,newNode);
        
        node* newNode2 = (node*)malloc(sizeof(node));
        printf("Please enter a number to insert into the end of the list: ");
        scanf("%d",&newNode2->data);
        newNode2->next = NULL;
        
        head=insertLast(head,newNode2);
        reverseList(head,&rHead);
return 0;
}


void printList(node* head)
{
        node* current = head;	//Current points to beginning node
        while(current!=NULL)
        {
                printf("%d  ",current->data);	//Prints data of current node
                current = current -> next;	//Moves current pointer forward
        }
        printf("\n\n");
return;
}

node* buildList(node* head,int tempC)
{
        node* current = head;				//Current points to first node of list
        node* temp = (node*)malloc(sizeof(node));	//Create and assign memory for temp node
        temp -> data = tempC;				//Assign value into temp node
        temp -> next = NULL;
        if(head == NULL)		//If the list is empty
        {
                head = temp;	
                current = temp;
        }
        else				//If list is not empty
        {
                node* temp1 = (node*)malloc(sizeof(node));	//Create and assign memory space for temp1
                while(current->next != NULL)
                {
                        temp1 = current->next;	//Insets node at the end
                        current = temp1; 
                }
                current-> next = temp;		//Sets up to insert next node
                current = temp ;
        }

return head;
}

void reverseList(node* head, node** rhead)
{
        node* current = head;
        node* prev = NULL;
        node* tempNext = NULL;
        while(current != NULL)			//Builds list in reverse
        {
                tempNext = current -> next;
                current->next = prev;
                prev = current;
                current = tempNext;
        }
        *rhead = prev;				//Pointer to beginning of reverse list
        printf("The List Reversed: \n");
        printList(*rhead);
return;
}

node* insertLast(node* head, node* newNode)
{
        node* current = head;
        while (current->next!=NULL)
        {
                current = current->next;
        }
        current-> next = newNode;
        printf("List with node added to end:\n");
        printList(head);
return head;
}

node* insertFirst(node* head, node* newNode)
{
        newNode->next = head;
        head = newNode;
        printf("List with node added to front:\n");
        printList(head);
return head;
}
void morePositive(node* head, node** positiveHead, node** negativeHead)
{
	int pcount = 0;
	int ncount = 0;
        node* current = head;
        while(current->next!=NULL)
        {
                if(current->data<0)
                {
                        node* tempN = (node*)malloc(sizeof(node));
                        tempN->data = current->data;
                        tempN->next = *negativeHead;
                        *negativeHead = tempN;
                        ncount++;
                }
                else
                {
                        node* tempP = (node*)malloc(sizeof(node));
                        tempP->data = current->data;
                        tempP->next = *positiveHead;
                        *positiveHead = tempP;
                        pcount++;
                }
                current = current->next;
        }
        
        if(pcount > ncount)
        	printf("\nThere are more positve numbers in the list:\n");
        	
        else if(pcount < ncount)
        	printf("\n There are more negative numbers in the list:\n");
        	
        else
        	printf("\n There are the same amount of positive and negative number in the list:\n");
return;
}



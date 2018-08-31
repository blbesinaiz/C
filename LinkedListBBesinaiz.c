#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int info;
        struct node* nextNode;
}node;

node* buildList(node*,int);
void printList(node*);
void reverseList(node*,node*);
void insertLast(node*,node*);
void insertFirst(node*, node*);
void morePositive(node*, node**, node**);

int main(int argc,char *argv[])
{
        int i;
        node* head = NULL;
        node* positive_head = NULL;
        node* negative_head =NULL;
        for(i = 1;i<argc;i++)
        {
                int c = strtol(argv[i],NULL,10);
                head = buildList(head,c);
        }
        printList(head);
        reverseList(head,head);
        morePositive(head,&positive_head,&negative_head);
return 0;
}

void printList(node* head)
{
        node* current = head;
        printf("Nodes in current list: ");
        while(current!=NULL)
        {
                printf("%d -> ",current->info);
                current = current -> nextNode;
        }
        printf("\n");
}

node* buildList(node* head,int tempC)
{
        node* current = head;
        node* temp = (node*)malloc(sizeof(node));
        temp -> info = tempC;
        temp -> nextNode = NULL;
        if(head == NULL)
        {
                head = temp;
                current = temp;
        }
        else
        {
                node* temp1;
                while(current->nextNode != NULL)
                {
                        temp1 = current->nextNode;
                        current = temp1;
                }
                current-> nextNode = temp;
                current = temp ;
        }

return head;
}
void reverseList(node* head, node* rhead)
{
        node* current = head;
        node* prev = NULL;
        node* tempNext = NULL;
        while(current != NULL)
        {
                tempNext = current -> nextNode;
                current->nextNode = prev;
                prev = current;
                current = tempNext;
        }
        rhead = prev;
        printf("The List Reversed: \n");
        printList(rhead);
return;
}

void insertLast(node* head, node* newNode)
{
        printf("inside last");
        node* current = head;
        while (current!=NULL)
        {
                current = current->nextNode;
        }
        current-> nextNode = newNode;
        newNode->nextNode = NULL;
return;
}
void insertFirst(node* head, node* newNode)
{
        newNode->nextNode = head;
        head = newNode;
return;
}
void morePositive(node* head, node** positiveHead, node** negativeHead)
{
        node* current = head;
        while(current!=NULL)
        {
                if(current->info >= 0)
                {
                        node* temp = current;
                        node* currentP;
                        if(*positiveHead == NULL)
                        {
                                *positiveHead = temp;
                                currentP = temp;
                        }
                        else
                        {
                                node* tempP;
                                while(currentP->nextNode!=NULL)
                                {
                                        tempP = currentP->nextNode;
                                        currentP = tempP;
                                }
                                currentP-> nextNode = temp;
                                currentP=temp;
                        }
                }
                else if(current->info < 0)
                {
                        node* temp = current;
                        node* currentN;
                        if(*negativeHead==NULL)
                        {
                                *negativeHead = temp;
                                currentN = temp;
                        }
                        else
                        {
                                node* tempN;
                                while(currentN->nextNode != NULL)
                                {
                                        tempN = currentN->nextNode;
                                        currentN = tempN;
                                }
                                currentN-> nextNode = temp;
                                currentN = temp;
                        }
                }
        current = current-> nextNode;
        }
        printf("The Postive List:\n");
        printList(*positiveHead);
        printf("The Negative List:\n");
        printList(*negativeHead);
return;
}


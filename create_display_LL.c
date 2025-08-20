#include<stdio.h>
#include<stdlib.h>
struct slist{
    int data;
    struct slist *next;
}*start=NULL;
typedef struct slist node;

void create()
{
    node *NN,*temp;
    int data;

    printf("Enter the data for New Node : ");
    scanf("%d",&data);

    NN=(node*)malloc(sizeof(node));
    NN->data=data;
    NN->next=NULL;

    if(start==NULL)
        start=NN;
    else
    {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=NN;
    }
}

void display()
{
    node *temp;
    temp=start;
    if(temp==NULL)
        printf("\nEmpty list.");
    else
    {
        printf("List : ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1->Create list\n2->Display list\n3->Exit\nEnter the choice : ");
        scanf("%d",&ch);

        if(ch==1)
            create();
        else if(ch==2)
            display();
        else if(ch==3)
            break;
        else
            printf("\nInvalis choice");
    }
    return 0;
}
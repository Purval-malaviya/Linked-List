#include<stdio.h>
#include<stdlib.h>
struct slist{
    int data;
    struct slist *next;
}*start=NULL,*last=NULL;
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

    if(start==NULL && last==NULL)
    {
        start=NN;
        last=NN;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=NN;
        last=NN;
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

void firstposcreate()
{
    node *NN,*temp;
    int data;

    printf("Enter the data for New Node : ");
    scanf("%d",&data);

    NN=(node*)malloc(sizeof(node));
    NN->next=NULL;
    NN->data=data;

    if(start==NULL && last==NULL)
    {
        start=NN;
        last=NN;
    }
    else
    {
        temp=start;
        NN->next=temp;
        start=NN;
    }
}

void lastposcreate()
{
    node *NN,*temp;
    int data;

    printf("Enter the data for New Node : ");
    scanf("%d",&data);

    NN=(node*)malloc(sizeof(node));
    NN->next=NULL;
    NN->data=data;

    if(start==NULL && last==NULL)
    {
        start=NN;
        last=NN;
    }
    else
    {
        temp=last;
        temp->next=NN;
        last=NN;
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1->Create list\n2->Display \n3->Create node at first position\n4->Create node at last position\n5->Exit\nEnter the choice : ");
        scanf("%d",&ch);

        if(ch==1)
            create();
        else if(ch==2)
            display();
        else if(ch==3)
            firstposcreate();
        else if(ch==4)
            lastposcreate();
        else if(ch==5)
            break;
        else
            printf("\nInvalid choice");
    }
    return 0;
}
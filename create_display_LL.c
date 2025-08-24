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

    if(start==NULL)
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

    if(start==NULL)
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

void givenposcreate()
{
    node *NN,*curr,*prev;
    int data,pos;

    printf("Enter the position : ");
    scanf("%d",&pos);
    printf("Enter the data for New Node : ");
    scanf("%d",&data);

    NN=(node*)malloc(sizeof(node));
    NN->next=NULL;
    NN->data=data;

    curr=start;
    prev=NULL;

    if(pos==1)
    {
       NN->next=curr;
       start=NN;
    }   
    else{
        int count=1;
        while(count<pos)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        // for(int i=1;i<pos;i++)
        // {
        //     prev=curr;
        //     curr=curr->next;
        // }
        prev->next=NN;
        NN->next=curr;
    }
    if(curr==NULL)
        last=NN;
}

void countnode()
{
    node *temp;
    temp=start;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Total nodes : %d\n",count);
}

int lsum()
{
    node *temp;
    int sum=0;
    if(start==NULL)
    {
        printf("List is Empty !\n");
        return 0;
    }
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            sum=sum+temp->data;
            temp=temp->next;
        }    
        printf("Sum of List : %d\n",sum);
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1->Create list\n2->Display \n3->Create node at first position\n4->Create node at last position\n5->Create node given position\n6->Count Nodes\n7->Sum of list\n8->Exit\nEnter the choice : ");
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
            givenposcreate();
        else if(ch==6)
            countnode();
        else if(ch==7)
            lsum();
        else if(ch==8)
            break;
        else
            printf("\nInvalid choice");
    }
    return 0;
}
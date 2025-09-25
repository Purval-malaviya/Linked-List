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
        printf("Empty list.\n");
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

void swap(node *a,node *b)
{
    int temp;
    temp=a->data;
    a->data=b->data;
    b->data=temp;
}

void ascsortlist()
{
    node *temp,*temp1;
    if(start==NULL)
    {
        printf("List is Empty !\n");
        return;
    }
    temp=start;
    printf("ASC Sorted List :");
    while(temp!=NULL)
    {
        temp1=temp->next;
        while(temp1!=NULL)
        {
            if(temp->data >temp1->data)
                swap(temp,temp1);
            temp1=temp1->next;
        }
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1->Create list\n2->Display \n3->Sort List\n4->Exit\nEnter the choice : ");
        scanf("%d",&ch);

        if(ch==1)
            create();
        else if(ch==2)
            display();
        else if(ch==3)
           ascsortlist();
        else if(ch==4)
            break;
        else
            printf("\nInvalid choice");
    }
    return 0;
}
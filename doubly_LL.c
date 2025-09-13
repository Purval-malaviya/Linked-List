#include<stdio.h>
#include<stdlib.h>
struct dll{
    struct dll *left;
    int data;
    struct dll *right;
}*first=NULL,*last=NULL;
typedef struct dll node;

void create()
{
    node *NN;
    int data;

    printf("Enter the value :");
    scanf("%d",&data);
    NN=(node*)malloc(sizeof(node));
    NN->left=NULL;
    NN->data=data;
    NN->right=NULL;

    if(first==NULL)
        first=last=NN;
    else
    {
        last->right=NN;
        NN->left=last;
        last=NN;
    }
}

void display()
{
    node *temp,*temp1;
    if(first==NULL)
        printf("List is Empty !\n");
    else
    {
        temp=first;
        printf("List :");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->right;
        }
        printf("\n");
        printf("R List :");
        temp1=last;
        while(temp1!=NULL)
        {
            printf("%d ",temp1->data);
            temp1=temp1->left;
        }
        printf("\n");
    }
}

void insertpos()
{
    node *curr,*prev,*NN;
    curr=first;
    prev=NULL;
    int count=1,pos,data;

    printf("Enter the positon : ");
    scanf("%d",&pos);

    printf("Enter the value :");
    scanf("%d",&data);

    NN=(node*)malloc(sizeof(node));
    NN->left=NULL;
    NN->data=data;
    NN->right=NULL;

    if(pos==1)
        first=NN;
    else
    {
        while(count<pos)
        {
            prev=curr;
            curr=curr->right;
            count++;
        }
    }
    if(prev!=NULL)   
        prev->right=NN;
    NN->left=prev;
    NN->right=curr;
    if(curr!=NULL)
        curr->left=NN;  

    if(curr==NULL)
        last=NN;
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Create list\n2.Display\n3.Insert given position\n4.Exit\nEnter the choice :");
        scanf("%d",&ch);

        if(ch==1)
            create();
        else if(ch==2)
            display();
        else if(ch==3)
            insertpos();
        else if(ch==4)
            break;
        else
            printf("Invalid choice....");
    }

    return 0;
}
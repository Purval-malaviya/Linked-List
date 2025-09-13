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

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Create list\n2.Display\n3.Exit\nEnter the choice :");
        scanf("%d",&ch);

        if(ch==1)
            create();
        else if(ch==2)
            display();
        else if(ch==3)
            break;
        else
            printf("Invalid choice....");
    }

    return 0;
}
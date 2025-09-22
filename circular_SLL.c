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

    if(start==NULL)
        start=last=NN;
    else
    {
        temp=start;
        while(temp->next!=start)
            temp=temp->next;
        temp->next=NN;
        last=NN;
    }
    last->next=start;
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
        while(temp->next!=start)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",last->data);
        printf("\n");
    }
}

void firstposcreate()
{
    node *NN;
    int data;

    printf("Enter the data for New Node : ");
    scanf("%d",&data);

    NN=(node*)malloc(sizeof(node));
    NN->next=NULL;
    NN->data=data;

    if(start==NULL)
        start=last=NN;
    else
    {
        NN->next=start;
        start=NN;
    }
    last->next=start;
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
    last->next=start;

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
    if(curr==start)
        last=NN;
    last->next=start;

}

void fdelete()
{
    node *temp;
    if(start==NULL)
        printf("List is empty !\n");
    else
    {
        temp=start->next;
        free(start);
        start=temp;
    }
    last->next=start;
}

void ldelete()
{
    node *temp,*prev,*curr;
    if(start==NULL)
        printf("List is empty !\n");
    else
    {
        // curr=start;             // Using two pointer
        // prev=NULL;
        // while(curr->next!=NULL)
        // {
        //     prev=curr;
        //     curr=curr->next;
        // }
        // free(curr);
        // last=prev;  
        temp=start;
        while(temp->next!=last)
            temp=temp->next;
        free(last);
        last=temp;
        last->next=NULL;
    }
    last->next=start;
}

int givenposdelete()
{
    node *prev,*curr; 
    curr=start;
    prev=NULL;
    if(start==NULL)
    {
        printf("List is empty !\n");
        return 0;
    }

    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(start==last)
    {
        free(start);
        start=last=NULL;
        return 0;
    }
    if(pos==1)
    {
        // start=start->next;  //Second way
        // free(curr);
        curr=curr->next;
        free(start);
        start=curr;
    }
    else
    {
        int count=1;
        while(count<pos)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        free(curr);
        if(prev->next==start)
        last=prev;
    }
    last->next=start;
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1->Create list\n2->Display \n3->Create node at first position\n4->Create node at last position\n5->Create node given position\n6->Delete First Node\n7->Delete Last Node\n8->Delete Given Position\n9->Exit\nEnter the choice : ");
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
            fdelete();
        else if(ch==7)
            ldelete();
        else if(ch==8)
            givenposdelete();
        else if(ch==9)
            break;
        else
            printf("\nInvalid choice");
    }
    return 0;
}
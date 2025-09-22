#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct member{
    int rollno;
    char name[50];
    int sem;
    float per;
    struct member *next;
}*first=NULL,*last=NULL;
typedef struct member newdata;

void newrecord()
{
    int roll,sem;
    float per;
    char name[50];

    newdata *NN;

    printf("Enter the Roll no :");
    scanf("%d",&roll);

    printf("Enter the Name :");
    scanf("%s",name);

    printf("Enter the Sem :");
    scanf("%d",&sem);

    printf("Enter the Percentage :");
    scanf("%f",&per);
    NN=(newdata*)malloc(sizeof(newdata));
    NN->rollno=roll;
    strcpy(NN->name,name);
    NN->sem=sem;
    NN->per=per;
    NN->next=NULL;

    if(first==NULL)
        first=last=NN;
    else
    {
        last->next=NN;
        last=NN;
    }
}

void displaydata()
{
    newdata *temp;
    if(first==NULL)
    {
        printf("List is Empty !\n");
        return;
    }
    else
    {
        temp=first;
        printf("\n\t\t----------Student Records----------\n");
        while(temp!=NULL)
        {
            printf("\n\t\t\tRoll No : %d\n\t\t\tName : %s\n\t\t\tSem : %d\n\t\t\tPercentage : %.2f\n",temp->rollno,temp->name,temp->sem,temp->per);
            temp=temp->next;
        }
        printf("\n");
    }
}

void searchstudent()
{
    newdata *temp;
    float per;
    if(first==NULL)
    {
        printf("List is Empty !\n");
        return;
    }
    else
    {
        temp=first;
        printf("Enter the Percentage to see it's greater than percentages students :");
        scanf("%f",&per);

        printf("\n\t\t----------Student Records which Greater than Searched Percentage----------\n");
        while(temp!=NULL)
        {
            if(temp->per>=per)
            {
                printf("\n\t\t\tRoll No : %d\n\t\t\tName : %s\n\t\t\tSem : %d\n\t\t\tPercentage : %.2f\n",temp->rollno,temp->name,temp->sem,temp->per);
            }
            temp=temp->next;
        }
    }
}

void deleterecord()
{
    newdata *curr,*prev;
    int rollno;

    printf("Enter the Roll No. to Delete Record :");
    scanf("%d",&rollno);

    curr=first;
    prev=NULL;
    printf("\n\t\t----------Student Records To Deleted----------\n");
    if(first->rollno==rollno)
    {
        printf("\n\t\t\tRoll No : %d\n\t\t\tName : %s\n\t\t\tSem : %d\n\t\t\tPercentage : %.2f\n",first->rollno,first->name,first->sem,first->per);
        first=first->next;
        free(curr);
        return;
    }
    while(curr->rollno!=rollno)
    {
        prev=curr;
        curr=curr->next;
        if(curr==NULL)
        {
            printf("Record doesn't exist !\n");
            return; 
        }
    }
    printf("\n\t\t\tRoll No : %d\n\t\t\tName : %s\n\t\t\tSem : %d\n\t\t\tPercentage : %.2f\n",curr->rollno,curr->name,curr->sem,curr->per);
    if(curr!=NULL)
    prev->next=curr->next;
    free(curr);

    if(prev->next==NULL)
    last=prev;
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1->New Record/Data\n2->Display\n3->Search Student based on Percentage\n4->Delete Record\n5->Exit\nEnter the choice :");
        scanf("%d",&ch);

        if(ch==1)
            newrecord();
        else if(ch==2)
            displaydata();
        else if(ch==3)
            searchstudent();
        else if(ch==4)
            deleterecord();
        else if(ch==5)
            break;
        else
            printf("Invalid choice...\n");
    }
    return 0;
}
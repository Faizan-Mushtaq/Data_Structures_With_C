#include<stdio.h>
#include<stdlib.h>
struct node{
    int data,row,col;
    struct node *next,*prev;
};
struct node *getnode();
struct node *insert(struct node *,int,int,int);
void display(struct node *,int,int);
int main()
{
    struct node *head=NULL;
    int m,n,row,col,data,ct;
    printf("enter order\n");//total order of matrix
    scanf("%d%d",&m,&n);
    printf("enter no of entries\n");//total no of non zero elements in matrix
    scanf("%d",&ct);
    for(int i=0;i<ct;i++)
    {
        printf("enter row col data\n");
        scanf("%d%d%d",&row,&col,&data);
        if(data!=0)
        {
            head=insert(head,row,col,data);
        }
    }
    display(head,m,n);
    return 0;
}
struct node *getnode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
struct node *insert(struct node *head,int row,int col,int data)
{
    struct node *temp=head,*newnode;
    newnode=getnode();
    newnode->data=data;
    newnode->row=row;
    newnode->col=col;
    if(head==NULL){return newnode;}
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
    return head;
}
void display(struct node *head,int m,int n)
{
    struct node *temp=head;
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(temp!=NULL && temp->row==i && temp->col==j)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
            }
            else{
                printf("0\t");
            }
        }
        printf("\n");
    }
}

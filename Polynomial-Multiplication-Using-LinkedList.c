#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef,expo;
    struct node *next;
};
typedef struct node *Node;
Node getnode();
Node readpoly(Node);
Node insert(Node,int,int);
Node mul(Node,Node);
void display(Node);
Node simplify(Node);//to simplify the polynomial to least terms

int main()
{
    Node poly1=NULL,poly2=NULL,poly3=NULL;
    printf("enter poly 1\n");
    poly1=readpoly(poly1);
    printf("enter poly2\n");
    poly2=readpoly(poly2);
    printf("poly 1 is\n");
    display(poly1);
    printf("poly 2  is\n");
    display(poly2);
    printf("result\n");
    poly3=mul(poly1,poly2);
    display(poly3);
    printf("simplified\n");
    poly3=simplify(poly3);
    display(poly3);
    return 0;
}
Node getnode()
{
    Node newnode;
    newnode=(Node)malloc(sizeof(struct node));
    return newnode;
}
Node readpoly(Node head)
{
    int i,expo,coef,n;
    printf("enter no of terms poly\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter cof and expo for %d term\n",i+1);
        scanf("%d%d",&coef,&expo);
        head=insert(head,coef,expo);
    }
    return head;
}
Node insert(Node head,int coef,int expo)
{
    Node newnode=getnode();
    newnode->coef=coef;
    newnode->expo=expo;
    newnode->next=NULL;
    if(head==NULL)
    {return newnode;}
    else
    {
        Node temp=head;
        while(temp->next!=NULL)
        {temp=temp->next;}
        temp->next=newnode;
        return head;
    }
}
Node mul(Node p1,Node p2)
{
    Node res=NULL,p,q;
    p=p1;
    q=p2;
    if(p==NULL||q==NULL)
    {printf(" one poly does not exist.\n");
exit(0);}
    while(p!=NULL)
    {
        q=p2;
        while(q!=NULL)
        {
            res=insert(res,p->coef*q->coef,p->expo+q->expo);
            q=q->next;
        }
        p=p->next;
    }
    return res;
}
void display(Node head)
{
    Node temp=head;
    if(head==NULL)
    {printf("no poly exists\n");
return;
     }
    while(temp!=NULL)
    {
        if(temp->coef!=0)
        {printf("%+d*X^%d ",temp->coef,temp->expo);}
        temp=temp->next;
    }
//    if(temp->coef!=0)
//    printf("%d*X^%d",temp->coef,temp->expo);
    printf("\n");
}
Node simplify(Node head)
{
    Node temp,new=NULL;
    temp=head;
    new=NULL;
    int deg=0,i,nc;
    while(temp!=NULL)
    {
        if(temp->expo>deg)
        {deg=temp->expo;}
        temp=temp->next;
    }
    for(i=0;i<=deg;i++)
    {
        temp=head;
        nc=0;
        while(temp!=NULL)
        {
            if(temp->expo==i)
            {nc=nc+temp->coef;}
            temp=temp->next;
        }
        if(nc!=0)
        {new=insert(new,nc,i);}
    }
    return new;
}

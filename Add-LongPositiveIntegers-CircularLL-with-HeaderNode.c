#include<stdio.h>
#include<stdlib.h>
struct node {
      int data;
      struct node *next;
};
struct node *getnode();
struct node *insert(struct node *,int);
struct node *add(struct node *,struct node *);
void display (struct node *);

int main()
{
  int i,value;
  char str1[100],str2[100];
  struct node *first=NULL,*second=NULL,*res=NULL;
  first = getnode();
  first->data=0;
  first->next=first;//header node
  second=getnode();
  second->data=0;
  second->next=second;
  printf("ENTER FIRST NO\n");
  scanf("%s",str1);
  printf("ENTER SECOND NO\n");
  scanf("%s",str2);
  for(i=0;str1[i]!='\0';i++)
  {
    value=str1[i]-48;
    first=insert(first,value);
  }
  printf("FIRST NUMBER IS:\n");
  puts(str1);//because display(first); prints backwards
  for(i=0;str2[i]!='\0';i++)
  {
    value=str2[i]-48;
    second=insert(second,value);//inserts front that is why display() prints backwards.
  }
  printf("SECOND NUMBER IS:\n");
  puts(str2);//display(second);
  res=add(first,second);
  printf("ANSWER IS:\n");
  display(res);
  return 0;
}

struct node *getnode()
{
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->next =newnode; //circular list
  return newnode;
}
struct node * insert(struct node *head,int value)
{
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));//or getnode()
  newnode->data=value;
  if(head->next==head)
  {
    head->next=newnode;
    newnode->next=head;
  }else{
    newnode->next=head->next;
    head->next=newnode;
  }
  return head;
}
struct node *add(struct node *first,struct node *second)
{
    struct node *res=NULL,*temp,*prev=NULL,*h1,*h2;
    int carry=0,sum=0;
    res=getnode();
    res->data=0;//value in header node
    res->next=res;//header node
    h1=first;
    h2=second;
    first=first->next;
    second=second->next;//to leave header
    while(first!=h1 && second!=h2)
      {
        sum=carry+(first?first->data:0)+(second?second->data:0);
        carry=(sum>=10)?1:0;
        sum=sum%10;
        res=insert(res,sum);
        if(first!=h1){first=first->next;}
        if(second!=h2){second=second->next;}
      }
      if(first!=h1)//if first no is long
      {
        while(first!=h1)
        {
          sum=carry+first->data;
          carry=(sum>=10)?1:0;
          sum=sum%10;
          res=insert(res,sum);
          if(first!=h1){first=first->next;}
        }
      }
      if(second!=h2)//if second no is long
      {
        while(second!=h2)
        {
          sum=carry+second->data;
          carry=(sum>=10)?1:0;
          sum=sum%10;
          res=insert(res,sum);
          if(second!=h2){second=second->next;}
        }
      }
      if(carry>0)//if any carry is left
      {
        res=insert(res,carry);
      }
      return res;
}
void display(struct node *head)
{
  struct node *temp;
 temp=head;
 temp=temp->next;//to leave header node
  while(temp!=head)//temp->next!=head;WHY?
  {
    printf("%d",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

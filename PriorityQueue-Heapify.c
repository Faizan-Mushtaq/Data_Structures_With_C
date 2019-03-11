#include<stdio.h>
#define size 5

void heapify(int a[],int i)
{
    int n=a[0]/2;//to store size of queue
    int left=2*i;//left child
    int right=left+1;//right child
    int large=i;
    if(left<=a[0]  && a[left]>a[large])
    {large=left;}
    if(right<=a[0] && a[right]>a[large])
    {large=right;}
    if(large!=i)
    {
        int temp=a[i];
        a[i]=a[large];
        a[large]=temp;
        heapify(a,large);
    }
}
void enqueue(int p[],int ele)
{
    p[++p[0]]=ele;
    for(int k=p[0]/2;k>=1;k--)
    {
        heapify(p,k);
    }
}
void dequeue(int p[])
{
    p[1]=p[p[0]--];
    for(int k=p[0]/2;k>=1;k--)
    {
        heapify(p,k);
    }
}
void display(int p[])
{
    if(p[0]==0)
    {
        printf("Q is empty\n");
    }
    else{
    int i;
    for(i=1;i<=p[0];i++)
    {
        printf("%d ",p[i]);
    }
}
}
int main()
{
    int p[size];
    p[0]=0;
    int ch,ele;
    while(1)
    {
        printf("current q is: ");
        display(p);
        printf("\nenter choice\n1enqueue\n2dequeue\n3display\n4exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(p[0]==size)
            {printf("Q is full\n");}
            else
            {
                printf("enter the element: ");
                scanf("%d",&ele);
                enqueue(p,ele);
            }
            break;
            case 2:if(p[0]==0)
            {printf("Q is empty\n");}
            else
            {
                dequeue(p);
            }
            break;
            case 3:display(p);
            break;
            case 4:return 0;
            default : printf("invalid choice\n");
        }
    }
    return 0;
}

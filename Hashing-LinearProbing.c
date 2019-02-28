#include<stdlib.h>
#define SIZE 5
#include<stdio.h>

void insert(int);
void display();
void delete(int);
int htable[SIZE];

int main()
{
    int ch,i,value;
    for(i=0;i<SIZE;i++)
    {
        htable[i]=-1;
    }
    while(1)
    {
        printf("ENTER CHOICE\n1:INSERT\n2:DISPLAY\n3:DELETE\n4:EXIT\n");
        scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("ENTER THE VALUE TO INSERT INTO HASH TABLE\n");
                scanf("%d",&value);
                insert(value);
                break;
        case 2: display();
                break;
        case 3: printf("ENTER A VALUE TO DELETE IN HASH TABLE\n");
                scanf("%d",&value);
                delete(value);
                break;
        case 4: exit(0);
    }
    }
    return 0;
}
void insert(int value)
{
    int index,i,flag=0;
    for(i=0;i<SIZE;i++)
    {
        /*h(x)=f(i) mod TABLE SIZE where f(i)=i */
        index=(value+i)%SIZE;
        if(htable[index]==-1)
        {
            htable[index]=value;
            flag=1;
            break;
        }
    }
    if (flag==0)
    {printf("ELEMENT CAN'T BE INSERTED\n");}
}
void delete(int value)
{
    int index,i,flag=0;
    for(i=0;i<SIZE;i++)
    {
        index=(value+i)%SIZE;
        if(htable[index]==value)
        {
            htable[index]=-1;
            printf("THE VALUE FOUND AT %d\n",index);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {printf("VALUE NOT FOUND\n");}
}
void display()
{
    int i;
    printf("ELEMENTS IN HASH TABLE ARE\n");
    for(i=0;i<SIZE;i++)
    {   
        printf("AT INDEX %d VALUE=%d\n",i,htable[i]);}
}

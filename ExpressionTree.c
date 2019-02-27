#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct exptree{
    char data;
    struct exptree *left,*right;
};
struct exptree *getnode(char);
struct exptree *createexptree(char[]);
int prcd(char);
void preorder(struct exptree *);
void inorder(struct exptree *);
void postorder(struct exptree *);

int  main()
{
    struct exptree *root=NULL;
    char infix[20];
    printf("ENTER THE INFIX EXP\n");
    scanf("%s",infix);
    root=createexptree(infix);
    printf("\nINFIX\n");
    inorder(root);
    printf("\nPOSTFIX\n");
    postorder(root);
    printf("\nPREFIX\n");
    preorder(root);
    return 0;
}
struct exptree *getnode(char item)
{
    struct exptree *newnode;
    newnode=(struct exptree *)malloc(sizeof(struct exptree));
    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int prcd(char x)
{
    switch(x)
    {
        case '^':return 3;break;
        case '/':
        case '*':return 2;break;
        case '+':
        case '-':return 1;break;
    }
    return 0;
}
struct exptree *createexptree(char infix[20])
{
    int i =0;
    char symbol;
    struct exptree *temp,*t1,*t2,*t3;
    struct exptree *operst[10],*treest[10];//operator stack and operand stack
    int top1=-1,top2=-1;
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(isalnum(symbol))
        {
            temp=getnode(symbol);
            treest[++top2] = temp;
        }
        else
        {
            temp=getnode(symbol);
            if(symbol=='(')
            {operst[++top1]=temp;}
            else if(top1 ==-1 || prcd(operst[top1]->data)< prcd(symbol))
            {operst[++top1]=temp;}
             else if(symbol==')')
                {
                    while((operst[top1]->data)!='(' && (top1!= -1) && top2!= -1 && prcd(operst[top1]->data) >= prcd(symbol))
                    {
                        t3=operst[top1--]; //take operator
                        t1=treest[top2--]; //take operand
                        t2=treest[top2--]; //another operand
                        t3->right=t1;
                        t3->left=t2;
                        treest[++top2]=t3; //push tree to stack
                    }
                    if(operst[top1]->data=='(')
                    {top1--;}
                }
                else
                {
                    while((top1!=-1)&&(top2!=-1)&&prcd(operst[top1]->data)>=prcd(symbol))
                    {
                        t3=operst[top1--];
                        t1=treest[top2--];
                        t2=treest[top2--];
                        t3->right=t1;
                        t3->left=t2;
                        treest[++top2]=t3;
                    }
                    operst[++top1]=temp;
                }
         }
     } //end of for
     while(top1 !=-1)
     {
         t1=treest[top2--];
         t2=treest[top2--];
         temp=operst[top1--];
         temp->right=t1;
         temp->left=t2;
         treest[++top2]=temp;
     }
     return treest[top2];
}
void inorder(struct exptree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}
void preorder(struct exptree *root)
{
    if(root!=NULL)
    {
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct exptree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c",root->data);
    }
}

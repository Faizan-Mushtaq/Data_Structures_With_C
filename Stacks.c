#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack {
		int st[SIZE];
		int top;
};
void push(struct stack *, int);
int  pop(struct stack *);
void display(struct stack *);
void tftop(struct stack *);
void tfbotm(struct stack *);
void npop(struct stack *);

int main()
{
	struct stack s;
	s.top=-1;
	int ch,b,x;
	while(1)
	{
	 printf("Enter the choice.\n");
	 printf("1:PUSH\n2:POP\n3:DISPLAY\n4:THIRD FROM TOP\n5:THIRD FROM BOTTOM\n6:POP 'N' ELEMENTS\n7:EXIT\n");
	 scanf("%d",&ch);
	 printf("\n");
	 switch(ch)
	 { case 1: printf("Enter the element to push\n");
	 			scanf("%d",&b);
	 			push(&s,b);
	 		//	printf("PUSHED\n");
	 			break;
	 	case 2: x=pop(&s);
	 	       printf("POPED is %d\n",x);
		 		break;
		case 3: display(&s);
				break;
		case 4: tftop(&s);
				break;
		case 5: tfbotm(&s);
				break;
		case 6: npop(&s);
		        break;

		case 7: exit (0);

	 }
	} return 0;
}
void push(struct stack *s,int b)
{
	if (s->top==SIZE-1)
	{printf("OVERFLOW\n");
	return;
	}else
		{s->top+=1;
		s->st[s->top]=b;    // or ++s->top

	    }
}
int pop(struct stack *s){
	 int a;
	if(s->top==-1){
		printf("UNDERFLOW\n");
		return(-1);
	}else{
		a=s->st[s->top];
		s->top-=1;
	    return a;         // or return (s->st[s->top--]);

	}
}
void display(struct stack *s)
{     if(s->top==-1){
	printf("Stack is empty\n");
}else{
int i;
	for (i=s->top;i>=0;i--)
	printf("%d\n",s->st[i]);
}
}
void tftop(struct stack *s)
{
	int i,y;
	struct stack temp;
	temp.top=-1;
	if (s->top<2){
		printf("No sufficient elements in stack\n");
	}else{

	for (i=0;i<2;i++)
	{
		y=pop(s);
		push(&temp,y);
	}
    y=pop(s);
    printf("The third element from top is %d.\n",y);
    push(s,y);
    for(i=0;i<2;i++){
    	y=pop(&temp);
    	push(s,y);
	}
    }
}
void tfbotm(struct stack *s)
{
	int i,y;
	struct stack temp;
	temp.top=-1;
	if (s->top<2){
		printf("No sufficient elements in stack.\n");

	}else{
		for(i=s->top;i>2;i--)
		{
			y=pop(s);
			push(&temp,y);
		}
		y=pop(s);
		printf("The third element from bottom is %d.\n",y);
		push(s,y);
		for (i=temp.top;i>=0;i--){
			y=pop(&temp);
			push(s,y);
		}
	}
}
void npop(struct stack *s)
{
	int n,i,y;
	printf("Enter the no of elements to be poped.\n");
	scanf("%d",&n);
	if (s->top<n-1){
		printf("Not sufficient elements.\n");
	}else{
		printf("Poped elements are:\n");
		for(i=0;i<=n-1;i++){
			y=pop(s);
			printf("%d\n",y);
		}
	}
}

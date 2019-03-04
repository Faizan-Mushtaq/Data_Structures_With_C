#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 10
struct stack{
	char exp[SIZE];
	int top;
};
void push(struct stack *,char);
char pop(struct stack *);
void intopost(struct stack *,char infixexp[],char postfixexp[]);
int prcd(char ch);

int main()
{
	char infixexp[50],postfixexp[50];
	struct stack s;
	s.top=-1;
	while(1){
	printf("Enter the infix expression.\n");
	scanf("%s",infixexp);
	intopost(&s,infixexp,postfixexp);
	printf("POSTFIX EXPRESSION: ");
	puts(postfixexp);//printf("postfix form is %s \n",postfixexp);
	}return 0;
}
void push(struct stack *s,char ch)
{
	s->top++;
	s->exp[s->top]=ch;
}
char pop(struct stack *s)
{
	char ch;
	ch=s->exp[s->top];
	s->top--;
	return ch;
}
 void intopost(struct stack *s,char infixexp[],char postfixexp[])
 {
 	int i=0,j=0;
 	char ch;
 	while (infixexp[i]!='\0')
 	{
 		if(isalnum(infixexp[i]))
		 {
		 	postfixexp[j++]=infixexp[i];

		 }else
		 {
		 	 if(infixexp[i]=='(')
		 	 {push(s,infixexp[i]);
			  }
			  else if(infixexp[i]==')')
			  {
			  while((ch=pop(s))!='(')
			  {
			     postfixexp[j++]=ch;
			  }
			  }
			  else if (prcd(infixexp[i])>prcd(s->exp[s->top]))
			  {
			  	push(s,infixexp[i]);
			  }else if(prcd(infixexp[i])<=prcd(s->exp[s->top]))
			  {
			  	while(prcd(infixexp[i])<= prcd(s->exp[s->top]))
			  	{
			  		ch=pop(s);
			  		postfixexp[j++]=ch;
				  }
				  push(s,infixexp[i]);
			  }
			 /*else//can skip it because we have witten '<=' in upper else if statement.
			  {
			  	while(prcd(infixexp[i])==prcd(s->exp[s->top]))
			  	{
			  		ch=pop(s);
			  		postfixexp[j++]=ch;
				  }
				  push(s,infixexp[i]);
			  }*/
		 }
        	i++; //update i for ist while loop
	 }
	 while(s->top!=-1)
	 {
	 	ch=pop(s);
	 	postfixexp[j++]=ch;
	 }postfixexp[j]='\0';
 }
 int prcd(char ch)
 {
 	if (ch=='$'){

 	return 3;}
 	else if (ch=='*'||ch=='/')
 	{
	 return 2;}
 	else if (ch=='+'||ch=='-')
 	{
	 return 1;}
 	else{
 		return 0;
	 }
 }

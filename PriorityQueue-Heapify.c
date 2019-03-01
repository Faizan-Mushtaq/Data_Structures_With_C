#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 5

void heapify (int a[],int i){
	int n = (a[0]/2);
	int l = 2*i;
	int r = l+1;
	int large = i;
	if (l <= a[0] && a[l] > a[large])
        large = l;
   if (r <= a[0] && a[r] > a[large])
        large = r;
	if(large != i){
		int temp = a[i];
		a[i] = a[large];
		a[large] = temp;
		heapify(a,large);
	}
}

void enqueue(int p[],int ele){
	p[++p[0]] = ele;
	for(int k=p[0]/2;k>=1;k--)
		heapify(p,k);
}

void dequeue(int p[]){
	p[1] = p[p[0]--];
	for(int k=p[0]/2;k>=1;k--)
		heapify(p,k);
}

void display(int p[]){
	for(int i=1;i<=p[0];i++)
		printf("%d ",p[i]);
}


void priorityq()
{
	int p[size];
	p[0] = 0;
	int ch,ele;
	while(1){

		display(p);
		printf("\n1 to enqueue\n2 to dequeue\n3 to exit\nenter your choice: " );
		scanf("%d",&ch );
		switch(ch){
			case 1:
			if(p[0] == size)
				printf("queue is full");
			else{
				printf("enter the element to be enqueued: " );
				scanf("%d",&ele);
				enqueue(p,ele);
			}
			break;

			case 2:
			if(p[0] == 0)
				printf("queue is empty");
			else
				dequeue(p);
			break;

			case 3:
			return;

			default:
			printf("invalid choice");
		}

	}
}
int main()
{

		priorityq();

	return 0;
}

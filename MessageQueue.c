#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 5

struct queue{
	char msgq[size][100];
	int front;
	int rear;
	};

void sendmsg(struct queue *,char[]);
void recvmsg(struct queue *);
void display (struct queue *);

int main()
{
	struct queue q;
	q.front=-1;
	q.rear=-1;
	char str[100];
	int ch;
while(1)
 {
     printf("MESSAGES CURRENTLY\n");
    display(&q);
    printf("FRONT=%d REAR=%d\n",q.front,q.rear);
    printf("ENTER CHOICE:\n");
	printf("1 SEND MESSAGE \n 2 RECEIVE MESSAGE \n 3 DISPLAY MESSAGES \n 4 EXIT \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: getchar();      //to read enter
				printf("ENTER THE MESSAGE TO SEND:\n");
				gets(str);//Use scanset instead that is better than gets()
				sendmsg(&q,str);    //enqueue
				break;
		case 2:
				recvmsg(&q);
				break;
		case 3:
				display(&q);
				break;
		case 4:  exit (0);

	}
 }
  return 0;
}

void sendmsg(struct queue *q,char str[])
{
	if(q->front==(q->rear+1)%size)
	{
		printf("QUEUE IS FULL\n");
	}
	else{
		q->rear=(q->rear+1)%size;
		strcpy(q->msgq[q->rear],str);
		if(q->front==-1)
		{
			q->front=0;
		}
	}
}

void recvmsg(struct queue *q)
{
	if(q->front== -1 && q->rear==-1)
	{
		printf("QUEUE IS EMPTY\n");

	}
	else{
		printf("RECEIVED MESSAGE IS: %s\n",q->msgq[q->front]);
		if(q->rear==q->front)
		{
			q->rear=-1;
			q->front=-1;

		}
		else{
			q->front=(q->front+1)%size;

		}
	}
}
void display(struct queue *q)
{
    int i;
    if(q->front == -1)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
            if(q->front <= q->rear)
            {
                for(i=q->front; i<= q->rear; i++)
                    printf("%s\n",q->msgq[i]);
            }
            else
            {
                for(i=q->front; i< size; i++)
                    printf("%s\n",q->msgq[i]);

                for(i=0; i<= q->rear; i++)
                    printf("%s\n",q->msgq[i]);
            }
    }

}

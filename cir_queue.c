#include <stdio.h>
#include <stdlib.h>
int front = -1, rear =-1;
int s;
void display(int *items);
void enqueue(int element, int *items);
int dequeue(int *items);
int main()
{
	int o,n;
	printf("Please enter the size of the circular queue\n");
	scanf("%d",&s);
	int items[s];
	while(1)
	{
		printf("Circular Queue Menu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&o);
		switch(o)
		{
		case 1:	printf("Selected enqueue\n");
			printf("Please enter the element to be inserted\t");
			scanf("%d",&n);
			enqueue(n,&items[s]);
			break;
		case 2:	printf("Selected dequeue\n");
			dequeue(&items[s]);
			break;
		case 3: printf("Elements in Queue are:\n ");
			display(&items[s]);
			break;
		case 4:	exit(-1);
		default: printf("Please enter the correct value\n");
		}
	}
return 0;
}
void enqueue(int element,int *items)
{
	if((front == rear + 1) || (front == 0 && rear == s-1)) 
	{
		printf("\n Queue is full!! \n");
	}
	else
	{
		if(front == -1) 
		{
			front = 0;
		}
		rear = (rear + 1) % s;
		items[rear] = element;
		printf("\n Inserted -> %d\n", element);
	}
}
int dequeue(int *items)
{
	int element;
	if(front == -1) 
	{
		printf("\n Queue is empty !! \n");
		return(-1);
	} 
	else 
	{
		element = items[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else 
		{
			front = (front + 1) % s;
		}
	printf("\n Deleted element -> %d \n", element);
	return(element);
	}
}

void display(int *items)
{
	int i;
	if(front == -1) 
	{
		printf(" \n Empty Queue\n");
	}
	else
	{
		printf("\n Front -> %d ",front);
		printf("\n Items -> ");
		for( i = front; i!=rear; i=(i+1)%s) 
		{
			printf("%d ",items[i]);
		}
		printf("%d ",items[i]);
		printf("\n Rear -> %d \n",rear);
	}
}






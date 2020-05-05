#include<stdio.h>
#include<stdlib.h>
void enqueue(int n,int *a);
void dequeue(int n,int *a);
void pr(int n,int *a);
int  n,o,item,i;
int front = -1,rear=-1;
int main()
{
	printf("Please enter size of queue\t");
	scanf("%d",&n);
	int a[n];
	while(1)
	{
		printf("\nMenu for Queue\n1.Enqueue\n2.Dequeue\n3.Print\n4.Exit\n");
		printf("Please enter the option\t");
		scanf("%d",&o);
		switch(o)
		{
		case 1:
				printf("\nSelected Enqueue\n");
				enqueue(n,&a[n]);
				break;
		case 2:
				printf("\nSelected Dequeue\n");
				dequeue(n,&a[n]);
				break;
		case 3:
				pr(n,&a[n]);
				break;

		case 4: 	exit(0);break;
		default: printf("Please enter the correct value\n");break;
		}	
	}
	  return 0;
}
void enqueue(int n,int *a)
{
			if(rear==n-1)
			{
				printf("\nSituation:Queue is Full\n");
	
			}
			else if(front==-1)
			{
				front=0;
				printf("Input element to be inserted\t");
				scanf("%d",&item);
				rear++;
				a[rear]=item;
				printf("Item Inserted\n\n");
			}
			else if(rear<n)
			{
				printf("Input element to be inserted\t");
				scanf("%d",&item);
				rear++;
				a[rear]=item;
				printf("Item Inserted\n\n");
			}
}
void dequeue(int n,int *a)
{
			if(rear==-1)
			{
				printf("\nSituation:Queue Empty\n");
			}
			else if(front==rear)
			{
				printf("%d Deleted\n\n",a[front]);
				front=-1;
				rear=-1;
			}
			else
			{
				printf("%d Deleted\n\n",a[front]);
				front++;
			}
}
void pr(int n,int *a)
{
			if(rear == -1)
			{
				printf("\nEmpty Queue\n");
			}
			printf("\nElements in Queue\n");
			for(i=front;i<=rear;i++)
			{
				printf("%d\n",a[i]);
			}
}



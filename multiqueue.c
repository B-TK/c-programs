#include <stdio.h>
int n=20;
void insert_que1(int *,int *,int *,int *,int);
void insert_que2(int *,int *,int *,int *,int);
void delete_que1(int *,int *,int *);
void delete_que2(int *,int *,int *);
void display_que1(int *,int *,int *);
void display_que2(int *,int *,int *);
int c1=0;
int c2=0;
int main()
{
	printf("Enter the size of the queue \t");
	scanf("%d",&n);
	int que[n];
	int front1,rear1,front2,rear2;
	int value,choice,i;
	front1 = rear1 = -1;
	front2 = rear2 = n;
	for(i=0;i<n;i++)
	que[i]=-1;
	START:
	while(1)
	{
		printf("\n\tMULTIPLE QUEUE:");
		display_que1(que,&front1,&rear1);
		display_que2(que,&front2,&rear2);
		printf("\n 1. Insert to queue1");
		printf("\n 2. Insert to queue2");
		printf("\n 3. Delete to queue1");
		printf("\n 4. Delete to queue2");
		printf("\n 5. Quit");
		printf("\n\tENTER CHOICE HERE :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("Enter the element to be inserted in front\n");
				scanf("%d",&value);
				insert_que1(que,&front1,&rear1,&rear2,value);
				break;
			case 2 : printf("Enter the element to be inserted in end\n");
				scanf("%d",&value);
				insert_que2(que,&front2,&rear1,&rear2,value);
				break;
			case 3 : delete_que1(que,&front1,&rear1);
				break;
			case 4 : delete_que2(que,&front2,&rear2);
				break;
			case 5 :goto EXIT;
			default:printf("Please enter the correct value\n"); goto START;
		}
	}
	EXIT:
	return 0;
	}
void insert_que1(int que[],int *front1,int *rear1,int *rear2,int value)
{
	int i,k;
	if((*rear1)+1 == *rear2)
	{
		printf("Front queue is full.\n");
		return;
	}
	if(*rear1 == -1)
	{
		*rear1=*front1=0;
		que[*rear1]=value;
		return;
	}
	else
	{
		(*rear1)++;
		que[*rear1]=value;
	}
}
void insert_que2(int que[],int *front2,int *rear1,int *rear2,int value)
{
	int i,k;
	if((*rear2)-1 == *rear1)
	{
		printf("\nBackqueue is full.\n");
		return;
	}
	if(*rear2 == n)
	{
		*rear2=*front2=(n-1);
		que[*rear2]=value;
		return;
	}
	else
	{
		(*rear2)--;
		que[*rear2]=value;
	}
}
void delete_que1(int que[],int *front1,int *rear1)
{
	if(*front1 == -1)
	{
		printf("Front queue is empty\n");
		return;
	}
	if(*front1 == *rear1)
	{
		printf("The value deleted from front is %d\n",que[*front1]);
		*front1=-1;
		*rear1=-1;
	}
	else
	{
		printf("The value deleted from front is %d\n",que[*front1]);
		(*front1)++;
	}
}
void delete_que2(int que[],int *front2,int *rear2)
{
	if(*front2 == n)
	{
		printf("Front queue is empty\n");
		return;
	}
	if(*front2 == *rear2)
	{	
		printf("The value deleted from front is %d\n",que[*front2]);
		*front2=n;
		*rear2=n;
	}
	else
	{
		printf("The value deleted from front is %d\n",que[*front2]);
		(*front2)--;
	}
}
void display_que1(int *que,int *front1,int*rear1)
{
	int i;
	printf("\n QUEUE NO 1 :\t");
	if(*front1 == -1 || *rear1 == -1)
		printf("Front queue is empty\n");
	else
	{
		printf("Front->");
		for(i=*front1;i<=*rear1;i++)
		printf(" %d",que[i]);
		printf(" <-Rear");
	}
}
void display_que2(int *que,int *front2,int*rear2)
{
	int i;
	printf("\n QUEUE NO 2 :\t");
	if(*front2 == n || *rear2 == n)
		printf("Backqueue is empty\n");
	else
	{ 
		printf("Front->");
		for(i=*front2;i>=*rear2;i--)
			printf(" %d",que[i]);
			printf(" <-Rear");
	}
}

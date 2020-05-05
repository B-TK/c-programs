#include<stdio.h>
#include<stdlib.h>
void push(int n,int *a);
void pop(int n,int *a);
void pr(int n,int *a);
int  n,o,item,i;
int bottom = -1,top=-1;
int main()
{
printf("Please enter size of stack\t");
scanf("%d",&n);
int a[n];
while(1)
{
	printf("\nMenu for Stack\n1.PUSH\n2.POP\n3.PRINT\n4.EXIT\n");
	printf("Please enter the option\t");
	scanf("%d",&o);
	switch(o)
	{
	case 1:
			printf("\nSelected Push\n");
			push(n,&a[n]);
			break;
	case 2:
			printf("\nSelected POP\n");
			pop(n,&a[n]);
			break;
	case 3:
			pr(n,&a[n]);
			break;
	case 4: exit(0);break;
	default: printf("Please enter the correct value\n");break;
	}	
}
  return 0;
} 
void push(int n,int *a)
{
			if(top==n-1)
			{
				printf("\nSituation:Stack Overflow\n");
	
			}
			else
			{
				printf("Input element to be inserted\t");
				scanf("%d",&item);
				top++;
				a[top]=item;
				printf("Item Inserted\n\n");
			}
}
void pop(int n,int *a)
{
			if(top==bottom)
			{
				printf("\nSituation:Stack Underflow\n");
			}
			else
			{
				printf("%d Deleted\n\n",a[top]);
				top--;
			}
}
void pr(int n,int *a)
{
			if(top == bottom)
			{
				printf("\nEmpty stack\n");
			}
			printf("\nElements in Stack\n");
			for(i=top;i>=0;i--)
			{
				printf("%d\n",a[i]);
			}
}

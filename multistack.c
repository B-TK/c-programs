#include <stdio.h>
#include<stdlib.h>
int SIZE=10;
int ar[10];
int top1 = -1;
int top2 = 10;

void pushstack1 (int data)
{
	if (top1 < top2 - 1)
	{
		ar[++top1] = data;
	}
	else
	{
		printf ("FrontStack Overflow!\n");
	}
}

void pushstack2 (int data)
{
	if (top1 < top2 - 1)
	{
		ar[--top2] = data; 
	}
	else
	{
		printf ("BackStack Overflow\n");
	}
}

void popstack1 ()
{
	if (top1 >= 0)
	{
		int popped_value = ar[top1--];
		printf ("%d is being popped from Stack 1\n", popped_value);
	}
	else
	{
		printf ("Stack1 Underflow!\n");
	}
}

void popstack2 ()
{
	if (top2 < SIZE)
	{
		int popped_value = ar[top2++];
		printf ("%d is being popped from Stack 2\n", popped_value);
	}
	else
	{
		printf ("Stack2 Underflow!\n");
	}
}


void printstack1 ()
{
	int i;
	for (i = top1; i >= 0; --i)
	{
		printf ("%d ", ar[i]);
	}
	printf ("\n");
}

void printstack2 ()
{
	int i;
	for (i = top2; i < SIZE; ++i)
	{
		printf ("%d ", ar[i]);
	}
	printf ("\n");
}


int main()
{
	int ar[SIZE];
	int i,o,m,label;
	int n;
	printf("Please enter the number of elements\t");
	scanf("%d",&SIZE);
	top2=SIZE;
	label:
	while(1)
	{
		printf("Menu\n1.Push1\n2.Push2\n3.Pop1\n4.Pop2\n5.Exit\n");
		scanf("%d",&o);
		if(o==1)
		{
			printf("Please insert the value\n");
			scanf("%d",&m);
			pushstack1 (m);
			printstack1 ();
			goto label;
		}
		else if(o==2)
		{
			printf("Please insert the value\n");
			scanf("%d",&m);
			pushstack2 (m);
			printstack2 ();
			goto label;
		}
		else if(o==3)
		{
			popstack1 ();
			printstack2 ();	
			goto label;
		}
		else if(o==4)
		{
			popstack1 ();
			printstack2 ();
			goto label;
		}
		else if(o==5)
		{
			exit(0);
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*top=NULL,*temp=NULL;
void push(int item);
void pop();
void pr();
int main()
{
	int o,item;
	while(1)
	{
		printf("Menu for Stack\n1.PUSH\n2.POP\n3.PRINT\n4.EXIT\n");
		printf("Please enter the option\t");
		scanf("%d",&o);
		switch(o)
		{
		case 1:
				printf("\nSelected Push\n");
				printf("Please enter the item to be inserted\n");
				scanf("%d",&item);
				push(item);
				break;
		case 2:
				printf("\nSelected POP\n");
				pop();
				break;
		case 3:
				pr();
				break;
		case 4: exit(0);
				break;
		default: printf("Please enter the correct value\n");break;
		}	
	}
	return 0;
}
void push(int item)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	if(top==NULL)
	{
		newnode->link=NULL;
	}
	else
	{
		newnode->link=top;
	}
	top=newnode;
	printf("Insertion Successful\n");
}
void pop()
{
	if(top==NULL)
	{
		printf("\nUnderflow\n");
	}
	else
	{
		temp=top;
		printf("\nDeleted element is %d\n",temp->data);
		top=temp->link;
		free(temp);
	}
}
void pr()
{
	if(top==NULL)
	{
		printf("\nEmpty stack\n");
	}
	else
	{
		temp=top;
		while(temp->link!=NULL)
		{
			printf("%d--->",temp->data);
			temp=temp->link;
		}
		printf("%d--->NULL\n",temp->data);
	}
}


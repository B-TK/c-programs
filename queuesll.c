#include<stdio.h>
#include<stdlib.h>
struct node	
	{
	int data;
	struct node *link;
	};
struct node *header=NULL;
void delete_begin();
void in_end();
void prin();
int main()
{
	int o,p,key;
	while(1)
	{
		printf("\nMenu for the Queue in Linked list\n");
		printf("1.Enqueue\n2.Dequeue\n3.Traversal(Printing)\n4.Exit\n");
		printf("Enter your Option\t");scanf("%d",&o);
		if(o==1)
		{
			printf("\nSelected Enqueue\n");
			in_end();
		}
		if(o==2)
		{
			printf("\nSelected Dequeue\n");
			delete_begin();
		}
		if(o==3)
		{
			prin();
		}
		if(o==4)
		{
			exit(0);	
		}
	}
return 0;
}
void in_end()
{	 
	struct node *newnode,*ptr;
	newnode=(struct node*) malloc(sizeof(struct node));
	printf("Enter the data\t");
	scanf("%d",&newnode->data);
	if(header==NULL)
	{
		newnode->link=NULL;
		header=newnode;
	}
	else
	{
		ptr=header;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		newnode->link=NULL;
		ptr->link=newnode;
	}
}
void delete_begin()
{
	struct node *ptr;
	ptr=header;
	if(ptr==NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		if(header->link==NULL)
		{
			header=NULL;
			free(ptr);
			printf("Deleted at Front\n\n");
		}
		else
		{
		header=ptr->link;
		free(ptr);
		printf("Deleted at Front\n\n");
		}
	}
}
void prin()
{
	struct node *ptr;
	if(header==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		ptr=header;
		printf("%d",ptr->data);
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
			printf("-->%d ",ptr->data);
		}
	}
}	

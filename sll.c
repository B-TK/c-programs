#include<stdio.h>
#include<stdlib.h>
struct node	
	{
	int data;
	struct node *link;
	};
struct node *header=NULL;
void in_begin();
void in_pos();
void in_end();
void delete_begin();
void delete_pos(int key);
void delete_end();
void prin();
void search(int key);
int main()
{
	int o,p,key;
	while(1)
	{
	printf("Menu for the Linked list\n");
	printf("1.Insertion\n2.Deletion\n3.Traversal(Printing)\n4.Searching\n5.Exit\n");
	printf("Enter your Option\t");scanf("%d",&o);
	if(o==1)
	{
		printf("\nMenu for the Insertion\n");
		printf("1.Front\n2.End\n3.Given position\n");
		printf("Enter your Option\t");
		scanf("%d",&p);
		switch(p)
		{
			case 1:printf("Insertion at Front\n\n");
				in_begin();
				break;
			case 2:printf("Insertion at End\n\n");
				in_end();
				break;
			case 3:printf("Insertion at given position\n\n");
				in_pos();
				break;
			default: printf("Please enter correct value\n\n");
		}
	}	
	else if(o==2)
	{
		printf("\nMenu for the Deletion\n");
		printf("1.Front\n2.End\n3.Given position\n");
		printf("Enter your Option\t");
		scanf("%d",&p);
		switch(p)
		{
			case 1:
				delete_begin();
				break;
			case 2:
				delete_end();
				break;
			case 3:
				printf("Please enter the item to delete\t");
				scanf("%d",&key);
				delete_pos(key);
				break;
			default: printf("Please enter correct value\n\n");
		}
	}
	else if(o==3)
	{
		printf("\nTraversal\n");
		prin();
	}
	else if(o==4)
	{
		printf("\nPlease enter the element to be searched\t");
		scanf("%d",&key);
		search(key);
	}
	else if(o==5)
	{
		exit(0);
	}
	else if(o>5||o<=0)
	{
		printf("Please enter correct value\n\n");
	}}
	return 0;
}
void in_begin()
{
	struct node *newnode;
	newnode=(struct node *) malloc(sizeof(struct node));
	printf("Enter the data of new node\t");
	scanf("%d",&newnode->data);
	newnode->link = header;
	header=newnode;
}
void in_end()
{	 
	struct node *newnode,*ptr;
	newnode=(struct node*) malloc(sizeof(struct node));
	printf("Enter the data of new node\t");
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
void in_pos()
{
	int key;
	struct node *newnode,*ptr;
	newnode=(struct node*) malloc(sizeof(struct node));
	if(header==NULL)
	{
		printf("Enter the data of new node\t");
		scanf("%d",&newnode->data);
		newnode->link=NULL;
		header=newnode;
		printf("Element Inserted\n");
	}
	else
	{
		printf("Please enter the Nearest previous item\n");
		scanf("%d",&key);
		ptr=header;
		while((ptr->data!=key)&&(ptr->link==NULL))
		{
			ptr=ptr->link;
		}
		if(ptr->data==key)
		{
			printf("Enter the data of new node\t");
			scanf("%d",&newnode->data);
			newnode->link=ptr->link;
			ptr->link=newnode;
			printf("Element Inserted\n");
		}
		if(ptr->link==NULL)
		{
			printf("No such position to insert\n");
		}
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
void delete_end()
{
	struct node *ptr,*ptr1;
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
			printf("Deleted at End\n\n");
		}
		else
		{
			while(ptr->link!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->link;
			}
			ptr1->link=NULL;
			free(ptr);
			printf("Deleted at End\n\n");
		}
	}
}
void delete_pos(int key)
{
	struct node *ptr,*ptr1;
	ptr=header;
	if(ptr==NULL)
	{
		printf("\nThe list is empty\n");
	}
	else if(header->data==key)
	{
		header=header->link;
	}
	else
	{
		if(header->link==NULL)
		{
			header=NULL;
			printf("Deleted at front\n\n");
		}
		else
		{
			while((ptr->link!=NULL)&&(ptr->data!=key))
			{
				ptr1=ptr;
				ptr=ptr->link;
			}
			if(ptr->data==key)
			{
				ptr1->link=ptr->link;
				free(ptr);
				printf("Element Deleted\n");
			}
			else if(ptr->link==NULL)
			{
				printf("No Element to delete\n");
			}
		}
	}
}
void prin()
{
	struct node *ptr;
	if(header==NULL)
	{
		printf("Printing not possible\n");
	}
	else
	{
		ptr=header;
		printf("%d\n",ptr->data);
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
			printf("%d\n",ptr->data);
		}
	}
}
void search(int key)
{
	struct node *ptr,*ptr1;
	if(header==NULL)
	{
		printf("Empty List\n");
	}
	else if(header->data==key)
		{
			printf("Found at first location\n\n");
		}
	else
	{
		ptr=header;
		while(ptr!=NULL)
		{
			if(ptr->data==key)
			{
				printf("Search Success at location next to %d\n",ptr1->data);
				break;
			}
			else
			{	
				ptr1=ptr;
				ptr=ptr->link;
			}
		}
	    if(ptr==NULL)
		{
			printf("Search Unsuccessfull\n");
		}
	}
}		

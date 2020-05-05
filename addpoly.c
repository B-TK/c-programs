#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int exp;
	struct node *link;
}*header1=NULL,*header2=NULL,*header3=NULL;
void insert_p1();
void insert_p2();
void addition();
void pr1();
void pr2();
void pr3();
void sort1();
void sort2();
int main()
{
	int o,p;
	while(1)
	{
		printf("Menu \n1.First array insertion\n2.Second array insertion\n3.Printing\n4.Polynomial Addition\n5.Exit\n");
		printf("Enter the option\t");
		scanf("%d",&o);
		switch(o)
		{
		case 1:
				printf("\nEnter the elements in 1st\n");
				insert_p1();
				break;
		case 2:
				printf("\nEnter the elements in 2nd\n");
				insert_p2();
				break;
		case 3:
				printf("\nEnter option\n1.First polynomial\n2.Second polynomial\n3.Added polynomial\n");
				scanf("%d",&p);
				if(p==1)
					pr1();
				else if(p==2)
					pr2();
				else if(p==3)
					pr3();	
				break;
		case 4:
				printf("\nPolynomial Addition\n");
				addition();
				break;
		case 5:	exit(0);
				break;
		default: printf("\nPlease enter the correct value\n");
				break;
		}
	}
	return 0;
}
void insert_p1()
{
	struct node *newnode1,*ptr;
	newnode1= (struct node *)malloc(sizeof(struct node));
	printf("Please enter the coeffecient\t");
	scanf("%d",&newnode1->coeff);
	printf("\nPlease enter the exponent\t");
	scanf("%d",&newnode1->exp);
	if(header1==NULL)
	{
		newnode1->link=NULL;
		header1=newnode1;
	}
	else
	{
		ptr=header1;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		newnode1->link=NULL;
		ptr->link=newnode1;
	}
}
void insert_p2()
{
	struct node *newnode2,*ptr;
	newnode2= (struct node *)malloc(sizeof(struct node));
	printf("Please enter the coeffecient\t");
	scanf("%d",&newnode2->coeff);
	printf("\nPlease enter the exponent\t");
	scanf("%d",&newnode2->exp);
	if(header2==NULL)
	{
		newnode2->link=NULL;
		header2=newnode2;
	}
	else
	{
		ptr=header2;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		newnode2->link=NULL;
		ptr->link=newnode2;
	}
}
void pr1()
{
	struct node *ptr;
	if(header1==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		ptr=header1;
		while(ptr->link!=NULL)
		{
			printf("%dX",ptr->coeff);
			printf("^%d   ",ptr->exp);
			ptr=ptr->link;
		}
		printf("%dX",ptr->coeff);
		printf("^%d   \n",ptr->exp);
	}
}
void pr2()
{
	struct node *ptr;
	if(header2==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		ptr=header2;
		while(ptr->link!=NULL)
		{
			printf("%dX",ptr->coeff);
			printf("^%d   ",ptr->exp);
			ptr=ptr->link;
		}
		printf("%dX",ptr->coeff);
		printf("^%d   \n",ptr->exp);
	}
}
void pr3()
{
	struct node *ptr;
	if(header3==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		ptr=header3;
		while(ptr->link!=NULL)
		{
			printf("%dX",ptr->coeff);
			printf("^%d   ",ptr->exp);
			ptr=ptr->link;
		}
		printf("%dX",ptr->coeff);
		printf("^%d   \n",ptr->exp);
	}
}
void addition()
{
	struct node *p1,*p2,*p3,*newnode;
	p1=header1;
	p2=header2;
	p3=header3;
	while(p1!=NULL && p2!=NULL)
	{
			
	               newnode=(struct node*)malloc(sizeof(struct node));
			if(p1->exp<p2->exp)
			{
				newnode->coeff=p1->coeff;
				newnode->exp=p1->exp;
				p1=p1->link;
			}
			else if(p1->exp>p2->exp)
			{
				newnode->coeff=p2->coeff;
				newnode->exp=p2->exp;
				p2=p2->link;
			}
			else if(p1->exp==p2->exp)
			{
				newnode->coeff=p2->coeff+p1->coeff;
				printf("%d",newnode->coeff);
				newnode->exp=p1->exp;
				p1=p1->link;
				p2=p2->link;
			}
			if(header3==NULL)
			{
				newnode->link=NULL;
				header3=newnode;
				p3=newnode;
           			}	
			else
			{
				newnode->link=NULL;
				p3->link=newnode;
				p3=newnode;
			}		
	}
	if(p1!=NULL || p2!=NULL)
	{
                struct node *ptr;
		if(p1!=NULL)
		{
		   ptr=p1;
                }
		else
 		{ 
		ptr=p2;
		}

		while(ptr!=NULL)
		{		
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->coeff=ptr->coeff;
			newnode->exp=ptr->exp;
			ptr=ptr->link;
				
		if(header3==NULL)
		{
			newnode->link=NULL;
			header3=newnode;
			p3=newnode;
		}
		else
		{
			newnode->link=NULL;
			p3->link=newnode;
			p3=newnode;
		}
	     }
       }
}



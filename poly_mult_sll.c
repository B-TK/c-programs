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
void mult();
void pr1();
void pr2();
int main()
{
	int o,p;
	while(1)
	{
		printf("Menu \n1.First array insertion\n2.Second array insertion\n3.Printing\n4.Polynomial Multiplication\n5.Exit\n");
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
				printf("\nEnter option\n1.First array\n2.Second array\n");
				scanf("%d",&p);
				if(p==1)
					pr1();
				else if(p==2)
					pr2();
				break;
		case 4:
				printf("\nPolynomial Multiplication\n");
				mult();
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
void mult()
{
	int c,e;
	struct node *p1,*p2,*newnode,*r,*rp;
	p1=header1;
	p2=header2;
	if((p1==NULL)||(p2==NULL))
	{
		printf("Multiplication not possible\n");
	}
	else
	{
		r=header3;
		while(p1!=NULL)
		{
			while(p2!=NULL)
			{
				c=p1->coeff*p2->coeff;
				e=p1->exp+p2->exp;
				if(header3==NULL)
				{
					newnode= (struct node *)malloc(sizeof(struct node));
					newnode->coeff=c;
					newnode->exp=e;
					newnode->link=NULL;
					header3=newnode;
				}
				else
				{
					r=header3;
					while((r!=NULL)&&(r->exp>e))
					{
						rp=r;
						r=r->link;
					}
					if(r->exp==e)
					{
						r->coeff=r->coeff+e;
					}
					else
					{
						newnode= (struct node *)malloc(sizeof(struct node));
						newnode->coeff=c;
						newnode->exp=e;
						newnode->link=r;
						rp->link=newnode;
					}
				}
				p2=p2->link;
			}
			p1=p1->link;
			p2=header2;
		}
	}
}


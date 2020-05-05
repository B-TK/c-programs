#include<stdio.h>
#include<ctype.h>
int main()
{
	int i,j,n,re,ha,q=0;
	printf("The Hash Function used is [Key mod Hsize]\n");
	printf("Enter the size of hash table\n");
	scanf("%d",&ha);
	n=ha;
	int a[n],h[n];
	printf("Please enter the keys function\n");
	for(i=0;i<n;i++) 
		scanf("%d",&a[i]);
	printf("\nElements :\t");
	for(j=0;j<n;j++)
	{
		printf("%d  ",a[j]);
	}
	for(j=0;j<n;j++)
	{
		h[j]=0;
	}
	printf("Keys :");
	for(j=0;j<n;j++)
	{
		re=a[j]%ha;
		printf("%d ",re);
		if(h[re]==0)
		{
			h[re]=a[j];
		}
		else if(h[re]!=0)
		{
			q=(q+1)%ha;
			while(h[q]!=0)
			{
				q=(q+1)%ha;
			}
			printf(" - collision resolved index %d ",q);
			h[q]=a[j];
		}
	}
	printf("\nThe Hash table is\n");
	for(j=0;j<ha;j++)
	{
		printf("|___%d___|\n",h[j]);
	}
	return 0;
}

//Linear search
#include<stdio.h>
int main()
{
	int i,k,n,flag;
	scanf("%d",&k);
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			flag=1;
			
			break;
		}
		else
		{ flag=0;}
	}
	if(flag==1)
		{printf("%d\n",i);}
	else
		{printf("Not Found\n");}
	return 0;
}
		

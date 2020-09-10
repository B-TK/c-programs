#include<stdio.h>
int main()
{
	int i,j,n,key,l,u,m,temp,loc=-1;
	scanf("%d",&key);
	scanf("%d",&n);
	int a[n];	
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
	for(i=0;i<n-1;i++)
	{
	for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
		}
	}
	l=0;
	u=n-1;
	m=(l+u)/2;
	while(l<=u)
	{
		 if(key==a[m])
		 {
		 	loc=m;
		 }
	   	 if(key<=a[m])
		{
			u=m-1;
		}
		 else
		{
			l=m+1;
		}
		m=(l+u)/2;
	}
	if(loc==-1)
		{
			printf("NOT FOUND\n");
		}
	else
                 printf("%d",loc);
	return 0;
}
			
	
	

//Majority Element
#include<stdio.h>
int main()
{
	int i,j,max=0,count=0,index=0,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{scanf("%d",&a[i]);}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]==a[j])
			{
				count++;
			}
		}
		if(count>max)
			{
				max=count;
				index=i;
			}
		count=0;
	}
	if(max>(n/2))
	{printf("%d\n",a[index]);}
	else
	{printf("Majority element does not exist\n");}
	return 0;
}
	


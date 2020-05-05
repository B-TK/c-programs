#include<stdio.h>
int main()
{
	int i,j,c,n,position,d,swap;
	printf("Please enter the number of elements\t");
	scanf("%d",&n);int a[n];
	printf("Please enter the elements to sort by selection sort\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (c = 0; c < (n - 1); c++)
	{
	    position = c;
	    for (d = c + 1; d < n; d++)
	    {
	      	if (a[position] > a[d])
			position = d;
	    }
	    if(position != c)
	    {
		    swap = a[c];
		    a[c] = a[position];
		    a[position] = swap;
	    }
	}
	printf("The sorted array is :\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
return 0;
}
	
 

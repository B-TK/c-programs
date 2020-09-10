#include<stdlib.h>
#include<stdio.h>
int a[100],b[100],label;
int result(int n);
void sort(int low, int high);
void merging(int low, int mid, int high);
void quicksort(int a[100],int first,int last);
int o,low,high,mid;
int main()
{
	int n,i,p;
	label:
	printf("Enter the number of elements: \t");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		printf("Choose your techinique:\t");
		printf("\n1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Merge sort\n5.Quicksort\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1:
			{
				int i,j,temp;
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
				result(n);
				if(o==1)
				{
					goto label;
				}
				else if(o==0)
				{
					exit(0);
				}
				break;
			}
			case 2:
			{
				int c,position,d,swap;
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
				result(n);
				if(o==1)
				{
					goto label;
				}
				else if(o==0)
				{
					exit(0);
				}
				break;
			}
			case 3:
			{
				int i,j,key;
				for(i=1;i<n;i++)
				{
					key=a[i];
					j=i-1;
				while((j>-1)&&(a[j]>key))
				{
					a[j+1]=a[j];
					j--;
				}
				a[j+1]=key;
				}
				result(n);
				if(o==1)
				{
					goto label;
				}
				else if(o==0)
				{
					exit(0);
				}
				break;
			}
			case 4:
			{
				sort(0, n);
				result(n);
				if(o==1)
				{
					goto label;
				}
				else if(o==0)
				{
					exit(0);
				} 
				break;
			}
			case 5:
			{
				quicksort(a,0,n-1);
				result(n);
				if(o==1)
				{
					goto label;
				}
				else if(o==0)
				{
					exit(0);
				} 
				break;
			}
			default: printf("Please enter correct value\n");
		}
	return 0;
}
void merging(int low, int mid, int high) 
{
	int l1, l2, i;
	for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
	{      
		if(a[l1] <= a[l2])
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	}
	while(l1 <= mid)    
		b[i++] = a[l1++];
	while(l2 <= high)   
		b[i++] = a[l2++];
	for(i = low; i <= high; i++)
		a[i] = b[i];
}
void sort(int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		sort(low, mid);
		sort(mid+1, high);
		merging(low, mid, high);
	} 
	else 
	{ 
		return;
	}   
}
int result(int n)
{
	int i;
	printf("The sorted array is :\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nPress 1 for sorting new elements and 0 to exit\t");
	scanf("%d",&o);
	return o;
}
void quicksort(int a[100],int first,int last)
{
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }
      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);
   }
}

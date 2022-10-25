#include<stdio.h>
int main()
{
	int n,i,a[30],temp,j;
	printf("Enter the size of the array: ");  //Giving the number of elements in the array
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //Entering the elements
	// To sort the array we need to compare the element with next element
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];        //Interchanging the elements
				a[j]=temp;
			}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

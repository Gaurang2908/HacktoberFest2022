#include<stdio.h>
int main()
{
	int a[5] = {11, 12, 13, 14, 15};
	int *p, i, n;
	
	printf("Enter the element number ");
	scanf("%d",&n);
	for(i=0;i<5;i++)
	{
		p = &a[i];
		if(i==n)
		{
			printf("\n%d",a[i]);
		    printf("\n%d",i[a]);
		    printf("\n%d",*(a + i));
		    printf("\n%d",&a[i]);
		    printf("\n%d",*p);
		    printf("\n%d",p);
		}

	}
}

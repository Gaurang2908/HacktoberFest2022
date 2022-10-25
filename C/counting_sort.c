#include<stdio.h>

void print_arr(int srt_array[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",srt_array[i]);
}

void counting(int a[],int n)
{
    //finding the maximum element in the array.
    int max=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }

    int count[max+1];
    //initializing array elements as 0.
    for(int i=0;i<max+1;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        int index=a[i];
        count[index]++;
    }
    
    int temp[max+1];
    for(int i=0;i<max+1;i++)
    {
        if(i==0)
            temp[i]=count[i];
        else
        {
            temp[i]=count[i]+temp[i-1];
        }
    }
    int srt_array[n];
    for(int i=0;i<n;i++)
    {
        int index=a[i];
        int ele_index=temp[index];
        ele_index=ele_index-1;
        srt_array[ele_index]=a[i];
        temp[index]=temp[index]-1;
        count[index]=count[index]-1;
    }
    printf("\nafter sorting the array:\n");
    print_arr(srt_array,n);
}
int main()
{
    int n;
    printf("enter number of elements in the array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nenter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }    
    counting(a,n);
return 0;
}
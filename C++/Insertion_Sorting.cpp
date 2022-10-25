#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number n for an array's element\n";
    cin>>n;
    int arr[n],key,t;
    for (int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
    for (int i = 0; i< n; i++)
    {
        if (arr[i]>arr[i+1])
        {
            t=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=t;
            key=i;
            for (int j = i-1; j >=0; j--)
            {
                if (arr[j]>arr[key])
                {
                    t=arr[j];
                    arr[j]=arr[key];
                    arr[key]=t;
                    key--;
                }
            } 
        }
    }
    cout<<"\nThe final elements in array are:\n";
    for (int i = 0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
#include<iostream>
using namespace std;
int sortedInsertion(int A[] , int n, int element, int index)
{
    
    for(int i=n-1;i>=index;i--)
    {
        A[i+1] = A[i];
    }
    A[index] = element ;
    n++;
}
int main()
{
    int n;
    cout<<"enter the size of an array : ";
    cin>>n;
    cout<<"Enter the elements of an array :";
    cout<<endl;
    int *A = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    int element;
    cout<<"Enter the element you want to insert :";
    cin>>element;
    cout<<endl;
    int index;
    cout<<"Enter the index where you want to insert the new element : ";
    cin>>index;
    cout<<endl;
    cout<<"Updated array is :";
    cout<<endl;
    sortedInsertion(A,n,element,index);
    for(int i=0;i<n+1;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

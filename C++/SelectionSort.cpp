//Program to implement selection sort 
#include<bits/stdc++.h>
using namespace std;

void swap(int *i,int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}

void SelectionSort(int arr[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(arr[j]<arr[k])
            k=j;

        }
        swap(&arr[i],&arr[k]);
    }
}

int main(){
    int arr[]={8,6,3,2,5,4};
    int n=6;
    SelectionSort(arr,n);
    cout<<"Sorted elements are:" << endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

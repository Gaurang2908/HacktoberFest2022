//cpp code to implement difference operation on arrays
#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void display(Array arr){
    int i;
    cout<<"Elements are:"<<endl;
    for(i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}
struct Array* Difference(Array *arr1, Array *arr2){
    int i=0,j=0,k=0;
    struct Array *arr3=(struct Array *)malloc (sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
         
         if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
         }

         else if(arr2->A[j]<arr1->A[i])
           j++;

         else{ 
           i++;  //if elements in both the arrays are equal 
           j++;
        }
    }
    for( ; i<arr1->length;i++){
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}
int main(){
    Array arr1={{2,6,10,15,25},10,5};
    Array arr2={{3,6,7,15,20},10,5};
    Array *arr3;
    arr3 = Difference(&arr1,&arr2);
    display(*arr3);
}

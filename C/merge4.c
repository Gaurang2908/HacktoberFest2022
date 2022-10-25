#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m1, int m, int m2, int r)
{
    int n1 = m1-l+1;
    int n2 = m-m1;
    int n3 = m2-m;
    int n4 = r-m2;
    int P[n1+1], Q[n2+1], R[n3+1], S[n4+1];
   
    //copying elements into the temp arrays P,Q,R and S
    for (int i=0; i<n1;i++)
    {
        P[i] = arr[l+i];
    }

    for (int j=0; j<n2;j++)
    {
        Q[j] = arr[m1+1+j];
    }
    for (int s=0; s<n2;s++)
    {
        R[s] = arr[m+1+s];
    }
    for (int o=0; o<n2;o++)
    {
        S[o] = arr[m2+1+o];
    }
   
    int i,j,k,o,s;
    i = 0;
    j = 0;
    s = 0;
    o = 0;
    k = l;
   
    //now we sort and group the elements
    while((i < n1) && (j < n2) && (s < n3) && (o < n4))  
    {
       
        if(P[i] <= Q[j])
        {
            if(P[i] <= R[s])
            {
                if(P[i] <= S[o])
                {
                    arr[k] = P[i];
                    k++;    
                }
            }
            i++;
        }
       
        if(Q[j] <= P[i])
        {
            if(Q[j] <= R[s])
            {
                if(Q[j] <= S[o])
                {
                    arr[k] = Q[j];
                    k++;
                }
            }
            j++;
        }
       
        if(R[s] <= Q[j])
        {
            if(R[s] <= P[i])
            {
                if(R[s] <= S[o])
                {
                    arr[k] = R[s];
                    k++;
                }
            }
            s++;
        }
       
        if(S[o] <= Q[j])
        {
            if(S[o] <= P[i])
            {
                if(S[o] <= R[s])
                {
                    arr[k] = S[o];
                    k++;
                }
            }
            o++;
        }
    }   
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        int m1 = (l+(m-1))/2;
        int m2 = (m+r)/2;
        mergeSort(arr,l,m1);
        mergeSort(arr,m1+1,m);
        mergeSort(arr,m+1,m2);
        mergeSort(arr,m2+1,r);
        merge(arr,l,m1,m,m2,r);
    }
}

void displayArr(int arr[], int cap)
{
    printf("\n");
    for(int i=0;i<cap;i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {1, 4, 7, 2, 9, 6, 8, 3};
    int cap = sizeof(A)/ sizeof(A[0]);
    printf("\nThe input array is: ");
    displayArr(A, cap);
    mergeSort(A,0,cap-1);
    printf("The sorted array is: ");
    displayArr(A, cap);
    return 0;
}

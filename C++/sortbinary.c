#include <stdio.h>
 
// Function to sort a binary array in linear time
int sort(int A[], int n)
{
    // count number of 0's
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0) {
            zeros++;
        }
    }
 
    // put 0's at the beginning
    int k = 0;
    while (zeros--) {
        A[k++] = 0;
    }
 
    // fill all remaining elements by 1
    while (k < n) {
        A[k++] = 1;
    }
}
 
int main(void)
{
    int A[] = { 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 };
    int n = sizeof(A)/sizeof(A[0]);
 
    sort(A, n);
 
    // print the rearranged array
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
 
    return 0;
}

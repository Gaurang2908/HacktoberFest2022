//Implementation of Radix Sort

#include <iostream>
using namespace std;

// user defined functions
int getMax(int arr[], int size);
void countSort(int arr[], int size, int exp);
void radixsort(int arr[], int size);
void print(int arr[], int size);

// main function
int main()
{
    int n;
    cout << "Enter number of elements for the array : ";
    cin >> n;
    int* arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i + 1) << " : ";
        cin >> arr[i];
    }
    cout << "Array before sorting is : \n";
    print(arr, n);
    cout << "\n****************************************\n";
    // Function Call to perform radix sort
    radixsort(arr, n);
    cout << "Array after sorting is : " << endl;
    print(arr, n);
    return 0;
}

// function to get maximum value in arr[]
int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// function for count sort
void countSort(int arr[], int size, int exp)
{
    int* output = new int[size]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < size; i++)
        arr[i] = output[i];
}

// function to perform Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    //Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << " " << endl;
}

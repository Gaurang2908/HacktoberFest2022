// C++ program to sort an array containing only 0's , 1's and 2's in only one traversal

#include <bits/stdc++.h>
using namespace std;

void sortingArray(int *arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Before sorting : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << '\n';

    sortingArray(arr, n);
    cout << "After sorting : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << '\n';

    delete[] arr;

    return 0;
}

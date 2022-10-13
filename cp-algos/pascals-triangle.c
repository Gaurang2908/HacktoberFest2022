/*
    Coded by - Aditya Raj <-- VirusARzk -->
*/

// C program for Pascal’s Triangle

#include <stdio.h>

void Print_Pascal_Triangle(int n)
{
    // A 2-Dimensional Array to store the values of the Pascal triangle
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        // Since every line has number of integers equal to line number
        for (int j = 0; j <= i; j++)
        {
            // Since every line has 1 as the first and last element
            if (i == j || j == 0)
                arr[i][j] = 1;
            else
                // Other values are sum of values just above and left of above
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter number of rows : ");
    scanf("%d", &n);
    Print_Pascal_Triangle(n);
    return 0;
}
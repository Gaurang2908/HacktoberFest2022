/*
    Coded by - Aditya Raj <-- VirusARzk -->
*/

// C program for Floyd's Triangle

#include <stdio.h>
void main()
{
    int num = 1, n;
    printf("Enter number of rows : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%2d ", num++);
        printf("\n");
    }
}
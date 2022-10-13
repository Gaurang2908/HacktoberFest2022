#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int stack_arr[16];
int top = -1;

// The below function converts decimal number into binary
void decimal_to_binary(ll a)
{
    while (a)
    {
        stack_arr[++top] = a % 2;
        a = a / 2;
    }
}

void Print(int a)
{
    printf("\n%d in Binary- ",a);
    for (int i = top; i >= 0; i--)
        printf("%d", stack_arr[i]);
    // printf("\n");
}

int main()
{
    ll a;
    printf("Enter a number: ");
    scanf("%d",&a);
    decimal_to_binary(a);
    Print(a);
    return 0;
}
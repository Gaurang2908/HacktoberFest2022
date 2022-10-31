//GCD of n num using recursion
int main()
{
    int GCD_of_n_num(int *ar, int n);
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int ar[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    printf("%d", GCD_of_n_num(ar, n));
}
int GCD_of_n_num(int *ar, int n)
{
    if (n == 1)
        return ar[0];
    int t, a = ar[n - 2], b = ar[n - 1];
    while (a != 0)
    {
        t = b % a;
        b = a;
        a = t;
    }
    ar[n - 2] = b;
    return GCD_of_n_num(ar, n - 1);
}
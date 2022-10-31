#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int best = arr[0];
    int maxi = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxi = ((arr[i] > maxi + arr[i]) ? arr[i] : maxi + arr[i]);
        best = ((best > maxi) ? best : maxi);
    }
    printf("%d\n", best);
    return 0;
}

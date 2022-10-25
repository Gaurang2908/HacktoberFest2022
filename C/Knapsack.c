#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
struct knap
{
    float x[20];  // solution vectors
    float profit; // total profit
};

void mergesort(float *A, float *B, float *C, int *D, int *p, int *q, int *r)
{
    int n1, n2, i, j, k;
    n1 = *q - *p + 1;
    n2 = *r - *q;
    float L1[n1 + 2], L2[n1 + 2], L3[n1 + 2], L4[n1 + 2], R1[n2 + 2], R2[n2 + 2], R3[n2 + 2], R4[n2 + 2];
    for (i = 1; i <= n1; i++)
    {
        L1[i] = A[*p + i - 1];
        L2[i] = B[*p + i - 1];
        L3[i] = C[*p + i - 1];
        L4[i] = D[*p + i - 1];
    }
    for (j = 1; j <= n2; j++)
    {
        R1[j] = A[*q + j];
        R2[j] = B[*q + j];
        R3[j] = C[*q + j];
        R4[j] = D[*q + j];
    }
    L1[n1 + 1] = INT_MIN;
    R1[n2 + 1] = INT_MIN;
    i = 1;
    j = 1;
    for (k = *p; k <= *r; k++)
    {
        if (L1[i] >= R1[j]) // changes here < by >
        {
            A[k] = L1[i];
            B[k] = L2[i];
            C[k] = L3[i];
            D[k] = L4[i];
            i = i + 1;
        }
        else
        {
            A[k] = R1[j];
            B[k] = R2[j];
            C[k] = R3[j];
            D[k] = R4[j];
            j = j + 1;
        }
    }
}

void merge_sort(float *v, float *w, float *c, int *a, int *l, int *end)
{
    if (*l < *end)
    {
        int mid, q;
        mid = ((*l + *end) / 2);
        q = mid + 1;
        merge_sort(v, w, c, a, l, &mid);
        merge_sort(v, w, c, a, &q, end);
        mergesort(v, w, c, a, l, &mid, end);
    }
    return;
}

struct knap *knapsack(int n, float *w, float *c, int *a, float W)
{
    struct knap *ptr;
    ptr = (struct knap *)malloc(sizeof(struct knap));
    // ptr1 =(struct knap *)malloc(sizeof(struct knap));
    float v[n], X[n];
    ptr->profit = 0;
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        ptr->x[i] = 0;
        v[i] = c[i] / w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("v=%f\n\n", *(v + i));
    }
    for (int i = 1; i <= n; i++)
    {
        printf("c=%f\n", *(c + i));
    }
    for (int i = 1; i <= n; i++)
    {
        printf("w=%f\n", *(w + i));
    }
    l = 1;
    r = n;
    merge_sort(v, w, c, a, &l, &r);
    for (int i = 1; i <= n; i++)
    {
        printf("\n%f\n", *(v + i));
    }
    for (int i = 1; i <= n; i++)
    {
        printf("c=%f\n\n", *(c + i));
    }
    for (int i = 1; i <= n; i++)
    {
        printf("a=%d\n\n", *(a + i));
    }
    int i = 1;
    while (i <= n && W != 0)
    {
        if (W >= (w[i]))
        {
            ptr->x[i] = 1;
            W = W - (w[i] * ptr->x[i]);
            ptr->profit += (ptr->x[i]) * (*(c + i));
        }
        else
        {
            ptr->x[i] = (W / (w[i]));
            W = W - ((w[i]) * ptr->x[i]);
            ptr->profit += (ptr->x[i]) * (*(c + i));
        }
        i = i + 1;
    }
    printf("The solution vector is\n");
    for (int i = 1; i <= n; i++)
        printf("x[%d] = %f\n", (*(a + i)), ptr->x[i]);
    return ptr;
}

int main()
{
    struct knap *ptr;
    int n, i, a[i]; // n is the number of objects
    printf("Enter the Number of Objects:\n");
    scanf("%d", &n);
    float w[n], c[n], W; // w[i], and c[i] are weights, and cost, W is the knapsack capacity
    for (i = 1; i <= n; i++)
    {
        printf("Enter the Weight of the object O[%d]\n", i);
        printf("w[%d] =", i);
        scanf("%f", (w + i));
    }
    for (i = 1; i <= n; i++)
    {
        printf("Enter the Cost of the object O[% d]\n", i);
        printf("c[%d] =", i);
        scanf("%f", (c + i));
    }
    printf("Weight\t\tCost\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%f\t%f\n", *(w + i), *(c + i));
    }
    for (int i = 1; i <= n; i++)
    {
        *(a + i) = i;
    }
    printf("Enter the capacity of knapsack:\n");
    scanf("%f", &W);
    ptr = knapsack(n, w, c, a, W);
    // printf("Maximum profit is : %f\n",ptr->profit);
    printf("The solution vector is\n");
    for (i = 1; i <= n; i++)
        printf("x[%d] = %f\n", *(a + i), ptr->x[i]);
    printf("Maximum profit is : %f\n", ptr->profit);
    return 0;
}
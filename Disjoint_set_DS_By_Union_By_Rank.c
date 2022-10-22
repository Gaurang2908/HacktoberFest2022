
#include <stdio.h>
#include <stdlib.h>
int parent[100];
int rank[100];

// Creating Disjoint set b using Make-set operation
int makeset(int x)
{
    parent[x] = x;
    rank[x] = 1;
    return x;
}

// For Path compression we make this set
int findset_pathcomp(int y)
{
    while (parent[y] != y)
    {
        parent[y] = findset_pathcomp(parent[y]);   //Path Compression Doing Here
    }
    return y;
}

// For Finding the set we make this function
int findset(int x)
{
    while (parent[x] != x)
    {
        x = parent[x];
    }
    return x;
}

// Taking Union Of Set
int munion(int x, int y)
{
    int r, s;
    r = findset_pathcomp(x);
    s = findset_pathcomp(y);
    if (r == s)
    {
        return r;
    }
    else
    {
        if (rank[r] >= rank[s])
        {
            parent[s] = r;
            if (rank[r] == rank[s])
            {
                rank[r] = rank[r] + 1;
            }
            return r;
        }
        else
        {
            parent[r] = s;
            return s;
        }
    }
}

int main()
{
    int n, i, t = 1, j, flag, count = 0;
    printf("How many disjoint set you want to create ?\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        makeset(i);//calling makeset function
    }
    printf("%d number of makeset operation are executed\n", n);
    while (t != -1)
    {
        printf("\nTo stop Union operation press -1\n");
        printf("\nEnter the value of t\n");
        scanf("%d", &t);
        if (t != -1)
        {
            printf("Enter iand j to to perform unin(i,j) operation\n");
            printf("I = ");
            scanf("%d", &i);
            printf("J = ");
            scanf("%d", &j);
            munion(i, j);
            printf("UNION(%d %d) is finished", i, j);
        }
    }
    printf("Do You want to find the connected components\n");
    printf("Press '1' for 'Yes' or '0' for 'NO:--->  ");
    scanf("%d", &flag);
    if (flag == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d  ", findset(i));
            if (findset(i) == i)
            {
                count = count + 1;
            }
        }
        printf("\nThe No of connected component is %d : ", count);
    }
    else
    {
        printf("We donot want to find the Connected components\n");
    }
    return 0;
}
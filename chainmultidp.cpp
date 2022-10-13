#include <bits\stdc++.h>
using namespace std;
int MCM(int i, int j, int p[200], int s[100][100], int m[100][100])
{
    if (m[i][j] != 0)
    {
        return m[i][j];
    }

    if (i == j)
    {
        return 0;
    }
    s[i][j]++;
    int mini;
    mini = INT_MAX;
    int q;
    int k;
    for (k = i; k < j; k++)
    {
        q = MCM(i, k, p, s, m) + MCM(k + 1, j, p, s, m) + (p[i - 1] * p[k] * p[j]);
        mini = min(q, mini);
        m[i][j] = mini;
    }
    return mini;
}
int main()
{
    int p[100] = {}, s1[100][100] = {}, m1[100][100] = {};
    int n;
    cout << "Number of matrices: ";
    cin >> n;
    cout<<"Enter dimension of sequence of matrices: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    s1[n][n] = {};
    m1[n][n] = {};
    cout << "Minimum number of scalar multiplications " << MCM(1, n, p, s1, m1);
    cout << "\n";

}

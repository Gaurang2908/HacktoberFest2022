#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int l;
        cin >> l;
        cin >> s;
        int c = 0;
        int d = 0;
        for (int j = 0; j < l; j++)
        {
            if (s[j] == '0')
            {
                c++;
            }
        }
        for (int k = 0; k < l - 1; k++)
        {
            if ((s[k] == s[k + 1]) && s[k] == '1')
            {
                d++;
            }
        }
        if (c == l)
            cout << 0 << endl;
        else if (d > 0)
            cout << 2<<endl;
        else
            cout << 1<<endl;
    }

    return 0;
}

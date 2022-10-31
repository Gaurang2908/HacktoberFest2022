#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int answer = 0;

    int temp = num;

    int cnt{};

    while (temp != 0)
    {
        if (temp & 1)
        {
            answer += (num << cnt);
        }
        cnt++;
        temp >>= 1;
    }

    cout << answer << '\n';

    return 0;
}

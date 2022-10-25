#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> catalan(INT16_MAX, 0);

unsigned int get_nth_catalan_number(int num)
{
    static unsigned int index = 2;
    catalan[0] = catalan[1] = 1;

    for (; index <= num; index++)
    {
        for (unsigned int j = 0; j < index; j++)
        {
            catalan[index] += catalan[j] * catalan[index - j - 1];
        }
    }

    return catalan[num];
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << get_nth_catalan_number(i) << " ";
    }

    return 0;
}

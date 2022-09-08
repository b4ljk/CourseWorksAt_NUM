
#include <iostream>

using namespace std;

int max(int a, int b, int c)
{
    int max;
    if (a > b)
    {
        if (a > c)
        {
            max = a;
        }
        else
        {
            max = c;
        }
    }
    else
    {
        if (b > c)
        {
            max = b;
        }
        else
        {
            max = c;
        }
    }
    return max;
}
int main()
{
    cout << max(1, 2, 3) << endl;

    return 0;
}

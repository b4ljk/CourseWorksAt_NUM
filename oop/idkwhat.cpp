
#include <iostream>
#include <math.h>
using namespace std;

void printPrime(int num)
{
    int i, j, isPrime, counts = 0;
    i = 2;
    while (counts < num)
    {
        isPrime = 1;
        for (j = 2; j <= ceil(sqrt(i)); j++)
        {
            if (i % j == 0 && i != j)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1)
        {
            counts++;
            cout << i << endl;
            i++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    printPrime(10);
}

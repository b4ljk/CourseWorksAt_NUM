
#include <iostream>

using namespace std;

double fontOddAVg(int A[], int n)
{
    float oddCount = 0;
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 != 0)
        {
            oddCount += 1;
            total += A[i];
        }
    }
    return total / oddCount;
}

int main()
{
    cout << "husnegtiin hemjeeg oruul\n";
    int sizeArr;
    cin >> sizeArr;
    int A[sizeArr];
    for (int i = 0; i < sizeArr; i++)
    {
        cin >> A[i];
    }
    cout << "odd element dundaj  : " << fontOddAVg(A, sizeof(A) / sizeof(int)) << endl;
    return 0;
}

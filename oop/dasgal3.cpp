
#include <iostream>

using namespace std;

int findEven(int A[], int n)
{
    int evenCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            evenCount++;
        }
    }
    return evenCount;
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
    cout << "tegsh element : " << findEven(A, sizeof(A) / sizeof(int)) << endl;
    return 0;
}

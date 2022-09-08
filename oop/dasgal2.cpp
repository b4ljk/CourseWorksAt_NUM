
#include <iostream>

using namespace std;

int make_set(int A[], int n, int B[])
{
    int i, j, c, k = 0;
    for (i = 0; i < n; i++)
    {
        c = 0;
        for (j = 0; j < k; j++)
        {
            if (A[i] == B[j])
            {
                c = 1;
                break;
            }
        }
        if (c == 0)
        {
            B[k] = A[i];
            k++;
        }
    }
    return k;
}

int main()
{
    cout << "husnegtiin hemjeeg oruul\n";
    int sizeArr;
    cin >> sizeArr;
    int A[sizeArr];
    int B[sizeArr];
    for (int i = 0; i < sizeArr; i++)
    {
        cin >> A[i];
    }
    cout << "Ylgaatai element : " << make_set(A, sizeof(A) / sizeof(int), B) << endl;
    return 0;
}

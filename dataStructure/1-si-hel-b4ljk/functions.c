#include "myinclude.h"

void read(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                scanf("%d", &A[i]);
}

void print(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                printf("%d ", A[i]);
        printf("\n");
}

int max(int A[], int n)
{
        // Энд функцыг хэрэгжүүл
        int max = A[0], i;
        for (i = 0; i < n; i++)
        {
                if (max < A[i])
                {
                        max = A[i];
                }
        }
        return max;
}

int min(int A[], int n)
{
        // Энд функцыг хэрэгжүүл
        int min = A[0], i;
        for (i = 0; i < n; i++)
        {
                if (min > A[i])
                {
                        min = A[i];
                }
        }
        return min;
}

void copy(int A[], int n, int B[])
{
        // Энд функцыг хэрэгжүүл
        int i;
        for (i = 0; i < n; i++)
        {
                B[i] = A[i];
        }
}

int find(int A[], int n, int x)
{
        // Энд функцыг хэрэгжүүл
        int i;
        for (i = 0; i < n; i++)
        {
                if (A[i] == x)
                {
                        return i;
                }
        }
        return -1;
}

int make_set(int A[], int n, int B[])
{
        // Энд функцыг хэрэгжүүл
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

int union_set(int A[], int n, int B[], int m)
{
        // Энд функцыг хэрэгжүүл
        int i, j, c;
        for (i = 0; i < m; i++)
        {
                c = 0;
                for (j = 0; j < n; j++)
                {
                        if (B[i] == A[j])
                        {
                                c = 1;
                                break;
                        }
                }
                if (c == 0)
                {
                        A[n] = B[i];
                        n++;
                }
        }

        return n;
}

int intersection_set(int A[], int n, int B[], int m, int C[])
{
        // Энд функцыг хэрэгжүүл
        int i, j, k = 0, z, c;
        for (i = 0; i < n; i++)
        {
                for (j = 0; j < m; j++)
                {
                        if (A[i] == B[j])
                        {
                                c = 0;
                                for (z = 0; z < k; z++)
                                {
                                        if (A[i] == C[z])
                                        {
                                                c = 1;
                                                break;
                                        }
                                }
                                if (c == 0)
                                {
                                        C[k] = A[i];
                                        k++;
                                        break;
                                }
                        }
                }
        }
        return k;
}

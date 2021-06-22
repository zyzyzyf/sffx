#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;



void InsertSort(int* a, int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        if (a[i - 1] > a[i])
        {
            int t = a[i];
            int j = i;
            while (j > l&& a[j - 1] > t)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = t;
        }
    }
}






int FindMid(int* a, int l, int r)
{
    if (l == r) return l;
    int i =0;
    int n =0;
    for (i = l; i < r - 5; i += 5)
    {
        InsertSort(a, i, i + 4);
        n = i - l;
        swap(a[l + n / 5], a[i + 2]);
    }

    int w = r - i + 1;
    if (w > 0)
    {
        InsertSort(a, i, i + w - 1);
        n = i - l;
        swap(a[l + n / 5], a[i + w / 2]);
    }
    n /= 5;
    if (n == l) return l;
    return FindMid(a, l, l + n);
}


int Partion(int* a, int l, int r, int p)
{
    swap(a[p], a[l]);
    int i = l;
    int j = r;
    int pivot = a[l];
    while (i < j)
    {
        while (a[j] >= pivot && i < j){
            j--;
        }
        a[i] = a[j];
        while (a[i] <= pivot && i < j) {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}

int BFPRT(int* a, int l, int r, int k)
{
    int p = FindMid(a, l, r);    
    int i = Partion(a, l, r, p);

    int m = i - l + 1;
    if (m == k){
        return a[i];
    }
    if (m > k){
        return BFPRT(a, l, i - 1, k);
    }
    return BFPRT(a, i + 1, r, k - m);
}

int main()
{

    int n, k;
    cin >> n;
    int* num = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    cin >> k;
    printf("�� %d С������ : %d\n", k, BFPRT(num, 0, n - 1, k));
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    return 0;
    
}

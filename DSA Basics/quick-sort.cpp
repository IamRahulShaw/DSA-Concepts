#include <bits/stdc++.h>
using namespace std;

int partition(int l, int r, vector<int> &vec)
{
    int mid = (l + r) / 2;
    swap(vec[l], vec[mid]);
    int pivot = l;
    while (l < r)
    {
        while (vec[l] <= vec[pivot])
        {
            ++l;
        }
        while (vec[r] > vec[pivot])
        {
            --r;
        }
        if (l < r)
        {
            swap(vec[l], vec[r]);
        }
    }
    swap(vec[pivot], vec[r]);
    return r;
}

void quick_sort(int l, int r, vector<int> &vec)
{
    if (l >= r)
    {
        return;
    }
    int pivot = partition(l, r, vec);
    quick_sort(l, pivot - 1, vec);
    quick_sort(pivot + 1, r, vec);
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    quick_sort(0, n - 1, vec);
    for (int val : vec)
    {
        cout << val << " ";
    }
    return 0;
}
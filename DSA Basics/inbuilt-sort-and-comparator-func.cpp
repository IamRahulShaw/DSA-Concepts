#include <bits/stdc++.h>
using namespace std;

bool cmp(int &a, int &b)
{
    // if (a > b) // by changing this comparation we change sort order
    //     return true;
    // else
    //     return false;

    return (a < b); // if we want ascending order then a < b otherwise a > b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    // for (int i = 0; i < n - 1; ++i)
    // {
    //     int min = i;
    //     for (int j = i; j < n; ++j)
    //     {
    //         // if (vec[j] < vec[min]) // comparation
    //         if (cmp(vec[j], vec[min]))
    //         {
    //             min = j;
    //         }
    //     }
    //     swap(vec[i], vec[min]);
    // }
    sort(vec.begin(), vec.end(), cmp); // insertion sort, heap sort, quick sort
    for (auto val : vec)
    {
        cout << val << " ";
    }
}
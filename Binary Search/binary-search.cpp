#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int num_find;
    cin >> num_find;
    int high = n - 1, low = 0, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;

        if (vec[mid] <= num_find)
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (vec[high] == num_find)
    {
        cout << " num: " << vec[high] << endl;
    }
    else if (vec[low] == num_find)
    {
        cout << " num: " << vec[low] << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
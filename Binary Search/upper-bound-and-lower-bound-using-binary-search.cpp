#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &v, int elem)
{
    int low = 0, high = v.size() - 1, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (elem >= v[mid])
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (v[low] >= elem)
    {
        return v[low];
    }
    else if (v[high] >= elem)
    {
        return v[high];
    }
    else
    {
        return -1;
    }
}

int upper_bound(vector<int> &v, int elem)
{
    int low = 0, high = v.size() - 1, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (elem >= v[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] > elem)
    {
        return v[low];
    }
    else if (v[high] > elem)
    {
        return v[high];
    }
    else
    {
        return -1;
    }
}

int main()
{ // we need to enter sorted array
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int num;
    cin >> num;
    cout << "lower bound is: " << (lower_bound(vec, num) != -1 ? lower_bound(vec, num) : -1) << endl;
    cout << "upper bound is: " << (upper_bound(vec, num) != -1 ? upper_bound(vec, num) : -1) << endl;
}
// https://www.spoj.com/problems/EKO/
#include <bits/stdc++.h>
using namespace std;
// constrains
//  M = 2*1e9, N = 1e6, H_Max = 1e9

vector<int> trees;

bool require_height(int h, int m)
{
    long long res = 0;
    for (int i = 0; i < trees.size(); ++i)
    {
        if (h < trees[i])
        {
            res = res + (trees[i] - h);
        }
    }
    return res >= m;
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        trees.push_back(val);
    }
    sort(trees.begin(), trees.end());
    int low = 0, high = 1e9, mid; // height can be any integer, that the man can cut to get m amount of wood. so, we check with different heights, that the man can get the m amount of wood or not
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (require_height(mid, m))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (require_height(high, m))
    {
        cout << high << endl;
    }
    else
    {
        cout << low << endl;
    }

    return 0;
}
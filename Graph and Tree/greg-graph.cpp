// https://codeforces.com/problemset/problem/295/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dist[n + 1][n + 1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int wt;
            cin >> wt;
            dist[i][j] = wt;
        }
    }
    vector<int> del_order;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        del_order.push_back(num);
    }
    reverse(del_order.begin(), del_order.end());
    vector<long long> ans;
    for (int k = 0; k < n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][del_order[k]] + dist[del_order[k]][j]);
            }
        }
        long long sum = 0;
        for (int i = 0; i <= k; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                sum = sum + dist[del_order[i]][del_order[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
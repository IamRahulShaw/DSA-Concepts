// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
array<int, N> dp;
int height[N];
int k;

// Recursive Approach -> Top Down
int jump(int n)
{
    if (dp[n] != -1)
        return dp[n];
    if (n <= 1)
    {
        dp[1] = 0;
        return 0;
    }
    int cost = INT_MAX;
    for (int j = 1; j <= k; ++j)
    {
        if (n - j >= 1)
        {
            cost = min(cost, jump(n - j) + abs(height[n] - height[n - j]));
        }
    }
    return dp[n] = cost;
}

int main()
{
    dp.fill(-1);
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        height[i] = num;
    }
    // cout << jump(n) << endl;

    // Iterative Approach -> Bottom Up
    dp[1] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (i + j <= n)
            {
                if (dp[i + j] == -1)
                    dp[i + j] = dp[i] + abs(height[i + j] - height[i]);
                else
                    dp[i + j] = min(dp[i + j], dp[i] + abs(height[i + j] - height[i]));
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}
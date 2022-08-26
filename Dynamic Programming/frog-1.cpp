// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
array<int, N> dp;
int height[N];

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
    int cost = jump(n - 1) + abs(height[n] - height[n - 1]);
    if (n >= 3)
    {
        cost = min(cost, jump(n - 2) + abs(height[n] - height[n - 2]));
    }
    return dp[n] = cost;
}

int main()
{
    dp.fill(-1);
    int n;
    cin >> n;
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
        if (dp[i + 1] == -1)
            dp[i + 1] = dp[i] + abs(height[i + 1] - height[i]);
        else
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(height[i + 1] - height[i]));

        if (i + 2 <= n)
        {
            if (dp[i + 2] == -1)
                dp[i + 2] = dp[i] + abs(height[i + 2] - height[i]);
            else
                dp[i + 2] = min(dp[i + 2], dp[i] + abs(height[i + 2] - height[i]));
        }
    }
    cout << dp[n] << endl;

    return 0;
}
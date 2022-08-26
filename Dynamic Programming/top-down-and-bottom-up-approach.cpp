#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
array<int, N> dp;

// Top Down Approach
int fib(int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n == 0)
    {
        dp[n] = 0;
        return 0;
    }
    if (n == 1)
    {
        dp[n] = 1;
        return 1;
    }

    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    dp.fill(-1);
    int n;
    cin >> n;
    // cout << fib(n) << endl;

    // Bottom Up Approach
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

    for (int i = 0; i <= n; ++i)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}
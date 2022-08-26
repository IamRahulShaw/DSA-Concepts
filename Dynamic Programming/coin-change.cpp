// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

int dp[22][10010];

int coin_change(int index, int amount, vector<int> &coins)
{
    if (dp[index][amount] != -1)
    {
        return dp[index][amount];
    }
    if (amount == 0)
    {
        dp[index][amount] = 0;
        return 0;
    }
    if (index >= coins.size())
    {
        return INT_MAX;
    }
    int ans = INT_MAX;
    int count = 0;
    for (int val = 0; val <= amount; val = val + coins[index])
    {
        ans = min(ans + 0LL, (coin_change(index + 1, amount - val, coins) + 0LL + count));
        ++count;
    }
    return dp[index][amount] = ans;
}

int coinChange(vector<int> &coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    int ans = coin_change(0, amount, coins);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 11) << endl;
    return 0;
}
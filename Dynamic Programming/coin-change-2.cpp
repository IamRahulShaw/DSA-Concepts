// https://leetcode.com/problems/coin-change-2/

#include <bits/stdc++.h>
using namespace std;

int dp[310][5010];

int coin_change(int index, int amount, vector<int> &coins)
{
    if (dp[index][amount] != -1)
        return dp[index][amount];
    if (amount == 0)
    {
        dp[index][amount] = 1;
        return 1;
    }
    if (index >= coins.size()) // Here we write this line after base condition because, in the case of 5, the index+1 means 4 is called for amount 0, so this line gives value 0, but the same time base condition hits. So, we need the value of base condition. So, we write the line after the base condition.
        return 0;
    int ways = 0;
    for (int val = 0; val <= amount; val = val + coins[index])
    {
        ways = ways + coin_change(index + 1, amount - val, coins);
    }
    return dp[index][amount] = ways;
}

int change(int amount, vector<int> &coins)
{
    memset(dp, -1, sizeof(dp));
    return coin_change(0, amount, coins);
}

int main()
{
    vector<int> coins = {10};
    cout << change(10, coins) << endl;
    return 0;
}
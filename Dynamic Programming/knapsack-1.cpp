// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

int weights[110];
int values[110];
long long dp[110][100010];

long long knapsack(int index, int weight)
{
    if (index < 0)
    {
        return 0;
    }
    if (dp[index][weight] != -1)
    {
        return dp[index][weight];
    }
    if (weight == 0)
    {
        dp[index][weight] = 0;
        return 0;
    }

    // Not take that index
    long long val = knapsack(index - 1, weight);

    // Take that index
    if (weight - weights[index] >= 0)
    {
        val = max(val, knapsack(index - 1, weight - weights[index]) + 0LL + values[index]);
    }
    return dp[index][weight] = val;
}

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; ++i)
    {
        int weight, value;
        cin >> weight >> value;
        weights[i] = weight;
        values[i] = value;
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(n - 1, w) << endl;
    return 0;
}
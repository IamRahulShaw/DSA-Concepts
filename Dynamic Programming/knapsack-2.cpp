// https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;

int weights[110];
int values[110];
long long dp[110][100010];

long long knapsack(int index, int value)
{
    if (value == 0) // if index is -1 and at the same time the value is zero, then we will return 0
    {
        return 0;
    }
    if (index < 0) // index is -1 but the value is not zero, then we will return a big value
    {
        return 1e16;
    }
    if (dp[index][value] != -1)
    {
        return dp[index][value];
    }

    // not choose the index
    long long wt = knapsack(index - 1, value);

    // choose the index
    if (value - values[index] >= 0)
    {
        wt = min(wt, knapsack(index - 1, value - values[index]) + 0LL + weights[index]);
    }

    return dp[index][value] = wt;
}

int main()
{
    int n, w, sumVal = 0;
    cin >> n >> w;
    for (int i = 0; i < n; ++i)
    {
        int weight, value;
        cin >> weight >> value;
        weights[i] = weight;
        values[i] = value;
        sumVal = sumVal + value;
    }
    memset(dp, -1, sizeof(dp));
    for (int i = sumVal; i >= 0; --i)
    {
        long long wt = knapsack(n - 1, i);
        if (wt <= w)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
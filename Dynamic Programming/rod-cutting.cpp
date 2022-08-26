#include <bits/stdc++.h>
using namespace std;

int dp[1010];

int cut_rod(int length, vector<int> &prices)
{
    if (dp[length] != -1)
    {
        return dp[length];
    }
    if (length == 0)
    {
        dp[length] = 0;
        return 0;
    }
    int tot_price = 0;
    for (int i = 1; i <= prices.size(); ++i)
    {
        if (length - i >= 0)
        {
            tot_price = max(tot_price, cut_rod(length - i, prices) + prices[i - 1]);
        }
    }
    return dp[length] = tot_price;
}

int cutRod(int price[], int n)
{
    // code here
    memset(dp, -1, sizeof(dp));
    vector<int> prices(price, price + n); // copy all array values in the vector
    return cut_rod(n, prices);
}

int main()
{
    int prices[] = {1, 1, 3, 4, 4, 6, 8, 9, 11};
    cout << cutRod(prices, 9) << endl;
    return 0;
}
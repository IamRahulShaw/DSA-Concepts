// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10;
array<int, N> dp;

int lis(int index, vector<int> &nums)
{
    if (dp[index] != 0)
        return dp[index];
    int ans = 1;
    for (int i = index - 1; i >= 0; --i)
    {
        if (nums[i] < nums[index])
        {
            ans = max(ans, lis(i, nums) + 1);
        }
    }
    return dp[index] = ans;
}

int lengthOfLIS(vector<int> &nums)
{
    dp.fill(0);
    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        ans = max(ans, lis(i, nums));
    }
    return ans;
}

int main()
{
    vector<int> vec = {7, 7, 7, 7, 7, 7, 7};
    cout << lengthOfLIS(vec) << endl;

    return 0;
}
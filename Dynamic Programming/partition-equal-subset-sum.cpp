#include <bits/stdc++.h>
using namespace std;

int dp[210][20010];

bool can_partition(int index, int sum, vector<int> &nums)
{
    if (sum == 0)
    {
        return true;
    }
    if (index < 0)
    {
        return false;
    }
    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }

    // not choose the index
    bool ans = can_partition(index - 1, sum, nums);

    // choose the index
    if (sum - nums[index] >= 0)
    {
        ans = ans || can_partition(index - 1, sum - nums[index], nums);
    }

    return dp[index][sum] = ans;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    sum /= 2; // We know that if we have a sum, then we can easily find that the sum of the subset of the array can produce the desired sum or not. So, we convert this problem into that problem. If the array can be divided into two parts which sum are equal then the sum/2 is the actual sum that we need to find in the subset and the other part which produce the sum obviously present in the array
    memset(dp, -1, sizeof(dp));
    return can_partition(nums.size() - 1, sum, nums);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums) << endl;
    return 0;
}
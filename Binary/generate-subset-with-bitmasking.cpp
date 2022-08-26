// https://leetcode.com/problems/subsets/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int> &nums)
    {

        int size = nums.size();
        int subset_count = (1 << size);
        for (int i = 0; i < subset_count; ++i)
        {
            vector<int> subset;
            for (int j = 0; j < size; ++j)
            {
                if ((i & (1 << j)) != 0)
                {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};
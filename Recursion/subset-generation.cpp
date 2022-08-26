// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;
    void generate_subset(vector<int> &subset, vector<int> &nums, int count)
    {
        if (count >= nums.size())
        {
            result.push_back(subset);
            return;
        }

        // include nums[count]
        subset.push_back(nums[count]);
        generate_subset(subset, nums, count + 1);
        subset.pop_back();

        // exclude nums[count]
        generate_subset(subset, nums, count + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int count = 0;
        vector<int> subset;
        generate_subset(subset, nums, count);
        return result;
    }
};
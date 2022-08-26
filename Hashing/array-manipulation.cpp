// https://www.hackerrank.com/challenges/crush/problem

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
long long prefix_sum[N];

long arrayManipulation(int n, vector<vector<int>> queries)
{
    for (auto query : queries)
    {
        int l = query[0];
        int r = query[1];
        int val = query[2];
        prefix_sum[l] += val;
        prefix_sum[r + 1] -= val;
    }
    long long ans = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        prefix_sum[i] = prefix_sum[i] + prefix_sum[i - 1];
        ans = max(ans, prefix_sum[i]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> queries = {{1, 5, 3}, {4, 8, 7}, {6, 9, 1}};
    cout << arrayManipulation(10, queries);
    return 0;
}
// https://www.interviewbit.com/problems/delete-edge/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e9 + 7;
vector<int> graph[N];
int subtree_sum[N];

void dfs(int vertex, int parent = 0, vector<int> &value_array)
{
    subtree_sum[vertex] = value_array[vertex - 1];
    for (auto child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex, value_array);
        subtree_sum[vertex] = subtree_sum[vertex] + subtree_sum[child];
    }
}

int deleteEdge(vector<int> &A, vector<vector<int>> &B)
{
    for (int i = 0; i < B.size(); ++i)
    {
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    dfs(1, 0, A);
    long long max_product = -1;
    for (int i = 2; i <= B.size() + 1; i++)
    {
        int part_1 = subtree_sum[i];
        int part_2 = subtree_sum[1] - subtree_sum[i];
        long long product = (part_1 * 1LL * part_2);
        max_product = max(max_product, product);
    }
    return max_product % M;
}

int main()
{

    return 0;
}
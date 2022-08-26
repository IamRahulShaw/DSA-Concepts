#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
int depth[N];
int height[N];

void dfs(int vertex, int parent = 0)
{
    for (auto child : graph[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    int max_depth = -1;
    int max_node = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (depth[i] > max_depth)
        {
            max_depth = depth[i];
            max_node = i;
        }
        depth[i] = 0;
        height[i] = 0;
    }
    dfs(max_node);
    cout << "diameter is: " << height[max_node] << endl;
    return 0;
}
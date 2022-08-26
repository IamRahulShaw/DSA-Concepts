#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
int subtree_sum[N];
int even_count[N];

void dfs(int vertex, int parent = 0)
{
    subtree_sum[vertex] = vertex;
    if (vertex % 2 == 0)
    {
        even_count[vertex]++;
    }
    for (auto child : graph[vertex])
    {
        if (child == parent)
        {
            continue;
        }
        dfs(child, vertex);
        subtree_sum[vertex] = subtree_sum[vertex] + subtree_sum[child];
        even_count[vertex] = even_count[vertex] + even_count[child];
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
    for (int i = 1; i <= n; ++i)
    {
        cout << i << "-> subtree sum: " << subtree_sum[i] << " and even count: " << even_count[i] << endl;
    }

    return 0;
}
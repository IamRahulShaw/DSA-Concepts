#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited_array[N];

bool dfs(int vertex, int parent)
{
    bool is_loop_exist = false;
    visited_array[vertex] = true;
    for (auto child : graph[vertex])
    {
        if (visited_array[child] && child != parent)
        {
            return true;
        }
        if (visited_array[child])
        {
            continue;
        }
        is_loop_exist = is_loop_exist || dfs(child, vertex);
    }
    return is_loop_exist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bool is_loop_exist = false;
    for (int i = 1; i <= n; ++i)
    {
        if (visited_array[i])
        {
            continue;
        }
        if (dfs(i, 0))
        {
            is_loop_exist = true;
            break;
        }
    }
    cout << is_loop_exist << endl;
    return 0;
}
// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited_array[N];
vector<vector<int>> connected_components_vector;
vector<int> connected_components;

void dfs(int vertex)
{
    visited_array[vertex] = true;
    connected_components.push_back(vertex);
    for (auto child : graph[vertex])
    {
        if (visited_array[child])
        {
            continue;
        }
        dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (visited_array[i])
        {
            continue;
        }
        connected_components.clear();
        dfs(i);
        connected_components_vector.push_back(connected_components);
        count++;
    }
    cout << count << endl;
    for (auto vec : connected_components_vector)
    {
        for (auto val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
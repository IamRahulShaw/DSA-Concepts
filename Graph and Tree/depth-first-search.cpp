#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited_array[N];

void dfs(int vertex)
{
    // take action on the vertex after entering the vertex
    // if(visited_array[vertex]){
    //     return;
    // }
    visited_array[vertex] = true;
    for (auto child : graph[vertex])
    {
        if (visited_array[child])
        {
            continue;
        }
        // take action on the child before entering the child node
        dfs(child);
        // take action on the child after exiting the child node
    }
    // take action on the vertex before exiting the vertex
} // Time complexity -> O(Vertex + Order of Edges)

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
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int group_size[N];

void make(int n)
{
    parent[n] = n;
    group_size[n] = 1;
}

int find(int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (group_size[a] < group_size[b])
            swap(a, b);
        parent[b] = a;
        group_size[a] = group_size[a] + group_size[b];
        group_size[b] = group_size[a];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        make(i);
    }
    vector<pair<int, pair<int, int>>> graph;
    vector<pair<int, pair<int, int>>> min_span_tree;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph.push_back({wt, {v1, v2}});
    }
    sort(graph.begin(), graph.end());
    int sum = 0;
    for (auto p : graph)
    {
        int wt = p.first;
        int v1 = p.second.first;
        int v2 = p.second.second;
        if (find(v1) == find(v2))
            continue;
        Union(v1, v2);
        min_span_tree.push_back({wt, {v1, v2}});
        sum += wt;
    }
    cout << "Total weight -> " << sum << endl;
    for (auto p : min_span_tree)
    {
        cout << p.second.first << " " << p.second.second << " " << p.first << endl;
    }
    return 0;
}
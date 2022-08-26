// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        make(i);
    }
    for (int i = 0; i < k; ++i)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int dist_ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (find(i) == i)
            dist_ct++;
    }
    cout << dist_ct << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int size[N];

void make(int num)
{
    parent[num] = num; // means a single set, where the parent of the number is itself
    size[num] = 1;     // because in the group, only 1 node is present
}

int find(int node)
{
    if (parent[node] == node)
        return node;
    parent[node] = find(parent[node]); // Here we make node's parent to node's parent's parent and eventually compress the path
    return parent[node];
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b); // Here we make variable a points to bigger group
        parent[b] = a;
        size[a] = size[a] + size[b];
        size[b] = size[a];
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

    int connected_ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (find(i) == i)
            connected_ct++;
    }
    cout << connected_ct << endl;
    return 0;
}
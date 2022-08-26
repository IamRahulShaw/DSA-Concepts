// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int group_size[N];
multiset<int> group_sizes;

void make(int n)
{
    parent[n] = n;
    group_size[n] = 1;
    group_sizes.insert(1);
}

int find(int node)
{
    if (parent[node] == node)
        return node;

    parent[node] = find(parent[node]);
    return parent[node];
}

void merge_group(int a, int b)
{
    if (a != b)
    {
        group_sizes.erase(group_sizes.find(group_size[a]));
        group_sizes.erase(group_sizes.find(group_size[b]));
        group_sizes.insert(group_size[a] + group_size[b]);
    }
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
        merge_group(a, b);
        group_size[a] = group_size[a] + group_size[b];
        group_size[b] = group_size[a];
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        make(i);
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
        if (group_sizes.size() == 1)
            cout << 0 << endl;
        else
        {
            int max = *(--group_sizes.end());
            int min = *(group_sizes.begin());
            cout << max - min << endl;
        }
    }

    return 0;
}
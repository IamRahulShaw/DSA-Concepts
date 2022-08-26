// https://codeforces.com/contest/1245/problem/D

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
    int n;
    cin >> n;
    vector<pair<int, int>> position(n + 1);
    vector<int> power_station(n + 1, 0);
    vector<int> wire_cost(n + 1);
    vector<pair<long long, pair<int, int>>> graph;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        position[i] = {x, y};
    }
    for (int i = 1; i <= n; ++i)
    {
        int c;
        cin >> c;
        power_station[i] = c;
    }
    for (int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        wire_cost[i] = k;
    }
    for (int i = 1; i <= n; ++i)
    {
        graph.push_back({power_station[i], {0, i}});
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int dist = abs(position[i].first - position[j].first) + abs(position[i].second - position[j].second);
            long long cost = dist * 1LL * (wire_cost[i] + wire_cost[j]);
            graph.push_back({cost, {i, j}});
        }
    }

    sort(graph.begin(), graph.end());
    for (int i = 1; i <= n; ++i)
    {
        make(i);
    }

    vector<pair<long long, int>> ultimate_power_station;
    vector<pair<long long, pair<int, int>>> ultimate_wire_cost;
    long long tot_cost = 0;
    for (auto p : graph)
    {
        int wt = p.first;
        int v1 = p.second.first;
        int v2 = p.second.second;
        if (find(v1) == find(v2))
        {
            continue;
        }
        Union(v1, v2);
        if (v1 == 0)
            ultimate_power_station.push_back({wt, v2});
        else
            ultimate_wire_cost.push_back({wt, {v1, v2}});
        tot_cost += wt;
    }
    cout << tot_cost << endl;
    cout << ultimate_power_station.size() << endl;
    for (auto p : ultimate_power_station)
    {
        cout << p.second << " ";
    }
    cout << endl;
    cout << ultimate_wire_cost.size() << endl;
    for (auto p : ultimate_wire_cost)
    {
        cout << p.second.first << " " << p.second.second << endl;
    }

    return 0;
}
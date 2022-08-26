// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

int dijkstra(vector<vector<int>> &times, int source, int n)
{
    vector<pair<int, int>> graph[n + 1];
    for (auto vec : times)
    {
        graph[vec[0]].push_back({vec[1], vec[2]});
    }
    int dist[n + 1];
    bool vis[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        dist[i] = INF;
        vis[i] = false;
    }
    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;
    while (!st.empty())
    {
        int st_begin = st.begin()->second;
        vis[st_begin] = true;
        st.erase(st.begin());
        for (auto p : graph[st_begin])
        {
            int child = p.first;
            int wt = p.second;
            if (vis[child])
                continue;
            if (dist[child] > dist[st_begin] + wt)
            {
                dist[child] = dist[st_begin] + wt;
                st.insert({dist[child], child});
            }
        }
    }
    int max_dist = -1;
    for (int i = 1; i <= n; ++i)
    {
        max_dist = max(max_dist, dist[i]);
    }
    return (max_dist == INF) ? -1 : max_dist;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    return dijkstra(times, k, n);
}

int main()
{
    vector<vector<int>> vec = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    int n = 3, k = 1;
    cout << networkDelayTime(vec, n, k) << endl;
    return 0;
}
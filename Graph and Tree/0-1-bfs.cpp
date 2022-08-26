// https://www.codechef.com/problems/REVERSE?tab=statement
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> graph[N];
vector<int> level(N, INF);

void bfs(int source)
{
    deque<int> q;
    q.push_back(source);
    level[source] = 0;
    while (!q.empty())
    {
        int q_front = q.front();
        q.pop_front();
        for (auto pair : graph[q_front])
        {
            int child = pair.first;
            int wt = pair.second;
            if (child == q_front)
                continue;
            if (level[q_front] + wt < level[child])
            {
                level[child] = level[q_front] + wt;
                if (wt == 0)
                {
                    q.push_front(child);
                }
                else
                {
                    q.push_back(child);
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back({v2, 0});
        graph[v2].push_back({v1, 1});
    }
    bfs(1);
    int ans = level[n] == INF ? -1 : level[n];
    cout << ans << endl;
    return 0;
}
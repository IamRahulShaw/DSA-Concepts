// https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int n, m;
int graph[N][N];
int level[N][N];
bool vis[N][N];

void reset()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            vis[i][j] = false;
            level[i][j] = INF;
        }
    }
}

vector<pair<int, int>> directions = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int bfs()
{
    int max_elem = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            max_elem = max(max_elem, graph[i][j]);
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (graph[i][j] == max_elem)
            {
                q.push({i, j});
                level[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }

    int max_level = 0;
    while (!q.empty())
    {
        pair<int, int> q_front = q.front();
        q.pop();
        for (auto p : directions)
        {
            pair<int, int> child;
            child.first = q_front.first + p.first;
            child.second = q_front.second + p.second;
            if (child.first < 0 || child.first >= m || child.second < 0 || child.second >= n)
                continue;
            if (vis[child.first][child.second])
                continue;
            q.push(child);
            level[child.first][child.second] = level[q_front.first][q_front.second] + 1;
            max_level = max(max_level, level[child.first][child.second]);
            vis[child.first][child.second] = true;
        }
    }
    return max_level;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int num;
                cin >> num;
                graph[i][j] = num;
            }
        }

        cout << bfs() << endl;
    }
    return 0;
}
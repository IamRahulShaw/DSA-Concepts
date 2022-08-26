#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited_array[N];
int level[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited_array[source] = true;
    while (!q.empty())
    {
        int front_elem = q.front();
        cout << front_elem << " ";
        q.pop();
        for (auto child : graph[front_elem])
        {
            if (visited_array[child] != true)
            {
                q.push(child);
                visited_array[child] = true;
                level[child] = level[front_elem] + 1;
            }
        }
    }
    cout << endl;
} // Time complexity -> O(Node + Edge)

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ": level-> " << level[i] << endl;
    }

    return 0;
}
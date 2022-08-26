#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
int par[N];

void dfs(int vertex, int parent = -1)
{
    par[vertex] = parent;
    for (auto child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
}

vector<int> path(int node)
{
    vector<int> answer;
    while (node != -1)
    {
        answer.push_back(node);
        node = par[node];
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> path_n1 = path(n1);
    vector<int> path_n2 = path(n2);

    int loop_size = min(path_n1.size(), path_n2.size());
    int lca = -1;
    for (int i = 0; i < loop_size; ++i)
    {
        if (path_n1[i] == path_n2[i])
        {
            lca = path_n1[i];
        }
        else
        {
            break;
        }
    }
    cout << "lca of " << n1 << " and " << n2 << " is: " << lca << endl;
    return 0;
}
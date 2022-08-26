// https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;

bool visited_array[8][8];
int level[8][8];
vector<pair<int, int>> steps = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

pair<int, int> pos_to_pair(string s)
{
    pair<int, int> p;
    p = {s[0] - 'a', s[1] - '1'};
    return p;
}

void reset()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            visited_array[i][j] = false;
            level[i][j] = 0;
        }
    }
}

void bfs(pair<int, int> source_pair, pair<int, int> dest_pair)
{
    queue<pair<int, int>> q;
    q.push(source_pair);
    visited_array[source_pair.first][source_pair.second] = true;
    level[source_pair.first][source_pair.second] = 0;
    while (q.empty() != true)
    {
        pair<int, int> q_front = q.front();
        if (visited_array[dest_pair.first][dest_pair.second])
        {
            break;
        }
        q.pop();
        for (auto step : steps)
        {
            if (q_front.first + step.first < 0 || q_front.first + step.first > 7)
                continue;
            if (q_front.second + step.second < 0 || q_front.second + step.second > 7)
                continue;
            if (visited_array[q_front.first + step.first][q_front.second + step.second] != true)
            {
                q.push({q_front.first + step.first, q_front.second + step.second});
                visited_array[q_front.first + step.first][q_front.second + step.second] = 1;
                level[q_front.first + step.first][q_front.second + step.second] = level[q_front.first][q_front.second] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        string source, dest;
        cin >> source >> dest;
        pair<int, int> source_pair, dest_pair;
        source_pair = pos_to_pair(source);
        dest_pair = pos_to_pair(dest);
        bfs(source_pair, dest_pair);
        cout << level[dest_pair.first][dest_pair.second] << endl;
    }
    return 0;
}
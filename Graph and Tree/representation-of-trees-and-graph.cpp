#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int matrix[N][N]; // But here we can't make the N > 1e4, because here the space complexity is n^2, for N=1e4, the space become 1e8. and we can only make order 1e7 size array globaly. so, adjacent matrix method is not good for storing large number of vertices.

// vector<int> list[N];
// vector<pair<int, int> > list[N]; // for weighted edges

int main()
{
    int n, m;
    cin >> n >> m;
    // int matrix[4][4] = {0}; // 0 based matrix
    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        // int v1, v2, wt; // if weight is given then
        cin >> v1 >> v2;
        matrix[v1][v2] = 1; // then we store weight matrix[v1][v2]=wt
        matrix[v2][v1] = 1;

        // list[v1].push_back(v2);
        // list[v2].push_back(v1);

        // list[v1].push_back({v2, wt}); // for weighted edges
        // list[v2].push_back({v1, wt});
    }

    return 0;
}
// https://leetcode.com/problems/flood-fill/submissions/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int i, int j, int color, int src_color)
{
    int n, m;
    n = image.size();
    m = image[0].size();
    if (i < 0 || j < 0)
    {
        return;
    }
    if (i >= n || j >= m)
    {
        return;
    }
    if (image[i][j] != src_color)
    {
        return;
    }
    image[i][j] = color;

    dfs(image, i - 1, j, color, src_color);
    dfs(image, i + 1, j, color, src_color);
    dfs(image, i, j - 1, color, src_color);
    dfs(image, i, j + 1, color, src_color);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    if (image[sr][sc] != color)
    {

        dfs(image, sr, sc, color, image[sr][sc]);
    }
    return image;
}

int main()
{

    return 0;
}
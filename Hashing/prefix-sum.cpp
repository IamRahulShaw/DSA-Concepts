/*
giveen array a of N integers. Given Q queries
and in each query given L and R print sum of
array elemnts from index L to R(L, R included)
Constraints
1 <= N <= 10^5
1 <= a[i] <= 10^9
1 <= Q <= 10^5
1 <= L, R <= N
*/

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 10;
// int prefix_sum[N];

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; ++i)
//     {
//         int num;
//         cin >> num;
//         a[i] = num;
//         prefix_sum[i + 1] = num + prefix_sum[i];
//     }
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int l, r;
//         cin >> l >> r;
//         int ans = prefix_sum[r + 1] - prefix_sum[l + 1 - 1]; // we have consider the l+1th index of the prefix sum array
//         cout << ans << endl;
//     }
//     return 0;
// }

/*
Given 2d array a of N*N integers. Given Q
queries and in each query given a, b, c and d
print sum of square represented by (a,b) as
top left point and (c,d) as top bottom right
point
Constraints
1 <= N <= 10^3
1 <= a[i][j] <= 10^9
1 <= Q <= 10^5
1 <= a,b,c,d <= N
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int prefix_sum[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int num;
            cin >> num;
            prefix_sum[i][j] = num + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = prefix_sum[c][d] + prefix_sum[a - 1][b - 1] - prefix_sum[a - 1][d] - prefix_sum[c][b - 1];
        cout << ans << endl;
    }
    return 0;
}
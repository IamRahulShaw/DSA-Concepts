// https://www.codechef.com/problems/GCDQ

#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 10;
// int gcd_left_to_right[N];
// int gcd_right_to_left[N];  // In every iteration of test case, we will not reassign the the arrays to 0, so we get wrong answer. We have to reassign the arrays with 0.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int A[n + 10];
        int gcd_left_to_right[n + 10];
        int gcd_right_to_left[n + 10];
        gcd_left_to_right[0] = gcd_right_to_left[n + 1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int num;
            cin >> num;
            A[i] = num;
        }
        for (int i = 1; i <= n; ++i)
        {
            gcd_left_to_right[i] = __gcd(A[i], gcd_left_to_right[i - 1]);
        }
        for (int i = n; i >= 1; --i)
        {
            gcd_right_to_left[i] = __gcd(A[i], gcd_right_to_left[i + 1]);
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int ans = __gcd(gcd_left_to_right[l - 1], gcd_right_to_left[r + 1]);
            cout << ans << endl;
        }
    }
    return 0;
}
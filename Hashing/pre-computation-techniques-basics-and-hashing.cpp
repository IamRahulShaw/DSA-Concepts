/*
Given T Test cases and in each
est case a number N. Print its factorial
for each test case & M
where M = 10^9+7.
Constraints
1 <= T <= 10^5
1 <= N <= 10^5
*/

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 10;
// const int M = 1e9 + 7;
// long long fact[N];

// int main()
// {
//     fact[0] = fact[1] = 1;
//     for (int i = 2; i <= 1e5; ++i)
//     {
//         fact[i] = (i * fact[i - 1]) % M;
//     }
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         cout << fact[n] << endl;
//     }

//     return 0;
// }

/*
Given array a of N integers. Given Q queries >>
and in each query given a number X, print
Count of that number in array.
Constraints
1 <= N <= 10^5
1 <= a [i] <= 10^7
1 <= Q <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
unordered_map<int, int> hsh;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        a[i] = num;
        auto it = hsh.find(num);
        if (it == hsh.end())
        {
            hsh.insert({num, 1});
        }
        else
        {
            ++hsh[num];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        cout << hsh[num] << endl;
    }

    return 0;
}
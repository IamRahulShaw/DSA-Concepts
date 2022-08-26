// https://leetcode.com/problems/super-pow/

#include <bits/stdc++.h>
using namespace std;

const int M = 1337;
const int phi_M = 1140; // Euler Totient Function --> phi of M  that is phi of 1337
int power(int a, int b, int m)
{
    int result = 1;
    while (b)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        b = b >> 1;
        a = (a * 1LL * a) % m;
    }
    return result;
}

int superPow(int a, vector<int> &b)
{
    // By Euler Theorem
    // int ans = 1, index = 0;
    // for (auto it = b.rbegin(); it != b.rend(); ++it)
    // {
    //     int power_value = ((*it) * 1LL * power(10, index, phi_M)) % phi_M;
    //     ans = (ans * power(a, power_value, M)) % M;
    //     ++index;
    // }
    // return ans;

    // By array traversal and power with 10
    int ans = 1;
    for (int val : b)
    {
        // ans = ( ans ^ 10 * a ^ val )
        ans = (power(ans, 10, M) * 1LL * power(a, val, M)) % M;
    }
    return ans;
}

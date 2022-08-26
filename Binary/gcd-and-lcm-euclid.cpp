#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int main()
{
    // gcd
    // cout << gcd(12, 18) << endl;
    // cout << __gcd(12, 18) << endl; // inbuilt formula of gcd
    // cout << gcd(14, 12) << endl;

    // lcm
    // cout << (12 * 18) / gcd(12, 18) << endl;
    return 0;
}
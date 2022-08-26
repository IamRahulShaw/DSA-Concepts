#include <bits/stdc++.h>
using namespace std;

// a^b, if a is be the range of 10^18 and M is 1e9 + 7, then first we take modulo of a before any calculations

// const int M = 1e9 + 7;

// int binaryExponentiation(long long a, long long b)
// {
//     a = a % M;
//     int result = 1;
//     while (b)
//     {
//         if (b & 1)
//         {
//             result = ((result * a) % M);
//         }
//         b = b >> 1;
//         a = ((a * a) % M);
//     }
//     return result;
// }

// a^b, if a is order of 1e18 and M is also order of 1e18, then a%M is also the order of 1e18. So, we can not do a * a, here we use binaryMultiplication

const int M = 1e18 + 7;

int binaryMultiplication(long long a, long long b)
{
    int result = 0;
    while (b)
    { // O(logb)
        if (b & 1)
        {
            result = ((result + a) % M);
        }
        b = b >> 1;
        a = ((a + a) % M);
    }
    return result;
}

int binaryExponentiation(long long a, long long b)
{
    int result = 1;
    while (b) // O(logb)
    {
        if (b & 1)
        {
            result = binaryMultiplication(result, a); // O(loga)
        }
        b = b >> 1;
        a = binaryMultiplication(a, a); // O(loga)
    }                                   // Total time complexity O(logb * 2 * loga) --> O((logN)^2)
    return result;
}

int main()
{
    cout << binaryExponentiation(1e18, 123);
    return 0;
}
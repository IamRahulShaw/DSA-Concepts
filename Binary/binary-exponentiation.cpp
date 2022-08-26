#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

// recursive method
int binaryExponentiationRecursive(int a, int b)
{

    if (b == 0)
    {
        return 1;
    }

    int result = binaryExponentiationRecursive(a, b / 2);
    if (b & 1)
    {
        return ((a * ((result * 1LL * result) % M)) % M); // result * result --> the operation will occur in integer system, so value can be overflowed. so, either we convert result from int to long long or just multiply with 1LL
    }
    else
    {
        return ((result * 1LL * result) % M);
    }
}

// iterative method
int binaryExponentiationIterative(int a, int b)
{
    int result = 1;
    while (b)
    {
        if (b & 1)
        {
            result = ((result * 1LL * a) % M);
        }
        b = b >> 1;
        a = ((a * 1LL * a) % M);
    }
    return result;
}

int main()
{
    cout << binaryExponentiationRecursive(2123123, 1231231) << endl;
    cout << binaryExponentiationIterative(2123123, 1231231) << endl;

    return 0;
}

// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/
#include <bits/stdc++.h>
using namespace std;

// 0 <= c <= 1e5
// max bits -> (int)5*log2(10)+1 -> 5*3 +1 -> 16

int main()
{
    int c, size;
    cin >> c;
    size = ((int)log2(c)) + 1;
    int a = 0, b = 0;
    vector<int> set_count; // 1, 3, 4, 5 <- set bits
    for (int i = 0; i < size; ++i)
    {
        if (c & (1 << i))
        {
            set_count.push_back(i);
        }
        else
        {
            a = a | (1 << i);
            b = b | (1 << i);
        }
    }

    int sz = (1 << set_count.size()); // max 2^16
    long long product = -1;
    for (int mask = 0; mask < sz; ++mask)
    {

        int a_copy = a, b_copy = b;
        for (int j = 0; j < set_count.size(); ++j)
        {
            if (mask & (1 << j))
            {
                a_copy = a_copy | (1 << set_count[j]);
            }
            else
            {
                b_copy = b_copy | (1 << set_count[j]);
            }
        }
        product = max(product, (a_copy * 1LL * b_copy));
    }
    cout << product << endl;
    return 0;
}
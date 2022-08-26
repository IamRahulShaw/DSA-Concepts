// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

vector<int> hsh_count(N);
vector<int> power_count(N);
vector<int> highest_prime(N);

vector<int> distint_prime_factors(int n)
{
    vector<int> result;
    while (n > 1)
    {
        int h_p = highest_prime[n];
        while (n % h_p == 0)
        {
            n /= h_p;
        }
        result.push_back(h_p);
    }
    return result;
}

int main()
{
    int n, q;
    cin >> n >> q;
    // hash count
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        hsh_count[num]++;
    }
    // highest prime
    for (int i = 2; i < N; ++i)
    {
        if (highest_prime[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                highest_prime[j] = i;
            }
        }
    }
    // power count
    for (int i = 2; i < N; ++i)
    {
        if (hsh_count[i])
        {
            for (long long j = i; j < N; j *= i)
            {
                power_count[j] = i; // power_count store base number also, if 2 is present in the array, means 2's power count is 2 and 4's power count is also 2
            }
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        bool res = false;

        vector<int> d_p_f = distint_prime_factors(x);

        for (int i = 0; i < d_p_f.size(); ++i)
        {
            for (int j = i; j < d_p_f.size(); ++j)
            {
                long long product = d_p_f[i] * d_p_f[j];
                if (i == j && x % product != 0)
                {
                    continue;
                }
                if (power_count[x / product] || (x / product) == 1)
                {
                    res = true;
                    break;
                }
            }
            if (res)
            {
                break;
            }
        }
        cout << (res ? "YES" : "NO") << endl;
    }

    return 0;
}
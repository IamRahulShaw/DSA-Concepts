#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int binaryExponentiation(int num, int power, int modulo)
{
    int result = 1;
    while (power)
    {
        if (power & 1)
        {
            result = (result * 1LL * num) % M;
        }
        power = power >> 1;
        num = (num * 1LL * num) % M;
    }
    return result;
}

/*
There are N toffees and K students. K<N. Count the number of ways to distribute toffee among K students such that each student get 1 toffee only
 nCk --> combinations
 n! / (n-k)! * k!
 K < N < 1e6
 Q < 1e5
*/

const int N = 1e6;
vector<int> factorials;

int main()
{
    // cout << binaryExponentiation(2, M - 2, M) << endl;// Modular Multiplicative Inverse of 2
    factorials.push_back(1);
    for (int i = 1; i <= N; ++i)
    {
        int fact = (i * 1LL * factorials[i - 1]) % M;
        factorials.push_back(fact);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        int n_fact = factorials[n];
        int k_fact = factorials[k];
        int n_k_fact = factorials[n - k];
        int denominator = (k_fact * 1LL * n_k_fact) % M;
        int result = (n_fact * 1LL * binaryExponentiation(denominator, M - 2, M)) % M; // Modular Multiplicative Inverse of denominator
        cout << result << endl;
    }
    return 0;
}
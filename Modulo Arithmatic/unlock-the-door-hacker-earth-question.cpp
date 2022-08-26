// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5;
vector<int> factorials;

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

int main()
{
    factorials.push_back(1);
    for (int i = 1; i <= N; ++i)
    {
        factorials.push_back(((i * 1LL * factorials[i - 1]) % M));
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        // n! * kCn --> n! * (k! / ((k-n)! * n!)) --> k! / (k-n)!
        int k_fact = factorials[k];
        int k_n_fact = factorials[k - n];
        int result = (k_fact * 1LL * binaryExponentiation(k_n_fact, M - 2, M)) % M;
        cout << result << endl;
    }
    return 0;
}
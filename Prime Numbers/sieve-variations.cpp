#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> is_prime(N, 1);
vector<int> highest_prime(N, 0);
vector<int> lowest_prime(N, 0);

int main()
{
    // highest prime & lowest prime
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (is_prime[i])
        {
            highest_prime[i] = lowest_prime[i] = i;
            for (int j = i * 2; j <= N; j = j + i)
            {
                is_prime[j] = false;
                highest_prime[j] = i;
                if (lowest_prime[j] == 0)
                {
                    lowest_prime[j] = i;
                }
            }
        }
    }

    // prime factorization
    // vector<int> prime_factorization;
    // int num;
    // cin >> num;
    // while (num > 1)
    // {
    //     prime_factorization.push_back(highest_prime[num]);
    //     num = num / highest_prime[num];
    // }

    // divisors
    int N1 = 1e5 + 10;
    vector<int> divisors[N1];
    divisors[1].push_back(1);
    for (int i = 2; i <= N1; ++i)
    {
        for (int j = i; j <= N1; j = j + i)
        {
            divisors[j].push_back(i);
        }
    } // n/2 + n/3 + n/4.. -> nlogn
    for (int i = 1; i <= 10; ++i)
    {
        for (int val : divisors[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
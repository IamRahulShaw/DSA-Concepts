#include <bits/stdc++.h>
using namespace std;

// Q -> 1e7 & N -> 1e7

const int N = 1e7 + 10;
vector<bool> is_prime(N, 1);

int main()
{
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= N; ++i)
    {

        if (is_prime[i])
        {
            for (int j = i * 2; j <= N; j = j + i)
            {
                is_prime[j] = 0;
            }
        }
    } // Time Complexity -> O(nlog(logn))
    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        if (is_prime[num])
        {
            cout << "prime" << endl;
        }
        else
        {
            cout << "not prime" << endl;
        }
    }

    return 0;
}
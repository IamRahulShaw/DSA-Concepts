#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0, sum = 0;
    cin >> n;

    // for (int i = 1; i <= n; ++i) // O(n)
    for (int i = 1; i * i <= n; ++i) // O(sqrt(n))
    {
        if (n % i == 0)
        {
            // cout << i << endl;
            // ++count;
            // sum = sum + i;
            cout << i << " " << (((n / i) != i) ? (n / i) : -1) << endl;
            ++count;
            sum = sum + i;
            if (i != (n / i))
            {
                ++count;
                sum = sum + (n / i);
            }
        }
    }
    cout << "count " << count << endl;
    cout << "sum " << sum << endl;
    return 0;
}
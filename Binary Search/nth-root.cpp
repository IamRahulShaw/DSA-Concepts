#include <bits/stdc++.h>
using namespace std;

double eps = 1e-7;

double multiply(double m, int n)
{
    double ans = 1;
    for (int i = 0; i < n; ++i)
    {
        ans = ans * m;
    }
    return ans;
}

int main()
{
    int n;
    double x;
    cin >> x >> n;
    double low = 1, high = x, mid;
    while (high - low > eps)
    {
        mid = (high + low) / 2;
        if (multiply(mid, n) < x)
        {
            low = mid; // mid+1 never happen because you just jump over the 1 digit, so lost all decimal precision. Add 1 will cause loss of all the decimal precise values.
        }
        else
        {
            high = mid;
        }
    }
    // Time complexity O( n * log( m * 1e7 ) )

    cout << setprecision(8) << low << " " << high << endl;

    return 0;
}

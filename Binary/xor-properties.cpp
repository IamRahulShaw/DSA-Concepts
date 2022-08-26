#include <bits/stdc++.h>
using namespace std;

int main()
{

    // swap using xor
    // int a = 4, b = 6;
    // cout << "before swap -> " << a << " " << b << endl;
    // a = a ^ b;
    // b = b ^ a;
    // a = a ^ b;
    // cout << "after swap -> " << a << " " << b << endl;

    /*
        Given an array of n integers. All integers are present in even count except one integer.
        Find that odd integer which has only one count in O(N) time complexity and O(1) space.
        N < 10^5
        a[i] < 10^5
    */

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        ans = ans ^ num; // initially ans = 0. so, xor of any number with 0 is the same number. so, first case ans will be the input number. The main strategy is xor of same number is 0. so, all even numbers gives 0 and the odd number's xor with 0 is the same odd number. thus, we get the odd number.
    }
    cout << ans << endl;
    return 0;
}
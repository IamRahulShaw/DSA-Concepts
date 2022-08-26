#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> prime_factors;
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n = n / i;
        }
    }
    /*
        Example: 60, i = 2, 60 divides by 2 and n becomes 60/2 = 30, again 30 divides by 2 and n becomes 15 but 15 % 2 != 0, so while loop breaks and i become 3 and 15 is a composite number, so there exist one prime number before sqrt(15) that divides 15. Now, i is 3, and 3*3 = 9 is less than 15, so execution enters in while loop, 15 divides by i means 3 and n become 15/3 = 5, and 5%3 != 0. so, i become 4 and 5 is a prime numbers so, there is no number before other than 1 and 5 that divide 5. Now, i = 4 and 4*4=16 is not less than 5, so for loop breaks. So, for the last prime number we, check in the if condition, if the number is greater than 1, so push that number in the vector.
    */
    if (n > 1)
    {
        prime_factors.push_back(n);
    }
    for (int val : prime_factors)
    {
        cout << val << " ";
    }
    return 0;
}
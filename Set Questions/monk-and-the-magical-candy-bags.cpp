// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        multiset<long long> candies;
        for (int i = 0; i < n; ++i)
        {
            long long candy;
            cin >> candy;
            candies.insert(candy);
        }
        long long sum = 0;
        for (int i = 0; i < k; ++i)
        {
            auto it = --candies.end();
            long long candy = *it;
            sum = sum + candy;
            candies.erase(it);
            candies.insert(candy / 2);
        }
        cout << sum << endl;
    }
    return 0;
}